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
#include <vector>
#include <map>

class BitcoinExchange
{
    private:

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::vector<std::string>);
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange & operator=(BitcoinExchange const & copy);
        double CalculRate(double, std::string);
        double ToInt(std::string);
        double TokenValue(std::string);
        std::string TokenDate(std::string);
       

};
#endif