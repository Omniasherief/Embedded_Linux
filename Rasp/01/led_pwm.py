import RPi.GPIO as GPIO
import time

LED_PIN = 18  # Change this to your GPIO pin number

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)

pwm = GPIO.PWM(LED_PIN, 1000)  # 1000Hz frequency
pwm.start(0)  # Start PWM with 0% duty cycle

try:
    for duty in range(0, 101, 1):  # Increase brightness
        pwm.ChangeDutyCycle(duty)
        time.sleep(0.02)

    for duty in range(100, -1, -1):  # Decrease brightness
        pwm.ChangeDutyCycle(duty)
        time.sleep(0.02)

except KeyboardInterrupt:
    pass

pwm.stop()
GPIO.cleanup()
