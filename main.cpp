#include <iostream>
#include <vector>
#include "FileProcessor.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc !=5)
    {
        cerr << "Usage: " << argv[0] << " <file> <-e|-d> <caesar_shift> <xor_key> \n";
        return 1;
    }

    string inputPath = argv[1];
    string operation = argv[2];
    int caesarShift = stoi(argv[3]);
    char xorKey = argv[4][0];

    bool isEncryption = (operation == "-e");

    if (!isEncryption && operation != "-d"){
        cerr << "Invalid operation. Use -e for encryption od -d for decryption.\n";
        return 1;        
    }

    string outputPath = (isEncryption ? "Encrypted_" : "Decrypted_") + inputPath;

    cout << "Opening files.\n";

    ProcessFile(inputPath, outputPath, caesarShift, xorKey, isEncryption);

    return 0;
    
}