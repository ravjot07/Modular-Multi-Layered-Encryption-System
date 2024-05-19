#include "VigenereCipher.h"
using namespace std;

string VigenereCipher(const string& text, const string& key, bool encrypt) {
    string result = text;
    int keyIndex = 0;
    int keyLength = key.length();
    for (char& c : result) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = key[keyIndex % keyLength] - base;
            if (encrypt) {
                c = (c - base + shift) % 26 + base;
            } else {
                c = (c - base - shift + 26) % 26 + base;
            }
            keyIndex++;
        }
    }
    return result;
}
