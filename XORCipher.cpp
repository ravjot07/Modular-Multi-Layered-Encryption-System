#include "XORCipher.h"

string XORCipher(const string& text, char key){
    string result = text;
    for (char& c: result){
        c ^= key;
    }
    return result;
}