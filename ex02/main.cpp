/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:35:14 by ychahbi           #+#    #+#             */
/*   Updated: 2024/01/22 11:05:56 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>


Base * generate(void)
{
    std::time_t currentTime = std::time(nullptr);
    int sec = currentTime % 3;
    switch(sec)
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default : return nullptr;
    }
};

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "Non of the above" << std::endl;
};

void Bf(Base &p)
{
    try {
        B& test = dynamic_cast<B&>(p);
        std::cout << "YOO it's B!" << std::endl;
    } catch (std::bad_cast &e) {
        // std::cout << e.what() << std::endl;
    }
}

void Cf(Base &p)
{
    try {
        C& test = dynamic_cast<C&>(p);
        std::cout << "YOO it's C!" << std::endl;
    } catch (std::bad_cast &e) {
        // std::cout << e.what() << std::endl;
    }
}

void Af(Base &p)
{
    try {
        A& test = dynamic_cast<A&>(p);
        std::cout << "YOO it's A!" << std::endl;
    } catch (std::bad_cast &e) {
        // std::cout << e.what() << std::endl;
    }
}

void identify(Base& p)
{
    Af(p);
    Bf(p);
    Cf(p);
};


int main()
{
    Base* ObjPtr;
    ObjPtr = generate();
    
    identify(ObjPtr);
    identify(*ObjPtr);
    return (0);
}