/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:00:05 by ychahbi           #+#    #+#             */
/*   Updated: 2024/01/20 23:26:22 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
}

void    toChar(long double num)
{
    std::cout << "Char: ";
    if (num >= -128 && num <= 127)
    {
        (num >= 32 && num <= 127) && (std::cout << (char)num << std::endl);
        (num < 32 || num > 127) && (std::cout << "Non displayable"<< std::endl);
    }
    else
        std::cout << "impossible" << std::endl;
}

void    toInt(long double num)
{
    std::cout << "Int: ";
    if (num >= INT_MIN && num <= INT_MAX)
        std::cout << static_cast<int>(num) << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void    toFloat(long double num)
{
    std::cout << "Float: ";
    if (num >= (std::numeric_limits<float>::lowest()) && num <= (3.40282347 * std::pow(10, 38)))
        std::cout << static_cast<float>(num) << std::endl;
    else if (std::numeric_limits<float>::infinity() == num || -std::numeric_limits<float>::infinity() == num)
        std::cout << std::numeric_limits<float>::infinity() * ((num > 0) ? 1 : -1) << "f" << std::endl;
    else if (std::isnan(num))
        std::cout << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void    toDouble(long double num)
{
    std::cout << "Double: ";
    std::cout << num << std::endl;
}

std::string* makearray()
{
    std::string *array = new std::string[6];
    array[0] = "+inf";
    array[4] = "-inf";
    array[1] = "-inff";
    array[5] = "+inff";
    array[2] = "nan";
    array[3] = "nanf";

    return (array);
}

int parssing(std::string str)
{
    std::string *array = makearray();
    int f_count = 0;
    int pointes = 0;
    int min     = 0;
    int str_size= static_cast<int>(str.size());
    
    for (int i = 0; i < 6; i++)
        if (str == array[i])
            return (delete[] array, 1);
    delete[] array;

    if ((str.size() == 1) && (str[0] >= 32 && str[0] <= 127)) return (1);
    for (int i = 0; i < str_size; i++)
    {
        (str[i] == 'f') && (f_count++);
        (str[i] == '.') && (pointes++);
        (str[i] == '-') && (min++);
        if ((!(str[i] >= 48 && str[i] <= 57) && str[i] != '.' && str[i] != 'f' && str[0] != '-') || f_count > 1 || pointes > 1 || min > 1)
            return (0);
            
    }
    return (1);
}

void ScalarConverter::convert(std::string name)
{
    std::stringstream Cast;
    long double Cas;
    std::string sval;

 
    if (parssing(name))
    {
        Cast << name;
        sval = Cast.str();
        try
        {
            Cas = std::stold(sval);
        }
        catch(std::exception& e)
        {
            std::cout << "no conversion were made" << std::endl;
            return;
        }
        //std::istringstream(sval) >> Cas;
        toChar(Cas);
        toInt(Cas);
        toFloat(Cas);
        toDouble(Cas);
    }
}

ScalarConverter::ScalarConverter(std::string name)
{
    convert(name);
}

ScalarConverter::~ScalarConverter(){}