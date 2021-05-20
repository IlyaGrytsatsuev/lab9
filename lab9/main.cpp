#include <stdio.h>
#include <stdlib.h>
#include "func.hpp"

int main()
{
    int p1 = 0;
    int p2 = 0;
    int size1 = 0;
    int size2 = 0;
    int i = 0;

    printf("enter the power:\n");
    scanf("%d", &p1);
    size1 = p1+1;
    
    float* k1 = (float*)malloc(p1*sizeof(float));
    if(k1 == NULL)
    {
        printf("Error");
        exit(-1);
    }

    for(i = 0; i<size1; i++)
    {
        printf("enter the coefficient x^%d:\n", i);
        scanf("%f", &k1[i]);
    }
    

    printf("enter the power:\n");
    scanf("%d", &p2);
    
    size2 = p2+1;
    
    float* k2 = (float*)malloc(p2*sizeof(float));
    if(k2 == NULL)
    {
        printf("Error");
        exit(-1);
    }

    for(i = 0; i<size2; i++)
    {
        printf("enter the coefficient x^%d:\n", i);
        scanf("%f", &k2[i]);
    }

    float* d1 = (float*)malloc((p1-1)*sizeof(float));
    if(d1 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    
    float* d2 = (float*)malloc((p2-1)*sizeof(float));
    if(d2 == NULL)
    {
        printf("Error");
        exit(-1);
    }

    derivative(k1, &p1, d1);
    derivative(k2, &p2, d2);
    int po = (p1+1)+(p2+1)-1;
    float* r = (float*)malloc(((p1+1)+(p2+1)-1)*sizeof(float));
    
    if(r == NULL)
    {
        printf("Error");
        exit(-1);
    }
    multiply(d1, p1, d2, p2, r);
    output(r, po);
   
    return 0;

}

