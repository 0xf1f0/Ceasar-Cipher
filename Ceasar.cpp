/*  Objective:  A program that implements the Ceasar's cipher encryption/decryption algorithm */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

/* Fucntion prototype */
void mainMenu(void);
string plainText();
string leftSegment(const string&);
string rightSegment(const string&);
string leftCipher(string&, const int);
string rightCipher(string&, const int);
string interleaved(string& , string&);


int main()
{
    string plaintext;   //The plaintext to be encrypted
    string leftSeg;     //The left segment of the plaintext
    string rightSeg;    //The right segment of the plaintext
    string leftCi;
    string rightCi;
    int option = 0;     //Option for the main menu
    int key = 0;        //Number of shift positions
    mainMenu();

    cout << "\nEnter your option: ";
    cin >> option;
    cin.ignore();
    while(1)
    {
        //Encrypt a plaintext
        if(option == 1)
        {
            plaintext = plainText();
            leftSeg = leftSegment(plaintext);
            rightSeg = rightSegment(plaintext);
            cout << "\nLeft Segment: " << leftSeg << "\n";
            cout << "Right Segment: " << rightSeg << "\n";

            leftCi = leftCipher(leftSeg, 4);
            rightCi = rightCipher(rightSeg, 4);

            /* Interleave the each cipher text from leftCi and rightCi*/
            string interleave;
            string temp1;
            string temp2;

                for(int i = 0; i < leftCi.length(); i++)
                {
                    for(int k = 0; k < rightCi.length(); k++)
                    {

                    }
                    cout << "\nThe temp Cipher[" << j <<"]: " << interleave[j];
                }
        }

        //Decrypt a cipher text
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
        cout << "\nEnter your option: ";
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
    string text;
    cout << "\nEnter a plaintext: ";
    getline(cin, text);

    for(int i = 0; i < text.length(); i++)
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
    int len = 0;

    cout << "The key[k1]: " << k1 <<"\n";
    cout << "The left text: " << leftText <<"\n";

    len = leftText.length();

    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < k1; k++)
        {
            /*Restart the shifting from 'a' when at 'z'
              Else continue shifting
            */
            if(leftText[i] == 'z')
                leftText[i] = 'a';
            else
                leftText[i]++ ;
            cout << "The Left Cipher[" << i <<"]: " << leftText[i] << "\n";
        }
    }
    cout << "The Left Cipher: " << leftText << "\n";
    return leftText;
}

string rightCipher(string &rightText, const int k2)
{
    int len = 0;

    cout << "The key[k2]: " << k2 <<"\n";
    cout << "The left text: " << rightText <<"\n";

    len = rightText.length();

    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < k2; k++)
        {
            /*Restart the shifting from 'a' when at 'z'
              Else continue shifting
            */
            if(rightText[i] == 'z')
                rightText[i] = 'a';
            else
                rightText[i]++ ;
            cout << "The Left Cipher[" << i <<"]: " << rightText[i] << "\n";
        }
    }
    cout << "The Left Cipher: " << rightText << "\n";
    return rightText;
}
