#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <deque>
#include <list>

class PmergeMe
{
private:
    /* data */
public:
    
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const & copy);
    PmergeMe & operator=(PmergeMe const & copy);
    PmergeMe(std::deque<int>);
    PmergeMe(std::list<int>);
    void MergeDeque(std::deque<int>, int, int);
    void MergeList(std::list<int>,int, int);
   

};




#endif