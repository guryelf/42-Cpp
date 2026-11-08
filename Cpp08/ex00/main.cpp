#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
static void test(const char *name, T &c, int value)
{
	try
	{
		typename T::iterator it = easyfind(c, value);
		std::cout << name << ": found " << *it << " at index "
			<< std::distance(c.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << ": " << e.what() << " (" << value << ")" << std::endl;
	}
}

int main()
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i * 2);
		l.push_back(i * 2);
		d.push_back(i * 2);
	}
	test("vector", v, 8);
	test("vector", v, 7);
	test("list  ", l, 0);
	test("list  ", l, 18);
	test("list  ", l, 19);
	test("deque ", d, 4);
	test("deque ", d, -1);

	const std::vector<int> cv(v);
	try
	{
		std::cout << "const vector: found " << *easyfind(cv, 6) << std::endl;
		easyfind(cv, 1);
	}
	catch (const std::exception &e)
	{
		std::cout << "const vector: " << e.what() << std::endl;
	}

	std::vector<int> empty;
	test("empty ", empty, 1);
	return 0;
}
