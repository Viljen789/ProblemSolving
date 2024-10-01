#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

   bitset<1000000> v;

   for (int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;
        for (int j = s; j <= e; j++) {
            v.flip(j);
        }
    }

   int ones = v.count();

    cout << n - ones << endl;

    return 0;
}
