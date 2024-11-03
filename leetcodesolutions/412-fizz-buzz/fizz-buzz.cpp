class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        for(int i = 1; i<=n; i++){
            if(!(i%15))v[i-1]="FizzBuzz";
            else if(!(i%5))v[i-1]="Buzz";
            else if(!(i%3))v[i-1]="Fizz";
            else v[i-1]=to_string(i);
        }
    return v;
    }
};