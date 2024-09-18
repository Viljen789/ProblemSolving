#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int days;
    int maxBergen = 0; int maxOslo = 0; int maxOsloBergen = 0; int maxBergenOslo = 0;

    cin >> days;
    int newDays = days + 6;

    vector<int> cityOslo(newDays, 0);
    vector<int> cityBergen(newDays, 0);
    vector<int> maxProfitOslo(newDays, 0);
    vector<int> maxProfitBergen(newDays, 0);

    for(int i=6; i<newDays; i++){
        cin >> cityBergen[i] >> cityOslo[i];
    
    if (i > 7) maxProfitOslo[i] = cityOslo[i];
    if(i > 8) maxProfitBergen[i] = cityBergen[i];
    
    maxOslo = max(maxOslo, maxProfitOslo[i-4]);
    maxBergen = max(maxBergen, maxProfitBergen[i-6]);
    maxOsloBergen = max(maxOsloBergen, maxProfitOslo[i-5]);
    maxBergenOslo = max(maxBergenOslo, maxProfitBergen[i-5]);
    
    maxProfitOslo[i] += max(maxOslo, maxBergenOslo);
    maxProfitBergen[i] += max(maxBergen, maxOsloBergen);
    }

    cout << max(*max_element(maxProfitOslo.begin(), maxProfitOslo.end()), *max_element(maxProfitBergen.begin(), maxProfitBergen.end())) << endl;
    return 0;
    
}
