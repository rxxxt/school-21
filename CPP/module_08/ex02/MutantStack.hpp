#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>


template<typename T>
class MutantStack : public std::stack<T> {

public:
	typedef typename std::stack<T>::container_type::iterator iterator;

public:
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack& other) : std::stack<T>(other) {};
	MutantStack &operator=(MutantStack& other) {
		if (this != &other) {
			for (int i = 0; i < (int)this->size(); ++i)
				this->pop();
			iterator it = other.begin();
			iterator ite = other.end();
			while (it != ite) {
				this->push(*it);
				++it;
			}
		}
		return *this;
	};
	~MutantStack() {};

	iterator begin() { return std::stack<T>::c.begin(); };
	iterator end() { return std::stack<T>::c.end(); };

};


#endif
