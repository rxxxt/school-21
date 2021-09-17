#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
//	std::cout << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;
//	std::cout << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int> mstack1(mstack);
	MutantStack<int>::iterator it = mstack1.begin();
	MutantStack<int>::iterator ite = mstack1.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	MutantStack<int> mstack11;
	mstack11 = mstack;
	MutantStack<int>::iterator it1 = mstack11.begin();
	MutantStack<int>::iterator ite1 = mstack11.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}

	std::stack<int> s(mstack);
	return 0;
}
