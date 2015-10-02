#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <string.h>
#include <math.h>

#define ii pair<float,float> 
#define vi vector<int> 
using namespace std;
 

ii P[6],D[6];
float lancioS;
float y(int i){
	cout<< ((D[i].second-P[i].second)*lancioS/10+P[i].second) << ":" << ((D[i].second-P[i].second)*lancioS/10) <<" + "<<P[i].second<<endl;
	return (D[i].second-P[i].second)*lancioS/10+P[i].second;
}

float posF[6];

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    int AN,DN,a;
    in >> lancioS >> AN >> DN;
   
	for(int i=0; i<AN; i++)
		in >> a>>P[i].second >>a>> D[i].second;
	for(int i=3; i<3+DN; i++)
		in >>a>> P[i].second >> a>>D[i].second;

	for(int i=0;i<6;i++)
		posF[i] = y(i);
	
	float minD=99999,minA=99999;
	for(int i=0;i<AN;i++)
		if(minA>posF[i])
			minA = posF[i];

	for(int i=3;i<3+DN;i++)
		if(minD>posF[i])
			minD = posF[i];

	for(int i=0;i<6;i++)
		cout <<posF[i]<<endl;

	cout << minD << " " << minA << endl;
	if(minD>minA)
		out<<"F";
	else
		out<<"R";
    in.close(); out.close();
   
    return 0;
}
