#ifndef TRANSPOSITION_CIPHER_H
#define TRANSPOSITION_CIPHER_H

#include <string>
#include <vector>
using namespace std;

string TranspositionCipher(const string& text, const vector<int>& key, bool encrypt);

#endif // TRANSPOSITION_CIPHER_H
