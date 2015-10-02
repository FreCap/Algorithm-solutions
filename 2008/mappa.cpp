#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#define ii pair<float,float> 
#define vi vector<int> 
using namespace std;
 
int mappa[100][100];
int N;

void dfs(int i, int j) {
    for (int r = -1; r < 2; r++)
        for (int s = -1; s < 2; s++) {
            if (i + r >= 0 && i + r < N && j + s >= 0 && j + s < N)
            	if (mappa[i + r][j + s] == 0 || mappa[i + r][j + s] > mappa[i][j] + 1) {
                	mappa[i + r][j + s] = mappa[i][j] + 1;
                	dfs(i + r, j + s);
	            }
        }
}

int main() {
    ifstream in ;
    ofstream out; in .open("input.txt");
    out.open("output.txt");

    in >> N;
 	char c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
           in >> c;
            if (c == '*')
                mappa[i][j] = 0;
            else
                mappa[i][j] = -1;
        }

    mappa[0][0] = 1;
    dfs(0, 0);
    out << mappa[N - 1][N - 1]; 

	in .close();out.close();

    return 0;
}
