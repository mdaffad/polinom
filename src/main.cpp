#include <cstdio>
#include <stdlib.h>
#include <bits/stdc++.h>   
#include <iostream>
#include "Polinom.h"
#include <chrono> 
using namespace std;
int Polinom::totalSum;
int Polinom::totalMultiplication;
int Polinom::totalSumDnC;
int Polinom::totalMultiplicationDnC;
int main()
{
    int indexer = 0;
    int num;
    int *input;

    cin>>num;
    // Generate array and random point
    // The degree is always same and but 
    // the element (constant) is generated with random
    
    Polinom a(num);
    Polinom b(num);

    for (int i = 0; i <= num; i++)
    {
        a.setElement(rand(),i);
        b.setElement(rand(),i);
    }
    
    // Brute Force

    cout<< "Running Brute Force" << endl << endl;


    auto start = chrono::high_resolution_clock::now();    
    ios_base::sync_with_stdio(false); 

    // START

    Polinom resultBF = a.bruteforce(b);
    resultBF.Print();
    cout<<endl;
    cout<<"Total Multiplication Brute Force : "<< Polinom::totalMultiplication <<endl;
    cout<<endl;
    cout<<"Total Sum Brute Force : " << Polinom::totalSum<<endl;
    cout<<endl;
    
    // END

    auto end = chrono::high_resolution_clock::now(); 
  
    // Calculating total time taken by the program. 
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
    

    // convert as micro second
    time_taken *= 1e-3; 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " micro second" << endl; 
    cout<<endl<<endl<<endl;


    // Divide and Conquer

    cout<< "Running Divide and Conquer" << endl<<endl;

    //START

    auto start2 = chrono::high_resolution_clock::now();    
    ios_base::sync_with_stdio(false); 
  
    Polinom * resultDnC = a.multiplicationDivideandConquer(b);

    resultDnC->Print();
    cout<<endl;
    cout<<"Total Multiplication Divide and Conquer : "<< Polinom::totalMultiplicationDnC <<endl;
    cout<<endl;
    cout<<"Total Sum Divide and Conquer : " << Polinom::totalSumDnC<<endl;
    cout<<endl;

    //END
    auto end2 = chrono::high_resolution_clock::now(); 
  
    // Calculating total time taken by the program. 
    double time_taken2 =  
      chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    // convert as micro second
    time_taken2 *= 1e-3; 
    cout << "Time taken by program is : " << fixed  
         << time_taken2 << setprecision(9); 
    cout << " micro second" << endl; 
    return 0;
}