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

/* void parseIndex(const std::string & fileName)
{
  
   BitcoinExchange output(std::string);
    
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
                output(line);
                    
                before = 0;
                findBar = line.find('|');
                dateIndex = line.substr(before, findBar - before);
                before = findBar + 1;
                valueIndex = ToInt(line.substr(findBar + 1, before ));
                std::cout << dateIndex << std::endl;
                std::cout << valueIndex << std::endl;                 
   //         }
     //       i++;
           
       // }
   // }
   
//} */

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

