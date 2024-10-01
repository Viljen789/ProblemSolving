#include <iostream>
#include <vector>
using namespace std;

int main(){
    int days;

    cin >> days;
    int newDays = days + 6;
    vector<int> cityOslo(newDays, 0);
    vector<int> cityBergen(newDays, 0);
    vector<int> maxProfitOslo(newDays, 0);
    vector<int> maxProfitBergen(newDays, 0);

    int maxBergen, maxOslo, maxOsloBergen, maxBergenOslo;

    for(int i=6; i<newDays; i++){
        cin >> cityBergen[i] >> cityOslo[i];
    
    if (i > 7) maxProfitOslo[i] = cityOslo[i];
    maxOslo = max(maxOslo, maxProfitOslo[i-4]);
    if(i > 8) maxProfitBergen[i] = cityBergen[i];
    maxBergen = max(maxBergen, maxProfitBergen[i-6]);
    
    
    
    maxOsloBergen = max(maxOsloBergen, maxProfitOslo[i-5]);
    maxBergenOslo = max(maxBergenOslo, maxProfitBergen[i-5]);
    maxProfitOslo[i] += max(maxOslo, maxBergenOslo);
    maxProfitBergen[i] += max(maxBergen, maxOsloBergen);
    }

    cout << max(*max_element(maxProfitOslo.begin(), maxProfitOslo.end()), *max_element(maxProfitBergen.begin(), maxProfitBergen.end()));
    return 0;
    
}
