#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

int	main( void ) {
	Animal* animals[20];
	int n = 2;

	for (int i = 0; i < n; i++) {
		if (i >= n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	Cat originalCat;

	originalCat.getBrain()->setIdeas("kl3z");
	std::cout << originalCat.getBrain()->getIdeas()[3] << std::endl;
	Cat copiedCat = originalCat;
	std::cout << copiedCat.getBrain()->getIdeas()[3] << std::endl;
	copiedCat.getBrain()->setIdeas("brrrrrtt");
	std::cout << copiedCat.getBrain()->getIdeas()[3] << std::endl;
	std::cout << originalCat.getBrain()->getIdeas()[3] << std::endl;

	for (int i = 0; i < n; i++) {
		delete animals[i];
	}
	return 0;
}