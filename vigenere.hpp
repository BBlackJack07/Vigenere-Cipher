#include <string>
#include <algorithm>

namespace Vigenere
{
    const std::string AVALAIBLE_CHARS { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 " };

    int index(char c);

    std::string encrypt(std::string msg, std::string key);
    std::string decrypt(std::string vigenere_msg, std::string key);

    class VigenereEncrypt
    {
        public:
            VigenereEncrypt(std::string key);
            char operator()(const char &char_to_encrypt);
    
        private:
            unsigned int m_count;
            std::string m_key;

    };

    class VigenereDecrypt
    {
        public:
            VigenereDecrypt(std::string key);
            char operator()(const char &char_to_decrypt);
    
        private:
            unsigned int m_count;
            std::string m_key;

    };

}
