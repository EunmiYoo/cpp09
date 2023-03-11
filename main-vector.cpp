#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include <string>
#include <sstream>

int main(int ac, char **av)
{
    double number;
     if(ac < 2 || ac > 2)
    {
    std::cout << "Error: could not open file." << std::endl;
    }

    else{

    std::ifstream file(av[1]);
    if (!file.is_open()){
         std::cout << "Error: could not open file." << std::endl;
    }

    if (file.is_open())
    {
      std::vector<std::string> allData;
      std::vector<std::string> dateData;
      std::vector<double> valueData;
      std::vector<double>::iterator iter;
      std::vector<std::string>::iterator iter1;
      std::vector<std::string>::iterator iter2;

      std::string readFile; //Save a line who called with the getline function
      int line = 0;
      
      while(getline(file, readFile))
      { 
        int before = 0;
        int findBar = 0;
        findBar = readFile.find('|');
        if(line != 0)
        {
          try
          {
            allData.push_back(readFile);
            std::string date = readFile.substr(before, findBar - before);
            dateData.push_back(date); 
            before = findBar + 1;
            std::stringstream ss(readFile.substr(findBar + 1, before ));
            //string->int convert;
            ss >> number; //add ss-> number;
            valueData.push_back(number);
          }
          catch (const std::out_of_range& e)
          {
            std::cout << "pos exceeds string size\n";
          }
          line++;
        }
        else
            line ++;
      } 
      file.close();
      for(iter = valueData.begin(); iter != valueData.end(); iter++)
      {
        std::cout << *iter * 0.3 << std::endl;
        }

   }
   }
}
