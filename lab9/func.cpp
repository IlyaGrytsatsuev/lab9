
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>

void input(int *size, float** k, int* p)
{
    float koeff;
    int num;
    int i = 0;
    int degree;
    printf("enter the power:\n");
    scanf("%d", &num);
    if(num == 0){
        *size = 1;
    }
    if(num > 0)
    {
        *size = num + 1 ;
    }
    if(num < 0)
    {
        *size = num*-1 + 1 ;
    }
    degree = num;
    *p = degree;
    float* kf = (float*)malloc(*size*sizeof(float));
    if(kf == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *k = kf;

   
    if(degree == 0)
    {
        for(i = 0; i<*size; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%f", &koeff);
            kf[i] = koeff;
        }
    }

    if(degree > 0)
    {
        for(i = 0; i<*size; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%f", &koeff);
            kf[i] = koeff;
            degree -- ;
        }
        degree++;
    }

    if(degree < 0)
    {
        for(i = 0; i<*size; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%f", &koeff);
            kf[i] = koeff;
            degree ++ ;
        }
    }
}

void derivative(int* size, float* k, int* p, float** d)
{
    int i = 0;
    float der;
    float* der1 = (float*)malloc(*size*sizeof(float));
    int degree = *p;
    
    if(der1 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *d = der1;
    if(*p == 0)
    {
        for (i = 0; i < *size; i++)
        {
            der = k[i]*(float)degree;
            der1[i] = der;
        }
    }
    if(*p > 0)
    {
        *p = degree - 1;
        for (i = 0; i < *size; i++)
        {
            der = k[i]*(float)degree;
            der1[i] = der;
            degree --;
        }
    }
    if( *p < 0)
    {
        *p = degree - 1;
        for (i = 0; i < *size; i++)
        {
            der = k[i]*(float)degree;
            der1[i] = der;
            degree ++;
        }
    }
}
void multiply (int* p1,int* size1, float* d1, int* p2, int* size2, float* d2,float** r, int** po)
{
    float num = 0;
    int count = 0;
    int deg1 = *p1;
    int deg2 = *p2;
    int i = 0;
    int j = 0;
    float* rez = (float*)malloc(*size1**size2*sizeof(float));
    
    if(rez == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *r = rez;
    int* pow = (int*)malloc(*size1**size2*sizeof(int));
    
    if(pow == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *po = pow;
    
    for ( i = 0; i < *size1; i++ )
    {
        for (j=0;j < *size2; j++)
        {
            num = d1[i]*d2[j];
            rez[count] = num;
            pow[count] = deg1+deg2;
            if (deg2>0){
                deg2--;
            }
            if (deg2<0){
                deg2++;
            }
            count++;
        }
        if (deg1>0)
        {
            deg1--;
        }
        if (deg1<0)
        {
            deg1++;
        }
        deg2 = *p2;
        }
    }


void output(float* r, int* po, int* size1, int* size2)
{
    printf("\n");
    printf("Rezult:\n");
    for (int i = 0; i < *size1**size2; i++ )
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
