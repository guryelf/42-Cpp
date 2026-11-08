#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
private:
	unsigned int		_max;
	std::vector<int>	_numbers;

	Span();

public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addNumber(Iterator first, Iterator last)
	{
		if (_numbers.size() + std::distance(first, last) > _max)
			throw std::length_error("Span: not enough room for range");
		_numbers.insert(_numbers.end(), first, last);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif
