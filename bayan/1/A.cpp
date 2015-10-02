#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>  
using namespace std;

#define MAX 1000000
int N;
string s;

int main() {

    ofstream out ("test.txt", ofstream::out);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s;
        for(int k=s.size()-1;k>=0;k--)
            out << s[k];
        out << endl;    
    }

    out.close();


    return 0;
}


