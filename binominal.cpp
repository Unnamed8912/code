#include <iostream>
using namespace std;

long binomial_coefficient(int n, int k) {
    long bc[n+1][n+1];
    
    for(int i = 0; i <= n; i++) {
        bc[i][0] = 1;
    }
    
    for(int i = 0; i <= n; i++) {
        bc[i][i] = 1;
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
        }
    }
    
    return bc[n][k];
}

int main() {
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") = " << binomial_coefficient(n, k) << endl;
    return 0;
}
