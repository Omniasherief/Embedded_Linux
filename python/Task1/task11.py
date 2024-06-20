#!/usr/bin/python3
def IsVowel(char):
    Vowel="aeiou"
    return char in Vowel
char= input("Enter charcter : ")
print(IsVowel(char.lower()))
'''
char= input("Enter charcter : ")
if(char.lower() == IsVowel(char)):
 print("is vowel")
else: print (" it is not vowel")
'''
