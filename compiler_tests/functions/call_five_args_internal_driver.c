#include <stdio.h> 
int f();

int main()
{
    printf("%d", f());
    return !(f()==15);
}
