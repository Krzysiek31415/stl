#include "vowel.hpp"
#include <string>
#include <vector>
#include <algorithm>

bool isVowel(char ch)
{
    // Make the list of vowels
    std::string str = "aeiouAEIOUYy";
    return (str.find(ch) != std::string::npos);
}

void removeVowels(std::vector<std::string>& data)
{
    for(auto& line: data)
    {
        line.erase(std::remove_if(line.begin(), line.end(), isVowel), line.end());
    }
}