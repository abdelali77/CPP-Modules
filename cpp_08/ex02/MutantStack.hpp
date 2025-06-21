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

class MutantStack : public std::stack<T, std::deque<T> > {
public:
	MutantStack( void ) { }
	MutantStack( const MutantStack& oth ) : std::stack<T>(oth) { (void)oth; }
	MutantStack& operator=( const MutantStack& oth ) {
		std::stack<T>::operator=(oth);
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	~MutantStack() { }
};

#endif