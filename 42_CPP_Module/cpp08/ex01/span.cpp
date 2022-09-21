#include "span.hpp"

Span::Span(){
    return;
}
Span::Span(unsigned int N) : N(N){
    return;
}
Span::~Span(){

}
Span::Span(const Span& origin){
    *this = origin;
}
Span& Span::operator=(const Span& origin){
    this->N = origin.N;
    this->ints.resize(origin.ints.size());
    std::copy(origin.ints.begin(), origin.ints.end(), this->ints.begin());
    return (*this);
}
std::vector<int> Span::getInts(){
    return this->ints;
}
unsigned int Span::getN(){
    return this->N;
}
void Span::addNumber(int num){
    if (this->ints.size() >= this->N)
        throw FullSpanException();
    this->ints.push_back(num);
}
void Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
    this->ints.assign(begin, end);
}
int Span::shortestSpan(){
    if (this->ints.size() < 2)
        throw NotEnoughSpanNumException();
    int smallest_span = *max_element(this->ints.begin(), this->ints.end());
    std::vector<int> temp;
    temp.resize(this->ints.size());
    std::copy(this->ints.begin(), this->ints.end(), temp.begin());
    sort(temp.begin(), temp.end());
    for (unsigned int i = 0; i < temp.size() - 1; i++) {
        if (temp[i + 1] - temp[i] <= smallest_span)
            smallest_span = temp[i + 1] - temp[i];
    }
    return smallest_span;
    
}
int Span::longestSpan(){
    if (this->ints.size() < 2)
        throw NotEnoughSpanNumException();
    int min = *min_element(this->ints.begin(), this->ints.end());
	int max = *max_element(this->ints.begin(), this->ints.end());
    return (max - min);
}
void Span::showAllElement(){
    for (unsigned int i = 0; i < this->ints.size(); i++) {
        std::cout << this->ints[i] << " ";
    }
    std::cout << std::endl;
}