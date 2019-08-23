#include "vigenere.hpp"

using namespace Vigenere;

VigenereCipher::VigenereCipher(std::string key, std::string mode)
{
    m_key = key;
    m_count = 0;

    if(mode == "encrypt") 
        m_mode = true;
    else if (mode == "decrypt") 
        m_mode = false;
    else 
        throw "Mode '" + mode + "' doesn't exist!";
}

int VigenereCipher::index(char c)
{
    for (unsigned short int i {0}; i < AVALAIBLE_CHARS.size(); i++)
        if (c == AVALAIBLE_CHARS[i]) { return i; }
    return -1;
}

char VigenereCipher::operator()(const char &char_to_encrypt)
{
    char c {char_to_encrypt};
    char r {};
    int shift {};
    
    if (isalnum(c) || c == ' ')
    {
        shift=index(m_key[m_count%m_key.size()]);

        if(m_mode)
        {
            r=AVALAIBLE_CHARS[(index(c) + shift) % AVALAIBLE_CHARS.size()];
        }
        
        else
        {
            if (index(c)-shift >= 0 )
                r=AVALAIBLE_CHARS[index(c)-shift];
            else
                r=AVALAIBLE_CHARS[index(c)-shift+AVALAIBLE_CHARS.size()];
        }
    }

    else
        r=c;
    
    m_count++;
    return r;
}

std::string Vigenere::encrypt(std::string msg, std::string key)
{
    VigenereCipher vencrypt(key, "encrypt");
    const int msgLen = msg.size();
    std::string vigenere_msg(msgLen, ' ');
    std::transform(msg.begin(), msg.end(), vigenere_msg.begin(), vencrypt);
    return vigenere_msg;
}


std::string Vigenere::decrypt(std::string vigenere_msg, std::string key)
{
    VigenereCipher vdecrypt(key, "decrypt");
    const int vmsgLen = vigenere_msg.size();
    std::string msg(vmsgLen, ' ');
    std::transform(vigenere_msg.begin(), vigenere_msg.end(), msg.begin(), vdecrypt);
    return msg;
}
