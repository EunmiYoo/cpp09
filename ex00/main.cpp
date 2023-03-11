#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> SaveTextInVector(const std::string & fileName)
{
    std::vector<std::string> lines;
    
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    if (file.is_open())
    {
       
        std::string line;
        int i = 0;
        while(getline(file, line))
        {
            if(i != 0)
            {
                lines.push_back(line);
            }
            i++;
           
        }
    }
    return (lines);
   
}
int main(int ac, char **av)
{
    if(ac < 2 || ac > 2)
    {
        std::cout << "Error: could not open file." << std::endl;
    }

    else
    {
        BitcoinExchange(SaveTextInVector(av[1]));
    }

}

