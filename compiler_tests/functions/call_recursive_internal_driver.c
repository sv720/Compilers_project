#include <stdio.h>
int f(int n);

int main()
{
    printf("%d %d %d %d %d ", f(1), f(2), f(3), f(4), f(5));
    return !(f(5)==15);
}
