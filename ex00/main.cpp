#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"
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
      std::string readFile;
      while(getline(file, readFile))
      { 
        std::cout << readFile << "\n";
      }
      file.close();
   }
   }
}
