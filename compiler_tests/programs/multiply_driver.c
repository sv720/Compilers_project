#include <stdio.h>
int multiply(int x, int y);

int main()
{
    printf("%d ", multiply(-20, 30));
    return !(multiply(-20,30)==-600);
}
