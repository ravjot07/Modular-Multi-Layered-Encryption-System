
# Multi-Layered Encryption System

## Overview

This project implements a multi-layered encryption and decryption system using several encryption techniques:

-   Caesar Cipher
-   XOR Cipher
-   Vigenère Cipher
-   Transposition Cipher

The system is designed to demonstrate the core concepts of C++ while providing a robust method for encrypting and decrypting text files. The encryption system operates from the command line and supports both encryption and decryption modes.

## Features

-   **Caesar Cipher**: Simple character shift encryption.
-   **XOR Cipher**: Bitwise XOR encryption.
-   **Vigenère Cipher**: Polyalphabetic substitution cipher.
-   **Transposition Cipher**: Rearranges characters based on a key.

## File Structure
```.
├── src
│   ├── CaesarCipher.cpp
│   ├── CaesarCipher.h
│   ├── XORCipher.cpp
│   ├── XORCipher.h
│   ├── VigenereCipher.cpp
│   ├── VigenereCipher.h
│   ├── TranspositionCipher.cpp
│   ├── TranspositionCipher.h
│   ├── FileProcessor.cpp
│   ├── FileProcessor.h
│   └── main.cpp
└── README.md` 
```
## Dependencies

-   C++ compiler (GCC, Clang, etc.)
-   Standard C++ libraries

## Getting Started

### Compiling the Project

To compile the project, use the following command:

```
g++ -o EncryptionSystem smain.cpp CaesarCipher.cpp sXORCipher.cpp VigenereCipher.cpp TranspositionCipher.cpp FileProcessor.cpp
```

### Running the Program

To run the program, use the following syntax:

```
./EncryptionSystem <file> <-e|-d> <caesar_shift> <xor_key> <vigenere_key> <transposition_key>
```

-   `<file>`: Path to the input file.
-   `-e` or `-d`: Mode of operation (`-e` for encryption, `-d` for decryption).
-   `<caesar_shift>`: Shift value for the Caesar cipher.
-   `<xor_key>`: Key character for the XOR cipher.
-   `<vigenere_key>`: Keyword for the Vigenère cipher.
-   `<transposition_key>`: Key for the transposition cipher (a string of digits).

### Example

Encrypting a file:
```
./EncryptionSystem data.txt -e 3 k secret 3142
```
Decrypting a file:

```
./EncryptionSystem ENCRYPTED_data.txt -d 3 k secret 3142
```

## Detailed Explanation

### Caesar Cipher

The Caesar Cipher shifts each character by a specified number of positions in the alphabet.

### XOR Cipher

The XOR Cipher performs a bitwise XOR operation between each character and a specified key character.

### Vigenère Cipher

The Vigenère Cipher uses a keyword to shift characters. Each character in the plaintext is shifted by an amount determined by the corresponding character in the keyword.

### Transposition Cipher

The Transposition Cipher rearranges the characters in the text according to a key. The key specifies the order in which columns of a grid are read.

## Code Explanation

### CaesarCipher.cpp/h

Contains the implementation of the Caesar Cipher.

### XORCipher.cpp/h

Contains the implementation of the XOR Cipher.

### VigenereCipher.cpp/h

Contains the implementation of the Vigenère Cipher.

### TranspositionCipher.cpp/h

Contains the implementation of the Transposition Cipher.

### FileProcessor.cpp/h

Handles reading from the input file, applying the ciphers, and writing to the output file.

### main.cpp

The main entry point of the application, parses command-line arguments, and invokes the `ProcessFile` function with the appropriate parameters.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any bugs or feature requests.
