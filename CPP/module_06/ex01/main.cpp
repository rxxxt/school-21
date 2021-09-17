#include <iostream>

typedef struct	s_data {
	char	c;
	int		i;
	float	f;
	double	d;
}				Data;

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

void	print(Data* data) {
	std::cout << "data->c = " << data->c << std::endl;
	std::cout << "data->i = " << data->i << std::endl;
	std::cout << "data->f = " << data->f << std::endl;
	std::cout << "data->d = " << data->d << std::endl;
}

int main() {
	Data	data;
	data.c = 'a';
	data.i = 100500;
	data.f = 9.5f;
	data.d = 0.12345;
	print(&data);
	uintptr_t ser = serialize(&data);
	Data* deser = deserialize(ser);
	print(deser);
	return 0;
}
