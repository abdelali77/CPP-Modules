#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <stack>
#include <deque>
#include <list>

// ************************************************************************** //
//                             MutantStack Class                              //
// ************************************************************************** //

template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container> {
public:
	MutantStack( void ) { }
	MutantStack( const MutantStack& oth ) { (void)oth; }
	MutantStack& operator=( const MutantStack& oth ) {
		std::stack<T, Container>::operator=(oth);
	}
	
	typedef typename Container::iterator iterator;
	iterator begin( ) { return this->c.begin(); }
	iterator end( ) { return this->c.end(); }
};

#endif