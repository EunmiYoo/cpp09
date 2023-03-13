#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
    *this = copy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & copy)
{
    (void)copy;
    return (*this);
}
PmergeMe::PmergeMe(std::deque<int> dequeSort)
{
    std::deque<int>::iterator iter;
    for(iter = dequeSort.begin(); iter != dequeSort.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << "before sorting" <<std::endl;
    int right = dequeSort.size();
    MergeDeque(dequeSort, 0, right);
    for(iter = dequeSort.begin(); iter != dequeSort.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << "afer sorting" << std::endl;
}
PmergeMe::PmergeMe(std::list<int> listSort)
{
    std::list<int>::iterator it;
    for(it = listSort.begin(); it != listSort.end(); it++)
        std::cout << *it  << ' ';
    std::cout << "before sorting" << std::endl;
    //sort(listSort.begin(), listSort.end());
    for(it = listSort.begin(); it != listSort.end(); it++)
        std::cout  << *it  << ' ';
    std::cout << "after sorting"<< std::endl;
}

void PmergeMe::MergeDeque(std::deque<int> dequeSort, int left, int right)
{
    // std::deque<int>::iterator i;
    // std::deque<int>::iterator j;
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        MergeDeque(dequeSort, left, mid);   
        MergeDeque(dequeSort, mid+1, right);
   

    } 

}

/* void PmergeMe::MergeList(std::list<int> listSort, int left, int right)
{

}
 */




