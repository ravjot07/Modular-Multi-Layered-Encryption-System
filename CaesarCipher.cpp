#include "CaesarCipher.h"
using namespace std;

string CaesarCipher(string& text, int shift , bool encrypt){
    string result = text;
    for (char& c : result){
        if (isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            if (encrypt){
                c = (c - base + shift) % 26 + base;
            } else {
                c = (c - base - shift + 26) % 26 + base;
            }
        }
    }
    return result;
}