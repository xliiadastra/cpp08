#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <numeric>

class   Span
{
private:
    unsigned int        N; // 넣을 배열의 size
    std::vector<int>    v; // capacity

public:
    Span();
    Span(unsigned int N);
    Span(const Span& orig);
    Span& operator=(const Span& orig);
    ~Span();
    void    addNumber(int n);

    template <typename Iter>
    void    addNumber(Iter begin, Iter end)
    {
        if (N < v.size() + end - begin) // N(size) < vector의 현재 capacity + 넣을 배열의 size -> 반복자 -연산으로써 구현가능.
            throw (NoSpaceException());
        v.insert(v.end(), begin, end); // 1. 넣을 iteraotr / 2. 넣을 시작 iterator / 3. 끝날(end-1) iterator
    }

    unsigned int    shortestSpan();
    unsigned int    longestSpan();

    class   NoSpanException : public std::exception {
        const char* what() const throw();
    };
    class   NoSpaceException : public std::exception {
        const char* what() const throw();
    };
};

#endif