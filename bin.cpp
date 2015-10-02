#include <string>
#include <iostream>

using namespace std;


int search(int a[], int l, int u){
  int mid;
  while(l<u && a[l]>=a[u]){
    mid=(l+u)/2;
    if(a[u]>=a[mid])
      u=mid;
    else if(a[l]<a[mid])
      l=mid;
    else return mid+1;
  }
  return l;
}

int A[100];
int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> A[i];
  cout << search(A,0,N-1);
}

//6 6 1 2 3 4 5

