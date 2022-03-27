#include <stdio.h> 
int f();

int main()
{
    int x;
    printf("%d", f());
    return !(f()==8);
}
