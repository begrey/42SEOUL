#ifndef _MUTANTSTACK_HPP
#define _MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
        MutantStack& operator=(const MutantStack& origin);
		MutantStack();
		MutantStack(const MutantStack& origin);
		~MutantStack(void);

		// using iterator = typename std::stack<T>::container_type::iterator;
		// using const_iterator = typename std::stack<T>::container_type::const_iterator;
		// using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
		// using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

		typedef typename std::stack<T>::container_type::iterator iterator; 
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void);
		iterator end(void);
		const_iterator cbegin(void) const;
		const_iterator cend(void) const;
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_reverse_iterator crbegin(void) const;
		const_reverse_iterator crend(void) const;
};

#endif