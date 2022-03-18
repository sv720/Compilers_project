
#include "stdio.h"
int f();

int main()
{
    int x = f();
    return !(f()==1234);
}
