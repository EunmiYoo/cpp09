#include "PmergeMe.hpp"

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
// group the list into pairs. If the list is odd, the last element is unpaired.
PmergeMe::PmergeMe(std::deque<int> dequeSort)
{
    std::deque <std::pair <int, int> > myDeque;
    std::deque<int>::iterator iter;
    std::deque <std::pair <int, int> >::iterator it;
    int i = 0;
    std::cout << "[Before] : ";
    while(dequeSort[i] != 0)
    {
        std::cout << dequeSort[i] << " ";
        i++;
    }
    size_t j = 0;
    while(j < dequeSort.size())
    {
        myDeque.push_back(std::make_pair(dequeSort[j], dequeSort[j+1]));
        j++;
        j++;
    }
    MergeDeque(myDeque);
}

// group the list into pairs. If the list is odd, the last element is unpaired.
PmergeMe::PmergeMe(std::vector<int> vectorSort)
{
    std::vector <std::pair <int, int> > myVector;
    std::vector<int>::iterator iter;
    std::vector <std::pair <int, int> >::iterator it;
    size_t i = 0;
    while(i < vectorSort.size())
    {    
        myVector.push_back(std::make_pair(vectorSort[i], vectorSort[i+1]));
        i++;
        i++;    
    }
    MergeVector(myVector);
}

void PmergeMe::MergeDeque(std::deque<std::pair <int, int> > myPair)
{
    std::deque <std::pair <int, int> >::iterator it;
    std::deque <int> leftDeque;
    std::deque <int> rightDeque;
    std::deque <int>::iterator leftIt;
    std::deque <int>::iterator rightIt;
    
    //Each pair sort into what we will call [int int] pairs.
    //after Put the first elements into named "leftDeque"
    //after Put the first elements into named "rightDeque"
    for(it = myPair.begin(); it != myPair.end(); it++)
    {
        if (it->first > it->second && it->second != 0)
        {
            std::swap(it->first, it->second);
        }
        leftDeque.push_back(it->first);
        rightDeque.push_back(it->second);

    }
    //sort for "leftDeque"
    std::sort(leftDeque.begin(), leftDeque.end());
    for(rightIt= rightDeque.begin(); rightIt != rightDeque.end(); rightIt++)
    {
        for(leftIt = leftDeque.begin(); leftIt != leftDeque.end(); leftIt++)
        {
            if(*leftIt <= *rightIt && *(leftIt + 1) > *rightIt)
            {
                leftDeque.insert(leftIt + 1, *rightIt);
                break;
            }
            if(*leftIt <= *rightIt && leftIt + 1 == leftDeque.end())
            {
                leftDeque.push_back(*rightIt);
                break;
            }           
        }
    }
    //print sorted elements
    std::cout << '\n';
    std::cout << "[After]: ";
    std::cout << " <std::deque>  -> " ;    
    for(leftIt = leftDeque.begin(); leftIt != leftDeque.end(); leftIt++)
    {
             std::cout << *leftIt << " ";
    }
}

void PmergeMe::MergeVector(std::vector<std::pair <int, int> > myVectorPair)
{
    std::vector<std::pair <int, int> >::iterator it;
    std::vector<int> leftV;
    std::vector<int> rightV;
    std::vector<int>::iterator leftItor;
    std::vector<int>::iterator rightItor;

    for(it = myVectorPair.begin(); it != myVectorPair.end(); it++)
    {
        if (it->first > it->second && it->second != 0)
        {
            std::swap(it->first, it->second);
        }
        leftV.push_back(it->first);
        rightV.push_back(it->second);
    } 
    std::sort(leftV.begin(), leftV.end());
    for(rightItor= rightV.begin(); rightItor != rightV.end(); rightItor++)
    {
        for(leftItor = leftV.begin(); leftItor != leftV.end(); leftItor++)
        {
            if(*leftItor <= *rightItor && *(leftItor + 1) > *rightItor)
            {
                leftV.insert(leftItor + 1, *rightItor);
                break;
            }
            if(*leftItor <= *rightItor && leftItor + 1 == leftV.end())
            {
                leftV.push_back(*rightItor);
                break;
            }              
        }
    }
    std::cout << '\n';
    std::cout << "          <std::vector> -> " ;
     for(leftItor = leftV.begin(); leftItor != leftV.end(); leftItor++)
    {
             std::cout << *leftItor << " ";
    }
    std::cout << std::endl;    
}