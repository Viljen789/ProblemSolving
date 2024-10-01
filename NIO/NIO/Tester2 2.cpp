//
//  Tester2.cpp
//  NIO
//
//  Created by Viljen Apalset Vassbø on 06/01/2023.
//

#include "Tester2.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
        int N, M, I, S;
        cout << "N";
        cin >> N;
        cout << "M";
        cin >> M;
        cout << "I";
        cin >> I;
        cout << "S";
        cin >> S;

  const int MAX_DAYS = 1'000'000;
  vector<vector<int>> sickness(N, vector<int>(MAX_DAYS + 1));
  vector<vector<int>> meetings(M, vector<int>(3));
  for (auto& meeting : meetings) {

    cout << "Person A";
    cin << meeting[0];
    cout << "Person B";
    cin >> meeting[1];
    cout << "Day";
    cin >> meeting[2];
  }

  // Count the number of sick people
  int num_sick = 1;

  for (const auto& meeting : meetings) {
      // Person A gets sick on day D + I
      sickness[meeting[0]][meeting[2] + I] += 1;
      // Person B gets sick on day D
      sickness[meeting[1]][meeting[2]] += 1;
  }

  // Print the number of sick people for each day
  for (int day = 0; day <= MAX_DAYS; ++day) {
      int sick_at_day = 0;
      for (const auto& person : sickness) {
          sick_at_day += person[day];
      }
      cout << "Day " << day << ": " << sick_at_day << " sick people" << endl;
  }

  // Remove recovered people
  for (auto& person : sickness) {
      for (int i = MAX_DAYS - S; i >= 0; --i) {
          person[i] = person[i + S];
      }
  }

  return 0;
}

