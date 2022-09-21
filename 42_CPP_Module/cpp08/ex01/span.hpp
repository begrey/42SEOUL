#ifndef _SPAN_HPP
#define _SPAN_HPP
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

class Span {
    private :
        std::vector<int> ints;
        unsigned int N;
        Span();
    public :
        Span(unsigned int N);
        ~Span();
        Span(const Span& origin);
        Span& operator=(const Span& origin);
        std::vector<int> getInts();
        unsigned int getN();
        void addNumber(int num);
        void addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        void showAllElement();

        class FullSpanException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "The Span is Full";
                }
        };

        class NotEnoughSpanNumException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "Not Enough Span Number";
                }
        };
};

#endif