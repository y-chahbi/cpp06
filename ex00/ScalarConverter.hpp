/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:00:12 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/03 10:37:06 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits.h>
#include <float.h>
#include <cmath>


class ScalarConverter
{
    private:
    public:
        ScalarConverter();
        ScalarConverter(std::string);
        static void convert(std::string);
        ScalarConverter(const ScalarConverter& Copy);
        ScalarConverter& operator=(const ScalarConverter& Copy);
        ~ScalarConverter();
};

#endif