#include <stdio.h> 
int bsqrt(int lo, int hi, int v);

int main()
{
    int x;
    printf("%d", bsqrt(1,10,8));
    return !(bsqrt(1,10,8)==8);
}
