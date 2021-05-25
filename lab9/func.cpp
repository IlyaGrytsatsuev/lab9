
#include <stdio.h>
#include <stdlib.h>
#include "func.hpp"

void derivative(float* k, int* p, float* d)
{
    int i = 0;
    int size = *p+1;
    
    d[0] = k[1];
    
    for (i = 2; i < size; i++)
    {
        d[i-1] = k[i]*(float)i;
    }
    
    *p-=1;
}

void multiply(float* d1, int p1, float* d2, int p2, float* r)
{
    p1+=1;
    p2+=1;

    for (int i=0; i < p1; i++)
    {
        for (int j=0; j < p2; j++)
        {
            r[i+j] += d1[i]*d2[j];
        }
    }

}


void output(float* r, int po)

{
    printf("\n");
    printf("Rezult:\n");
    
    for (int i = 0; i < po; i++ )
    {
        if(i == 0)
        {
            printf("%f", r[i]);
        }
        else
        {
            
            if(r[i] < 0)
            {
                printf("%fx^%d", r[i], i);
            }
            if (r[i] > 0)
            {
                printf(" + %fx^%d", r[i], i);
            }
        }
}
    printf("\n\n");
}
