
#include <stdio.h>
#include "func.hpp"
 void func(int size1, int size2, int* kf, int* power, int* kf2, int* power2)
{
    
    int num = 0;
    int rezult [60];
    int pow [60];
    int count = 0;
    int rez [60];
    int der1[60];
    int der2[60];
    int i = 0;
    int j = 0;
    int der;
    for (i = 0; i < size1; i++){
        der = kf[i]*power[i];
        der1[i] = der;
        kf[i] = 0;
        power[i]-=1;
        printf(" der1 = %d\n", der1 [i]);
    }
    for (i = 0; i < size2; i++){
        der = kf2[i]*power2[i];
        der2[i] = der;
        kf2[i] = 0;
        power2[i]-=1;
        printf(" der2 = %d\n", der2[i]);
        
    }
    for ( i = 0; i < size1; i++ )
    {
        for (j=0;j < size2; j++){
            num =der1[i]*der2[j];
            if (num > 0){
                rez[count] = num;
                pow[count] = power[i]+power2[j];
                printf("%dx^%d + ", rez[count], pow[count]);
                count ++;
            }
        }
    }
    for ( i = 0; i < count; i++ )
    {
        for (j=i+1;j < count; j++){
            if (pow[i] == pow[j]){
                rezult[count]=rez[i] + rez[j];
                printf("%dx^%d + ", rezult[count], pow[count]);
            }
        }
        count ++;
    }
        
           return;
       }
    
  
    


