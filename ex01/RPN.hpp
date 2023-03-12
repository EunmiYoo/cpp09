#include <iostream>

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>

class RPN
{
private:
    /* data */
public:
    
    RPN();
    ~RPN();
    RPN(RPN const & copy);
    RPN & operator=(RPN const & copy);
    RPN(std::string);
    int calcul(int, int, char);
    int isOperator(char);
    int isNumber(char);

};




#endif