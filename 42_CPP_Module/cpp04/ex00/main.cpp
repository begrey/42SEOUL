#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
// ! virtual을 빼면 왜 자식의 멤버함수가 아닌 부모의 멤버함수로만 호출될까?
// ? C++ 컴파일러가 실제로 가리키는 객체의 자료형을 기준으로 하는게 아닌, 
// ? 포인터 변수의 자료형을 기준으로 판단하기 때문


int main() {
    std::cout << "-----------make Dog and Cat and Animal--------------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "-----------Dog and Cat Type--------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "-----------Dog and Cat makeSound()--------------" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "-----------Desturctor Called--------------" << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout << "-----------Make Wrong Animal and Wrong Cat--------------" << std::endl;
    const WrongAnimal* w_animal = new WrongAnimal();
    const WrongAnimal* w_cat = new WrongCat();
    std::cout << w_animal->getType() << " " << std::endl;
    std::cout << w_cat->getType() << " " << std::endl;
    w_animal->makeSound();
    w_cat->makeSound();
    std::cout << "-----------Desturctor Called--------------" << std::endl;
    delete w_animal;
    delete w_cat;
}
