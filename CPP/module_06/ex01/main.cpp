#include <iostream>

typedef struct	s_data {
	char	*str;
	int		number;
}				Data;

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
