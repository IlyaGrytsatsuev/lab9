#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>

int main()
{
    int p1 = 0;
    int p2 = 0;
    int size1 = 0;
    int size2 = 0;
    int num;
    int i = 0;
    int degree1 = 0;
    int degree2 = 0;
    
    printf("enter the power:\n");
    scanf("%d", &num);
    
    if(num == 0)
    {
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
    
    degree1 = num;
    p1 = degree1;
    
    float* k1 = (float*)malloc(size1*sizeof(float));
    if(k1 == NULL)
    {
        printf("Error");
        exit(-1);
    }

    if(p1 == 0)
    {
        for(i = 0; i<size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree1);
            scanf("%f", &k1[i]);
        }
    }

    if(p1 > 0)
    {
        for(i = 0; i<size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree1);
            scanf("%f", &k1[i]);
            degree1 -- ;
        }
    }

    if(p1 < 0)
    {
        for(i = 0; i<size1; i++)
        {
            printf("enter the coefficient x^%d:\n", degree1);
            scanf("%f", &k1[i]);
            degree1 ++ ;
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

    degree2 = num;
    p2 = degree2;
    
    float* k2 = (float*)malloc(size2*sizeof(float));
    if(k2 == NULL)
    {
        printf("Error");
        exit(-1);
    }


    if(p2 == 0)
    {
        for(i = 0; i<size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree2);
            scanf("%f", &k2[i]);
        }
    }

    if(p2 > 0)
    {
        for(i = 0; i<size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree2);
            scanf("%f", &k2[i]);
            degree2 -- ;
        }
        degree2++;
    }

    if(p2 < 0)
    {
        for(i = 0; i<size2; i++)
        {
            printf("enter the coefficient x^%d:\n", degree2);
            scanf("%f", &k2[i]);
            degree2 ++ ;
        }
    }

    
    float* d1 = (float*)malloc(size1*sizeof(float));
    
    if(d1 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    
    float* d2 = (float*)malloc(size2*sizeof(float));
    
    if(d2 == NULL)
    {
        printf("Error");
        exit(-1);
    }
    
    float* r = (float*)malloc(size1*size2*sizeof(float));
    if(r == NULL)
    {
        printf("Error");
        exit(-1);
    }
    
    int* po = (int*)malloc(size1*size2*sizeof(int));
    if(po == NULL)
    {
        printf("Error");
        exit(-1);
    }
    derivative (size1, k1, &p1, d1);
    derivative (size2, k2, &p2, d2);
    multiply (p1, size1, d1, p2, size2, d2, r, po);
    output (r, po, size1, size2);
   
   
    free(k1);
    free(k2);
    free(po);
    free(r);
    free(d1);
    free(d2);
    return 0;
}
