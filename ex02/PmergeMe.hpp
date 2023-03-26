#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

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
    PmergeMe(std::vector<int>);
    void MergeDeque(std::deque<std::pair <int, int> >);
    void MergeVector(std::vector<std::pair <int, int> > myPair);
};




#endif