#include "sort.hpp"

std::deque<std::string>  lengthSort(std::forward_list<std::string> &wordFlist)
{
    std::deque<std::string> wordDeque{};
    wordFlist.sort();
    auto lambda = [](const std::string &a, const std::string &b){return (b.size() > a.size())?true:false;};
    //wordFlist.sort(cmp);
    // wordFlist.sort(
    // [](const std::string &a, const std::string &b){return (b.size() > a.size())?true:false;});
    wordFlist.sort(lambda);
    wordDeque.insert(wordDeque.begin(),wordFlist.begin(),wordFlist.end());
    return wordDeque;
}

bool cmp(const std::string &a, const std::string &b)
{
    if(b.size() > a.size())
        return true;
    else 
        return false;
}
