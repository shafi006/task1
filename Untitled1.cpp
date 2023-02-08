//Write a program to encrypt and decrypt message using The One Time Pad method
#include <iostream>
#include <string>

std::string encrypt(const std::string &plaintext, const std::string &key) {
  std::string ciphertext;
  for (int i = 0; i < plaintext.length(); i++) {
    int char_plain = plaintext[i];
    int char_key = key[i % key.length()];
    int char_cipher = (char_plain + char_key) % 256;
    ciphertext += (char)char_cipher;
  }
  return ciphertext;
}

std::string decrypt(const std::string &ciphertext, const std::string &key) {
  std::string plaintext;
  for (int i = 0; i < ciphertext.length(); i++) {
    int char_cipher = ciphertext[i];
    int char_key = key[i % key.length()];
    int char_plain = (char_cipher - char_key + 256) % 256;
    plaintext += (char)char_plain;
  }
  return plaintext;
}

int main() {
  std::string plaintext, key;
  std::cout << "Enter plaintext: ";
  std::getline(std::cin, plaintext);
  std::cout << "Enter key: ";
  std::getline(std::cin, key);

  std::string ciphertext = encrypt(plaintext, key);
  std::cout << "Ciphertext: " << ciphertext << std::endl;

  std::string decrypted = decrypt(ciphertext, key);
  std::cout << "Decrypted: " << decrypted << std::endl;

  return 0;
}

