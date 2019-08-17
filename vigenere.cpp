#include "vigenere.hpp"

using namespace Vigenere;

VigenereEncrypt::VigenereEncrypt(std::string key)
{
    m_key = key;
    m_count = 0;
}


VigenereDecrypt::VigenereDecrypt(std::string key)
{
    m_key = key;
    m_count = 0;
}

int Vigenere::index(char c)
{
    for (unsigned short int i {0}; i < AVALAIBLE_CHARS.size(); i++)
        if (c == AVALAIBLE_CHARS[i]) { return i; }
    return -1;
}

char VigenereEncrypt::operator()(const char &char_to_encrypt)
{
    char c {char_to_encrypt};
    char r {};
    unsigned int shift {};
    if (isalnum(c) || c == ' ')
    {
        if (m_count < m_key.size())
            shift=index(m_key[m_count]);  
        else
            shift=index(m_key[m_count%m_key.size()]);

        if (shift+index(c) < AVALAIBLE_CHARS.size())
            r=AVALAIBLE_CHARS[shift+index(c)];
        else
            r=AVALAIBLE_CHARS[shift+index(c)-AVALAIBLE_CHARS.size()];
            
    }
    else
        r=c;
    m_count++;
    return r;
}

char VigenereDecrypt::operator()(const char &char_to_decrypt)
{
    char c {char_to_decrypt};
    char r {};
    int shift {};
    if (isalnum(c) || c == ' ')
    {
        if (m_count < m_key.size())
            shift=index(m_key[m_count]);  
        else
            shift=index(m_key[m_count%m_key.size()]);

        if (index(c)-shift >= 0 )
            r=AVALAIBLE_CHARS[index(c)-shift];
        else
            r=AVALAIBLE_CHARS[index(c)-shift+AVALAIBLE_CHARS.size()];
            
    }
    else
        r=c;
    m_count++;
    return r;
}


std::string Vigenere::encrypt(std::string msg, std::string key)
{
    VigenereEncrypt vencrypt(key);
    const int msgLen = msg.size();
    std::string vigenere_msg(msgLen, ' ');
    std::transform(msg.begin(), msg.end(), vigenere_msg.begin(), vencrypt);
    return vigenere_msg;
}


std::string Vigenere::decrypt(std::string vigenere_msg, std::string key)
{
    VigenereDecrypt vdecrypt(key);
    const int vmsgLen = vigenere_msg.size();
    std::string msg(vmsgLen, ' ');
    std::transform(vigenere_msg.begin(), vigenere_msg.end(), msg.begin(), vdecrypt);
    return msg;
}
