#include "metal_detector.h"
#include <avr/io.h>
#include <util/delay.h>

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 0b00100000  // PA5 for LED
#define TIMER_CAPTURE_PIN 0b00000100  // PD2 (Timer Capture Input)

// Initialize Timer1 for Frequency Measurement
void timer_init() {
    TCB0.CTRLA = TCB_CLKSEL_CLKDIV1_gc | TCB_ENABLE_bm;  // Enable Timer with no prescaler
    TCB0.CTRLB = TCB_CNTMODE_CAPT_gc;  // Capture mode
}

// Measure frequency from 555 Timer
uint16_t measure_frequency() {
    while (!(TCB0.INTFLAGS & TCB_CAPT_bm));  // Wait for capture event
    uint16_t count = TCB0.CCMP;  // Get captured value
    TCB0.INTFLAGS = TCB_CAPT_bm;  // Clear flag
    return count;
}

int main() {
    // Configure PA5 as output for LED
    PORTA.DIR |= LED_PIN;  // Set PA5 (LED) as output
    
    // Initialize Timer for frequency capture
    timer_init();
    
    // Get baseline frequency (no metal detected)
    uint16_t baseline_freq = measure_frequency();

    while (1) {
        uint16_t freq = measure_frequency();

        // If frequency drops (metal detected), turn on LED
        if (freq < baseline_freq - 500) {
            PORTA.OUT |= LED_PIN;  // Turn LED ON
        } else {
            PORTA.OUT &= ~LED_PIN; // Turn LED OFF
        }

        _delay_ms(200);  // Small delay to prevent flickering
    }
}
