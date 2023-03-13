#include <iostream>
// #include <cstdlib>
#include <iomanip>
//#include "PmergeMe.hpp"
#include <deque>
#include <list>
#include <sstream>

int main(int ac, char **av)
{
    std::deque<int> d;
    std::deque<int>::iterator iter;
    std::list<int> l;
    std::list<int>::iterator it;
    std::stringstream ss;
    int num;

    
    if(ac < 2)
    {
        std::cout << "Error, One argument" << std::endl;
    }
    else
    {
        try{
            //std::cout << "argc == " << ac << '\n';
            for(int i = 1; i != ac; ++i)
            {
                ss << av[i];
                ss >> num;
                d.push_back(num);
                l.push_back(num);
              //  std::cout << "argc[" << i <<"] ================"  << num <<  std::endl; 
                ss.clear();
                if(num <= 0)
                 {
                    std::cout << "Error: just POSITIVE numbers possible" << std::endl;
                    return (0);
                 }
          
            }
            }
            catch(std::invalid_argument& e){
                std::cout << "Error ! " << e.what() << std::endl;
                }
    }
    for(iter = d.begin(); iter != d.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << std::endl;
    for(it = l.begin(); it != l.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    return (0);
}