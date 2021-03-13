#include <stdio.h>
#include <stdlib.h>
#include "func.hpp"
int main()
{
    int num;
    int kf [16];
    int power [16];
    int kf2 [16];
    int power2 [16];
    int i = 0;
    int size;
    printf("enter the size of polynomial:\n");
    scanf("%d", &size);
    
    for(i = 0; i<size; i++)
    {
        printf("enter the coefficient:\n");
        scanf("%d", &num);
        kf[i] = num ;
    }
    for(i = 0; i<size; i++)
    {
        printf("enter the power:\n");
        scanf("%d", &num);
        power[i] = num ;
    }
   for(i = 0; i<size; i++)
    {
        printf("enter the coefficient:\n");
        scanf("%d", &num);
        kf2[i] = num ;
    }
    for(i = 0; i<size; i++)
    {
        printf("enter the power:\n");
        scanf("%d", &num);
        power2[i] = num ;
    }
    func(size, kf, power, kf2, power2);
    return 0;
}

