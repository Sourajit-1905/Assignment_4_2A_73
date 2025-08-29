#include <stdio.h>

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n = 7;
    int k = 3;
    int survivor = josephus(n, k);
    printf("The survivor is person number %d\n", survivor);
    return 0;
}