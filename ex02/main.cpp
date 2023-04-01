#include "PmergeMe.hpp"
#include <limits.h>
int main(int ac, char **av)
{
    std::deque<int> d;
    std::deque<int>::iterator iter;
    std::vector<int> v;
    std::vector<int>::iterator it;
    std::stringstream ss;
    clock_t startDeque,startVector, dequeStop, vectorStop;

    int num;
    if(ac < 2)
    {
        std::cout << "Error, One argument" << std::endl;
    }
    else
    {
        try{        
            for(int i = 1; i != ac; ++i)
            {
                for(int j = 0; av[i][j]; j++)
                {
                    if(!isdigit(av[i][j]) && !(av[i][j]=='+'))
                    {
                        std::cout << "Error: not allowed format(only positive number possible)" << std::endl;
                        return (0);
                    }        
                }
                std::istringstream ss(av[i]);
                if(ss >> num)
                {
                     if(num <= 0)
                    {
                        std::cout << "Error: not allowed format(only positive number possible)" << std::endl;
                        return (0);
                    }
                    else if (num > INT_MAX)
                    {
                        std::cout << "Error: integer out of range" << std::endl;
                        return (0);
                    }
                    //after parse, put the elements into each containers.
                    d.push_back(num); 
                    v.push_back(num);        
                    ss.clear();                     
                }
                else
                {
                    std::cout << "Error: not allowed format(only number or positive number possible)" << std::endl;
                    return (0);
                }
            }
            // Start sort using deque container
            startDeque = clock() ;
            PmergeMe dequeSort(d);
            dequeStop = clock();
            // Start sort using vector container
            startVector = clock() ;
            PmergeMe VertorSort(v);
            vectorStop = clock();

            std::cout << "Time to process a range of "<< d.size() <<" elements with std::[deque] :" << (float)(dequeStop - startDeque)/CLOCKS_PER_SEC << " ms"<< std::endl;
            std::cout << "Time to process a range of "<< v.size() <<" elements with std::[vector] :" << (float)(vectorStop - startVector)/CLOCKS_PER_SEC << " ms"<< std::endl;
            }
            catch(std::invalid_argument& e){
                std::cout << "Error ! " << e.what() << std::endl;
                }
    }
    return (0);
}