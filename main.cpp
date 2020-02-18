#include <cstdio>
#include <stdlib.h>
#include <time.h>  
#include <iostream>
using namespace std;
int main()
{
    int indexer = 0;
    int num;
    int *input;

    // Generate array and random point
    scanf("%d",&num);
    input = new int[num];
    for (int i = 0; i < num; i++)
    {
        input[i] = rand();
        cout<<input[i]<<endl;
    }
    
    return 0;
}