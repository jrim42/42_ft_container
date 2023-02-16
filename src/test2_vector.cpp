#include "../include/ft_container.hpp"
#include <sys/time.h>

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string WHITE = "\x1B[1;39m";
const std::string RESET = "\033[0m";

using std::cout;
using std::endl;

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#define NAMESPACE std
    #define TYPE "std"
#else
	#include "../include/map.hpp"
	#include "../include/stack.hpp"
	#include "../include/vector.hpp"
	#define NAMESPACE ft
    #define TYPE "ft"
#endif

void	test2_vector(void)
{
	cout << REDD + "==========" + "constructor" + "==========" + RESET << endl;
	{
		// constructors used in the same order as described above:
		NAMESPACE::vector<int> first;                                // empty vector of ints
		NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
		NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
		NAMESPACE::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		NAMESPACE::vector<int> fiNAMESPACEh (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fiNAMESPACEh are:";
		for (NAMESPACE::vector<int>::iterator it = fiNAMESPACEh.begin(); it != fiNAMESPACEh.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "begin" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (NAMESPACE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "end" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (NAMESPACE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "rbegin" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "rend" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

		NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();

		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "size" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		int val = 100;
		myints.insert (myints.end(),10,val);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}
	cout << REDD + "==========" + "max_size" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}
	cout << REDD + "==========" + "resize" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (unsigned long i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	cout << REDD + "==========" + "capacity" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	cout << REDD + "==========" + "empty" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	cout << REDD + "==========" + "reserve" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	cout << REDD + "==========" + "at" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}
	cout << REDD + "==========" + "front" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	cout << REDD + "==========" + "back" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	cout << REDD + "==========" + "assign" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> first;
		NAMESPACE::vector<int> second;
		NAMESPACE::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		NAMESPACE::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	cout << REDD + "==========" + "push_back" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;
		for (int i = 0; i < 42; ++i)
			myvector.push_back (i);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}
	cout << REDD + "==========" + "pop_back" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		std::cout << "The elements of myvector add up to " << sum << '\n';
	}
	cout << REDD + "==========" + "insert" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector (3,100);
		NAMESPACE::vector<int>::iterator it;

		int val = 300;
		it = myvector.begin();
		val = 200;
		it = myvector.insert ( it , val );
		myvector.insert (it,2,val);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		NAMESPACE::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "erase" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	cout << REDD + "==========" + "swap" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
		NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (NAMESPACE::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (NAMESPACE::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	cout << REDD + "==========" + "clear" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	cout << REDD + "==========" + "operator" + "==========" + RESET << endl;
	{
		NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
		NAMESPACE::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	cout << REDD + "==========" + "iterator" + "==========" + RESET << endl;
	{
		{
			NAMESPACE::vector<int> v;
			for (int i = 0; i < 10; i++)
					v.push_back(i * 4);

			// for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
			NAMESPACE::vector<int>::const_iterator it = v.begin();
			NAMESPACE::vector<int>::const_iterator ite = v.end();
			while (it != ite){
					std::cout << *it << std::endl;
					it++;
			}

			// test comparison of 2 iterators (const & non-const)
			NAMESPACE::vector<char> a;
			for (int i = 0 ; i < 6; i ++)
					a.push_back(i + 'a');
			NAMESPACE::vector<char>::iterator it1 = a.begin() + 1;
			NAMESPACE::vector<char>::const_iterator cit = a.begin() + 2;
			std::cout << (it1 != cit) << std::endl;
			std::cout << (it1 > cit) << std::endl;
		}
		{
			NAMESPACE::vector<int> v;
			for (int i = 0; i < 10; i++)
				v.push_back(i * 4);

			std::string s = "0101010001111010101010101001010111101";
			for (unsigned int i = 0; i < s.size(); i++) {
				if (s[i] == '1')
						v.push_back(i);
				if (s[i] == '0')
						v.pop_back();
			}

			// for (NAMESPACE::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
			NAMESPACE::vector<int>::const_reverse_iterator it = v.rbegin();
			NAMESPACE::vector<int>::const_reverse_iterator ite = v.rend();
			while (it != ite) {
				std::cout << (*(it)) << std::endl;
				it++;
			}
		}
	}
}