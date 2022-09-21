#ifndef _ARRAY_HPP
#define _ARRAY_HPP
#include <iostream>
#include <string>

template <typename T>
class Array {
    private :
        T *array;
        unsigned int n;
    public :
        Array() : array(new T[0]), n(0){}
        ~Array() { // ?  [0, 1 ,2 ,3 ,4]
            delete [] this->array;
        };
        Array(unsigned int n) : n(n) {
            array = new T[n];
            for (unsigned int i = 0; i < n; i++)
                array[i] = 0;
        }
        Array(const Array &origin){
            this->array = new T[origin.n];
            copy(this->array, origin, origin.n);
            this->n = origin.n;
        }
        Array& operator=(const Array &origin){
            this->array = new T[origin.n];
            copy(this->array, origin, origin.n);
            this->n = origin.n;
            return (*this);
        }
        T& operator[] (unsigned idx)
        {
            if(idx < 0 || idx >= n)
                throw IndexOutofBoundException();
            else
                return array[idx];
        }
        class IndexOutofBoundException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "Array index out of bound exception";
                }
        };
        int size() const {
            return this->n;
        }
        void copy(T *arr, const Array &origin, unsigned int n) {
            for (unsigned int i = 0; i < n; i++)
                arr[i] = origin.array[i];
        }
};

#endif