
#include <stdio.h>
#include "func.hpp"
 void func(int size,int* kf, int* power, int* kf2, int* power2)
{
    
    int num = 0;
    int rezult [26];
    int pow [26];
    int count = 0;
    int rez [26];
    int der1[16];
    int der2[16];
    int i = 0;
    int j = 0;
    int der;
    for (i = 0; i < size; i++){
        der = kf[i]*power[i];
        der1[i] = der;
        kf[i] = 0;
        power[i]-=1;
     //   printf("%d\n", power[i]);
    }
    for (i = 0; i < size; i++){
        der = kf2[i]*power2[i];
        der2[i] = der;
        kf2[i] = 0;
        power2[i]-=1;
     //   printf("%d\n", rez[i]);
    }
    for ( i = 0; i < size; i++ )
    {
        for (j=0;j < size; j++){
            rez[count] = der1[i]*der2[j];
            pow[count] = power[i]+power2[j];
           // printf("%dx^%d + ", rez[count], pow[count]);
           count ++;
        }
    }
       for (i=0; i<count; i++){
            for(j=i+1;j<count; j++){
                if(pow[i] == pow[j]){
                    rezult[i] = rezult[i] + (rez[i] + rez[j]);
                    printf ("%d\n", rezult[i]);
                    num++;
                }
                else{
                    rezult[i] = rez[i];
                    printf("%d\n", rezult [i]);
                    num++;
               }
            }
       }
           return;
       }
    
  
    


