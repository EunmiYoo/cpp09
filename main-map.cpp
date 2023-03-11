#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"
#include <map>

int main(int ac, char **av)
{
    
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
      std::map<std::string,std::string> a;
      std::map<std::string,std::string>::iterator iter;
      std::string readFile;
      int line = 0;
      
      while(getline(file, readFile))
      { 
        int before = 0;
        int findBar = 0;
        findBar = readFile.find('|');
       // std::cout << findBar << std::endl;
        if(line != 0)
        {
          //std::cout << findBar << std::endl;
          try{
          std::string data = readFile.substr(before, findBar - before);

         // std::cout << data << std::endl;
          before = findBar + 1;
          std::string value = readFile.substr(findBar, before );
          a.insert(std::make_pair(data, value));
          }
          catch (const std::out_of_range& e)
          {
            std::cout << "pos exceeds string size\n";
          }
          }
          line ++;
      } 
        
  
      file.close();
      for(iter = a.begin(); iter != a.end(); iter++)
      {
        std::cout << iter->first << " " << iter->second << std::endl;
      }
   }
   }
}
