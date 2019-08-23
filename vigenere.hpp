#include <string>
#include <algorithm>

namespace Vigenere
{
    const std::string AVALAIBLE_CHARS { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 " };

    std::string encrypt(std::string msg, std::string key);
    std::string decrypt(std::string vigenere_msg, std::string key);

    class VigenereCipher
    {
        public:
            VigenereCipher(std::string key, std::string mode);
            char operator()(const char &char_to_encrypt);
            int index(char c);

        private:
            unsigned int m_count;
            std::string m_key;
            bool m_mode;
    };

}
