import tkinter as tk
from tkinter import messagebox

def factorial(num):
    if num==0 or num==1:
        return 1
    else:
        return num *factorial(num-1)



def calculate_button():
    try:
        num=int(entry.get()) # Get the input from the Entry widget
        Ans=factorial(num)
        messagebox.showinfo("Answer",f"Factorial of {num} ={Ans} ")
    except ValueError:
        messagebox.showerror("Error", "Please enter a valid integer.")    



# Create the main application window
root = tk.Tk()
root.title("Factorial Calculator")

# Create and place widgets
label = tk.Label(root, text="Enter an integer N:")
label.grid(row=0,column=0)

entry = tk.Entry(root)
entry.grid(row=0,column=1)

button = tk.Button(root, text="Calculate Factorial", command=calculate_button)
button.grid(row=1,column=1)

# Run the application
root.mainloop()

