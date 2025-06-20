#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <stack>
#include <deque>
#include <list>

// ************************************************************************** //
//                             MutantStack Class                              //
// ************************************************************************** //

template <typename T>

class MutantStack : public std::stack<T> {
public:
	MutantStack( void ) { }
	MutantStack( const MutantStack& oth ) { (void)oth; }
	MutantStack& operator=( const MutantStack& oth ) {
		std::stack<T>::operator=(oth);
	}
	typedef typename std::deque<T>::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	~MutantStack() { }
};

#endif