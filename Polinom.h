#ifndef POLINOM_H
#define POLINOM_H


class Polinom 
{
    public:
        // Constructor, copy constructor, destructor, dan operasi assignment
        Polinom();
        Polinom(int degree);
        ~Polinom();
        Polinom(const Polinom& polinom);
        void setElement(int newElement, int index);
        Polinom& operator= (const Polinom& polinom);
        Polinom& operator* (const Polinom& polinom, string method);
        Polinom& bruteforce(const Polinom& polinom);
        Polinom& divideandconquer(const Polinom& polinom);
        int getElement(int index) const;
        int getDegree() const;

    private:
        int degree;
        int *element;


};

#endif