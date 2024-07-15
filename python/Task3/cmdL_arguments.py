
import sys

def get_script_name_and_args():
  """
  Retrieves the script name and command-line arguments.

  Returns:
      tuple: A tuple containing the script name and a list of arguments.
  """

  script_name = sys.argv[0]
  arguments = sys.argv[1:]  # Assign arguments after checking length
  # Check for at least one argument (excluding script name)
  if len(arguments) < 1:
      arguments = 0  # Set arguments to 0 (or an empty list) if no arguments provided
  
  return script_name, arguments

if __name__ == "__main__":
  script_name, args = get_script_name_and_args()

  print(f"Script name: {script_name}")
  print(f"Command-line arguments: {args}")