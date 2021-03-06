#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
 
using namespace std;

struct nodo{
	int nextId, 
		posX, posY, 
		pallaX, pallaY;
};

nodo nodi[105];

int distanza(int posx, int posy, int i,int k){
	if(i==-1)
		return k;
	int iDist = abs(nodi[i].posX-posx)+abs(nodi[i].posY-posy);
	int kDist = abs(nodi[k].posX-posx)+abs(nodi[k].posY-posy);
printf("%d %d\n", iDist, kDist);
	if(iDist==kDist){
		if(nodi[i].posX==nodi[k].posX){
			if(nodi[i].posY==nodi[k].posY){
				return i;
			}else if(nodi[i].posY<nodi[k].posY)
				return i;
			return k;	
		}else if(nodi[i].posX<nodi[k].posX)
			return i;
		return k;		
	}else if(iDist>kDist)
		return k;
	return i;
}

int main() {

    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");

    int N, count=0, pallaX, pallaY, NAmici, XMax,YMax;
	int corrente=-1, correnteNew=0;

    in>>XMax>>YMax;
	in>>pallaX>>pallaY;
	in>>NAmici;

	for(int i=0; i<NAmici; i++){
		nodi[i].nextId = -1;
		in>>nodi[i].posX>>nodi[i].posY;
		in>>nodi[i].pallaX>>nodi[i].pallaY;
	}

    while(1){
		printf("\n#########\n");

		printf("Palla: %d %d\n", pallaX,pallaY);
		printf("Corrente Id: %d \n", corrente);

		if(corrente!=-1 && nodi[corrente].nextId!=-1)
			break;

		correnteNew=0;
		for(int i=0;i<NAmici;i++)
	        correnteNew=distanza(pallaX, pallaY, correnteNew, i);

		printf("Co Palla: %d %d\n", nodi[corrente].pallaX,nodi[corrente].pallaY);
		printf("Corrente: %d %d\n", nodi[corrente].posX,nodi[corrente].posY);

		printf("Dist    : %d\n", abs(nodi[correnteNew].posX-pallaX)+abs(nodi[correnteNew].posY-pallaY));
		printf("NC Palla: %d %d\n", nodi[correnteNew].pallaX,nodi[correnteNew].pallaY);
		printf("NCorrent: %d %d\n", nodi[correnteNew].posX,nodi[correnteNew].posY);

		if(corrente!=-1)
			nodi[corrente].nextId = correnteNew;
		corrente = correnteNew;
		pallaX=nodi[corrente].pallaX;
		pallaY=nodi[corrente].pallaY;
		count++;
    }

	count--;
    out<<count;
   
    in.close(); out.close();
   
    return 0;
}
