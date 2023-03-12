#include "RPN.hpp"
#include <string>
#include<cmath>
#include<climits>
#include <sstream>
#include <stdexcept>
RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const & copy)
{
    *this = copy;
}

RPN & RPN::operator=(RPN const & copy)
{
    (void)copy;
    return (*this);
}
RPN::RPN(std::string input)
{
    std::stack<int> s;
    int a, b;
    std::string::iterator it;
    for(it = input.begin(); it != input.end(); it++)
    {
        if(*it == ' ')
            it++;
        if(isOperator(*it) == 1)
        {
            if (s.size() < 2) 
                throw std::invalid_argument("invalid_argument");
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(calcul(a, b, *it));
          //  std::cout <<"연산하고푸쉬한 숫자" << s.top() << std::endl;
            
        }
        else    
        {
         //   std::cout << "문자검사" << *it << std::endl;   
           if(isNumber(*it) == 1) 
           {int n;
            std::stringstream ss;
            ss << (*it);
            ss >> n;
           // std::cout << "숫자검사" << n << std::endl;
            s.push(n);
           }
           else
            throw std::invalid_argument("invalid_argument");

           // std::cout <<"그냥푸쉬한 숫자" << s.top() << std::endl;
        }
      
    }
    std::cout << s.top() << std::endl;
  
}
int RPN::isOperator(char c)
{
  if(c == '+' || c == '-'|| c == '*' || c == '/')
  {
    return 1;
  }
  return (-1);
}

int RPN::calcul(int a, int b, char c)
{
    if(c == '+')
        return (b + a);
    else if(c == '-')
        return (b - a);
    else if(c == '*')
        return (b * a);
    else 
        return (b / a);   
}

int RPN::isNumber(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return -1;
}

