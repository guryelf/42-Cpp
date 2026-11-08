#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Span.hpp"

int main()
{
	std::cout << "--- subject test ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "--- full ---" << std::endl;
	try { sp.addNumber(1); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "--- empty / one ---" << std::endl;
	Span a(3);
	try { a.shortestSpan(); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	a.addNumber(42);
	try { a.longestSpan(); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "--- duplicates / negatives ---" << std::endl;
	Span b(4);
	b.addNumber(-10);
	b.addNumber(5);
	b.addNumber(5);
	b.addNumber(2147483647);
	std::cout << b.shortestSpan() << " " << b.longestSpan() << std::endl;

	std::cout << "--- 20000 numbers via range ---" << std::endl;
	std::srand(std::time(NULL));
	std::list<int> nums;
	for (int i = 0; i < 20000; i++)
		nums.push_back(i * 3);
	Span big(20000);
	big.addNumber(nums.begin(), nums.end());
	std::cout << big.shortestSpan() << " " << big.longestSpan() << std::endl;
	try { big.addNumber(nums.begin(), nums.begin()); big.addNumber(0); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "--- range too big ---" << std::endl;
	Span small(3);
	try { small.addNumber(nums.begin(), nums.end()); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "--- 100000 random ---" << std::endl;
	Span rnd(100000);
	for (int i = 0; i < 100000; i++)
		rnd.addNumber(std::rand());
	std::cout << rnd.shortestSpan() << " " << rnd.longestSpan() << std::endl;

	std::cout << "--- copy ---" << std::endl;
	Span c(sp);
	Span d(1);
	d = sp;
	std::cout << c.longestSpan() << " " << d.shortestSpan() << std::endl;
	return 0;
}
