#include "replacer.hpp"

int	main( int ac, char **av ) {
	if (ac == 4) {
		std::string	s1 = av[2];
		std::string s2 = av[3];
		std::ifstream    srcFile(av[1]);
		if (srcFile.fail()) {
			std::cerr << "Error opening file " << av[1] << std::endl;
			return 1;
		}
		std::ofstream	dstFile;
		std::string		replace_file = av[1];
		replace_file.append(".replace");
		dstFile.open(replace_file);
		std::string content;
		std::string word;
		std::string line;
		// bool	firstWord = true;
		while (std::getline(srcFile, line)) {
			size_t i = 0;
			while (i < line.length()) {
				std::string tmp;
				tmp = line.substr(i, s1.length());
				std::cout << tmp << std::endl;
				std::cout << s1 << std::endl;
				if (tmp == s1) {
					content += s2;
					i += s1.length() - 1;
				} else {
					content += line[i];
				}
				i++;
			}
			content.append("\n");
		}
		dstFile << content;
	} else {
		std::cout << "Usage [filename] [s1] [s2]" << std::endl;
	}

	return 0;
}
