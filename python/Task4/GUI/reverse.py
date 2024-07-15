import tkinter as tk

def reverse_word():
  word = entry.get()  # Get the text entered in the entry widget
  reversed_word = word[::-1]  # Reverse the word using slicing
  label.config(text="Reversed Word: " + reversed_word)  # Update the label text

# Create the main window
root = tk.Tk()
root.title("Word Reversal")

# Create an entry widget for user input
entry = tk.Entry(root, width=20)
entry.pack()

# Create a button to trigger the reversal
button = tk.Button(root, text="Reverse", command=reverse_word)
button.pack()

# Create a label to display the reversed word
label = tk.Label(root, text="")
label.pack()

# Run the main event loop
root.mainloop()