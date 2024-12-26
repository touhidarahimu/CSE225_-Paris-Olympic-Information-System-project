// cd /path/to/your/project
// g++ -std=c++11 -o main main.cpp
//./main


#include <iostream>    // For input/output operations
#include <vector>      // For using dynamic array
#include <string>      // For using string 
#include <algorithm>   // For standard algorithms like sort, find, etc.
#include <cstdlib>     // For functions  rand(), srand(), etc.
#include <cstring>     // For string  functions


using namespace std;


class User {
public:
    char id[1000];
    char name[1000];
    char gender[1000];
    char country[1000];
};


class Athletics {
public:
    string title;
    string name;           
    string gender;         
    string country; 
    int id;
    int IndexNumber;
    int AthleticsNumber;
    int info; // 
    Athletics* next; // pointer to the next event in the list

    Athletics() : next(nullptr),IndexNumber(0) {}

    // Function declarations
    Athletics* addAthletics(int);
    void updateAthleticsInfo();
    void deleteAthleticsInfo();
    void searchAthleticsInfo();
    void sortAthleticsInfo();
    void displayAthletics(Athletics*);
    
};

// Global variable to hold the head of the linked list
Athletics* head = nullptr;



Athletics* Athletics::addAthletics(int ath) {
    Athletics* newAthletics = new Athletics();
    newAthletics->AthleticsNumber = ath;
     newAthletics->IndexNumber = ath;

    cout << "\n    Enter ID: ";
    cin >> newAthletics->id;

  
    cout << "\n    Enter Name: ";
    cin.ignore(); 
    getline(cin, newAthletics->name);

  
    cout << "\n    Enter Gender: ";
    cin >> newAthletics->gender;

 
    cout << "\n    Enter Country: ";
    cin.ignore(); 
    getline(cin, newAthletics->country);

   
    newAthletics->info = 0;  
    newAthletics->next = nullptr;

   
    if (head == nullptr) {
        head = newAthletics;
    } else {
        Athletics* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newAthletics;
    }

    cout << "\n   Athletics information Added Successfully!";
    cout << "\n\nPress any key to continue...";
    cin.ignore(); 
    cin.get();

    return newAthletics;
}


void Athletics::searchAthleticsInfo() {
    int choice;
    cout << "\nChoose Search Criteria:";
    cout << "\n1. Search by Index Number";
    cout << "\n2. Search by ID";
    cout << "\n3. Search by Name";
    cout << "\n4. Go Back";
    cout << "\nEnter your choice: ";
    cin >> choice;

    
    if (choice == 4) {
        cout << "\nReturning to the Main Menu...\n";
        return; //
    }

    Athletics* temp = head;
    bool found = false;

    if (choice == 1) {
       
        int ath;
        cout << "\nEnter Index Number to Search : ";
        cin >> ath;

        if (ath == 0) {
            cout << "\nReturning to the Main Menu...\n";
            return; // Exit the function
        }

        while (temp != nullptr) {
            if (temp->AthleticsNumber == ath) {
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            cout << "\n\t\t\t\t\t--------Athletics Search Details --------\n\n";
            displayAthletics(temp);
        } else {
            cout << "\n   Athletics with Index Number " << ath << " not found.";
        }

    } else if (choice == 2) {
        // Search by ID
        int id;
        cout << "\nEnter ID to Search: ";
        cin >> id;

        if (id == 0) {
            cout << "\nReturning to the Main Menu...\n";
            return; // Exit the function
        }

        while (temp != nullptr) {
            if (temp->id == id) {
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            cout << "\n\t\t\t\t\t--------Athletics Search Details --------\n\n";
            displayAthletics(temp);
        } else {
            cout << "\n   Athletics with ID " << id << " not found.";
        }

    } else if (choice == 3) {
        // Search by Name
        string name;
        cout << "\nEnter Name to Search: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);

        if (name == "0") {
            cout << "\nReturning to the Main Menu...\n";
            return; // Exit the function
        }

        while (temp != nullptr) {
            if (temp->name == name) {
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            cout << "\n\t\t\t\t\t--------Athletics Search Details --------\n\n";
            displayAthletics(temp);
        } else {
            cout << "\n   Athletics with Name \"" << name << "\" not found.";
        }

    } else {
        cout << "\nInvalid choice! Please try again.";
    }

    cin.ignore(); // Wait for user input
    cin.get();
}


void Athletics::updateAthleticsInfo() {
    int eventId;
    bool found = false;

    
    cout << "\nEnter the Athletics ID to Update: ";
    cin >> eventId;

    Athletics* temp = head;  

   
    while (temp != nullptr) {
        if (temp->id == eventId) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "\nUpdating Information for Athletics ID: " << temp->id;

       
        int choice;
        do {
            cout << "\nChoose the Field to Update:";
            cout << "\n1. Update Name";
            cout << "\n2. Update Gender";
            cout << "\n3. Update Country";
            cout << "\n4. View Updated Information";
            cout << "\n5. Go Back";
            cout << "\nEnter your choice: ";
            cin >> choice;

            cin.ignore(); // Clear input buffer

            switch (choice) {
            case 1: {
                cout << "\nEnter New Name: ";
                getline(cin, temp->name);
                cout << "\nName Updated Successfully!";

                break;
            }
            case 2: {
                cout << "\nEnter New Gender: ";
                cin >> temp->gender;
                cout << "\nGender Updated Successfully!";
                break;
            }
            case 3: {
                cout << "\nEnter New Country: ";
                getline(cin, temp->country);
                cout << "\nCountry Updated Successfully!";
                break;
            }
            case 4:
                // View Updated Information
                cout << "\n\t\t\t--------Updated Athletics Information--------\n";
                displayAthletics(temp);
                break;
            case 5:
                cout << "\nReturning to the previous menu...\n";
                return; 
            default:
                cout << "\nInvalid choice! Please try again.";
            }
        } while (choice != 5);

    } else {
        cout << "\nAthletics with ID " << eventId << " not found.";
    }
}


void Athletics::deleteAthleticsInfo() {
    int choice;
    cout << "\nChoose Delete Criteria:";
    cout << "\n1. Delete by ID";
    cout << "\n2. Delete by Name";
    cout << "\n3. Delete Database";
    cout << "\n4. Go Back";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
       
        int deleteID;
        bool found = false;

        cout << "\nEnter the Athletics ID to delete: ";
        cin >> deleteID;

        Athletics* temp = head;
        Athletics* prev = nullptr;

        while (temp != nullptr) {
            if (temp->id == deleteID) {
                found = true;

                if (prev == nullptr) {
                    head = temp->next; // Update head if deleting the first node
                } else {
                    prev->next = temp->next;
                }

                delete temp; // Free the memory
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (found) {
            cout << "\nAthletics with ID " << deleteID << " deleted successfully!\n";
        } else {
            cout << "\nAthletics with ID " << deleteID << " not found!\n";
        }

    } else if (choice == 2) {
       
        string deleteName;
        bool found = false;

        cout << "\nEnter the Athletics Name to delete: ";
        cin.ignore(); 
        getline(cin, deleteName);

        Athletics* temp = head;
        Athletics* prev = nullptr;

        while (temp != nullptr) {
            if (temp->name == deleteName) {
                found = true;

                if (prev == nullptr) {
                    head = temp->next; // Update head if deleting the first node
                } else {
                    prev->next = temp->next;
                }

                delete temp; // Free the memory
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (found) {
            cout << "\nAthletics with Name \"" << deleteName << "\" deleted successfully!\n";
        } else {
            cout << "\nAthletics with Name \"" << deleteName << "\" not found!\n";
        }

    } else if (choice == 3) {
        
        Athletics* temp = head;

        if (temp == nullptr) {
            cout << "\nNo information available to delete!\n";
        } else {
            while (temp != nullptr) {
                Athletics* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            head = nullptr; 
            cout << "\nAll Athletics information has been deleted successfully!\n";
        }

    } else if (choice == 4) {
       
        cout << "\nReturning to the main menu...\n";
        return; 
    } else {
        cout << "\nInvalid choice! Please try again.\n";
    }
}


void Athletics::displayAthletics(Athletics* tempAthletics) {
    cout << "\n\n  Athletics Information  \n";
    cout << "\n   Athletics Index Number: " << tempAthletics->AthleticsNumber;
    cout << "\n   Athletics ID: " << tempAthletics->id;
    cout << "\n   Athletics Name: " << tempAthletics->name;
    cout << "\n   Athletics Gender: " << tempAthletics->gender;
    cout << "\n   Athletics Country: " << tempAthletics->country;
    
}
void Athletics::sortAthleticsInfo() {
    if (head == nullptr || head->next == nullptr) {
        cout << "\nNot enough data to sort.";
        return;
    }

    int choice;
    cout << "\nChoose Sorting Criteria:";
    cout << "\n1. Sort by Index Number ";
    cout << "\n2. Sort by ID ";
    cout << "\n3. Sort by Name ";
    cout << "\n4. Sort by Country ";
    cout << "\n5. Go Back";
    cout << "\nEnter your choice: ";
    cin >> choice;

    // Handle the "Go Back" option
    if (choice == 5) {
        cout << "\nReturning to the main menu...\n";
        return;
    }

    // Bubble Sort Algorithm for Singly Linked List
    Athletics* current;
    Athletics* next;
    bool swapped;

    do {
        swapped = false;
        current = head;

        while (current != nullptr && current->next != nullptr) {
            next = current->next;

            bool condition = false;

           
            if (choice == 1) {
                condition = current->IndexNumber > next->IndexNumber;
            } else if (choice == 2) {
                condition = current->id > next->id;
            } else if (choice == 3) {
                condition = current->name > next->name;
            } else if (choice == 4) {
                condition = current->country > next->country;
            } else {
                cout << "\nInvalid choice! Returning to the main menu.";
                return;
            }

            if (condition) {

                swap(current->IndexNumber, next->IndexNumber);
                swap(current->id, next->id);
                swap(current->name, next->name);
                swap(current->gender, next->gender);
                swap(current->country, next->country);

                swapped = true;
            }

            current = current->next;
        }
    } while (swapped);

    cout << "\nAthletics list sorted successfully!";

    char viewChoice;
    cout << "\nDo you want to view the sorted list? (Y/N): ";
    cin >> viewChoice;

    if (toupper(viewChoice) == 'Y') {
        int displayChoice;
        cout << "\nHow would you like to view the sorted list?";
        cout << "\n1. Show only ID";
        cout << "\n2. Show only Name";
        cout << "\n3. Show only Country";
        cout << "\n4. Show Full Information ";
        cout << "\n5. Go Back";
        cout << "\nEnter your choice: ";
        cin >> displayChoice;

        if (displayChoice == 5) {
            cout << "\nReturning to the main menu...\n";
            return;
        }

        Athletics* temp = head;
        cout << "\n\n\tSorted Athletics List:\n";

        while (temp != nullptr) {
            if (displayChoice == 1) {
                cout << "\nID: " << temp->id;
            } else if (displayChoice == 2) {
                cout << "\nName: " << temp->name;
            } else if (displayChoice == 3) {
                cout << "\nCountry: " << temp->country;
            } else if (displayChoice == 4) {
                cout << "\nIndex Number: " << temp->IndexNumber;
                cout << "\nID: " << temp->id;
                cout << "\nName: " << temp->name;
                cout << "\nGender: " << temp->gender;
                cout << "\nCountry: " << temp->country;
                cout << "\n---------------------";
            } else {
                cout << "\nInvalid choice! Returning to the main menu.";
                return;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Athletics AthleticsObj;
    int choice;
    int athNumber = 1;

    do {
        cout << "\n    -------------------------------------------------------";
        cout << "\n    |||||  Paris Olympic Information System System  |||||| ";
        cout << "\n    -------------------------------------------------------";
        cout << "\n    |             1. Add Athletics                        |";
        cout << "\n    |             2. Update Athletics                     |";
        cout << "\n    |             3. Delete Athletics                     |";
        cout << "\n    |             4. Search Athletics                     |";
        cout << "\n    |             5. Sort Athletics                       |";
        cout << "\n    |             6. Exit                                 |";
        cout << "\n    -------------------------------------------------------";
        cout << "\n                  Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            AthleticsObj.addAthletics(athNumber++);
            break;
        case 2:
            AthleticsObj.updateAthleticsInfo();
            break;
        case 3:
            AthleticsObj.deleteAthleticsInfo();
            break;
        case 4:
            AthleticsObj.searchAthleticsInfo();
            break;
        case 5:
            AthleticsObj.sortAthleticsInfo(); 
            break;
        case 6:
            cout << "\nExiting... Thank you for using the system!";
            break;
        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (choice != 6); 
    return 0;
}
