#include <iostream>
#include <algorithm>
#include <thread>
#include "vigenere_crypt.hpp"

int main()
{
    
	using namespace std::chrono_literals;
    std::string str {};
    std::string key {};
    std::cout << "Entrez la clé : ";
    getline(std::cin, key);
    std::this_thread::sleep_for(1000ms);
    std::cout << "Entrez la phrase à chiffrer : ";
    getline(std::cin, str);

    VigenereCrypt crypt(key);

    std::transform(str.begin(), str.end(), str.begin(), crypt);

    std::cout << std::endl << str << std::endl;
    
    return 0;

}

