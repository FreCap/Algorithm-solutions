#include <iostream>
#include <algorithm>
#include <algorithm>
#include <utility>
using namespace std;

int n;
int h[2010];
pair<int,int> h2[2010];


struct compareFirstPairMember {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second < b.second;
    }
};

int main() {

	cin >> n;
    for (int i = 0; i < n; i++){
        cin >> h[i];
		h2[i] = make_pair(h[i],i);
	}

	sort(h2,h2+n);
	int last=h2[0].first;
	pair<int,int> l;

	int counter = 0;
    for (int i = 1; i < n && counter<2;  i++){
		if(h2[i].first==last) counter++;
		last = h2[i].first;
	}
	
	if(counter<2)
		cout << "NO";
	else{
		cout << "YES" << endl;
		for (int i = 0; i < n;  i++)
			cout << h2[i].second+1 << " ";
		cout << endl;
		l=h2[0];
		counter = 0;
		for (int i = 1; i < n;  i++){
			if(h2[i].first==l.first){ counter++; h2[i-1] = h2[i]; h2[i]=l;}

			l = h2[i];
		}
		for (int i = 0; i < n;  i++)
			cout << h2[i].second+1 << " ";
		cout << endl;
		counter = 0;
		l=h2[0];
		for (int i = 1; i < n && counter<1;  i++){
			if(h2[i].first==l.first) {counter++;h2[i-1] = h2[i]; h2[i]=l;}
			l = h2[i];
		}
		for (int i = 0; i < n;  i++)
			cout << h2[i].second+1 << " ";
	}	

    return 0;
}


