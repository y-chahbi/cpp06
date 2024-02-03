/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:28:55 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/03 16:29:15 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
};

Data*       Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
};

Serializer::Serializer(const Serializer& Copy)
{
    *this = Copy;
};

Serializer& Serializer::operator=(const Serializer& Copy)
{
    (void)Copy;
    return (*this);
};