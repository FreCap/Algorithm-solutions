#include <iostream>
using namespace std;
#define N_MAX 110
int n, m, mat[N_MAX][N_MAX];

bool check(int t) {
    for (int i = t / 2 - 1, j = t / 2; i >= 0, j < t; i--, j++)
        for (int k = 0; k < m; k++)
            if (mat[i][k] != mat[j][k])
                return false;
    return true;

}

int main() {

    cin >> n >> m;
    int t = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    if (n % 2 != 0) {
        cout << n;
        return 0;
    }
    while (t % 2 == 0 && check(t))
        t /= 2;

    cout << t;
    return 0;
}


