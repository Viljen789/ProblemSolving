#include <iostream>
#include <vector>

int get_primes(int n) {
    int sum;
    std::vector<bool> sieve(n + 1, true); // initialize sieve with all values set to true
    std::vector<int> primes; // initialize empty vector to hold prime numbers
    
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) { // if i is prime
            primes.push_back(i); // add i to the list of primes
            sum +=1;
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false; // mark all multiples of i as composite
            }
        }
    }
    
    return sum;
}

int main() {
    
    
    int primes = get_primes(2000000);
    
    std::cout << primes;
    
    return 0;
}
