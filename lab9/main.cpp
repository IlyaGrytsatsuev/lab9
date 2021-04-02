
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>
int main()
{
    int koeff;
    int num;
   // int kf [6000];
    //int power [6000];
   // int kf2 [6000];
   // int power2 [6000];
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
    if(kf == NULL){
        printf("Error");
        exit(-1);
    }
  
    int* power = (int*)malloc((size1 - 1)*sizeof(int));
    if(power == NULL){
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
    if(kf2 == NULL){
        printf("Error");
        exit(-1);
    }
    int* power2 = (int*)malloc((size2 - 1)*sizeof(int));
    if(power2 == NULL){
        printf("Error");
        exit(-1);
    }
    if(degree == 0){
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
    
    func(size1, size2, kf, power, kf2, power2);
    free(kf);
    free(power);
    free(kf2);
    free(power2);
    return 0;
}
