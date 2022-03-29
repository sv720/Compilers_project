#include <stdio.h>
float f();

int main()
{
    printf("%f", f());
    return !(f()==2.3f);
}
