#include <map>
#include <string>

class VigenereCrypt
{
    public:
        VigenereCrypt(std::string key);
        char operator()(const char &c);

    private:
        unsigned int m_count;
        std::string m_key;
        std::map<char,unsigned short int> vigenere_table;
};

