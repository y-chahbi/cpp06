/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:28:54 by ychahbi           #+#    #+#             */
/*   Updated: 2024/01/26 05:03:01 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct Data
{
    int a;
    int b;
}           Data;


class Serializer
{
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        Serializer(const Serializer& Copy);
        Serializer& operator=(const Serializer& Copy);
        ~Serializer();
};

#endif