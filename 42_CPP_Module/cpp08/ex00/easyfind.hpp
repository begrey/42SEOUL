#ifndef _EASYFIND_HPP
#define _EASYFIND_HPP
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class NoSuchElement : public std::exception
{
    public:
        const char * what() const throw()
        {
            return "There is no such element.";
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int N){
    typename T::iterator iter;
    iter = std::find(container.begin(), container.end(), N);
    if (iter == container.end())
        throw NoSuchElement();
    else
        return iter;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int N){
    typename T::const_iterator iter;
    iter = std::find(container.begin(), container.end(), N);
    if (iter == container.end())
        throw NoSuchElement();
    else
        return iter;
}


#endif