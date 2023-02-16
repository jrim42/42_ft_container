#include "../include/ft_container.hpp"

void	test3_stack(void)
{
	cout << REDD + "==========" + "constructor" + "==========" + RESET << endl;
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		NAMESPACE::vector<int> myvector (2,200);        // vector with 2 elements

		NAMESPACE::stack<int> first;                    // empty stack
		NAMESPACE::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

		NAMESPACE::stack<int,NAMESPACE::vector<int> > third;  // empty stack using vector
		NAMESPACE::stack<int,NAMESPACE::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	cout << REDD + "==========" + "empty" + "==========" + RESET << endl;
	{
		NAMESPACE::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	cout << REDD + "==========" + "size" + "==========" + RESET << endl;
	{
		NAMESPACE::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	cout << REDD + "==========" + "top" + "==========" + RESET << endl;
	{
		NAMESPACE::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	cout << REDD + "==========" + "push" + "==========" + RESET << endl;
	{
		NAMESPACE::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	cout << REDD + "==========" + "pop" + "==========" + RESET << endl;
	{
		NAMESPACE::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	cout << REDD + "==========" + "operator" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> foo1 (3,100);   // three ints with a value of 100
		NAMESPACE::vector<int> bar1 (2,200);   // two ints with a value of 200

		NAMESPACE::stack<int, NAMESPACE::vector<int> > foo (foo1);
		NAMESPACE::stack<int, NAMESPACE::vector<int> > bar (bar1);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
}