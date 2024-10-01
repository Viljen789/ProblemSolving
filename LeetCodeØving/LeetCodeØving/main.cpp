#include <iostream>
#include <vector>

int sumPrimes(int n) {
    int sum = 0;
    std::vector<bool> sieve(n, true);

    for (int p = 2; p < n; ++p) {
        if (sieve[p]) {
            sum += p;
            for (int i = p*p; i < n; i += p) {
                sieve[i] = false;
            }
        }
    }

    return sum;
}

int main() {
    std::cout << sumPrimes(2000000) << std::endl;
    return 0;
}
