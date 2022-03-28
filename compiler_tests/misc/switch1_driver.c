#include <stdio.h> 
int g(int x);

int main()
{
    int x;
    printf("%d , %d ", g(1), g(2));
    return !( (g(1)+g(2))==21);
}
