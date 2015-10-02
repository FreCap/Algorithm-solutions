#include <stdio.h>
#include <assert.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
//g++ -std=c++11 crittografia.cpp 
char asd[20];
int codifica(int N) {
    std::string s = std::to_string(N);
    std::reverse(s.begin(),s.end());   
    int value = atoi(s.c_str()); 
    return N+value;
}


int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", codifica(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
