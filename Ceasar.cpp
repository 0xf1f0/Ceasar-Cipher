/*  Objective:  A program that implements the Ceasar's cipher encryption algorithm */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

/* Fucntion prototype */
void mainMenu(void);
string plainText(const string);

using namespace std;

int main()
{
    string plainText;          //The plaintext to be encrypted
    string leftSeg;            //The left segment of the plaintext
    string rightSeg;           //The right segment of the plaintext
    int option = 0;            //Option for the main menu
    int i = 0;

    mainMenu();
    //std::cin.ignore();
    while(1)
    {
        cout << "Enter your option: ";
        cin >> option;

        switch(option)
        {
            case 1:
                cout << "Option is: " << option <<"\n";
                break;
            case 2:
                cout << "Option is: " << option <<"\n";
                break;
            case 3:
                cout << "Option is: " << option <<"\n";
                cout << "Good bye!";
                exit(0);
            default:
                cout << "Invalid option '" << option << "' check main menu and try again\n";
        }
    }
}


/*Function to display the main menu to users */
void mainMenu()
{
    cout <<"\n";
    cout <<"\t*****************************************************\n";
    cout <<"\t*         CEASAR'S CIPHER IMPLEMENTATION            *\n";
    cout <<"\t*                                                   *\n";
    cout <<"\t* Available options:                                *\n";
    cout <<"\t*                                                   *\n";
    cout <<"\t* (1)Encrypt a plaintext                            *\n";
    cout <<"\t* (2)Decrypt a ciphertext                           *\n";
    cout <<"\t* (3)Exit the program                               *\n";
    cout <<"\t*****************************************************\n";
}

string plainText(const string input)
{
    cout << "\nEnter a plaintext: ";
    getline(cin, input);
}

string leftSegment(const string input)
{
    int i = 0;
    int arr = 0;
    arr = input.length();

    for(i; i < arr; i++)
    {


    }

}

string rightSegment(const string input)
{

}
