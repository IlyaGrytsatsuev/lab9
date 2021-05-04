
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>
int main()
{
    float* k;
    float* k2;
    int p1 = 0;
    int p2 = 0;
    int size1 = 0;
    int size2 = 0;
    int* po;
    float* r;
    float* d1;
    float* d2;
    
    input(&size1, &k, &p1);
    input(&size2, &k2,  &p2);
    derivative (&size1, k, &p1,&d1);
    derivative (&size2, k2, &p2, &d2);
    multiply (&p1, &size1, d1, &p2, &size2, d2, &r, &po);
    output (r, po, &size1, &size2);
   // for(int i = 0; i < size1*size2 ; i++){
    //    printf("%f ", r[i]);
   // }
   // for(int i = 0; i < size2 ; i++){
    //    printf("%f ", d2[i]);
    //}
   // printf("%d ",p1 );
   // printf("\n");
   // for(int i = 0; i < size1*size2 ; i++){
    //    printf("%d ", po[i]);
    //}
    return 0;
}
