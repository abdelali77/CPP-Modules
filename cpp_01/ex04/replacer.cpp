#include "replacer.hpp"

void	replaceString(std::string s1, std::string s2, char **av) {
	std::ifstream    srcFile(av[1]);
	if (srcFile.fail()) {
		std::cerr << "Error opening file " << av[1] << std::endl;
		exit(1);
	}
	std::ofstream	dstFile;
	std::string		replace_file = av[1];
	replace_file.append(".replace");
	dstFile.open(replace_file);
	std::string content;
	std::string line;
	while (std::getline(srcFile, line)) {
		size_t i = 0;
		while (i < line.length()) {
			std::string tmp;
			tmp = line.substr(i, s1.length());
			if (tmp == s1) {
				content.append(s2);
				i += s1.length();
			} else {
				content += line[i];
				i++;
			}
		}
		content.append("\n");
	}
	dstFile << content;
}