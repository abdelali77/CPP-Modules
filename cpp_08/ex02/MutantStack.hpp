#ifndef __MUTANSTACK_HPP__
#define __MUTANSTACK_HPP__

#include <iostream>
#include <stack>
#include <deque>

// ************************************************************************** //
//                             MutantStack Class                              //
// ************************************************************************** //

template <typename T, typename Container = std::deque<T> >

class MutanStack : public std::stack<T> {
public:
	MutanStack( void ) { }
	MutanStack( const MutanStack& oth ) { (void)oth; }
	MutanStack& operator=( const MutanStack& oth ) { (void)oth; return *this; }
	
	
};

#endif