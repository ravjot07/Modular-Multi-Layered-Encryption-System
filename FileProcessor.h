#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>
#include <vector>

void ProcessFile(const std::string& inputPath, const std::string& outputPath, int caesarShift, bool isEncryption);

#endif // FILE_PROCESSOR_H
