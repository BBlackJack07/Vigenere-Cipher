#include <cstdio>
#include <iostream>
#include <fstream>
#include "vigenere.hpp"

std::string read_file(std::string filename);
void showHelp(void);

int main(int argc, char* argv[])
{

    if (argc != 4)
    {
        showHelp();
        return -1;
    }
    
    int ret = -1;

    std::string mode = argv[1];

    if (mode == "--encrypt")
    {
        std::string msg = argv[2];
        std::string key = argv[3];
        std::cout << Vigenere::encrypt(msg, key) << std::endl;
        ret = 1;
    }
    
    else if (mode == "--decrypt")
    {
        std::string msg = argv[2];
        std::string key = argv[3];
        std::cout << Vigenere::decrypt(msg, key) << std::endl;
        ret = 1;
    }

    else if (mode == "--encrypt-file")
    {
        std::string msg {};
        std::string key = argv[3];
        std::string filename(argv[2]); 
        msg=read_file(filename);
        
        std::cout << Vigenere::encrypt(msg, key) << std::endl;
        ret = 1;
    }

    else if (mode == "--decrypt-file")
    {
        std::string msg {};
        std::string key = argv[3];
        std::string filename(argv[2]); 
        msg=read_file(filename);

        std::cout << Vigenere::decrypt(msg, key) << std::endl;
        ret = 1;
    }

    else
    {
        showHelp();
    }

    return ret;

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

void showHelp(void) {
    puts(" Usage: vigenere MODE MSG KEY");
    puts("        vigenere MODE PATH KEY");
    puts(" where MODE should be :");
    puts("\t--encrypt         to encrypt message MSG using key KEY");
    puts("\t--decrypt         to decrypt message MSG using key KEY");
    puts("\t--encrypt-file    to encrypt message from file PATH using key KEY");
    puts("\t--decrypt-file    to decrypt message from file PATH using key KEY");
}
