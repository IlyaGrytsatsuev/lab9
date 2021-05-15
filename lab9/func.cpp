
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>


void derivative(int size, float* k, int* p, float* d)
{
    int i = 0;
    int degree = *p;
    if(*p == 0)
    {
        for (i = 0; i < size; i++)
        {
            d[i] = k[i]*(float)degree;
        }
    }
    
    if(*p > 0)
    {
        *p = degree - 1;
        for (i = 0; i < size; i++)
        {
            d[i] = k[i]*(float)degree;
            degree --;
        }
    }
    
    if( *p < 0)
    {
        *p = degree - 1;
        for (i = 0; i < size; i++)
        {
            d[i] = k[i]*(float)degree;
            degree ++;
        }
    }
}

void multiply (int p1, int size1, float* d1, int p2, int size2, float* d2,float* r, int* po)
{
    int count = 0;
    int deg1 = p1;
    int deg2 = p2;
    int i = 0;
    int j = 0;
    
    
    for ( i = 0; i < size1; i++ )
    {
        for (j=0;j < size2; j++)
        {
            r[count] = d1[i]*d2[j];
            po[count] = deg1+deg2;
            if (deg2>0){
                deg2--;
            }
            if (deg2<0){
                deg2++;
            }
            count++;
        }
        if (p1>0)
        {
            deg1--;
        }
        if (deg1<0)
        {
            deg1++;
        }
        deg2 = p2;
        }
    }


void output(float* r, int* po, int size1, int size2)
{
    printf("\n");
    printf("Rezult:\n");
    
    for (int i = 0; i < size1*size2; i++ )
    {
        if(i == 0)
        {
            if(r[i] == 0)
            {
                printf("%f", r[i]);
            }
            if (r[i] < 0)
            {
                printf(" %fx^%d", r[i], po[i]);
            }
            if (r[i] > 0)
            {
                printf("%fx^%d", r[i], po[i]);
            }
        }
        else
        {
            if(r[i] < 0)
            {
                printf(" %fx^%d", r[i], po[i]);
            }
            if (r[i] > 0)
            {
                printf(" + %fx^%d", r[i], po[i]);
            }
        }
    }
    printf("\n\n");
}
