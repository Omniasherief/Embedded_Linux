import pyautogui
import os
from time import sleep

os.system("xdg-open https://mail.google.com/mail/u/0/#inbox")
sleep(3)
# print(pyautogui.position())
# sleep(2)
# pyautogui.click(x=622, y=370)
# sleep(1)
# pyautogui.click(x=594, y=371)
# sleep(2)
try:
    sleep(3)
    location=pyautogui.locateOnScreen('markall.png',confidence=0.8)
    sleep(4)
    print(pyautogui.position())
    if location:
        pyautogui.click(location)
        pyautogui.click(location.x,(location.y)+30)
except:
   print("image not found")




