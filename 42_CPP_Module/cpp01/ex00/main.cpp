#include "Zombie.hpp"
//생성자 및 객체에 대해서!
//new 연산자를 사용하여 포인터로 받아온 객체는 힙 영역에 들어가 있다. 함수 밖에서도 메모리 유지
//단순히 Zombie z(); 과 같이 객체를 호출하면 스택 영역에 들어가 있음!

//소멸자에 대해서!
//스택 영역에 저장된 객체는 main함수가 끝나기 전 자동적으로 소멸자를 호출한다.
//단, 힙 영역에 저장된 객체는 delete를 명시적으로 사용하여 소멸자를 호출해야한다.
int main(void)
{
    Zombie *zombie_heap = NULL;
    Zombie zombie_stack;

    zombie_heap = zombie_heap->newZombie("jimkwon");
    zombie_heap->announce();
    zombie_stack.randomChump("42SEOUL");
    //명시적으로 삭제하지 않을 시, 힙 영역에 저장된 zombie_heap의 소멸자가 호출되지 않는다!
    delete zombie_heap;
}