#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {

public:
	class OutOfTheLimits : public std::exception {

	public:
		const char *what() const throw() {
			return ("This element is out of the limits");
		};

	};

private:
	T* arr_;
	unsigned int size_;

public:
	Array<T>() :
			arr_(new T[0]),
			size_(0) {}

	Array<T>(unsigned int n) :
			arr_(new T[n]),
			size_(n) {
		for (unsigned int i = 0; i < size_; ++i)
			arr_[i] = 0;
	}

	Array<T>(const Array<T>& other) :
			arr_(new T[other.size_]),
			size_(other.size_) {
		for (unsigned int i = 0; i < size_; ++i)
			arr_[i] = other.arr_[i];
	}

	Array<T>& operator=(const Array<T>& other) {
		if (this != &other) {
			delete [] arr_;
			size_ = other.size_;
			arr_ = new T[size_];
			for (unsigned int i = 0; i < size_; ++i)
				arr_[i] = other.arr_[i];
		}
		return *this;
	};

	T& operator[](unsigned int i) {
		if (i >= size_)
			throw OutOfTheLimits();
		return arr_[i];
	}

	~Array<T>() {
		delete [] arr_;
	};

	unsigned int size() const {
		return size_;
	};

};

#endif
