#include <cstdio>
#include <stdlib.h>
#include <time.h>  
#include <iostream>
#include "Polinom.h"
using namespace std;
int main()
{
    int indexer = 0;
    int num;
    int *input;

    // Generate array and random point
    // scanf("%d",&num);
    // input = new int[num];
    // for (int i = 0; i < num; i++)
    // {
    //     input[i] = rand();
    //     cout<<input[i]<<endl;
    // }
    
    Polinom a(2,1);
    Polinom b(2,2);

    // a = a.bruteforce(b);
    // a.Print();
    Polinom * result = a.karatsubaMultiplication(b);
    result->Print();
    
    return 0;
}