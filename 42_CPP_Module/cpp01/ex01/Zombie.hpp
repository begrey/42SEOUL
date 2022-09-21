#ifndef _Zombie_HPP
#define _Zombie_HPP
#include <iostream>
#include <string>

class Zombie {
private:
    //멤버변수
    std::string name;

public:
    //생성자
    Zombie();
    //zombie 부대
    Zombie* zombieHorde( int N, std::string name );
    //소멸자
    ~Zombie();

    void announce(void);
    
    //getter, setter
    void setName(std::string name) {
        this->name = name;
    }
    std::string getName() {
        return this->name;
    }

};
#endif