#include "TranspositionCipher.h"
using namespace std;

string TranspositionCipher(const string& text, const vector<int>& key, bool encrypt) {
    string result = text;
    int textLen = text.length();
    int keyLen = key.size();
    int rows = (textLen + keyLen - 1) / keyLen; // Calculate number of rows needed

    vector<vector<char>> grid(rows, vector<char>(keyLen, ' '));

    // Fill the grid with the characters from the text
    for (int i = 0; i < textLen; ++i) {
        grid[i / keyLen][i % keyLen] = text[i];
    }

    // Transposition based on the key
    if (encrypt) {
        int k = 0;
        for (int col : key) {
            for (int row = 0; row < rows; ++row) {
                if (grid[row][col] != ' ') {
                    result[k++] = grid[row][col];
                }
            }
        }
    } else {
        string encrypted = result;
        int k = 0;
        for (int col : key) {
            for (int row = 0; row < rows; ++row) {
                if (k < textLen) {
                    grid[row][col] = result[k++];
                }
            }
        }
        k = 0;
        for (int i = 0; i < textLen; ++i) {
            result[i] = grid[i / keyLen][i % keyLen];
        }
    }

    return result;
}
