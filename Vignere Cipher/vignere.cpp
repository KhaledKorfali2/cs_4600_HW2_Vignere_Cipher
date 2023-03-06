/* This program implements the Vigenere Cipher algorithm to 
     encrypt and decrypt a plaintext using a given key.*/ 
#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a plaintext string using a given key
string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyIndex = 0;
    // Loop through each character in the plaintext string
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        // If the character is a letter, encrypt it using the corresponding key character
        if (isalpha(c)) {
            int shift = toupper(key[keyIndex]) - 'A'; // convert key character to shift amount
            char shiftedChar = ((toupper(c) - 'A' + shift) % 26 + 'A'); // shift plaintext character
            ciphertext += shiftedChar;
            keyIndex = (keyIndex + 1) % key.length(); // move to next key character
        }
        else {
            ciphertext += c; // leave non-letter characters unchanged
        }
    }
    return ciphertext;
}

// Function to decrypt a ciphertext string using a given key
string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keyIndex = 0;
    // Loop through each character in the ciphertext string
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        // If the character is a letter, decrypt it using the corresponding key character
        if (isalpha(c)) {
            int shift = toupper(key[keyIndex]) - 'A'; // convert key character to shift amount
            char shiftedChar = ((toupper(c) - 'A' - shift + 26) % 26 + 'A'); // shift ciphertext character
            plaintext += shiftedChar;
            keyIndex = (keyIndex + 1) % key.length(); // move to next key character
        }
        else {
            plaintext += c; // leave non-letter characters unchanged
        }
    }
    return plaintext;
}

/* Main function that takes in the keyand plaintext as command line 
   argumentsand calls the encryptionand decryption functions*/
int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments have been provided
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <key> <plaintext>" << endl;
        return 1;
    }

    // Extract the key and plaintext from the command line arguments
    string key = argv[1];
    string plaintext = argv[2];

    // Encrypt the plaintext using the key and print the resulting ciphertext
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext using the key and print the resulting plaintext
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    // Succesfully Executed Program
    return 0;
}
