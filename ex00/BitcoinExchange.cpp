#include "BitcoinExchange.hpp"
#include <cctype>
BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string line)
{     
    bool checkLine = validLine(line);
    std::string date = DateToken(line); 
    std::string value = ValueToken(line);
    float num = ToInt(value);
    float rate = searchRateInMap(date);
    float result = num * rate;

    if(!checkLine)
    {
         std::cout <<"Error: bad input => " << line << std::endl;
    }
    else if(validDateFormat(date))
    {
      std::cout <<"Error: bad input => " << line << std::endl;
    }
    else if(!validValueFormat(value))
    {
         std::cout <<"Error: bad input => " << line << std::endl;
    }   
    else if((num <= 0))
    {
        std::cout << "Error: not a positive number."<< std::endl;
    }  
    else if(num >= 1000)
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
        }
    }
    fs.close();
    return (Rates);

}


std::string BitcoinExchange::ValueToken(std::string line)
{
    int findBar = 0;
    std::string valueIndex;
    std::string::iterator it;
    findBar = line.find('|');
    valueIndex = line.substr(findBar + 1);
    valueIndex.erase(std::remove(valueIndex.begin(),valueIndex.end(),' '),valueIndex.end());
    return (valueIndex);
}

std::string BitcoinExchange::DateToken(std::string line)
{
    int before = 0;
    int findBar = 0;
    std::string dateIndex;
    findBar = line.find('|');
    dateIndex = line.substr(before, findBar);
    std::string::iterator end_pos = std::remove(dateIndex.begin(), dateIndex.end(), ' ');
    dateIndex.erase(end_pos, dateIndex.end());
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
        return (true);
    }
    if(!(year > 2008 && year < 2023) || isdigit(year))
    {
        return (true);
    }
    if(month >= 1 && month <=12)
    {
        if( (month >=1 && month <= 9)  && !(months.length() == 2) )
        {
                 return (true);
        }
    }
    if(!(month >= 1 && month <=12) || isdigit(month))
    {
        return (true);
    }
    if((day >= 1 && day <= 31))
    {
        if( (day >=1 && day <= 9)  && !(days.length() == 2) )
        {
                 return (true);
        }
    }
    if(!(day >= 1 && day <= 31) || isdigit(day))
        return (true);

    return(false);  
}

bool BitcoinExchange::validValueFormat(std::string value)
{
    int count = std::count(value.begin(), value.end(), '.');
    if(value.size() == 0)
        return false;
    if(count >= 2)
        return false;
    int i = 0;
    while(value[i])
    {
        if(value[i] == '-')
            i++;
        if(value[i] == '.')
            i++;
        if(isdigit(value[i]))
            i++;
        else  
         return false;
    }
    return true;
}

bool BitcoinExchange::validLine(std::string line) 
{
   int i = 0;
   int count = std::count(line.begin(), line.end(), '|');
   if(count >= 2)
    return false;
   while(line[i])
   {
    if(line[i] == '|')
        return true;
    i++;
   }
   return false;
}