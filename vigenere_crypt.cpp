#include "vigenere_crypt.hpp"

VigenereCrypt::VigenereCrypt(std::string key)
{
    vigenere_table['A'] = 0;
    vigenere_table['B'] = 1;
    vigenere_table['C'] = 2;
    vigenere_table['D'] = 3;
    vigenere_table['E'] = 4;
    vigenere_table['F'] = 5;
    vigenere_table['G'] = 6;
    vigenere_table['H'] = 7;
    vigenere_table['I'] = 8;
    vigenere_table['J'] = 9;
    vigenere_table['K'] = 10;
    vigenere_table['L'] = 11;
    vigenere_table['M'] = 12;
    vigenere_table['N'] = 13;
    vigenere_table['O'] = 14;
    vigenere_table['P'] = 15;
    vigenere_table['Q'] = 16;
    vigenere_table['R'] = 17;
    vigenere_table['S'] = 18;
    vigenere_table['T'] = 19;
    vigenere_table['U'] = 20;
    vigenere_table['V'] = 21;
    vigenere_table['W'] = 22;
    vigenere_table['X'] = 23;
    vigenere_table['Y'] = 24;
    vigenere_table['Z'] = 25;

    m_key = key;
    m_count = 0;
    
}

char VigenereCrypt::operator()(const char &c)
{
    char r {};
    unsigned int shift {};
    std::string alphabet { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    if (isalpha(c))
    {
        if (m_count < m_key.size())
            shift=vigenere_table[toupper(m_key[m_count])];  
        else
            shift=vigenere_table[toupper(m_key[m_count%m_key.size()])];

        if (shift+vigenere_table[toupper(c)] <= 25)
            r=alphabet[shift+vigenere_table[toupper(c)]];
        else
            r=alphabet[shift+vigenere_table[toupper(c)]-26];
            
    }
    else
        r=c;
    m_count++;
    return r;
}

