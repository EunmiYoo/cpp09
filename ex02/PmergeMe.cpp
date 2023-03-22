#include "PmergeMe.hpp"
#include <algorithm>
#include <utility> 

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
    int right = dequeSort.size() - 1;
    std::cout << dequeSort.size() << std::endl;
    MergeDeque(dequeSort, 0, right);
   
}
PmergeMe::PmergeMe(std::list<int> listSort)
{
    std::list<int>::iterator it;
    for(it = listSort.begin(); it != listSort.end(); it++)
        std::cout << *it  << ' ';
    std::cout << "before sorting" << std::endl;
    //sort(listSort.begin(), listSort.end());
  /*   for(it = listSort.begin(); it != listSort.end(); it++)
        std::cout  << *it  << ' ';
    std::cout << "after sorting"<< std::endl; */
}

void PmergeMe::MergeDeque(std::deque<int> dequeSort, int left, int right)
{
    
    // std::deque<int>::iterator j;
    int mid;
    if(left < right)
    {
       
        mid = (left + right) / 2;
        if (mid-left == 1 || right - (mid + 1) == 1 )
            MergeInsert(dequeSort, left, mid, right);
        else{
       // std::cout << left << " " << mid << std::endl;
        //std::cout << "--------------- " << std::endl;
        std::cout << left << " " << mid << std::endl;
        std::cout << " 왼쪽 라인 =============== " << std::endl;
        MergeDeque(dequeSort, left, mid);
        std::cout << mid + 1 << " " << right << std::endl;
        std::cout << "오른쪽 라인++++++++++++++ " << std::endl;
        MergeDeque(dequeSort, mid+1, right);
        
        }

   

    }
 

}
void PmergeMe::MergeInsert(std::deque<int> &dequeSort, int l, int m, int r)  

{
     std::cout << l << std::endl;
     std::cout << m<< std::endl;
    
     std::deque<int> merge;


     std::deque<int>::iterator i;
     {
     if(dequeSort[l]> dequeSort[m]) 
     {
        std::swap(dequeSort[l], dequeSort[m]);
        std::cout << "@@@@@@@@@@@@" << std::endl;     
        std::cout << "앞: " <<dequeSort[l]<<"뒤: " << dequeSort[m] << std::endl;
        std::cout << "@@@@@@@@@@@@" << std::endl;
     
    
     }
    merge.push_back(dequeSort[l]);
    merge.push_back(dequeSort[m]);
       
    
     std::cout << m + 1<< std::endl;
     std::cout << r << std::endl;
   
     if(dequeSort[m+1] > dequeSort[r]) 
    {  
        std::swap(dequeSort[m+1], dequeSort[r]);
        std::cout << "===========" << std::endl;
        std::cout << "앞: " <<dequeSort[m+1]<<"뒤: " << dequeSort[r] << std::endl;
        std::cout << "===========" << std::endl;
     
      
    }
    merge.push_back(dequeSort[m+1]);
    merge.push_back(dequeSort[r]);
    
     }
  
    for(i = merge.begin(); i != merge.end(); i++)
    std::cout << *i << ' ';
    std::cout << "afer sorting" << std::endl;
}
/* void PmergeMe::MergeList(std::list<int> listSort, int left, int right)
{

}
 */




