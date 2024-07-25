#include <iostream>
#include <memory_resource>
#include <vector>
#include <string>

struct contact {

    std::string name;
    std::string phoneNo;
    std::string email;
};


void addContact(std::vector<contact> &contacts)
{
   contact newcontact;
   std::cout << "Enter  name : ";
   std::getline(std::cin,newcontact.name);
   std::cout << "Enter phone number : ";
   std::getline(std::cin,newcontact.phoneNo);
   std::cout << "Enter email : ";
   std::getline(std::cin,newcontact.email);
   contacts.push_back(newcontact);
   std::cout <<"contact is added successfully\n";

}

void deleteContact(std::vector<contact> &contacts)
{
   std::string name;
   std::cout << "Enter the name of contact to delete ";
   std::getline(std::cin,name);

   for(auto it=contacts.begin(); it !=contacts.end(); ++it)
   {
    if(it->name ==name)
    {
        contacts.erase(it);
        std::cout <<"contact  deleted successfully\n";
        return;
    }
   }
   std::cout << "Contact Not Found\n";
}

void deleteAllContacts(std::vector <contact> &contacts)
{
    contacts.clear();
    std::cout <<"All contacts deleted successfully!\n";
}

void searchContact(const std::vector<contact> &contacts)
{
    std::string name;
    std::cout << "Enter the name of the contact to update: ";
    std::getline(std::cin, name);

    for(const auto& contact :contacts)
    {

       if(contact.name==name)
        { 
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Phone: " << contact.phoneNo << "\n";
            std::cout << "Email: " << contact.email << "\n";
            return;
        }

    }

 std::cout <<"Contact Not Found\n";
}

void listContacts(const std::vector<contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No Contacts Found.\n";
        return;
    }

    for (const auto& contact : contacts) {
        std::cout << "Name : " << contact.name << "\n";
        std::cout << "Phone: " << contact.phoneNo << "\n";
        std::cout << "Email: " << contact.email << "\n";
        std::cout << "----------------------\n";
    }
}

void updateContact( std::vector<contact> &contacts)
{
    std::string name;
    std::cout << "Enter the name of the contact to update: ";
    std::getline(std::cin, name);

    for(auto& contact :contacts)
    {

       if(contact.name==name)
        { 
            std::cout << "Enter new phone: ";
            std::getline(std::cin, contact.phoneNo);
            std::cout << "Enter new email: ";
            std::getline(std::cin, contact.email);
            std::cout << "Contact updated successfully!\n";
            return;
        }

    }

 std::cout <<"Contact Not Found\n";
}

void displayMenu() {
    std::cout << "\nWelcome to your favorite address book!\n";
    std::cout << "What do you want to do?\n";
    std::cout << "1. List       | Lists all users\n";
    std::cout << "2. Add        | Adds a user\n";
    std::cout << "3. Delete     | Deletes a user\n";
    std::cout << "4. Delete all | Removes all users\n";
    std::cout << "5. Search     | Search for a user\n";
    std::cout << "6. update     | updates a user\n";
    std::cout << "7. Close      | Closes the address book\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<contact> contacts;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                listContacts(contacts);
                break;
            case 2:
                addContact(contacts);
                break;
            case 3:
                deleteContact(contacts);
                break;
            case 4:
                deleteAllContacts(contacts);
                break;
            case 5:
                searchContact(contacts);
                break;

            case 6:
                updateContact(contacts);
                break;    
            case 7:
                std::cout << "Closing the address book.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}