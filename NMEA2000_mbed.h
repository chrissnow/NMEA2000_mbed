/*
NMEA2000_mbed.h

2017 Copyright (c) Al Thomason   All rights reserved

Support the MBED targeted CPUs  (STM32F072, etc)
See: https://github.com/thomasonw/NMEA2000_mbed
     https://github.com/ttlappalainen/NMEA2000


Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

See also NMEA2000 library.
*/


#ifndef _NMEA2000_MBED_H_
#define _NMEA2000_MBED_H_

#include <NMEA2000.h>
#include <N2kMsg.h>
#include "mbed.h"


//extern Serial pc;                                               // Likely /dev/ttyACM0

void     delay(uint32_t ms);
uint32_t millis(void);

class tNMEA2000_mbed : public tNMEA2000
{
protected:
    virtual bool CANSendFrame(unsigned long id, unsigned char len, const unsigned char *buf, bool wait_sent);
    virtual bool CANOpen();
    virtual bool CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf);

public:
    tNMEA2000_mbed();

};



class tmbedStream : public N2kStream {
public:
   virtual int read();
   virtual size_t write(const uint8_t* data, size_t size);
};




#endif