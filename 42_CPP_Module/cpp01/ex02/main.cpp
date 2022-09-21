/*  ref 와 pointer의 차이점
    *** reference ***
    NULL로 초기화 하는것이 허용되지 않음
    주소값이 아닌 참조 대상 그대로 할당 (선언과 동시에 초기화를 해야 함)
    -> & . 등의 포인터 연산자 없이 그대로 접근 가능

    *** pointer ***
    NULL 초기화 가능, 안할 시 seg error OR null pointer Exception 발생
    &연산자를 통해 주소값을 할당
    -> & . 연산자를 통해 접근

    *** ref를 왜 쓸까? ***
    포인터를 잘못 사용했을 때 생기는 수많은 문제들을 최소화 하기 위해 많은 점을 제약한 상태
    보다 안정적인 call-by-reference 활용 가능

    *** C++ FAQ Say... ***
    Use references when you can, and pointers when you have to
    사용할 수 있다면 참조자를, 어쩔 수 없다면 포인터를 써라
*/
#include <iostream>
#include <string>
int main(void)
{
    std::string *stringPTR;
    std::string string = "HI THIS IS BRAIN";
    std::string &stringREF = string;
    stringPTR = &string;

    //display the address in memory of the string and using PTR REF
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "string address: " << &string << std::endl;
    std::cout << "address by using stringPTR: " << stringPTR << std::endl;
    std::cout << "address by using stringREF: " << &stringREF << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    //display the string using PTR and REF
    std::cout << "string using stringPTR: " << *stringPTR << std::endl;
    std::cout << "string using stringREF: " << stringREF << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

}