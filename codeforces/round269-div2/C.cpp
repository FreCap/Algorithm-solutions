#include <iostream>
#include <algorithm>
#include <algorithm>
#include <utility>
using namespace std;

long long n;
long long h[3000001];

int main() {

	cin >> n;
	h[0] = 2;
	int count = 0;
	if(n>=2 && (n-h[0])%3==0) count++;
    
	for (int i = 1; i<3000001 && h[i-1] <= n; i++){
        h[i] = h[i-1]+2+3*i;
		if(h[i] <= n &&(n-h[i])%3==0) count++;
	}


	cout << count;

    return 0;
}


