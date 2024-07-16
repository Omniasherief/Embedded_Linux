import pyautogui
from time import sleep

pyautogui.FAILSAFE = False


pyautogui.moveTo(1000, 1000, duration=0.7)
sleep(4)
distance = 200
while distance > 0:
        pyautogui.drag(distance, 0, duration=0.5)   # move right
        distance -= 5
        pyautogui.drag(0, distance, duration=0.5)   # move down
        pyautogui.drag(-distance, 0, duration=0.5)  # move left
        distance -= 5
        pyautogui.drag(0, -distance, duration=0.5)  # move up



'''
print(pyautogui.position())
sleep(2)
pyautogui.click(99,1041)

sleep(1)
pyautogui.move(1000,1000)

print(pyautogui.position())
sleep(2)
pyautogui.click(66,1041)
sleep(2)
print(pyautogui.size())
#pyautogui.moveTo(1000, 1000, duration=0.7)h
sleep(2)

pyautogui.press("o")
pyautogui.press(["o","m","n","i","a"],presses=2)

pyautogui.click(99,1041)
sleep(4)
pyautogui.moveTo(1000, 1000, duration=0.7)
sleep(4)
pyautogui.mouseDown()
sleep(3)
pyautogui.mouseUp()
pyautogui.keyDown("h")
pyautogui.keyUp("h")

pyautogui.countdown(5)
'''