#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>
#include <vector>
using namespace std;

void ProcessFile(const string& inputPath, const string& outputPath, int caesarShift, char xorKey, const string& vigenereKey, bool isEncryption);

#endif // FILE_PROCESSOR_H
