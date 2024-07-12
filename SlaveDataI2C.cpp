#include "SlaveDataI2C.h"

SlaveDataI2C::SlaveDataI2C(uint8_t slaveAddress) {
    _slaveAddress = slaveAddress;
}

void SlaveDataI2C::begin() {
    Wire.begin();
}

bool SlaveDataI2C::requestData(uint16_t &pulseCount1, uint16_t &pulseCount2) {
    Wire.beginTransmission(_slaveAddress);
    Wire.write(0x01);  // Send request command
    if (Wire.endTransmission() != 0) {
        return false; // Transmission error
    }

    // Request 4 bytes from the slave
    Wire.requestFrom(_slaveAddress, (uint8_t)4);
    if (Wire.available() == 4) {
        _buffer[0] = Wire.read();
        _buffer[1] = Wire.read();
        _buffer[2] = Wire.read();
        _buffer[3] = Wire.read();

        // Combine bytes into 16-bit integers
        pulseCount1 = (_buffer[1] << 8) | _buffer[0];
        pulseCount2 = (_buffer[3] << 8) | _buffer[2];
        return true;
    }

    return false; // Not enough data received
}
