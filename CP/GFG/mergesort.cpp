#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>::iterator left_begin, vector<int>::iterator left_end, vector<int>::iterator right_begin, vector<int>::iterator right_end, vector<int>::iterator result){
    while(left_begin != left_end && right_begin != right_end){
        if(*left_begin < *right_begin){
            *result = *left_begin;
            left_begin++;
        }else{
            *result = *right_begin;
            right_begin++;
        }
        result++;
    }
    while(left_begin != left_end){
        *result = *left_begin;
        left_begin++;
        result++;
    }
    while(right_begin != right_end){
        *result = *right_begin;
        right_begin++;
        result++;
    }
}

vector<int> mergesort(vector<int> v){
    if(v.size() <= 1) return v;
    vector<int> left(v.begin(), v.begin() + v.size()/2);
    vector<int> right(v.begin() + v.size()/2, v.end());
    left = mergesort(left);
    right = mergesort(right);
    vector<int> result;
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(result));
    return result;
}


int main(){
    vector<int> v = {3, 2, 1, 5, 4};
}