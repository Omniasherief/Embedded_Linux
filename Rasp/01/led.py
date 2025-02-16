
import os
import time
import RPi.GPIO as GPIO

LED_PIN = 21  # Change to GPIO21 (Pin 40)

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)

# Open VS Code
os.system("code &")

try:
    while True:
        GPIO.output(LED_PIN, GPIO.HIGH)  # LED ON
        time.sleep(1)
        GPIO.output(LED_PIN, GPIO.LOW)   # LED OFF
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()
