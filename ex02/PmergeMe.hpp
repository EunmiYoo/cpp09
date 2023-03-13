#include <iostream>

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>

class PmergeMe
{
private:
    /* data */
public:
    
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const & copy);
    PmergeMe & operator=(PmergeMe const & copy);
    PmergeMe(std::string);
   

};




#endif