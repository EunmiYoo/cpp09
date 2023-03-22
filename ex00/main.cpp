#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include <string>
#include <sstream>

int main(int ac, char **av)
{
    if(ac < 2 || ac > 2)
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    else
    {
        std::ifstream file(av[1]);
        if (!file.is_open())
        {
            std::cout << "Error: could not open file." << std::endl;
        }
        if (file.is_open())
        { 
            std::string line;
            while(getline(file, line))
            {
                if (line != "date | value")
                {              
                    try
                    {
                        BitcoinExchange output(line);
                    }
                    catch(std::exception & e)
                    {
                        std::cout << "Error ! " << e.what() << std::endl;
                        return (0);
                    }              
                }           
            }
            file.close();
        }
    }
    return (0);

}

