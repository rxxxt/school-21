#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>


class Span {

public:
	class StorageIsFull : public std::exception {

	public:
		const char * what() const throw();

	};

	class ThereIsNoSpan : public std::exception {

	public:
		const char * what() const throw();

	};

private:
	unsigned int maxSize_;
	std::vector<int> arr_;

public:
	explicit Span(unsigned int size);
	Span(const Span& other);
	Span &operator=(const Span& other);
	~Span();

	void addNumber(int number);
	void addNumbers(int count);
	int shortestSpan();
	int longestSpan();

private:
	Span();
	static bool greater(int a, int b);

};


#endif
