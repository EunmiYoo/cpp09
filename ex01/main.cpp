#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
   
    if(ac < 2 || ac > 2)
    {
        std::cout << "Error, One argument" << std::endl;
    }
    else{
        try
        {
        RPN a(av[1]);
        }
        catch(std::invalid_argument& e){
             std::cout << "Error ! " << e.what() << std::endl;

        }
    }
    return (0);
}