#include "Span.hpp"

const char * Span::StorageIsFull::what() const throw() {
	return "The storage is full";
}

const char * Span::ThereIsNoSpan::what() const throw() {
	return "There is no span";
}

Span::Span() {}

Span::Span(unsigned int size) :
		maxSize_(size) {}

Span::Span(const Span& other) :
		maxSize_(other.maxSize_) {
	std::vector<int>::const_iterator it = other.arr_.cbegin();
	std::vector<int>::const_iterator ite = other.arr_.cend();
	while (it != ite) {
		arr_.push_back(*it);
		++it;
	}
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		maxSize_ = other.maxSize_;
		arr_.clear();
		std::vector<int>::const_iterator it = other.arr_.cbegin();
		std::vector<int>::const_iterator ite = other.arr_.cend();
		while (it != ite) {
			arr_.push_back(*it);
			++it;
		}
	}
	return *this;
}

Span::~Span() {
	arr_.clear();
}

bool Span::greater(int a, int b) {
	return (a > b);
}

void Span::addNumber(int number) {
	if (arr_.size() == maxSize_)
		throw StorageIsFull();
	arr_.push_back(number);
}

void Span::addNumbers(int count) {
	std::srand(time(NULL));
	for (int i = 0; i < count; ++i)
		arr_.push_back(rand() % (count * 2));
}

int Span::shortestSpan() {
	if (arr_.size() < 2)
		throw ThereIsNoSpan();
	std::vector<int> copyArr(arr_);
	std::sort(copyArr.begin(), copyArr.end(), greater);
	std::vector<int>::const_iterator it = copyArr.begin();
	std::vector<int>::const_iterator ite = copyArr.end();
	int shortestSpan = *it;
	int span;
	while (it + 1 != ite) {
		span = *it - *(it + 1);
		if (span < shortestSpan)
			shortestSpan = span;
		++it;
	}
	return shortestSpan;
}

int Span::longestSpan() {
	if (arr_.size() < 2)
		throw ThereIsNoSpan();
	return *max_element(arr_.begin(), arr_.end()) - *min_element(arr_.begin(), arr_.end());
}
