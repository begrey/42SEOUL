#ifndef _Cast_HPP
#define _Cast_HPP
#include <iostream>
#include <string>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif