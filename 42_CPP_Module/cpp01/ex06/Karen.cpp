#include "Karen.hpp"

void Karen::debug(void) {
    std::cout << "[DEBUG]\n"
    << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
    << std::endl;
}

void Karen::info(void) {
    std::cout << "[INFO]\n"
    << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
    << std::endl;
}

void Karen::warning(void) {
    std::cout << "[WARNING]\n"
    << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." 
    << std::endl;
}

void Karen::error(void) {
    std::cout << "[ERROR]\n"
    << "This is unacceptable, I want to speak to the manager now."
    << std::endl;
}

void Karen::complain(std::string level) {
    cmt com[4];

    com[0].level = "DEBUG";
    com[1].level = "INFO";
    com[2].level = "WARNING";
    com[3].level = "ERROR";
    com[0].levptr = &Karen::debug;
    com[1].levptr = &Karen::info;
    com[2].levptr = &Karen::warning;
    com[3].levptr = &Karen::error;
    // ! 멤버 함수 포인터는 해당 객체의 내용물을 참조 하기 때문에 멤버 함수 포인터 호출 시
    // ! 어떤 객체인지 객체 변수도 함께 주어져야 함 : this!
    // ? Karen::처럼 직접 namespace를 써서 Karen::*com[i].levptr() 인 경우
    // ? "*" 연산자는 무조건 namespace앞에 와야 하는데 뒤에 오게 되기 때문에 안됨
    // ? 따라서 this를 통해 Karen객체임을 언급하는것이라고 함..?

    // ! 2번째 방법
    // Karen k2;
    // cmt2 com2[4];
    // com2[0].level = "DEBUG";
    // com2[1].level = "INFO";
    // com2[2].level = "WARNING";
    // com2[3].level = "ERROR";
    // com2[0].p = &Karen::debug;
    // com2[1].p = &Karen::info;
    // com2[2].p = &Karen::warning;
    // com2[3].p = &Karen::error;
    int i;
    for (i = 0; i < 4; i++) {
        if (level == com[i].level) {
            break;
            // ! 1번째 방법
            //(k2.*(com2[i].p))();
            // ! 2번째 방법
            (*this.*com[i].levptr)(); // ? this->*com도 가능하나 과부화 발생 가능
        }
    }
    switch (i)
    {
    case 0:
        (*this.*com[0].levptr)();
    case 1:
        (*this.*com[1].levptr)();
    case 2:
        (*this.*com[2].levptr)();
    case 3:
        (*this.*com[3].levptr)();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }

}