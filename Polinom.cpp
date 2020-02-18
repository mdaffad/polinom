#include "Polinom.h"
#include <iostream>
using namespace std;

Polinom::Polinom(int degree)
{
    this->degree = degree;
    this->element = new int[degree];
}
Polinom::Polinom() : Polinom(10)
{

}
Polinom::~Polinom()
{
    delete this->element;
}
int Polinom::getElement(int index) const
{
    return this->element[index];
}
int Polinom::getDegree() const
{
    return this->degree;
}
Polinom::Polinom(const Polinom& polinom)
{
    this->degree = polinom.degree;
    this->element = new int[polinom.getDegree()];
    for(int i = 0; i < this->getDegree(); i++)
    {
        this->element[i] = polinom.getElement(i);
    }
}
void Polinom::setElement(int newElement, int index)
{
    this->element[index] = newElement;
}
Polinom& Polinom::operator= (const Polinom& polinom)
{

}
Polinom& Polinom::operator* (const Polinom& polinom, string method)
{

}
Polinom& Polinom::bruteforce(const Polinom& polinom)
{

}
Polinom& Polinom::divideandconquer(const Polinom& polinom)
{

}
