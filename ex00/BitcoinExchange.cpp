#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::vector<std::string> lines)
{
    std::vector<std::string>::iterator iter;
    for(iter = lines.begin(); iter != lines.end(); iter++)
    {
        std::string date = TokenDate(*iter);
        double num = TokenValue(*iter);
        double result = CalculRate(num);
        if((num < 0))
        {
            *iter = "Error: not a positive number.";
            std::cout << *iter << std::endl;
        }
        else if(!num)
        {
            std::cout <<"Error: bad input => " << *iter << std::endl;
        }
        else if(num > 1000)
        {
            *iter = "Error: too large a number.";
            std::cout << *iter << std::endl;

        }
        else{
        std::cout << date << "=> " << num << " = " << result << std::endl;
        }
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & copy)
{
    (void)copy;
    return(*this);
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
    *this = copy;
}

double BitcoinExchange::CalculRate(double number)
{
    double rate = 0.3;
    number = number * rate;
    return (number);
}

double BitcoinExchange::TokenValue(std::string line)
{
    int before = 0;
    int findBar = 0;
    double valueIndex;
    findBar = line.find('|');
    before = findBar + 1;
    valueIndex = ToInt(line.substr(findBar + 1, before));
    return(valueIndex);
}

std::string BitcoinExchange::TokenDate(std::string line)
{
    int before = 0;
    int findBar = 0;
    std::string dateIndex;
    findBar = line.find('|');
    dateIndex = line.substr(before, findBar - before);
    return(dateIndex);
}


double BitcoinExchange::ToInt(std::string string)
{
     double number;
      std::stringstream ss(string);
      ss >> number;
     return (number); //string->int convert;
}

