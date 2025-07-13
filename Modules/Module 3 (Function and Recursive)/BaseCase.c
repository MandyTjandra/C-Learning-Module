#include <stdio.h>
 
int power(int a, int m)
{
    if (m == 0) return 1;       // base case
    return (a * power(a, m-1)); // recursive case
}
 
int main()
{
    printf("%d\n", power(2,3));
    return 0;
}