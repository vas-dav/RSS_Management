//
// Created by Vasily Davydov on 4.1.2022.
//

#ifndef RSS_MANAGEMENT_SERIALPORT_H
#define RSS_MANAGEMENT_SERIALPORT_H


#include <unistd.h> //ssize_t
#include <chrono>
#include <fcntl.h> //open()
#include <cstdio>
#include <termios.h>
#include <unistd.h> //write(), read(), close()
#include <cerrno> //errno
#include <cstring>



int openAndConfigureSerialPort(const char* portPath, int baudRate);



bool serialPortIsOpen();



ssize_t flushSerialData();



ssize_t writeSerialData(const char* bytes, size_t length);



ssize_t readSerialData(char* bytes, size_t length);



ssize_t closeSerialPort(void);



int getSerialFileDescriptor(void);



#endif //RSS_MANAGEMENT_SERIALPORT_H
