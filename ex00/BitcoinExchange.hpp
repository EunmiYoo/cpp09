/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyoo <eyoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:32:26 by eyoo              #+#    #+#             */
/*   Updated: 2023/03/09 13:36:16 by eyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <stdexcept>

class BitcoinExchange
{
    private:

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::string);
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange & operator=(BitcoinExchange const & copy);
        float CalculRate(float, std::string);
        float ToInt(std::string);
        float ValueToken(std::string);
        std::string DateToken(std::string);
        std::map<std::string, float> saveDataMap();
        float searchRateInMap(std::string date);
        bool validDateFormat(std::string);
       

};
#endif