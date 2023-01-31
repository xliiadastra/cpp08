#include "Span.hpp"

Span::Span()
{
    this->N = 10;
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::Span(const Span& orig)
{
    this->N = orig.N;
    this->v = orig.v;
}

Span& Span::operator=(const Span& orig)
{
    if (this != & orig)
    {
        this->N = orig.N;
        this->v = orig.v;
    }
    return (*this);
}

Span::~Span()
{
}

void    Span::addNumber(int n)
{
    if (N == v.size()) // 
        throw (NoSpaceException());
    v.push_back(n);
}

unsigned int    Span::shortestSpan()
{
    if (v.size() < 2)
        throw (NoSpanException());
    std::vector<int> tmp = v;
    
    std::sort(tmp.begin(), tmp.end());
    std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
    return (*std::min_element(tmp.begin() + 1, tmp.end()));
}

unsigned int    Span::longestSpan()
{
    if (v.size() < 2)
        throw (NoSpanException());
//    std::vector<int> tmp = v;
    
//    std::sort(tmp.begin(), tmp.end());
	return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()));
}

const char* Span::NoSpanException::what() const throw()
{
    return ("No Span Exception\n");
}

const char* Span::NoSpaceException::what() const throw()
{
    return ("No Space Exception\n");
}
