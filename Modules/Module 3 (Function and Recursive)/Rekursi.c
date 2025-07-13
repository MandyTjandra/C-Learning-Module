#include <stdio.h>
 
void rekursi(int n)
{
    printf("%d\n", n);
    rekursi(n+1);       // memanggil dirinya sendiri
}

int main()
{
    rekursi(1);
    return 0;
}