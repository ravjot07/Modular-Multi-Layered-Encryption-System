#include <iostream>
#include <vector>
#include "FileProcessor.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc !=6)
    {
        cerr << "Usage: " << argv[0] << " <file> <-e|-d> <caesar_shift> <xor_key> <vigenere_key> \n";
        return 1;
    }

    string inputPath = argv[1];
    string operation = argv[2];
    int caesarShift = stoi(argv[3]);
    char xorKey = argv[4][0];
    string vigenerekey = argv[5];

    bool isEncryption = (operation == "-e");

    if (!isEncryption && operation != "-d"){
        cerr << "Invalid operation. Use -e for encryption od -d for decryption.\n";
        return 1;        
    }

    string outputPath = (isEncryption ? "Encrypted_" : "Decrypted_") + inputPath;

    cout << "Opening files.\n";

    ProcessFile(inputPath, outputPath, caesarShift, xorKey, vigenerekey, isEncryption);

    return 0;
    
}