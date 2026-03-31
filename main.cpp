#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate sum of proper divisors (excluding n itself)
long long sumProperDivisors(long long n) {
    if (n == 1) {
        return 0;  // 1 has no proper divisors
    }

    long long sum = 1;  // 1 is always a divisor (and proper for n > 1)
    long long sqrtN = sqrt(n);

    // Check divisors from 2 to sqrt(n)
    for (long long i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            sum += i;  // Add the divisor i
            // Add n/i if it's different from i (to avoid double counting for perfect squares)
            if (i != n / i && n / i != n) {
                sum += n / i;
            }
        }
    }

    return sum;
}

int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        long long n;
        cin >> n;

        long long divisorSum = sumProperDivisors(n);

        if (divisorSum == n) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
