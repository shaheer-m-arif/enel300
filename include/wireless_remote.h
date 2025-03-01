#ifndef WIRELESS_REMOTE_H
#define WIRELESS_REMOTE_H

void wireless_remote_init(void);
void transmit_data(const char* data);
char* receive_data(void);

#endif // WIRELESS_REMOTE_H
