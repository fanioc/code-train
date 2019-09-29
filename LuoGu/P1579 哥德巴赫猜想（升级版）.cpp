#include <iostream>
using namespace std;

int minPrime[] = {2,3,5,7};

int judgePrime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return 1;
    return 0;
}

int main()
{
    int x;
    scanf ("%d", &x);
    for (int i = 2; i <= x / 3; i++)
    {
        if (!judgePrime(i)) continue;
        for (int j = 2; j <= (x - i) / 2; j++)
        {
            if (!judgePrime(j)) continue;
            int k = x - i - j;
            if (judgePrime(k))
            {
                printf ("%d %d %d\n", i, j, k);
                return 0;
            }
        }
    }
    return 0;
}