#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 21  // GPIO21 (Physical Pin 40)

int main() {
    if (wiringPiSetupGpio() == -1) {
        printf("Setup Failed!\n");
        return 1;
    }

    pinMode(LED_PIN, OUTPUT);

    while (1) {
        digitalWrite(LED_PIN, HIGH);
        sleep(1);
        digitalWrite(LED_PIN, LOW);
        sleep(1);
    }

    return 0;
}
