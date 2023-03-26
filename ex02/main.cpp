#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::deque<int> d;
    std::deque<int>::iterator iter;
    std::vector<int> v;
    std::vector<int>::iterator it;
    std::stringstream ss;
    clock_t start, dequeStop, vectorStop;

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
                    if(!isdigit(av[i][j]))
                    {
                        std::cout << "Error: not allowed format(only number possible)" << std::endl;
                        return (0);
                    }        
                }
                if(isdigit(*av[i]))
                {
                    ss << av[i];
                    ss >> num; 
                    if(num <= 0)
                    {
                        std::cout << "Error: not allowed format(only positive number possible)" << std::endl;
                        return (0);
                    }
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
        
            start = clock() ;
            PmergeMe dequeSort(d);
            dequeStop = clock();
           
            start = clock() ;
            PmergeMe VertorSort(v);
            vectorStop = clock();

            std::cout << "Time to process a range of "<< d.size() <<" elements with std::[deque] :" << (float)(dequeStop - start)/CLOCKS_PER_SEC << " ms"<< std::endl;
            std::cout << "Time to process a range of "<< v.size() <<" elements with std::[vector] :" << (float)(vectorStop - start)/CLOCKS_PER_SEC << " ms"<< std::endl;
            }
            catch(std::invalid_argument& e){
                std::cout << "Error ! " << e.what() << std::endl;
                }
    }
   
  
    return (0);
}