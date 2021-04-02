
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>
void func(int size1, int size2, int* kf, int* power, int* kf2, int* power2)
{
    
    int num = 0;
    //int pow [6000];
    int count = 0;
   // int rez [6000];
    //int der1[6000];
    //int der2[6000];
    int i = 0;
    int j = 0;
    int der;
    int* der1 = (int*)malloc(size1*sizeof(int));
    if(der1 == NULL){
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
    if(der2 == NULL){
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
    int* rez = (int*)malloc(size1*size2*sizeof(int));
    if(rez == NULL){
        printf("Error");
        exit(-1);
    }
    int* pow = (int*)malloc(size1*size2*sizeof(int));
    if(pow == NULL){
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
                    if (rez[count] < 0){
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
    
  
    


