/*  Objective:  A program that implements the Ceasar's cipher encryption/decryption algorithm */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#define LIST "abcdefghijklmnopqrstuvwxyz"  //The list of alphabetical letters

using namespace std;

/* Fucntion prototype */
void mainMenu(void);
string plainText();
string leftSegment(const string&);
string rightSegment(const string&);
string leftCipher(string&, const int);
string rightCipher(const string&, int);

int main()
{
    string plaintext;   //The plaintext to be encrypted
    string leftSeg;     //The left segment of the plaintext
    string rightSeg;    //The right segment of the plaintext
    string leftCi;
    int option = 0;     //Option for the main menu
    int key = 0;         //Number of shift positions
    mainMenu();

    cout << "Enter your option: ";
    cin >> option;
    cin.ignore();
    while(1)
    {
        if(option == 1)
        {
            plaintext = plainText();
            leftSeg = leftSegment(plaintext);
            rightSeg = rightSegment(plaintext);
            cout << "\nLeft Segment: " << leftSeg << "\n";
            cout << "Right Segment: " << rightSeg << "\n";

            leftCi = leftCipher(leftSeg, 4);

        }
        else if(option == 2)
        {
            break;
        }
        else if(option == 3)
        {
            cout << "Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid option, try again\n";
        }
        cout << "Enter your option: ";
        cin >> option;
        cin.ignore();
    }
    return 0;
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

string plainText()
{
    int i = 0;
    string text;
    cout << "\nEnter a plaintext: ";
    getline(cin, text);
    for(i; i < text.length(); i++)
    {
        if(text[0] == '\0')
        {
            cout << "\nEnter a plaintext: ";
            getline(cin, text);
        }
        else
            text[i] = tolower(text[i]);
    }
    return text;
}

string leftSegment(const string &input)
{
    int len = 0;
    string left;
    len = input.length();
    left = input.substr(0, len/2);
    return left;
}

string rightSegment(const string &input)
{
    int len = 0;
    string right;
    len = input.length();
    right = input.substr(len/2);
    return right;
}

string leftCipher(string &leftText, const int k1)
{
    string lText;
    string input;

    int i = 0;
    int k = 0;
    int len = 0;



    cout << "The key[k1]: " << k1 <<"\n";
    cout << "The left text: " << leftText <<"\n";

    len = leftText.length();

    for(i; i < len; i++)
    {
        for(k; k < k1; k++)
        {
            /*Restart the shifting from 'a' when at 'z'
              Else continue shifting
            */
            if(leftText[i] == 'z')
                leftText[i] = 'a';
            else
                leftText[i]++;
            cout << "The Left Cipher[" << i <<"]: " << leftText[i] << "\n";
        }
    }
    cout << "The Left Cipher: " << leftText << "\n";
    return leftText;
}

string rightCipher(const string &leftText, int k2)
{


}
