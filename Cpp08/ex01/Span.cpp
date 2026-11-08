#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _max(0) {}

Span::Span(unsigned int n) : _max(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span &other) : _max(other._max), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max = other._max;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _max)
		throw std::length_error("Span: already full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: need at least two numbers");
	std::vector<long> sorted(_numbers.begin(), _numbers.end());
	std::sort(sorted.begin(), sorted.end());
	std::vector<long> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
	return static_cast<unsigned int>(*std::min_element(diffs.begin() + 1, diffs.end()));
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: need at least two numbers");
	long min = *std::min_element(_numbers.begin(), _numbers.end());
	long max = *std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(max - min);
}
