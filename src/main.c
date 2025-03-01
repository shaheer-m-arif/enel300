#include <stdio.h>
#include "config.h"
#include "motor_control.h"
#include "distance_sensor.h"
#include "metal_detector.h"
#include "remotecontroller.h"
#include "wireless_remote.h"

int main(void) {
    distance_sensor_init();
    metal_detector_init();
    remotecontroller_init();
    wireless_remote_init();

    while (1) {
        uint16_t distance = get_distance();
        uint8_t metal = detect_metal();
        uint8_t command = receive_command();
        transmit_data("Hello");

        // Do something with these values
    }
    return 0;
}
