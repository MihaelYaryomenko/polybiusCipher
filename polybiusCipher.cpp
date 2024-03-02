#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <conio.h>

#define KEY_1 49
#define KEY_2 50

void encryptAndSave();
void readAndDecrypt();
void userPlay();

namespace polybiusKeysValuePair
{
    std::map<char, int> map = {
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
}

int main()
{
    userPlay();
}

void userPlay()
{
    using namespace std;

    std::cout << "What you wanna do, enter a number: " << '\n';
    std::cout << "1. Encrypt" << '\n';
    std::cout << "2. Decrypt" << '\n';

    switch (getch())
    {
    case KEY_1:
        encryptAndSave();
    case KEY_2:
        readAndDecrypt();
    default:
        std::cout << "You made a mistake, please behave in a pattern expected by creator" << '\n';
        userPlay();
    }
}

void encryptAndSave()
{
    using namespace polybiusKeysValuePair;

    std::string strToEncrypt;
    std::string encryptedWord;
    std::cout << "Enter word you want to encrypt in Polybius Cipher: ";
    std::cin >> strToEncrypt;

    for (char &character : strToEncrypt)
    {
        character = ::tolower(character);
    }
    for (int i = 0; i < strToEncrypt.size(); i++)
    {
        encryptedWord += std::to_string(map[strToEncrypt[i]]);
    }
    std::ofstream file("save.txt");
    file << encryptedWord;
    file.close();
}

void readAndDecrypt()
{
    std::string strToDecrypt;
    std::ifstream file("save.txt");
    file >> strToDecrypt;
    file.close();
}