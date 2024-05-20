#include <iostream>
#include <fstream>
#include <sstream>  // Include this for stringstream
#include "CaesarCipher.h"
#include "XORCipher.h"
#include "FileProcessor.h"
#include "VigenereCipher.h"
#include "TranspositionCipher.h"

using namespace std;

void ProcessFile(const string &inputPath, const string &outputPath, int caesarShift, char xorKey, const string& vigenereKey, const vector<int>& transpositionKey, bool isEncryption)
{
    ifstream inputFile(inputPath, ios::binary);
    ofstream outputFile(outputPath, ios::binary);

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string message = buffer.str();

    if (!inputFile.is_open())
    {
        cerr << "Error: File " << inputPath << " not found.\n";
        return;
    }
    if (!outputFile.is_open())
    {
        cerr << "Error: File " << outputPath << " could not be opened for writing.\n";
        inputFile.close(); // Make sure to close the input file if output file opening fails
        return;
    }

    string processed = message;

    if (isEncryption)
    {
        processed = CaesarCipher(processed, caesarShift, true);
        processed = XORCipher(processed, xorKey);
        processed = VigenereCipher(processed, vigenereKey, true);
        processed = TranspositionCipher(processed, transpositionKey, true);
    }
    else
    {
        processed = TranspositionCipher(processed, transpositionKey, false);
        processed = VigenereCipher(processed, vigenereKey, false);
        processed = XORCipher(processed, xorKey);
        processed = CaesarCipher(processed, caesarShift, false);
    }

    cout << (isEncryption ? "Encrypting" : "Decrypting") << " file: " << inputPath << "\n";

    
    outputFile << processed;

    inputFile.close();
    outputFile.close();

    cout << "Process finished. Output file is " << outputPath << ".\n";
}