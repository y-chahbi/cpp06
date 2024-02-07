/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:35:14 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/07 15:22:10 by ychahbi          ###   ########.fr       */
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
        default : return NULL;
    }
};

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "identify said A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "identify said B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "identify said C" << std::endl;
    else
        std::cout << "Non of the above" << std::endl;
};

bool Bf(Base &p)
{
    try {
        B& test = dynamic_cast<B&>(p);
        test.helloB();
        return (true);
    } catch (std::bad_cast &e) {
        (void)e;
    }
    return false;
}

bool Cf(Base &p)
{
    try {
        C& test = dynamic_cast<C&>(p);
        test.helloC();
        return (true);
    } catch (std::bad_cast &e) {
        (void)e;
    }
    return false;
}

bool Af(Base &p)
{
    try {
        A& test = dynamic_cast<A&>(p);
        test.helloA();
        return (true);
    } catch (std::bad_cast &e) {
        (void)e;
    }
    return (0);
}

void identify(Base& p)
{
    bool    ent = 0;
    (ent == 0) && (ent = Af(p));
    (ent == 0) && (ent = Bf(p));
    (ent == 0) && (ent = Cf(p));
};


int main()
{
    Base* ObjPtr;
    ObjPtr = generate();
    
    identify(ObjPtr);
    identify(*ObjPtr);
    delete ObjPtr;
    return (0);
}