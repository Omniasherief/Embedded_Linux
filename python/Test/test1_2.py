
#!/usr/bin/python3

from greet import greetP
import json
import os
import sys
import datetime
import requests


print("A") if 5>2 else print('B')
response = requests.get("https://api.github.com")
print(response.json())

print(json.dumps({"name": "John", "age": 30}))  # Convert dictionary to JSON string
print(os.getcwd())  # Get current working directory
print(sys.version)  # Get Python version
print(datetime.datetime.now())  # Get current date and time
words=["Omnia","Sherief"]
joined="_".join(words)
print(joined)

print('''iam ''')
print (len("omg"))
string="hello world"
String2=("   I Am Omnia    ")
sub=string[0:6]
print(sub)
print(string[-1])
print(string.upper())
print(string)
print(string.lower())
#strip() Removes leading and trailing whitespace.
print(String2.strip().lower())
print(String2.split())
#if
i = 6
if i > 5:
    print("hi")
elif i > 8:
    print("ok")
else:
    print("WTH")




#loops

for i in range (5):
    print(i)
   

while i>3:
    print("LOOP")
    i-=1
#call function

greetP()

#Return
def add(a, b):
    return a + b

result = add(5, 1)
print(result)


def check_even_odd(number):
    if number % 2 == 0:
        return "even"
    else:
        return "odd"

for i in range(1, 11):
    print(f"{i} is {check_even_odd(i)}")


def check(number):
    if number>5:
      return "bigger"
    else:
        return"smaller"
    #  return "bigger" if number > 5 else "smaller"
#i=0

for i in range (1,10):
     print(f"{i} is {check(i)}")   
    


def hi(name="Omnia"):
    print(f"hello,{name}")

hi()
hi("che")

#variadic Functions
#*args for a tuple of positional arguments and **kwargs for a dictionary of keyword arguments.
def sumNumbers(*Num):
    return sum(Num)

result=sumNumbers(3,7,-1)
print(result)

def print_Dic(**info):
    for key,value in info.items():
        print(f"{key}:{value}")

print_Dic(name="omnia", age=20, country="Egypt")    


#Lambda
numbers=[1,2,3,5,6,7]
squared=list(map(lambda x:x**2,numbers))
print(squared)

even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # Output: [2, 4]