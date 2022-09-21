#ifndef _Zombie_HPP
#define _Zombie_HPP
#include <iostream>
#include <string>

class Zombie {
private:

    std::string name;

public:
    //생성자
    Zombie();
    //이름 포함
    Zombie* newZombie( std::string name );
    //announce 포함
    void randomChump( std::string name );
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