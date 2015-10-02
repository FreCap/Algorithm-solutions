#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define trR(container, it) \
    for(typeof(container.rbegin()) it = container.rbegin(); it != container.rend(); it++)


#define ii pair<int, int>  
using namespace std;



int zigzag[100001], N, totalCost;

set<ii> soluzioni[2];

set<ii>::iterator current, it;
set<ii>::reverse_iterator currentR, itR;

void precedente(int pos) {
    int max = 1, maxPurger = 0;

    tr(soluzioni[0], it)
    if (it->first < zigzag[pos] && it->second + 1 > max)
        max = it->second + 1;
    cout << "Psize:"<<soluzioni[1].size() << endl;
    soluzioni[1].insert(make_pair(zigzag[pos], max));
        cout << "Dsize:"<<soluzioni[1].size() << endl;

    cout << endl;

    trR(soluzioni[1], it) {
        if (maxPurger < it->second)
            maxPurger = it->second;
        else
            soluzioni[1].erase(--it.base());
    }
    cout << maxPurger << endl;
    max = 1;
    tr(soluzioni[1], it)
    if (it->first > zigzag[pos] && it->second + 1 > max)
        max = it->second + 1;

    for(set<ii>::iterator it= soluzioni[0].begin(); it!=soluzioni[0].end();) {
        if (maxPurger < it->second){
            maxPurger = it->second;
            ++it;
        }else
            soluzioni[0].erase(it++);
    }
    soluzioni[0].insert(make_pair(zigzag[pos], max));
}

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    int i, max = 0;
    in >> N;

    for (i = 0; i < N; i++)
        in >> zigzag[i];

    for (i = 0; i < N; i++)
        precedente(i);

    tr(soluzioni[0], it)
    if (it->second > max)
        max = it->second;

    tr(soluzioni[1], it)
    if (it->second > max)
        max = it->second;

    out << max;
    cout << max;
    in.close();
    out.close();

    return 0;
}
