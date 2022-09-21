#include "HumanA.hpp"
//* 생성자에서 ':' 인 경우는 객체 생성과 동시에 초기화가 필요한 경우!
HumanA::HumanA(std::string name, Weapon &weapon) : W(weapon) {
    this->name = name;
    std::cout << this->name + " Atype Born!" << std::endl;
}

HumanA::~HumanA() {
    std::cout << this->name + " Atype Dead..." << std::endl;
}
    
void HumanA::attack() {
    std::cout << name << " attacks with his " << this->W.getType() << std::endl;
}