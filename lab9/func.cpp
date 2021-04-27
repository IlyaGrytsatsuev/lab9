
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>

void input(int *size, int** k, int** p)
{
    int koeff;
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
    int* kf = (int*)malloc(*size*sizeof(int));
    if(kf == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *k = kf;

    int* power = (int*)malloc((*size - 1)*sizeof(int));
    if(power == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *p = power;
    if(degree == 0)
    {
        for(i = 0; i<*size; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
        }
    }

    if(degree > 0)
    {
        for(i = 0; i<*size; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
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
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
            degree ++ ;
        }
    }
}

void derivative(int* size, int* k, int* p, int** d)
{
    int i = 0;
    int der;
    int* der1 = (int*)malloc(*size*sizeof(int));
    
    if(der1 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *d = der1;
    if( p[0] == 0)
    {
        for (i = 0; i < *size; i++)
        {
            der = k[i]*p[i];
            der1[i] = der;
            k[i] = 0;
            p[i] = 0;
        }
    }
    if( p[0] > 0)
    {
        for (i = 0; i < *size; i++)
        {
            der = k[i]*p[i];
            der1[i] = der;
            k[i] = 0;
            p[i]-=1;
        }
    }
    if( p[0] < 0)
    {
        for (i = 0; i < *size; i++)
        {
            der = k[i]*p[i];
            der1[i] = der;
            k[i] = 0;
            p[i]-=1;
        }
    }
}

void multiply (int* p1, int* p2,int* size1, int* size2, int* d1, int* d2,int** r, int** po, int* c)
{
    int num = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    int* rez = (int*)malloc(*size1**size2*sizeof(int));
    
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
            pow[count] = p1[i]+p2[j];
            count ++;
            }
        }
    *c = count;
    }

void output(int* c,int* r, int* po )
{
    printf("\n");
    printf("Rezult:\n");
    for (int i = 0; i < *c; i++ )
    {
        if(i == 0)
        {
            if(r[i] == 0)
            {
                printf("%d", r[i]);
            }
            if (r[i] < 0)
            {
                printf(" %dx^%d", r[i], po[i]);
            }
            if (r[i] > 0)
            {
                printf("%dx^%d", r[i], po[i]);
            }
        }
        else
        {
            if(r[i] < 0)
            {
                printf(" %dx^%d", r[i], po[i]);
            }
            if (r[i] > 0)
            {
                printf(" + %dx^%d", r[i], po[i]);
            }
        }
    }
    printf("\n\n");
}
