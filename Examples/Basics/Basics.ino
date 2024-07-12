#include <Wire.h>
#include <SlaveDataI2C.h>

// Define the I2C address of the slave
#define SLAVE_ADDRESS 0x50

SlaveDataI2C pulseData(SLAVE_ADDRESS);

void setup() {
    Serial.begin(9600);
    pulseData.begin();
}

void loop() {
    uint16_t pulseCount1 = 0;
    uint16_t pulseCount2 = 0;

    if (pulseData.requestPulseData(pulseCount1, pulseCount2)) {
        Serial.print("Pulse Count 1: ");
        Serial.println(pulseCount1);
        Serial.print("Pulse Count 2: ");
        Serial.println(pulseCount2);
    } else {
        Serial.println("Failed to request pulse data");
    }

    delay(1000);
}
