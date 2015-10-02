#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 1000000
#define MIN(a,b) a<b?a:b
#define fi first
#define se second
#define sq(a) (a)*(a)

#define REP(i,f,n) for(int i=f;i<n;i++)

typedef struct{
    pair<long long, long long> h,p;
    void print(){ cout << p.fi<< " " << p.se << endl;}
} mole;

mole r[400];
int n;

long long d(int i, int i2){
    return sq(r[i].p.fi-r[i2].p.fi) + sq(r[i].p.se-r[i2].p.se);  
}

bool check(int i){
    vector<long long> p;
    for(int j=0;j<4;j++){
        for(int k=j+1;k<4;k++){
            p.push_back(d(i+j,i+k));
        }           
    }
    sort(p.begin(),p.end());
    int l=0;
    for(;l<4;l++) if(p[l]!=p[0])return false;
    for(;l<6;l++) if(p[l]!=p[4]) return false;
    return p[0]!=0 && p[4]!=0;
}

void rotate(int i){
    int temp=r[i].p.fi;  
    r[i].p.fi = (-(r[i].p.se-r[i].h.se)+r[i].h.fi);  
    r[i].p.se = ((temp-r[i].h.fi)+r[i].h.se); 
}

int main() {
    cin >> n;

    for(int i=0;i<n*4;i++){
        cin >> r[i].p.fi >> r[i].p.se
            >> r[i].h.fi >> r[i].h.se;
    }
    //   rotate(0);    rotate(0);    rotate(0);   rotate(0);

    for(int i=0;i<n;i++){
        //comb
        int min=999;
        for (int j1=0;j1<4;j1++){
            for(int j2=0;j2<4;j2++){
                for (int j3=0;j3<4;j3++){
                    for(int j4=0;j4<4;j4++){
                        if(check(i*4)) {
                            min = MIN(j1+j2+j3+j4,min); 
                            /*                           cout << "################" << j1+j2+j3+j4 << endl;
                                                         r[i*4+0].print();
                                                         r[i*4+1].print();
                                                         r[i*4+2].print();
                                                         r[i*4+3].print();
                                                         cout << endl;
                             */                       }

                        rotate(i*4+3);
                        /*  cout << "################" << endl;
                            r[i*4+0].print();
                            r[i*4+1].print();
                            r[i*4+2].print();
                            r[i*4+3].print();
                            cout << endl;*/
                    }
                    rotate(i*4+2); 
                }
                rotate(i*4+1); 
            } 
            rotate(i*4+0);  
        }   
        if(min==999) cout << -1; else cout << min;
        cout << endl;
    }

    return 0;
}
