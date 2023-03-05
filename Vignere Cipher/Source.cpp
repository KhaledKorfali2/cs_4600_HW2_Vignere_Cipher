#include <iostream>
#include <string>

using namespace std;

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyIndex = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
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

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keyIndex = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
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

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <key> <plaintext>" << endl;
        return 1;
    }
    string key = argv[1];
    string plaintext = argv[2];
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;
    return 0;
}
