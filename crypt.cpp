#include <iostream>
#include <thread>
#include "vigenere.hpp"

int main(int argc, char* argv[])
{
    
    if (argc == 3)
    {
        std::string msg = argv[1];
        std::string key = argv[2];
        std::cout << Vigenere::encrypt(msg, key) << std::endl;
    }

    else
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
    }
    return 0;

}

