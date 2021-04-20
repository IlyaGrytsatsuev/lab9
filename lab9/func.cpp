
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>

void input()
{
    int koeff;
    int num;
    int i = 0;
    int size1 = 0;
    int size2 = 0;
    int degree;

    printf("enter the power:\n");
    scanf("%d", &num);
    if(num == 0){
        size1 = 1;
    }
    if(num > 0)
    {
        size1 = num + 1 ;
    }
    if(num < 0)
    {
        size1 = num*-1 + 1 ;
    }
    degree = num;
    int* kf = (int*)malloc(size1*sizeof(int));
    if(kf == NULL)
    {
        printf("Error");
        exit(-1);
    }

    int* power = (int*)malloc((size1 - 1)*sizeof(int));
    if(power == NULL)
    {
        printf("Error");
        exit(-1);
    }

    if(degree == 0)
    {
        for(i = 0; i<size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
            //printf ("power = %d", power [i]);
            //printf ("kf = %d\n", kf [i]);
        }
    }

    if(degree > 0)
    {
        for(i = 0; i<size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
            //printf ("power = %d", power [i]);
            //printf ("kf = %d\n", kf [i]);
            degree -- ;
        }
        degree++;
    }

    if(degree < 0)
    {
        for(i = 0; i<size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            power[i] = degree;
            kf[i] = koeff;
            //printf ("power = %d", power [i]);
            //printf ("kf = %d\n", kf [i]);
            degree ++ ;
        }
    }
    printf("enter the power:\n");
    scanf("%d", &num);
    if(num == 0)
    {
        size2 = 1;
    }
    if(num > 0)
    {
        size2 = num + 1 ;
    }
    if(num < 0)
    {
        size2 = num*-1 + 1 ;
    }
    degree = num;
    int* kf2 = (int*)malloc(size2*sizeof(int));
    if(kf2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    int* power2 = (int*)malloc((size2 - 1)*sizeof(int));
    if(power2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    if(degree == 0)
    {
        for(i = 0; i<size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            kf2[i] = koeff ;
            power2[i] = degree;
            //printf ("power2 = %d", power2 [i]);
            //printf ("kf2 = %d\n", kf2 [i]);
        }
    }
    if(degree > 0)
    {
        for(i = 0; i<size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            kf2[i] = koeff ;
            power2[i] = degree;
            //printf ("power2 = %d", power2 [i]);
            //printf ("kf2 = %d\n", kf2 [i]);
            degree -- ;
        }
    degree++;
    }
    if(degree < 0)
    {
        for(i = 0; i<size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree);
            scanf("%d", &koeff);
            kf2[i] = koeff ;
            power2[i] = degree;
            //printf ("power2 = %d", power2 [i]);
            //printf ("kf2 = %d\n", kf2 [i]);
            degree ++ ;
        }
    }
    derivative (size1, size2, kf, power, kf2, power2);
    free(kf);
    free(power);
    free(kf2);
    free(power2);
}

void derivative(int size1, int size2, int* kf, int* power, int* kf2, int* power2)
{
    int i = 0;
    int der;
    int* der1 = (int*)malloc(size1*sizeof(int));
    
    if(der1 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    if( power[0] == 0)
    {
        for (i = 0; i < size1; i++)
        {
            der = kf[i]*power[i];
            der1[i] = der;
            kf[i] = 0;
            power[i] = 0;
            //printf(" der1 = %d\n", der1 [i]);
        }
    }
    if( power[0] > 0)
    {
        for (i = 0; i < size1; i++)
        {
            der = kf[i]*power[i];
            der1[i] = der;
            kf[i] = 0;
            power[i]-=1;
            //printf(" der1 = %d\n", der1 [i]);
        }
    }
    if( power[0] < 0)
    {
        for (i = 0; i < size1; i++)
        {
            der = kf[i]*power[i];
            der1[i] = der;
            kf[i] = 0;
            power[i]-=1;
            //printf(" der1 = %d\n", der1 [i]);
        }
    }
    int* der2 = (int*)malloc(size2*sizeof(int));
    if(der2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    if(power2[0] == 0)
    {
        for (i = 0; i < size2; i++)
        {
            der = kf2[i]*power2[i];
            der2[i] = der;
            kf2[i] = 0;
            power2[i]=0;
            //printf(" der2 = %d\n", der2[i]);
        }
    }
    if(power2[0] > 0)
    {
        for (i = 0; i < size2; i++)
        {
            der = kf2[i]*power2[i];
            der2[i] = der;
            kf2[i] = 0;
            power2[i]-=1;
            //printf(" der2 = %d\n", der2[i]);
        }
    }
    if(power2[0] < 0)
    {
        for (i = 0; i < size2; i++)
        {
            der = kf2[i]*power2[i];
            der2[i] = der;
            kf2[i] = 0;
            power2[i]-=1;
            //printf(" der2 = %d\n", der2[i]);
        }
    }
    multiply (der1,  der2, power,  power2, size1,  size2);
}

void multiply (int* der1, int* der2, int* power, int* power2,int size1, int size2)
{
    int num = 0;
    //int pow [6000];
    int count = 0;
    // int rez [6000];
    //int der1[6000];
    //int der2[6000];
    int i = 0;
    int j = 0;
    int* rez = (int*)malloc(size1*size2*sizeof(int));
    
    if(rez == NULL)
    {
        printf("Error");
        exit(-1);
    }
    
    int* pow = (int*)malloc(size1*size2*sizeof(int));
    
    if(pow == NULL)
    {
        printf("Error");
        exit(-1);
    }
    printf(" rezult:\n");
    for ( i = 0; i < size1; i++ )
    {
        for (j=0;j < size2; j++)
        {
            num = der1[i]*der2[j];
            rez[count] = num;
            pow[count] = power[i]+power2[j];
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
    free(der1);
    free(der2);
    return;
    }
