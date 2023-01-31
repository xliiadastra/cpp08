#include "MutantStack.hpp"
#include <iostream>
#include <list>

void test()
{
    MutantStack<int> mstack;
    mstack.push(5); // push -> stack의 탑을 쌓듯이 원소를 넣는다.
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // 가장 top 에 있는 것을 호출.
    mstack.pop(); // pop -> stack의 탑을 위에서부터 원소를 하나씩 뺀다.
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
	mstack.push(42);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); // 5 3 5 737 42 0
    MutantStack<int>::iterator ite = mstack.end();
    ++it; // deque에 있는 iterator를 가져와서 사용했기 때문에 헤더에 정의되어 있는 ++ -- 도 사용할 수 있는지를 판단하기 위한 코드.
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void myTest()
{
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	std::cout << "list.top(): " << l.back() << std::endl;
	l.pop_back();
	std::cout << "list.size(): " << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(42);
	l.push_back(0);
	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	test();
	std::cout << '\n';
	myTest();
	return (0);
}