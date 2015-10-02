#include <algorithm>
using namespace std;
char mioV[100012];


int Trova(int N, int K, int* insieme) {
   int temp, count=0;
   sort(insieme, insieme+N);
    for(int i=0;i<N;i++)
        mioV[insieme[i]]=1;
    
     for(int i=0;i<N;i++)
        if(mioV[insieme[i]]==1 && insieme[i]*K<=100011)
            mioV[insieme[i]*K]=2;

    for(int i=0;i<100001;i++)
        if(mioV[i]==1) count++;

	return count;
}
