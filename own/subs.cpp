#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
 

FILE * pFile, * pFileW;
const char *s1, *s2, *current, *i;

char a[1000010];
int main() {
    
	int N;
	current=a;

    pFile = fopen("input.txt", "r");
    pFileW = fopen("output.txt", "w");

	fscanf(pFile,"%d", &N);
	fscanf(pFile,"%s",a);
	a[N]=0;
	for(i=a+1; i!=a+N; ++i){
		char stop = 0;
		if(*i>*(i-1) && *i>=*current)
		for(s1=current,s2=i; stop!=1;++s1,++s2){
			if(*current<*s2){
				current=i=s2;
				stop=1;
			}else
			if(*s1<*s2){
				current = i;
				stop=1;
			}else if(*s1!=*s2){
				if(s1>i)
					i=s1;
				stop=1;
			}
		}		
	}
    
	fprintf(pFileW, "%ld", current-a);

    fclose(pFile);
    fclose(pFileW);
    return 0;
}
