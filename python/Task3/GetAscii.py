
char = input("Enter a character: ")

# Check if it's a single character
if len(char) == 1:
  # Get and print ASCII code using ord()
  ascii_code = ord(char)
  print("The ASCII code for", char, "is", ascii_code)
else:
  print("Please enter a single character.")

