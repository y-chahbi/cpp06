/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:28:58 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/04 10:29:29 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main()
{
    Data *hello = new Data;
    uintptr_t   Data_uns;
    Data *test  = new Data;

    hello->a = 15;
    hello->b = 65;

    Data_uns = Serializer::serialize(hello);
    test     = Serializer::deserialize(Data_uns);
    
    std::cout << "-----------------" << std::endl;
    std::cout << "|  Original " << hello->a <<"   |"
    << std::endl << "|  New      "<< test->a <<"   |" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "|  Original " << hello->b <<"   |"
    << std::endl << "|  New      "<< test->b <<"   |" << std::endl;
    std::cout << "-----------------" << std::endl;
}