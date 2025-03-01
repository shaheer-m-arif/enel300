#ifndef REMOTECONTROLLER_H
#define REMOTECONTROLLER_H

void remotecontroller_init(void);
void send_command(uint8_t command);
uint8_t receive_command(void);

#endif // REMOTECONTROLLER_H
