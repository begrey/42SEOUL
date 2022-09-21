#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& origin){
    this->c =origin.c;
}
template <typename T>
MutantStack<T>::~MutantStack(){
    return ;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& origin) {
    this->c = origin.c;
    //std::stack<t>::operator=(origin);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
    return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const {
    return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const {
    return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void) {
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void) {
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void) const {
    return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void) const {
    return (this->c.crend());
}