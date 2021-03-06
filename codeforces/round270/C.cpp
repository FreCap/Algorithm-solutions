#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;


#define MAX 400000
int N;
pair<string,int> a[MAX];
int f[MAX];
int main() {
	string temp;
	cin >>N;
    for (int i = 0; i < N*2; i+=2){
        cin >> temp;
		a[i]=make_pair(temp, i/2);
        cin >> temp;
		a[i+1]=make_pair(temp, i/2);
	}

	for(int j=0;j<N;j++)
		cin >> f[j];

	sort(a, a+N*2);
	int current = 0;
	for(int i=0; i<N*2 && current != N; i++)
		if(a[i].second == f[current]-1)
			current++;
	
	if(current == N)
		cout << "YES";
	else
		cout << "NO";

    return 0;
}


