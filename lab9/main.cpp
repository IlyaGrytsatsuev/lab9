
#include <stdio.h>
#include "func.hpp"
#include <stdlib.h>
int main()
{
    int* k;
    int* k2;
    int* p1;
    int* p2;
    int* d1;
    int* d2;
    int size1 = 0;
    int size2 = 0;
    input(&size1, &size2, &k, &k2, &p1, &p2);
    derivative (&size1, &size2,k, p1, k2, p2, &d1, &d2);
    multiply (p1, p2, &size1, &size2, d1,  d2);
    free(k);
    free(k2);
    free(p1);
    free(p2);
    free(d1);
    free(d2);
    return 0;
}
