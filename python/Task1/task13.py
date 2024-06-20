import calendar

def print_calendar(year, month):
  """Prints the calendar for the given month and year."""
  print(calendar.month(year, month))

 
year = int(input("Enter the year: "))
month = int(input("Enter the month (1-12): "))



print_calendar(year, month)