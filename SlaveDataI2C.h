#ifndef SLAVEDATAI2C_H
#define SLAVEDATAI2C_H

#include <Wire.h>

class SlaveDataI2C {
public:
    SlaveDataI2C(uint8_t slaveAddress);
    void begin();
    bool requestData(uint16_t &pulseCount1, uint16_t &pulseCount2);

private:
    uint8_t _slaveAddress;
    uint8_t _buffer[4];
};

#endif
