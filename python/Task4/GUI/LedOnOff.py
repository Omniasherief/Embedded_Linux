
import tkinter as tk

ledState = False
 
def LedOn():
  global led_state
  ledState=True
  canvas.itemconfig(led_circle, fill="blue")

def LedOff():
    global led_state
    ledState=False
    canvas.itemconfig(led_circle, fill="white")
  



# Create the main application window
root = tk.Tk()
root.title("LED Simulator")

# Create a canvas for drawing the LED circle
canvas_width = 300
canvas_height = 300
canvas=tk.Canvas(root, width=canvas_width,height=canvas_height)
canvas.pack()



# LED circle radius (adjust based on canvas size)
led_radius = canvas_width // 2  - 20 #Account for some padding

# Draw the LED circle (initially off - red)
center_x = canvas_width // 2
center_y = canvas_height // 2
led_circle = canvas.create_oval(center_x - led_radius, center_y - led_radius,
                                  center_x + led_radius, center_y + led_radius,
                                  fill="white")

# Create buttons to turn the LED on and off
on_button = tk.Button(root, text="Turn On", command=LedOn)
on_button.pack(padx=10, pady=10)

off_button = tk.Button(root, text="Turn Off", command=LedOff)
off_button.pack(padx=10, pady=10)

# Run the application
root.mainloop()

