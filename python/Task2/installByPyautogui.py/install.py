import pyautogui
from time import sleep
import os


extensions = {
    "clangd":"clangd.png",  
    "cmake":"cmake_tools.png",  
    "cpp test mate":"cmake.png",  
    "cpp helper":"cpp_helper.png",  
    "cpp tastemate":"cpp_tastemate.png"
}
def search_and_install(extension_name, picture_name):
    """Searches for an extension based on name and picture, then clicks install."""
    location = None
    while location is None:
        try:
           
            pyautogui.hotkey("ctrl", "a")  # Select all text
            sleep(2)
            pyautogui.press("delete")  # Clear search bar
            sleep(2)

            # Search for extension by name
            pyautogui.write(extension_name)
            sleep(3)

            # Locate extension image on screen
            location = pyautogui.locateOnScreen(picture_name)
            sleep(2)

            if location:

                
                install_button = pyautogui.locateOnScreen("install.png",confidence=0.7)
                sleep(3)
                if install_button:
                    pyautogui.click(install_button)
                    sleep(2)
                    print(f"Installing extension: {extension_name}")
                    
                else:
                    print(f"Extension: {extension_name} - Install button not found")
            else:
                print(f"Extension: {extension_name} not found")
            break  # Exit loop after search completes

        except pyautogui.ImageNotFoundException:
            print("Image not found")
            break  # Exit loop on image not found




os.system("code")
sleep(2)
    #pyautogui.hotkey("ctrl", "`")  
    #sleep(1)
    #pyautogui.typewrite("code")  
    #sleep(1)
    #pyautogui.press("enter")
    #sleep(1)
pyautogui.hotkey("ctrl", "shift", "x")  # open extentions
sleep(1)

# Install extensions
for extension_name, picture_name in extensions.items():
    search_and_install(extension_name, picture_name)

print("All extension installation checks completed!")

