
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>

void input(int *size1, int *size2, int** k, int** k2,int** p1,int** p2)
{
    int koeff;
    int num;
    int i = 0;
    int degree;
    printf("enter the power:\n");
    scanf("%d", &num);
    if(num == 0){
        *size1 = 1;
    }
    if(num > 0)
    {
        *size1 = num + 1 ;
    }
    if(num < 0)
    {
        *size1 = num*-1 + 1 ;
    }
    degree = num;
    int* kf = (int*)malloc(*size1*sizeof(int));
    if(kf == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *k = kf;

    int* power = (int*)malloc((*size1 - 1)*sizeof(int));
    if(power == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *p1 = power;
    if(degree == 0)
    {
        for(i = 0; i<*size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
        }
    }

    if(degree > 0)
    {
        for(i = 0; i<*size1; i++)
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
        for(i = 0; i<*size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
            degree ++ ;
        }
    }
    printf("enter the power:\n");
    scanf("%d", &num);
    if(num == 0)
    {
        *size2 = 1;
    }
    if(num > 0)
    {
        *size2 = num + 1 ;
    }
    if(num < 0)
    {
        *size2 = num*-1 + 1 ;
    }
    degree = num;
    int* kf2 = (int*)malloc(*size2*sizeof(int));
    if(kf2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *k2 = kf2;
    int* power2 = (int*)malloc((*size2 - 1)*sizeof(int));
    if(power2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *p2 = power2;
    if(degree == 0)
    {
        for(i = 0; i<*size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            kf2[i] = koeff ;
            power2[i] = degree;
        }
    }
    if(degree > 0)
    {
        for(i = 0; i<*size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            kf2[i] = koeff ;
            power2[i] = degree;
            degree -- ;
        }
    degree++;
    }
    if(degree < 0)
    {
        for(i = 0; i<*size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            kf2[i] = koeff ;
            power2[i] = degree;
            degree ++ ;
        }
    }
}

void derivative(int* size1, int* size2, int* k, int* p1, int* k2, int* p2, int** d1,int** d2)
{
    int i = 0;
    int der;
    int* der1 = (int*)malloc(*size1*sizeof(int));
    
    if(der1 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *d1 = der1;
    if( p1[0] == 0)
    {
        for (i = 0; i < *size1; i++)
        {
            der = k[i]*p1[i];
            der1[i] = der;
            k[i] = 0;
            p1[i] = 0;
        }
    }
    if( p1[0] > 0)
    {
        for (i = 0; i < *size1; i++)
        {
            der = k[i]*p1[i];
            der1[i] = der;
            k[i] = 0;
            p1[i]-=1;
        }
    }
    if( p1[0] < 0)
    {
        for (i = 0; i < *size1; i++)
        {
            der = k[i]*p1[i];
            der1[i] = der;
            k[i] = 0;
            p1[i]-=1;
        }
    }
    int* der2 = (int*)malloc(*size2*sizeof(int));
    if(der2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    *d2 = der2;
    if(p2[0] == 0)
    {
        for (i = 0; i < *size2; i++)
        {
            der = k2[i]*p2[i];
            der2[i] = der;
            k2[i] = 0;
            p2[i]=0;
        }
    }
    if(p2[0] > 0)
    {
        for (i = 0; i < *size2; i++)
        {
            der = k2[i]*p2[i];
            der2[i] = der;
            k2[i] = 0;
            p2[i]-=1;
        }
    }
    if(p2[0] < 0)
    {
        for (i = 0; i < *size2; i++)
        {
            der = k2[i]*p2[i];
            der2[i] = der;
            k2[i] = 0;
            p2[i]-=1;
        }
    }
}

void multiply (int* p1, int* p2,int* size1, int* size2, int* d1, int* d2)
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
    
    int* pow = (int*)malloc(*size1**size2*sizeof(int));
    
    if(pow == NULL)
    {
        printf("Error");
        exit(-1);
    }
    printf(" rezult:\n");
    for ( i = 0; i < *size1; i++ )
    {
        for (j=0;j < *size2; j++)
        {
            num = d1[i]*d2[j];
            rez[count] = num;
            pow[count] = p1[i]+p2[j];
            if(count == 0)
            {
                if(rez[count] == 0)
                {
                    printf("%d", rez[count]);
                }
                    if (rez[count] < 0)
                    {
                        printf(" %dx^%d", rez[count], pow[count]);
                    }
                    if (rez[count] > 0)
                    {
                        printf("%dx^%d", rez[count], pow[count]);
                    }
            }
                else
                {
                    if(rez[count] < 0)
                    {
                        printf(" %dx^%d", rez[count], pow[count]);
                    }
                    if (rez[count] > 0)
                    {
                        printf(" + %dx^%d", rez[count], pow[count]);
                    }
                }
            count ++;
            }
        }
    printf("\n");
    free(pow);
    free(rez);
    return;
    }
