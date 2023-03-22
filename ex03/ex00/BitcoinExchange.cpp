#include "BitcoinExchange.hpp"
#include <string.h>
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
        double result = CalculRate(num, date);
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

double BitcoinExchange::CalculRate(double number, std::string date)
{
    std::map<std::string, double> Rates;
    std::vector<std::string>::iterator iterDate;
    std::fstream fs;
    std::string RateDate;
    int findComma;
    double rate;
    int front;
    fs.open("data.csv",std::ios::in);
    if (!fs.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    if (fs.is_open())
    {
       
        std::string getLine;
        int i = 0;
        while(getline(fs, getLine))
        {
            if(i != 0)
            { 
                findComma = getLine.find(',');
                front = 0;
                RateDate = getLine.substr(front, findComma);
                std::cout << "date output" << date << std::endl;
                std::string ratee = getLine.substr(findComma + 1);
                rate = ToInt(getLine.substr(findComma + 1));
            //    Rates.insert(std::make_pair<RateDate, rate>);
                std::cout << "rate out put : " << ratee << std::endl;
                std::cout << "rate output int  : " << rate << std::endl;
            }
            i++;
           
        }
    }
 

/* 
    iterDate = std::find(Rates.begin(), Rates.end(), date);
    std::cout <<  "ㅇㅁㅅㄷ ㅊㅇㄹㄴㅇ" << std::endl;
    std::cout << *iterDate << std::endl;
    iterDate += 2;
    std::cout <<  "ㅇㅁㅅㄷ ㅊㅇㄹㄴㅇ" << std::endl;
    std::cout << *iterDate << std::endl;
    std::string rateString = *iterDate;
    double rate = ToInt(rateString); */
    
  //  number = number * rate;
    return (number);
}

double BitcoinExchange::TokenValue(std::string line)
{
   // int before = 0;
    int findBar = 0;
    double valueIndex;
    findBar = line.find('|');
   // before = findBar + 1;
    valueIndex = ToInt(line.substr(findBar + 1));
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

