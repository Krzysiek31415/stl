#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& data)
{
    
    data.sort();
    data.sort([](const auto &a, const auto &b){ return (b.size() > a.size()) ? true : false; });

    return std::deque<std::string>{data.begin(), data.end()};
}

