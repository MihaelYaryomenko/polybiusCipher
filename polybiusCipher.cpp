#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <conio.h>

#define KEY_1 49
#define KEY_2 50

using namespace std;

void encryptAndSave();
void readAndDecrypt();
void userPlay();

namespace polybiusKeysValuePair
{
    map<char, int> letterPair = {
        {'a', 11},
        {'b', 12},
        {'c', 13},
        {'d', 14},
        {'e', 15},
        {'f', 21},
        {'g', 22},
        {'h', 23},
        {'j', 24},
        {'i', 24},
        {'k', 25},
        {'l', 31},
        {'m', 32},
        {'n', 33},
        {'o', 34},
        {'p', 35},
        {'q', 41},
        {'r', 42},
        {'s', 43},
        {'t', 44},
        {'u', 45},
        {'v', 51},
        {'w', 52},
        {'x', 53},
        {'y', 54},
        {'z', 55},
    };

    map<int, char> intPair = {
        {11, 'a'},
        {12, 'b'},
        {13, 'c'},
        {14, 'd'},
        {15, 'e'},
        {21, 'f'},
        {22, 'g'},
        {23, 'h'},
        {24, 'i'},
        {25, 'k'},
        {31, 'l'},
        {32, 'm'},
        {33, 'n'},
        {34, 'o'},
        {35, 'p'},
        {41, 'q'},
        {42, 'r'},
        {43, 's'},
        {44, 't'},
        {45, 'u'},
        {51, 'v'},
        {52, 'w'},
        {53, 'x'},
        {54, 'y'},
        {55, 'z'},
    };
}

int main()
{
    userPlay();
}

void userPlay()
{
    cout << "What you wanna do, enter a number: " << '\n';
    cout << "1. Encrypt" << '\n';
    cout << "2. Decrypt" << '\n';

    switch (getch())
    {
    case KEY_1:
        encryptAndSave();
    case KEY_2:
        readAndDecrypt();
    default:
        cout << "You made a mistake, please behave in a pattern expected by creator" << '\n';
        userPlay();
    }
}

void encryptAndSave()
{
    using namespace polybiusKeysValuePair;

    string strToEncrypt;
    string encryptedWord;
    cout << "Enter word you want to encrypt in Polybius Cipher: ";
    cin >> strToEncrypt;

    for (char &character : strToEncrypt)
    {
        character = ::tolower(character);
    }
    for (int i = 0; i < strToEncrypt.size(); i++)
    {
        encryptedWord += to_string(letterPair[strToEncrypt[i]]);
    }
    ofstream file("save.txt");
    file << encryptedWord;
    file.close();
}

void readAndDecrypt()
{
    using namespace polybiusKeysValuePair;

    string strToDecrypt;
    string decryptedWord;
    ifstream file("save.txt");
    file >> strToDecrypt;
    // cout << strToDecrypt;
    file.close();
    for (int i = 0; i < strToDecrypt.size(); i += 2)
    {
        decryptedWord += intPair[strToDecrypt[i]];
    }
    cout << decryptedWord;
}