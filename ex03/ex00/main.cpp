#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include <string>
#include <sstream>

/* double ToInt(std::string string)
{
     double number;
      std::stringstream ss(string);
      ss >> number;
     return (number); //string->int convert;
} */

void parseIndex(const std::string & fileName)
{
   std::string dateIndex;
   double valueIndex;
   int before;
   int findBar;
   double value;
    
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
                BitcoinExchange(line);      
               /*  before = 0;
                findBar = line.find('|');
                dateIndex = line.substr(before, findBar - before);
                before = findBar + 1;
                valueIndex = ToInt(line.substr(findBar + 1, before ));
                std::cout << dateIndex << std::endl;
                std::cout << valueIndex << std::endl; */
                  
            }
            i++;
           
        }
    }
   
}
int main(int ac, char **av)
{
    if(ac < 2 || ac > 2)
    {
        std::cout << "Error: could not open file." << std::endl;
    }

    else
    {
     parseIndex(av[1]);
    }

}

