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
        if(isOperator(*it) == 1)
        {
            
            if (s.size() < 2) 
                throw std::invalid_argument("invalid_argument");
            a = s.top();
            if(a == 0 && *it == '/')
                throw std::invalid_argument("ZERO invalid_argument");
              
            s.pop();
            b = s.top();
            s.pop();
            s.push(calcul(a, b, *it));
            
        }
        else if(isNumber(*it) == 1) 
        {
            int n;
            std::stringstream ss;
            ss << (*it);
            ss >> n;
            s.push(n);
        }
        else if (*it != ' ')
            throw std::invalid_argument("invalid_argument");
    
    }
    if(s.size() != 1)
        throw std::invalid_argument("invalid_argument");
    

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

