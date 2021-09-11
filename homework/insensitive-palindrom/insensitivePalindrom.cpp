#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>

std::string& sentenceToLower(std::string& str)
{
    for(auto & s: str)
    {
        s = std::tolower(s);
    }
    return str;
}

std::string& onlyAlphanumeric(std::string& str)
{
    std::string alphanum;
    std::copy_if(str.begin(), str.end(), alphanum.begin(),
                [](auto & s){ return std::isalnum(s); });
    str = alphanum;
    return str;
}


bool is_palindrome(std::string str)
{
    sentenceToLower(str);
    onlyAlphanumeric(str);
    return std::mismatch(str.begin(), str.end(), str.rbegin()).first == str.end();

}