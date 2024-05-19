#include <iostream>
#include <fstream>
#include "CaesarCipher.h"
#include "XORCipher.h"
#include "FileProcessor.h"

using namespace std;

void ProcessFile(const string& inputPath, const string& outputPath, int caesarShift, char xorKey, bool isEncryption){
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    if (!inputFile.is_open()) {
        cerr << "Error: File " << inputPath << " not found.\n";
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Error: File " << outputPath << " could not be opened for writing.\n";
        inputFile.close();  // Make sure to close the input file if output file opening fails
        return;
    }

    cout << (isEncryption ? "Encrypting" : "Decrypting") << " file: " << inputPath << "\n";

    string message;
    getline(inputFile, message);

    //Apply Caesar Cipher
    string caesarProcessed = CaesarCipher(message, caesarShift, isEncryption);
    // Apply XOR Cipher
    string xorProcessed = XORCipher(caesarProcessed, xorKey);

    outputFile << xorProcessed;

    inputFile.close();
    outputFile.close();

    cout << "Process finished. Output file is " << outputPath << ".\n";
}