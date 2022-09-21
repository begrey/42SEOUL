#include "Cast.hpp"

Base * generate(void){
    srand(time(NULL));
    int a = rand() % 3; // ? 0 ~ 2까지 난수 생성
    if (a < 1)
        return (new A);
    else if (a >= 1 && a < 2)
        return (new B);
    else
        return (new C);
}
void identify(Base* p){
    if (A *a = dynamic_cast<A*>(p))
        std::cout << "It's a A class that downcast from Base" << std::endl;
    else if (B *a = dynamic_cast<B*>(p))
        std::cout << "It's a B class that downcast from Base" << std::endl;
    else if (C *a = dynamic_cast<C*>(p))
        std::cout << "It's a C class that downcast from Base" << std::endl;
    else
        std::cout << "NO class that downcast from Base" << std::endl;
    
}
void identify(Base& p){
    identify(&p);
}