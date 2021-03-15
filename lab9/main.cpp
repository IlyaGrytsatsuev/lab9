
#include <stdio.h>
#include <stdlib.h>
#include "func.hpp"
int main()
{
    int koeff;
    int num;
    int kf [60];
    int power [60];
    int kf2 [60];
    int power2 [60];
    int i = 0;
    int size1;
    int size2;
    int degree;
   
    printf("enter the power:\n");
    scanf("%d", &num);
    size1 = num + 1 ;
    degree = num;
    
    for(i = 0; i<size1; i++)
    {
        printf("enter the coefficient x^%d:\n", degree);
        scanf("%d", &koeff);
        power[i] = degree;
        kf[i] = koeff;
        printf ("power = %d", power [i]);
        printf ("kf = %d\n", kf [i]);
        degree -- ;
        
    }
    printf("enter the power:\n");
    scanf("%d", &num);
    size2 = num + 1 ;
    degree = num ;
   for(i = 0; i<size2; i++)
    {
        printf("enter the coefficient x^%d:\n", degree);
        scanf("%d", &koeff);
        kf2[i] = koeff ;
        power2[i] = degree;
        printf ("power2 = %d", power2 [i]);
        printf ("kf2 = %d\n", kf2 [i]);
        degree -- ;
    }
    
    func(size1, size2, kf, power, kf2, power2);
    return 0;
}
