#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	wrong_animal() {
	const WrongAnimal*	wrongMeta	= new WrongAnimal();
	const WrongAnimal*	wrongCat	= new WrongCat();
	
	std::cout << wrongMeta->getType() << ": "; wrongMeta->makeSound();
	std::cout << wrongCat->getType() << ": "; wrongCat->makeSound();
	
	delete wrongMeta; delete wrongCat;
}

int	main( void ) {
	const Animal*	meta	= new Animal();
	const Animal*	j 		= new Dog();
	const Animal*	i		= new Cat();
	
	std::cout << j->getType() << ": "; j->makeSound();
	std::cout << i->getType() << ": "; i->makeSound();
	std::cout << meta->getType() << ": "; meta->makeSound();
	
	delete meta;delete i;delete j;
	
	// wrong_animal();
}