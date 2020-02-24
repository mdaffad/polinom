#include "Polinom.h"
#include <iostream>
using namespace std;

Polinom::Polinom(int degree)
{
    this->degree = degree;
    this->element = new int[this->getDegree() + 1];
}
Polinom::Polinom(int degree, int initElement)
{
    this->degree = degree ;
    this->element = new int[this->getDegree() + 1];
    for(int i = 0; i <= this-> degree; i++)
    {
        this->element[i] = initElement;
    }
}
Polinom::Polinom(int * element, int size)
{
    this->degree = size ;
    this->element = new int[this->getRealSize()];
    for(int i = 0; i <= this-> getDegree(); i++)
    {
        this->element[i] = element[i];
    }
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
int Polinom::getRealSize() const
{
    return this->degree + 1;
}
Polinom::Polinom(const Polinom& polinom)
{
    this->degree = polinom.degree;
    this->element = new int[polinom.getDegree()];
    for(int i = 0; i <= this->getDegree(); i++)
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
    this->degree = polinom.degree;
    for (int i = 0; i <= polinom.getDegree(); i++)
    {
        this->element[i] = polinom.getElement(i);
    }
    return *this;
}
Polinom Polinom::bruteforce(const Polinom& polinom)
{
    Polinom result(this->getDegree() + polinom.getDegree());
    if (this->getDegree() > polinom.getDegree())
    {
        for (int i = 0; i <= polinom.getDegree(); i++)
        {
            for (int j = 0; j <= this->getDegree(); j++)
            {
                result.setElement(result.getElement(i+j) + polinom.getElement(i) * this-> getElement(j), i+j);
            }
        }
    }
    else
    {
        for (int i = 0; i <= this->getDegree(); i++)
        {
            for (int j = 0; j <= polinom.getDegree(); j++)
            {
                result.setElement(result.getElement(i+j) + this-> getElement(i) * polinom.getElement(j), i+j);
            }
        }
    }
    
    return result;
}
Polinom * Polinom::karatsubaMultiplication(const Polinom & rPolynom)  
{

    if (this->getDegree() != rPolynom.getDegree()) {
        return nullptr;
    }

    int realSize = degreePowerOfTwo(this->getRealSize());

    int * left;
    int * right;
    int * result;
    if (realSize != this->getRealSize()) {
        left = fillElement(this->element, realSize);
        right = fillElement(rPolynom.element, realSize);


        result = divideandconquer(left, right, realSize);
 

        delete [] left;
        delete [] right;
    } else {
 
        result = divideandconquer(this->element, rPolynom.element, this->getRealSize());
  
    }


    return new Polinom(result, realSize);
}
int * Polinom::fillElement(int * constants, int size) {

    int rightDegree = degreePowerOfTwo(size-1);
    int * newConstants;

    if(rightDegree != size) {
        newConstants = new int[rightDegree];

        for(int i = 0; i < rightDegree; i++) {
            if(i < size) {
                newConstants[i] = constants[i];
            } else {
                newConstants[i] = 0;
            }
        }
    } else {
        newConstants = constants;
    }

    return newConstants;
}
int Polinom::degreePowerOfTwo(int degree) const {
    int power = 1;

    while(power < degree) {
        power *= 2;
    }
    return power;
}


int * Polinom::divideandconquer(int * left, int * right, int size)  {

    int resultSize = size * 2 + 1;

    int * result = new int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        result[i] = 0;
    }

    if (size == 1) {
        result[0] = left[0] * right[0];
        return result;
    }

    int halfSize = size/2;

    int * leftLowP = left;
    int * rightLowP = right;
    int * leftHighP = &left[halfSize];
    int * rightHighP = &right[halfSize];

    int * p0 = divideandconquer(leftLowP, rightLowP, halfSize);
    //memory leak for sumPolynomial
    int * p1 = divideandconquer(sumPolynomial(leftLowP, leftHighP, halfSize), sumPolynomial(rightLowP, rightHighP, halfSize), halfSize);
    int * p2 = divideandconquer(leftHighP, rightHighP, halfSize);

    for(int i = 0; i < size; i++) {
        result[i] += p0[i];
        result[i + size] += p2[i];
        result[i + halfSize] += p1[i] - p2[i] - p0[i];
    }

    delete [] p0;
    delete [] p1;
    delete [] p2;

    return result;

}
int * Polinom::sumPolynomial(int * left, int * right, int size)  
{

    int * result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = left[i] + right[i];
    }

    return result;
}
void Polinom::Print()
{
    for(int i = 0; i <= getDegree(); i++)
    {
        cout<<element[i]<< " " << i <<endl;
    }
}
