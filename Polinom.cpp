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
Polinom * Polinom::multiplicationDivideandConquer(const Polinom & polinom)  
{
    // fail if the degree not equal
    if (this->getDegree() != polinom.getDegree()) 
    {
        return nullptr;
    }

    int realSize = setDegreeForm(this->getRealSize());

    int * operand1;
    int * operand2;
    int * result;
    if (realSize != this->getRealSize()) 
    {
        operand1 = fillElement(this->element, realSize);
        operand2 = fillElement(polinom.element, realSize);
        result = divideandconquer(operand1, operand2, realSize);

        //destruct
        delete [] operand1;
        delete [] operand2;
    } 
    else 
    {
 
        result = divideandconquer(this->element, polinom.element, this->getRealSize());
  
    }
    return new Polinom(result, realSize);
}
int * Polinom::fillElement(int * element, int size) 
{
    int DegreeForm = setDegreeForm(size-1);
    // The divide and conquer use the half size degree hence we need setting up the degree in multiples of poewer 2
    int * newElement;

    if(DegreeForm != size) 
    {
        newElement = new int[DegreeForm];

        for(int i = 0; i < DegreeForm; i++) 
        {
            if(i < size) 
            {
                newElement[i] = element[i];
            } 
            else 
            {
                newElement[i] = 0;
            }
        }
    } 
    else // if it has the form of power 2 
    {
        newElement = element;
    }

    return newElement;
}
int Polinom::setDegreeForm(int degree) const 
{
    int power = 1;

    while(power < degree) 
    {
        power *= 2;
    }
    return power;
}


int * Polinom::divideandconquer(int * operand1, int * operand2, int size)  
{

    int resultSize = size * 2 + 1;

    int * result = new int[resultSize];
    for (int i = 0; i < resultSize; i++) 
    {
        result[i] = 0;
    }

    if (size == 1) 
    {
        result[0] = operand1[0] * operand2[0];
        return result;
    }

    int currentSize = size/2;

    int * operand1LowP = operand1;
    int * operand2LowP = operand2;
    int * operand1HighP = &operand1[currentSize];
    int * operand2HighP = &operand2[currentSize];

    // Use the same variable name in if2211 Strategi Algoritma : Algoritma Divide and Conquer (revisi 2020) p.134
    int * Y = divideandconquer(sumElement(operand1LowP, operand1HighP, currentSize), sumElement(operand2LowP, operand2HighP, currentSize), currentSize);
    int * U = divideandconquer(operand1LowP, operand2LowP, currentSize);
    // 
    int * Z = divideandconquer(operand1HighP, operand2HighP, currentSize);

    for(int i = 0; i < size; i++) 
    {
        result[i] += U[i];
        result[i + size] += Z[i];

        result[i + currentSize] += Y[i] - U[i] - Z[i];
    }
    return result;

}
int * Polinom::sumElement(int * operand1, int * operand2, int size)  
{

    int * result = new int[size];
    for (int i = 0; i < size; i++) 
    {
        result[i] = operand1[i] + operand2[i];
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
