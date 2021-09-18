#include "compression.hpp"
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> & bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    

    for(size_t rowNumber = 0; rowNumber < height; rowNumber++)
    {
        for(size_t columnNumber = 0; columnNumber < width; columnNumber++)
        {
            uint8_t number = bitmap[rowNumber][columnNumber];
            uint8_t quantity{1};
            while(number == bitmap[rowNumber][columnNumber+1])
            {
                columnNumber++;
                quantity++;
                if(columnNumber == width -1 )
                {
                    break;
                }
            }
            auto p = std::make_pair(number,quantity);
            compressed.push_back(p);
        }
    }
    return compressed;


    

}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale2(std::array<std::array<uint8_t, width>, height> & bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    auto lama =  [counter{0U}, &compressed,  i{0U}] ( uint8_t & value) mutable 
    {
        i++;
        static uint8_t prevValue = value;
        if(value == prevValue){
            counter++;
        }else{
            compressed.push_back(std::make_pair(prevValue,counter));
            counter = 1U;
            prevValue = value;
        }
        if(i == width){
            compressed.push_back(std::make_pair(prevValue,counter));
        }
        
    };
    auto takeArray = [&lama](auto & array){std::for_each(array.begin(),array.end(),lama);};
    std::for_each(bitmap.begin(),bitmap.end(),takeArray);

    return compressed;
}


void printMap(std::array<std::array<uint8_t, width>, height> array)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            uint8_t sign = array.at(i).at(j); 
            if(!std::isprint(sign)  || std::isspace(sign))
                std::cout<<' ';
            else
                std::cout<<sign;
            
        }
        std::cout<<'\n';
    }
}

void printMap(std::vector<std::pair<uint8_t, uint8_t>> bitmap)
{
    int sign{}; // the current number of characters on the line
    for(int i = 0; i < bitmap.size(); ++i)
    {  
        auto pair = bitmap[i];
        for(int j = 0; j < pair.second; j++)
        {
            sign++;
            if(!std::isprint(pair.first)  || std::isspace(pair.first))
                std::cout<<(int)pair.first<<' ';
            else
                std::cout<<(int)pair.first;

            if(sign == width )
            {
                std::cout<<'\n';
                sign=0;
            }
            
        }
    }
    std::cout<<'\n';
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vector)
{
    std::array<std::array<uint8_t, width>, height> decompressed;
    uint8_t row{};
    uint8_t column{};
    for(int i = 0; i < vector.size(); ++i)
    {
        auto pair = vector[i];
        for(int j = 0; j < pair.second; j++)
        {
            decompressed[row][column] = pair.first;
            column++; 
            if(column == width )
            {
                column = 0;
                row++;
            }
        }
    }
    return decompressed;
} 

//***********************************************************************************************
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale2(std::array<std::array<uint8_t, width>, height> bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    
    int row{};
    for(size_t columnNumber = 0; columnNumber < width; columnNumber++) // column
    {
        uint8_t number = bitmap[row][columnNumber];
        uint8_t quantity{1};
        while(number == bitmap[row][columnNumber+1])
        {
            columnNumber++;
            quantity++;
            if(columnNumber == width)
            {
                row++;
                columnNumber=0;
            }
        }
        auto p = std::make_pair(number,quantity);
        compressed.push_back(p);
    }
    
    //for(int i =0; i<10; i++)
     //   std::cout<<(int)compressed[i].first<<" "<<(int)compressed[i].second<<'\n';
    return compressed;
}

void printMap2(std::vector<std::pair<uint8_t, uint8_t>> bitmap)
{
    int sign{}; // the current number of characters on the line
    for(int i = 0; i < bitmap.size(); ++i)
    {  
        auto pair = bitmap[i];
        for(int j = 0; j < pair.second; j++)
        {
            sign++;
            if(!std::isprint(pair.first)  || std::isspace(pair.first))
                std::cout<<' ';
            else
                std::cout<<pair.first;

            if(sign == width)
            {
                std::cout<<'\n';
                sign=0;
            }
            
        }
    }
}

void printMap3(std::array<std::array<uint8_t, width>, height> array)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            // char sign = array.at(i).at(j); 
            // if(!std::isprint(sign)  || std::isspace(sign))
            //     std::cout<<' ';
            // else
            //     std::cout<<sign;
            uint8_t sign = array.at(i).at(j); 
            std::cout<<static_cast<int>(sign)<<' ';
            
        }
        std::cout<<'\n';
    }
}

void printPair(std::vector<std::pair<uint8_t, uint8_t>> &bitmap)
{
    for(int i = 0; i<bitmap.size(); i++)
       std::cout<< "( "<<(int)bitmap[i].first<<" , "<<(int)bitmap[i].second<<" )"<<std::endl;
    std::cout<<std::endl;
}

void printPair(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
               std::vector<std::pair<uint8_t, uint8_t>> &bitmap2)
{
    std::cout<<std::boolalpha<<(bitmap1.size() == bitmap2.size() )<<std::endl;
    bool theSame{true};
    for(int i = 0; i<bitmap1.size(); i++)
    {
        std::cout<< "( "<<(int)bitmap1[i].first<<" , "<<(int)bitmap1[i].second<<" )"<<"\t\t";
        std::cout<< "( "<<(int)bitmap2[i].first<<" , "<<(int)bitmap2[i].second<<" )"<<std::endl;
    }
       
    std::cout<<std::endl;
}

bool equal(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
               std::vector<std::pair<uint8_t, uint8_t>> &bitmap2)
{
    std::cout<<"size(): "<<std::boolalpha<<(bitmap1.size() == bitmap2.size() )<<std::endl;
    bool theSame{true};
    for(int i = 0; i<bitmap1.size(); i++)
    {
        if(!(bitmap1[i].first==bitmap2[i].first && bitmap1[i].second == bitmap2[i].second))
        {
            std::cout<<"diffrent cointeners ";
            return false;
        }
    }
       
    std::cout<<std::endl;
    return true;
}

void whatDiffrent(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
               std::vector<std::pair<uint8_t, uint8_t>> &bitmap2)
{
    
    for(int i = 0; i<bitmap1.size(); i++)
    {
        if(!(bitmap1[i].first==bitmap2[i].first && bitmap1[i].second == bitmap2[i].second))
        {
            std::cout<< "( "<<(int)bitmap1[i].first<<" , "<<(int)bitmap1[i].second<<" )"<<"\t\t";
            std::cout<< "( "<<(int)bitmap2[i].first<<" , "<<(int)bitmap2[i].second<<" )"<<std::endl;
        }
    }
       
    std::cout<<std::endl;
}