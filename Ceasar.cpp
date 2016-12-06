/*  Objective:  A program that implements the Ceasar's cipher encryption/decryption algorithm */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

/* Fucntion prototype */
void mainMenu(void);
string userInput();
string leftSegment(const string&);
string rightSegment(const string&);
string leftCipher(string&, const int);
string rightCipher(string&, const int);
string interLeavedCipher(const string&, const string&);
string ceasarCipher(string&, const int);
string ceasarDecipher(string&, const int);
string leftDecipher(string&, const int);
string rightDecipher(string&, const int);
string interLeavedDecipher(string&, string&);


int main()
{
    string leftSeg;     //The left segment of the plaintext
    string rightSeg;    //The right segment of the plaintext
    string leftCi;
    string rightCi;
    unsigned int option = 0;     //Option for the main menu
    unsigned int k1 = 0;        //Number of shift positions, k1
    unsigned int k2 = 0;        //Number of shift positions, k2
    unsigned int k3 = 0;        //Number of shift positions, k3


    mainMenu();

    cout << "\nEnter your option: ";
    cin >> option;
    cin.ignore();
    if(option >= 1  && option <= 3)
    {
        if(option == 3)
        {
            cout << "Goodbye!\n";
            exit(1);
        }
        else
        {
            while(1)
            {
                //Encrypt a plaintext
                if(option == 1 && cin.good())
                {
                    string plaintext;   //The plaintext to be encrypted

                    cout << "Enter the plaintext to encrypt: ";
                    plaintext = userInput();
                    cout << "Key ranges from [1 - 26]";
                    cout << "\nEnter key[1]: ";
                    cin >> k1;
                    cout << "\nEnter key[2]: ";
                    cin >> k2;
                    cout << "\nEnter key[3]: ";
                    cin >> k3;
                    while(1)
                    {
                        if((k1 >= 1 && k1 <= 25) && (k2 >= 1 && k2 <= 25) && (k3 >= 1 && k3 <= 25))
                        {
                            leftSeg = leftSegment(plaintext);
                            rightSeg = rightSegment(plaintext);
                            cout << "\nLeft Segment: " << leftSeg << "\n";
                            cout << "Right Segment: " << rightSeg << "\n";

                            leftCi = leftCipher(leftSeg, k1);
                            rightCi = rightCipher(rightSeg, k2);

                            /* Interleave the each cipher text from leftCi and rightCi*/
                            string interCipher;
                            interCipher = interLeavedCipher(leftCi, rightCi);
                            /* Encrypt the interleaved cipher text using k3 */
                            string finalCipher;
                            finalCipher = ceasarCipher(interCipher, k3);
                            cout << "\nFinal Ciphertext : " << finalCipher << "\n";
                            break;  //Return to outer loop
                        }
                        else
                        {
                            cout << "\nInvalid input(s)\n";
                            break;
                        }
                    }
                }

                //Decrypt a cipher text
                else if(option == 2 && cin.good())
                {
                    string finalCiphertext;   //The plaintext to be encrypted

                    cout << "Enter the ciphertext to decrypt: ";
                    finalCiphertext = userInput();
                    cout << "Key ranges from [1 - 26]";
                    cout << "\nEnter key[1]: ";
                    cin >> k1;
                    cout << "\nEnter key[2]: ";
                    cin >> k2;
                    cout << "\nEnter key[3]: ";
                    cin >> k3;

                    while(1)
                    {
                        if((k1 >= 1 && k1 <= 25) && (k2 >= 1 && k2 <= 25) && (k3 >= 1 && k3 <= 25))
                        {
                            /* Decrypt the final ciphertext using key k3*/
                            string deinterText;
                            deinterText = ceasarDecipher(finalCiphertext, k3);
                            cout << "The Decrypted ciphertext: " << deinterText << "\n";

                            /*Split the decrypted cipher into left and right ciphers
                              Interleave the left and right ciphers and split again
                              Decrypt left and right ciphers with keys k1 and k2 respectively
                            */
                            leftCi= leftSegment(deinterText);
                            rightCi = rightSegment(deinterText);
                            cout << "\nLeft Cipher: " << leftCi << "\n";
                            cout << "Right Cipher: " << rightCi << "\n";

                            string interCipher;
                            interCipher = interLeavedDecipher(leftCi, rightCi);
                            //Reshuffle the ciphers to deinterleaved them
            			leftCi= leftSegment(interCipher);
                            	rightCi = rightSegment(interCipher);
				interCipher = interLeavedCipher(leftCi, rightCi);

                            string lDecipher;
                            string rDecipher;
                            lDecipher = leftSegment(interCipher);
                            rDecipher = rightSegment(interCipher);
                            leftSeg = leftDecipher(lDecipher, k1);
                            rightSeg = rightDecipher(rDecipher, k2);

                            cout << "\nOriginal Plaintext: " << leftSeg + rightSeg <<"\n";
                            break; //return option input /outter loop
                        }

                        else
                        {
                            cout << "\nInvalid input(s)\n";
                            break;
                        }
                    }
                }

                else
                {
                    cout << "Invalid option, exiting ...\n";
                    break;
                }
                cout << "\nEnter your option: ";
                cin >> option;
                cin.ignore();
                if(option >= 1  && option <= 3)
                {
                    if(option == 3)
                    {
                        cout << "Goodbye!\n";
                        exit(1);
                    }
                }
                else
                {
                    cout << "Invalid option, exiting ...\n";
                    break;
                }

            }
        }
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

/* Beginning of encryption block */

string userInput()
{
    string text;
    getline(cin, text);

    for(int i = 0; i < text.length(); i++)
    {
        //convert input to lower case
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
           //cout << "The Left Cipher[" << i <<"]: " << leftText[i] << "\n";
        }
    }
    cout << "The Left Cipher: " << leftText << "\n";
    return leftText;
}

string rightCipher(string &rightText, const int k2)
{
    int len = 0;

    cout << "The key[k2]: " << k2 <<"\n";
    cout << "The right text: " << rightText <<"\n";

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
            //cout << "The right Cipher[" << i <<"]: " << rightText[i] << "\n";
        }
    }
    cout << "The right Cipher: " << rightText << "\n";
    return rightText;
}


 string interLeavedCipher(const string &lCipher, const string &rCipher)
 {
     if (lCipher.length() == 0)
        return rCipher;
     if (rCipher.length() == 0)
        return  lCipher;
     return (lCipher.substr(0,1) + rCipher.substr(0,1) + interLeavedCipher(lCipher.substr(1), rCipher.substr(1)));
 }


 string ceasarCipher(string &interCipher, const int k3)
{
    int len = 0;

    cout << "The key[k3]: " << k3 <<"\n";
    cout << "The interCipher: " << interCipher <<"\n";

    len = interCipher.length();

    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < k3; k++)
        {
            /*Restart the shifting from 'a' when at 'z'
              Else continue shifting
            */
            if(interCipher[i] == 'z')
                interCipher[i] = 'a';
            else
                interCipher[i]++ ;
        }
    }
    return interCipher;
}

/* End of encryption block */

/* ***************************** */

/* Beginning of decryption block */

 string ceasarDecipher(string &finalCipher, const int k3)
 {

    int len = 0;
    cout << "The key[k3]: " << k3 <<"\n";
    cout << "The finalCipher: " << finalCipher <<"\n";

    len = finalCipher.length();

    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < k3; k++)
        {
            /*Restart the shifting from 'z' when at 'a'
              Else shift back k3 positions to get the interleaved ciphertext
            */
            if(finalCipher[i] == 'a')
                finalCipher[i] = 'z';
            else
                finalCipher[i]-- ;
        }
    }
    return finalCipher;
 }


string leftDecipher(string &leftCi, const int k1)
{
    int len = 0;

    cout << "The key[k1]: " << k1 <<"\n";
    cout << "The left cipher: " << leftCi <<"\n";

    len = leftCi.length();

    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < k1; k++)
        {
            /*Restart the shifting from 'z' when at 'a'
              Else continue shifting backwards k1 position
            */
            if(leftCi[i] == 'a')
                leftCi[i] = 'z';
            else
                leftCi[i]-- ;
           //cout << "The Left Cipher[" << i <<"]: " << leftText[i] << "\n";
        }
    }
    cout << "The Left Text: " << leftCi << "\n";
    return leftCi;
}

string rightDecipher(string &rightCi, const int k2)
{
    int len = 0;

    cout << "The key[k2]: " << k2 <<"\n";
    cout << "The right cipher: " << rightCi <<"\n";

    len = rightCi.length();

    for(int i = 0; i < len; i++)
    {
        for(int k = 0; k < k2; k++)
        {
            /*Restart the shifting from 'z' when at 'a'
              Else continue shifting backwards k2 position
            */
            if(rightCi[i] == 'a')
                rightCi[i] = 'z';
            else
                rightCi[i]-- ;
           //cout << "The Left Cipher[" << i <<"]: " << leftText[i] << "\n";
        }
    }
    cout << "The Right Text: " << rightCi << "\n";
    return rightCi;
}

string interLeavedDecipher(string& lCipher, string& rCipher)
{
    string temp;
    string temp1;
    string current;

    if (lCipher.length() == 0)
        return rCipher;
    if (rCipher.length() == 0)
        return  lCipher;
    if(rCipher.length() % 2 == 1)
    {
        temp = rCipher.back();
        rCipher.pop_back();
        rCipher = rCipher + temp;
        current = (lCipher.substr(0,1) + rCipher.substr(0,1) + interLeavedCipher(lCipher.substr(1), rCipher.substr(1)));

    }
    else
    {
        current = (lCipher.substr(0,1) + rCipher.substr(0,1) + interLeavedCipher(lCipher.substr(1), rCipher.substr(1)));
    }
    return current;
}

/* End of decryption block */
