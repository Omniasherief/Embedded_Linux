#include <iostream>
#include <cctype> // For tolower

int main() {
    char ch;

    std::cout << "Enter a character: ";
    std::cin >> ch;
if(isalpha(ch))
{
    ch = tolower(ch); 

    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            std::cout << ch << " is a vowel." << std::endl;
            break;
        default:
            std::cout << ch << " is a consonant." << std::endl;
    }
}
else 
{
   std::cout << ch << " it is not a character" << std::endl;
}
    return 0;
}
