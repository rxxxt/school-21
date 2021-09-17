#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename U>
void iter(T *arr, const U& length, void (*f)(const T&)) {
	for (U i = 0; i < length; ++i)
		f(arr[i]);
}

#endif
