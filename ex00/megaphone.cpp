#include <iostream>
#include <cctype>
#include <cstring>

int	main(int ac, char **av) {
	if (ac > 1) {
		for (int i = 1; i < ac ; i++) {
			char *str = av[i];
			for (size_t j = 0; j < std::strlen(str); j++) {
				if (std::isalpha(str[j]))
					str[j] = std::toupper(str[j]);
			}
			std::cout << str;
		}
		std::cout << std::endl;
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}