#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class MyClass{
  const string name_;

    public:
      MyClass (const string& name) : name_(name) {}

      string getName() const { return name_;};
      ~MyClass() { cout << "~MyClass(): " << name_ << endl; }
      void print() const { cout << name_ << ": " << name_ << endl; }
};



/*
int main() {
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string al = alphabet.erase(2);
  cout << alphabet << endl;
  string a = "abcdef";
  for( char c : alphabet) {
    if(a.find(c)<a.length()){ //to find +
    cout << c;
} else {
    cout << 0;
}
  }
  }



int main(){
    string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
    string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < alphabet_lower.length(); i++){
        cout << int(alphabet_lower[i])-96 << " ";
        cout << int(alphabet_upper[i])-38 << " ";
   
}
    return 0;
}
*/

  /*
  int main() {
    char c = 'c';
cout << c << endl;
  return 0;
  }
  */

/*
int main(){

    string s, t, r;
    s = "abcdefgh";
    //string a = s.erase(0, 2);
    int len = s.length();
    t = s.erase(len/2);
    cout << "t:"<< t << endl << "s:"<<s << endl;

    return 0;
}
*/

int main(){
  MyClass MyObj1("A");
  cout << MyObj1.getName() << endl;
  MyClass MyObj2("B");
  cout << MyObj2.getName() << endl;
  MyClass MyObj3("C");
  cout << MyObj3.getName() << endl;
  MyObj2.print();
  MyObj1.print();
  MyObj3.print();

  return 0;
}

