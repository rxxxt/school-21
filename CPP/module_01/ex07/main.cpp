#include <iostream>
#include <fstream>
#include <string>

# define RED		"\033[0;31m"
# define BRED		"\033[1;31m"
# define UBRED		"\033[4;31m"
# define BURED		"\033[1;4;31m"
# define RESET		"\033[0m"

int main(int argc, char **argv) {
	if (argc == 4 && *argv[1] && *argv[2] && *argv[3]) {
		std::ifstream fin(argv[1]);
		if (fin.is_open()) {
			std::ofstream fout(std::string(argv[1]) + std::string(".replace"));
			if (fout.is_open()) {
				std::string	line;
				size_t		start = 0;
				while (fin.good()) {
					std::getline(fin, line);
					while (start < line.length()) {
						start = line.find(argv[2], start);
						line.replace(start, std::strlen(argv[2]), argv[3]);
						start += std::strlen(argv[3]);
					}
					fout << line << std::endl;
				}
				fout.close();
			} else
				std::cout << RED << "Failed to create file " << BURED << argv[1]<< ".replace" << std::endl;
			fin.close();
		} else
			std::cout << RED << "Couldn't open the file " << BURED << argv[1] << std::endl;
	} else
		std::cout << RED << "Invalid number of arguments!\n" << RESET;
	return (0);
}