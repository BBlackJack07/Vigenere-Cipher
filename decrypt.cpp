#include <iostream>
#include <algorithm>
#include <thread>
#include "vigenere_decrypt.hpp"

int main()
{
    
	using namespace std::chrono_literals;
    std::string str {};
    std::string key {};
    std::cout << "Entrez la clé : ";
    getline(std::cin, key);
    std::this_thread::sleep_for(1000ms);
    std::cout << "Entrez la phrase à déchiffrer : ";
    getline(std::cin, str);

    VigenereDecrypt decrypt(key);

    std::transform(str.begin(), str.end(), str.begin(), decrypt);

    std::cout << std::endl << str << std::endl;
    
    return 0;

}

