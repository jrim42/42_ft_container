#include "../include/ft_container.hpp"

bool fncomp (char lhs, char rhs)
{return lhs<rhs;}

struct classcomp {
bool operator() (const char& lhs, const char& rhs) const
{return lhs<rhs;}

};

template <class T, class V, class C>
void fillMap(NAMESPACE::map<T, V, C> &mp) {
        mp.insert(NAMESPACE::make_pair(16, 3));
        mp.insert(NAMESPACE::make_pair(8, 3));
        mp.insert(NAMESPACE::make_pair(23, 3));
        mp.insert(NAMESPACE::make_pair(7, 3));
        mp.insert(NAMESPACE::make_pair(19, 3));
        mp.insert(NAMESPACE::make_pair(29, 3));
        mp.insert(NAMESPACE::make_pair(41, 3));
        mp.insert(NAMESPACE::make_pair(4, 3));
        mp.insert(NAMESPACE::make_pair(11, 3));
}

void	test4_map(void)
{
	cout << REDD + "==========" + "constructor" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		NAMESPACE::map<char,int> second (first.begin(),first.end());

		NAMESPACE::map<char,int> third (second);

		NAMESPACE::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		NAMESPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		(void)fn_pt;
	}
	cout << REDD + "==========" + "begin, end" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	cout << REDD + "==========" + "rbegin, rend" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		NAMESPACE::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	cout << REDD + "==========" + "empty" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	cout << REDD + "==========" + "size" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		std::cout << "mymap.size() is " << mymap.size() << '\n';
	}
	cout << REDD + "==========" + "max_size" + "==========" + RESET << endl;
	{
		int i;
		NAMESPACE::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
				std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
	}
	cout << REDD + "==========" + "insert" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( NAMESPACE::pair<char,int>('a',100) );
		mymap.insert ( NAMESPACE::pair<char,int>('z',200) );

		NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( NAMESPACE::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		NAMESPACE::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		NAMESPACE::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	cout << REDD + "==========" + "erase" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	cout << REDD + "==========" + "swap" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	cout << REDD + "==========" + "clear" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "mymap contains:\n";
		for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "mymap contains:\n";
		for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	cout << REDD + "==========" + "key_comp" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		NAMESPACE::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
	}
	cout << REDD + "==========" + "value_comp" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element

		NAMESPACE::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	cout << REDD + "==========" + "find" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
		mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	cout << REDD + "==========" + "count" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
  }
	}
	cout << REDD + "==========" + "lower_bound, upper_bound" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	cout << REDD + "==========" + "equal_range" + "==========" + RESET << endl;
	{
		NAMESPACE::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	cout << REDD + "==========" + "get_allocator" + "==========" + RESET << endl;
	{
		int psize;
		NAMESPACE::map<char,int> mymap;
		NAMESPACE::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(NAMESPACE::map<char,int>::value_type)*5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}
	cout << REDD + "==========" + "operator" + "==========" + RESET << endl;
	{
		NAMESPACE::map<int, int> foo;
			for (int i = 0; i < 10; i++)
				foo[i] = (i * 4);
		NAMESPACE::map<int, int> bar;
			for (int i = 0; i < 10; i++)
				bar[i] = (i * 3);

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
			NAMESPACE::map<int, int> v;
			for (int i = 0; i < 10; i++)
				v[i] = (i * 4);
			// for (map<int>::const_iterator it = v.begin(); it != v.end(); ++it)
			NAMESPACE::map<int, int>::const_iterator it = v.begin();
			NAMESPACE::map<int, int>::const_iterator ite = v.end();
			while (it != ite){
					std::cout << it->second << std::endl;
					it++;
			}

			// test comparison of 2 iterators (const & non-const)
			NAMESPACE::map<int, char> a;
			for (int i = 0 ; i < 6; i ++)
					a[i] = (i + 'a');
			NAMESPACE::map<int, char>::iterator it1 = ++a.begin();
			NAMESPACE::map<int, char>::const_iterator cit = ++(++a.begin());
			std::cout << (it1 != cit) << std::endl;
		}
		{
			NAMESPACE::map<int, int> v;
			for (int i = 0; i < 10; i++)
				v[i] = (i * 4);
			std::string s = "0101010001111010101010101001010111101";
			for (unsigned int i = 0; i < s.size(); i++) {
				if (s[i] == '1')
					v[i] = (i);
				if (s[i] == '0')
					v.erase(--v.end());
			}

			// for (NAMESPACE::map<int, int>::const_iterator it = v.begin(); it != v.end(); ++it)
			NAMESPACE::map<int, int>::const_reverse_iterator it = v.rbegin();
			NAMESPACE::map<int, int>::const_reverse_iterator ite = v.rend();
			while (it != ite) {
				std::cout << it->second << std::endl;
				it++;
			}
		}
	}
	cout << REDD + "==========" + "compare" + "==========" + RESET << endl;
	{
		NAMESPACE::map<int, int> mp;
		NAMESPACE::vector<int> v;
		fillMap(mp);
		for (NAMESPACE::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::map<int, int, std::greater<int> > mp1;
		fillMap(mp1);
		v.push_back(mp1.begin()->first);
		mp1.erase(41);
		v.push_back(mp1.begin()->first);
		mp1.erase(29);
		v.push_back(mp1.begin()->first);
		NAMESPACE::map<int, int, std::greater<int> > mp2;
		mp2.insert(NAMESPACE::make_pair(3, 3));
		v.push_back(mp2.begin()->first);
		mp2.erase(3);
		if (mp2.begin() == mp2.end())
			v.push_back(1);
		NAMESPACE::map<int, int, std::plus<int> > mp3;
		fillMap(mp3);
		for (NAMESPACE::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::map<int, int, std::minus<int> > mp4;
		fillMap(mp4);
		for (NAMESPACE::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::map<int, int, std::greater_equal<int> > mp5;
		fillMap(mp5);
		for (NAMESPACE::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::map<int, int, std::multiplies<int> > mp6;
		fillMap(mp6);
		for (NAMESPACE::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::map<int, int, std::bit_xor<int> > mp7;
		fillMap(mp7);
		for (NAMESPACE::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
		NAMESPACE::map<int, int, std::logical_and<int> > mp8;
		fillMap(mp8);
		for (NAMESPACE::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
		for (NAMESPACE::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
		v.push_back(mp1.size());
		
		NAMESPACE::vector<int>::iterator it = v.begin();
		NAMESPACE::vector<int>::iterator ite = v.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			it++;
		}
	}
}