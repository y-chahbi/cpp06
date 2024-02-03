/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:00:05 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/03 16:01:22 by ychahbi          ###   ########.fr       */
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
        {
            std::cout << static_cast<float>(num);
            if (std::floor(num) == num)
                std::cout << ".0f";
            else
                std::cout << "f";
            std::cout << std::endl;
        }
    else if (std::numeric_limits<float>::infinity() == num || -std::numeric_limits<float>::infinity() == num)
        std::cout << std::numeric_limits<float>::infinity() * ((num > 0) ? 1 : -1) << "f" << std::endl;
    else if (std::isnan(num))
        std::cout << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;
}


void    printImpossible()
{
    std::cout << "Char: impossible\nInt: impossible\nFloat: impossible\nDouble: impossible" << std:: endl;
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

bool not_inarray(long double num)
{
    std::string *ar = makearray();
    std::stringstream str;
    std::string tmp;

    str << num;
    str >> tmp;
    for (int i = 0; i < 6 ; i++)
    {
        if (str.str() == ar[i])
            return (0);
    }
    return (1);
}

void    toDouble(long double num)
{
    std::cout << "Double: ";
    std::cout << num;
    if (std::floor(num) == num && not_inarray(num))
            std::cout << ".0";
    std::cout << std::endl;
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
        if (str[i] == 'f')
        {
            if (i + 1 < str_size)
                return (0);
            f_count++;
        }
        (str[i] == '.') && (pointes++);
        (str[i] == '-') && (min++);
        if ((!(str[i] >= 48 && str[i] <= 57) && str[i] != '.' && str[i] != 'f' && str[0] != '-') || f_count > 1 || pointes > 1 || min > 1)
            return (0);
            
    }
    return (1);
}

void    printThem(long double num)
{
    toChar(num);
    toInt(num);
    toFloat(num);
    toDouble(num);
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
        if ((sval.size() == 1) && (sval[0] >= 32 && sval[0] <= 127) && !(sval[0] >= '0' && sval[0] <= '9'))
            printThem(sval[0]);
        else{
            try{
                Cas = std::stod(sval);
                printThem(Cas);
            }
            catch(std::exception& e)
            {
                (void)e;
                printImpossible();
            }
        }
    }
    else
        printImpossible();
}

ScalarConverter::ScalarConverter(std::string name)
{
    convert(name);
}

ScalarConverter::ScalarConverter(const ScalarConverter& Copy)
{
    *this = Copy;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& Copy)
{
    (void)Copy;
    return (*this);
};
        
ScalarConverter::~ScalarConverter(){}