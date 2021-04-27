
#ifndef func_hpp
#define func_hpp
//void func(int size1, int size2, int* kf, int* power, int* kf2, int* power2);
void input(int *size, int** k,int** p);
void derivative(int* size, int* k, int* p,  int** d);
void multiply (int* p1, int* p2,int* size1, int* size2, int* d1, int* d2, int** r, int** po, int* c);
void output (int* c, int* r, int* po);
#endif /* func_hpp */
