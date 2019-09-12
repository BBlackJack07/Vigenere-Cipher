# Vigenere Cipher
Algorithm using Vigenère Cipher polyalphabetic substitution method to crypt/decrypt messages.

I added lower characters, spaces and numeric characters to cryptable characters for more security, but the principle is always the same.

I writed a functor called VigenereCipher in the file 'vigenere.hpp' you can use it with the `std::transform` algorithm to crypt each character of a collection of `char`. There are two functions in the same file, `Vigenere::encrypt` and `Vigenere::decrypt` which will do it for you whith `std::string`.
