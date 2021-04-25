
#ifndef func_hpp
#define func_hpp
//void func(int size1, int size2, int* kf, int* power, int* kf2, int* power2);
void input(int *size1, int *size2, int** k, int** k2,int** p1,int** p2);
void derivative(int* size1, int* size2, int* k, int* p1, int* k2, int* p2, int** d1,int** d2);
void multiply (int* p1, int* p2,int* size1, int* size2, int* d1, int* d2);
#endif /* func_hpp */
