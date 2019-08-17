#include <iostream>
#include <thread>
#include "vigenere.hpp"

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

    std::cout << std::endl << Vigenere::encrypt(str, key) << std::endl;
    
    return 0;

}

