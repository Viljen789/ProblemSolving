#include <vector>
#include <string>
#include <iostream>

using namespace std;

class UnionFind {
private :
vector <int > p, rank , setSize ;
//p er lederen til hver enkelt node
// rank er kun for o p t i m a l i s e r i n g naar vi slaar sammen grupper
// setSize er antall noder i hver gruppe
int numSets ; // antall grupper
public :
UnionFind ( int N) {
setSize . assign (N, 1) ; // er kun 1 i hver gruppe
numSets = N; //N grupper
rank.assign (N, 0) ;
p. assign (N, 0) ;
for ( int i = 0; i < N; i++)
p[i] = i;
}
int findSet ( int i) {
return (p[i] == i) ? i : (p[i] = findSet (p[i]) ) ;
//p[i]= findSet (p[i]) er kun for aa optimalisere ,
// slik at den husker hvem som er lederen til neste gang
}
bool isSameSet ( int i, int j) { return findSet (i) == findSet (
j); }
void unionSet ( int i, int j) {
if (! isSameSet (i, j)) {
numSets --;
int x = findSet (i) , y = findSet (j);
// rank holder avstanden fra lederen til sinemedlemer kort
if ( rank [x] > rank [y]) {
p[y] = x;
setSize [x] += setSize [y];
} else {
p[x] = y;
setSize [y] += setSize [x];
if ( rank [x] == rank [y])
rank [y ]++;
}
}
}
int numDisjointSets () { return numSets ; }
int sizeOfSet ( int i) { return setSize [ findSet (i) ]; }
};
//Vi kan da simulere eksempelet ovenfor slikt,
// 0= Gates , 1= Brin , 2= Jobs , 3= Zuckerberg
int main(){
    UnionFind UF (4) ;
UF. unionSet (0 , 1) ;
UF. unionSet (2 , 3) ;
if (UF. inSameSet (0 , 3) )
cout << " Gates og Zuckerberg er venner \n";
else
cout << " Gates og Zuckerberg er ikke venner \n";
cout << " Antall grupper : " << UF. numDisjointSets () << endl ;
cout << " Antall personer i gruppen som Brin er med i: " << UF.
sizeOfSet (1) << endl ;
UF. unionSet (1 , 3) ;
cout << " Lederen til Zuckerberg er: " << UF. findSet (3) << endl ;
return 0;
}
