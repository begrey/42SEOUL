#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
// ! 순수 가상 함수(pure virtual function)란?
// ? 파생 클래스에서 반드시 재정의해야 하는 멤버 함수, 파생 클래스에서 재정의하지 않으면 사용할 수 없다.
// ! 추상 클래스(abstract class)란?
// ? 하나 이상의 순수 가상 함수를 포함하는 클래스를 추상 클래스(abstract class)
// ? 추상 클래스는 동작이 정의되지 않은 순수 가상 함수를 포함하고 있으므로, 인스턴스를 생성할 수 없습니다.

int main() {
    std::cout << "-----------make Dog and Cat and Animal--------------" << std::endl;
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "-----------Dog and Cat Type--------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "-----------Dog and Cat makeSound()--------------" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    //meta->makeSound();
    std::cout << "-----------Desturctor Called--------------" << std::endl;
    //delete meta;
    delete j;
    delete i;
}
