/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyoo <eyoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:32:26 by eyoo              #+#    #+#             */
/*   Updated: 2023/03/27 13:21:08 by eyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
class BitcoinExchange
{
    private:

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::string);
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange & operator=(BitcoinExchange const & copy);
        float ToInt(std::string);
        std::string ValueToken(std::string);
        std::string DateToken(std::string);
        std::map<std::string, float> saveDataMap();
        float searchRateInMap(std::string);
        bool validDateFormat(std::string);
        bool validValueFormat(std::string);
        bool validLine(std::string);
       

};
#endif