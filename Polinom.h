#ifndef POLINOM_H
#define POLINOM_H


class Polinom 
{
    public:
        // Constructor, copy constructor, destructor, dan operasi assignment
        Polinom();
        Polinom(int * element, int size);
        Polinom(int degree);
        Polinom(int degree, int initElement);
        ~Polinom();
        Polinom(const Polinom& polinom);
        void setElement(int newElement, int index);
        Polinom& operator= (const Polinom& polinom);
        Polinom bruteforce(const Polinom& polinom);
        // Polinom divideandconquer(Polinom& a, Polinom& b, int size);
        int * divideandconquer(int * operand1, int * right, int size);
        int * sumElement(int * operand1, int * right, int size) ;
        int getElement(int index) const;
        int getDegree() const;
        Polinom& operator+(Polinom& polinom);
        void Print();
        int getRealSize() const;
        Polinom * multiplicationDivideandConquer(const Polinom & rPolynom);  
        float * fillElement(float * constants, int size);
        int setDegreeForm(int degree) const;
        int * fillElement(int * constants, int size);
        static int totalSum;
        static int totalMultiplication;
        static int totalSumDnC;
        static int totalMultiplicationDnC;

    private:
        int degree;
        int *element;
};

#endif