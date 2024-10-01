#include "/Users/vilje/Documents/GD/Unity/2021.3.18f1/PlaybackEngines/WebGLSupport/BuildTools/Emscripten/emscripten/cache/sysroot/include/c++/v1/bits/stdc++.h"
using namespace std;

// Function to calculate the overlapping area
int overlapArea(int rect1[], int rect2[]){

   //Finding the length and width of overlap area
   int x = max(0, min(rect1[2], rect2[2]) - max(rect1[0], rect2[0]));
   int y = max(0, min(rect1[3], rect2[3]) - max(rect1[1], rect2[1]));
   int area = 2*(x + y);
   return area;
}
int totalArea(int rect1[], int rect2[]){
   int area1 = abs(rect1[2] - rect1[0]) + abs(rect1[3] - rect1[1])*2;
   int area2 = abs(rect2[2] - rect2[0]) + abs(rect2[3] - rect2[1])*2;

   
   // Checking for overlap
   if (rect1[0] > rect2[2] || rect2[0] > rect1[2] || rect1[1] > rect2[3] || rect2[1] > rect1[3])    {
   
      // No overlap
      return area1 + area2;
   } else {
   
      // Overlap
      int overlap = overlapArea(rect1, rect2);
      return area1 + area2 - overlap;
   }
}
int main(){
   int rect1[4] = {2,4, 7, 8}, rect2[4] = {6, 4, 9, 8};
   cout << totalArea(rect1, rect2);
   return 0;
}