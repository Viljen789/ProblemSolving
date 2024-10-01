#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twosum(int arr[], int size, int target){
    unordered_map<int, int> map;
    for(int i = 0; i < size; i++){
        int complement = target - arr[i];
        if(map.count(complement)){
            return {map[complement], i};
        }
        map[arr[i]] = i;
    }
    return {};
}

int main(){
    int arr[] = {8, 1, 2, 3, 4, 5};
    int target = 8;
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = twosum(arr, size, target);
    for(int i : result){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}



