#include <stdio.h>

int f(int n);

// int g1(int n){
//     return n;
// }

// int f1(int n){
//     return n+g1(n-1);
// }

int main()
{
    // printf("%d", f1(1));
    printf("%d", f(1));
    return !(f(1)==1);
}
