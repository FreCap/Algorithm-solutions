#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000
int N,k;
int f[MAX];
int p[MAX];
int pp;

int main() {
	cin >> N >> k;
    for (int i = 0; i < N; i++){
        cin >> f[i];
	}
	pp = N;

	sort(f, f+N);
	int t = 0;
	for(int i=0;i<N;i+=k)
		t+=f[N-i-1]*2-2;

	cout << t;

    return 0;
}


