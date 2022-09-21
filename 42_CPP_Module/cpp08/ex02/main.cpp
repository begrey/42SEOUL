#include "mutantstack.hpp"
#include "mutantstack.cpp"

int main() {
    MutantStack<int> int_stack;

    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);

    std::cout << "top element : " << int_stack.top() << std::endl;
    int_stack.pop(); // delete 3
    int_stack.pop(); // delete 2

    std::cout << "top element : " << int_stack.top() << std::endl;
    std::cout << "stack size : " << int_stack.size() << std::endl;
    std::cout << "is empty? : " << int_stack.empty() << std::endl;
    int_stack.pop();
    std::cout << "is empty? : " << int_stack.empty() << std::endl;

    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    int_stack.push(4);
    int_stack.push(5);

    MutantStack<int>::iterator iter = int_stack.begin();
    while (iter != int_stack.end()) {
        std::cout << *iter << " ";
        iter++;
    }
    std::cout << std::endl;

    MutantStack<int>::reverse_iterator riter = int_stack.rbegin();
    while (riter != int_stack.rend()) {
        std::cout << *riter << " ";
        riter++;
    }
    std::cout << std::endl;

    MutantStack<const int> const_int_stack;
    const_int_stack.push(1);
    const_int_stack.push(2);
    const_int_stack.push(3);

    MutantStack<const int>::const_iterator const_iter = const_int_stack.cbegin();
    while (const_iter != const_int_stack.cend()) {
        std::cout << *const_iter << " ";
        const_iter++;
    }
    std::cout << std::endl;

        MutantStack<const int>::const_reverse_iterator const_reverse_iter = const_int_stack.crbegin();
    while (const_reverse_iter != const_int_stack.crend()) {
        std::cout << *const_reverse_iter << " ";
        const_reverse_iter++;
    }
    std::cout << std::endl;
}