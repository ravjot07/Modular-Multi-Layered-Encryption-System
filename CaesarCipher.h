#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>
#include <cctype> 
using namespace std;

std::string CaesarCipher(string& text, int shift, bool encrypt);

#endif // CAESAR_CIPHER_H
