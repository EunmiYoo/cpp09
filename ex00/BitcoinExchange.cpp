#include "BitcoinExchange.hpp"
#include <string>
//#include <time.h> 

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string line)
{
    std::string date = DateToken(line); 
    float num = ValueToken(line);
    float rate = searchRateInMap(date);
    float result = num * rate;
    char c = line[line.find("|") + 1];
    char b = line[line.find("|") - 1];
   // std::cout << "무슨문자?: " << line[line.find("|") + 1] << std::endl;
    if(!isspace(c) || !isspace(b))
    {
        std::cout << "Error: not good format => need space before ou after bar" << std::endl;
    }

    if(validDateFormat(date))
    {
      std::cout <<"Error: bad input => " << date << std::endl;
    }
   
    else if((num < 0))
    {
        std::cout << "Error: not a positive number."<< std::endl;
    }  
    else if(num > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
    } 
    else{
         std::cout << date << " => " << num << " = " << result << std::endl;
        }

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
 
float BitcoinExchange::searchRateInMap(std::string date)
{
    std::map<std::string, float> mapData;
    std::map<std::string, float>::iterator it;
    float rate;
    
    mapData = saveDataMap();
    it = mapData.find(date);
    if(it != mapData.end())
        rate = it->second;
    else
        rate =  (--mapData.lower_bound(date))->second;
    return (rate);
} 
std::map<std::string, float> BitcoinExchange::saveDataMap()
{
    std::map<std::string, float> Rates;
    std::fstream fs;
    std::string RateDate;
    int findComma;
    float rate;
    int front;
    fs.open("data.csv",std::ios::in);
    if (!fs.is_open())
    {
        throw std::invalid_argument("could not open file.");
    }
    else if (fs.is_open())
    {
       
        std::string getLine;
     //   int i = 0;
        while(getline(fs, getLine))
        {
            if(getLine != "date,exchange_rate")
            { 
                findComma = getLine.find(',');
                front = 0;
                RateDate = getLine.substr(front, findComma);
                front = findComma + 1;
                std::string ratee = getLine.substr(findComma + 1,front);
                rate = ToInt(getLine.substr(findComma + 1));
                Rates.insert(std::pair<std::string, float>(RateDate,rate));
            }
       //.     i++;
           
        }
    }
    return (Rates);

}
/* float BitcoinExchange::CalculRate(float number, std::string date)
{
} */

float BitcoinExchange::ValueToken(std::string line)
{
    int end;
    int findBar = 0;
    float valueIndex;
    findBar = line.find('|');
    end = findBar + 1;
    valueIndex = ToInt(line.substr(findBar + 2, end));
    return(valueIndex);
}

std::string BitcoinExchange::DateToken(std::string line)
{
    int before = 0;
    int findBar = 0;
    std::string dateIndex;
    findBar = line.find('|');
    dateIndex = line.substr(before, findBar - 1);
    return(dateIndex);
}


float BitcoinExchange::ToInt(std::string string)
{
     float number;
      std::stringstream ss(string);
      ss >> number;
     return (number); //string->float convert;
}

bool BitcoinExchange::validDateFormat(std::string date)
{
    int year, month, day;
    std::string dateSplit = date;
    std::string years = dateSplit.substr(0, dateSplit.find("-"));
    dateSplit.erase(0, dateSplit.find("-") + 1);
    std::string months = dateSplit.substr(0, dateSplit.find("-"));
    dateSplit.erase(0, dateSplit.find("-") + 1);
    std::string days = dateSplit.substr(0, dateSplit.find("-"));
    year = ToInt(years);
    month = ToInt(months);
    day = ToInt(days);

    struct tm tm;
    
    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
    {
        //std::cout <<"Error: bad input => format " << date << std::endl;
        return (true);
    }

    if(!(year > 2008 && year <= 2023) || isdigit(year))
    {
        //std::cout <<"Error: bad input year => " << year << std::endl;
        return (true);
    }

  /*   if( month >=1 && month <= 9)
    {
        if(!(months[0] == '0'))
             std::cout <<"Error: bad input month => " << date << std::endl;

    } */
    if(month >= 1 && month <=12)
    {
        if( (month >=1 && month <= 9)  && !(months.length() == 2) )
        {
         //       std::cout <<"Error: bad input month => " << date << std::endl;
                 return (true);
        }
    }

    if(!(month >= 1 && month <=12) || isdigit(month))
    {
       // std::cout <<"Error: bad input month => " << date << std::endl;
        return (true);
    }
      // 

    
    if((day >= 1 && day <= 31))
    {
        if( (day >=1 && day <= 9)  && !(days.length() == 2) )
        {
             //   std::cout <<"Error: bad input month => " << date << std::endl;
                 return (true);
        }
        //std::cout <<"Error: bad input day => " << date << std::endl;
          //  return (true);

    }
    if(!(day >= 1 && day <= 31) || isdigit(day))
        return (true);

    return(false);  
  //  std::cout << year << std::endl;
    //std::cout << month << std::endl;
    //std::cout << day << std::endl;



}