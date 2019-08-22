#include <iostream>
#include <fstream>
#include "vigenere.hpp"

std::string read_file(std::string filename);

int main(int argc, char* argv[])
{
    
    if (argc == 3)
    {
        std::string msg = argv[1];
        std::string key = argv[2];
        std::cout << Vigenere::encrypt(msg, key) << std::endl;
    }

    else if (argc == 2)
    {
        std::string str {};
        std::string key {};
        std::cout << "Entrez la clé : ";
        getline(std::cin, key);
        std::string filename(argv[1]); 
        str=read_file(filename);

        std::cout << std::endl << Vigenere::encrypt(str, key) << std::endl;
    }
    return 0;

}

std::string read_file(std::string filename)
{
    std::ifstream f(filename);
    std::string line;
    std::string content;
    while( getline(f, line) )
        content += line + "\n";
    f.close();
    return content;
}

