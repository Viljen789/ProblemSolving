#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int pandemic_strain(int n, int m, int i, int s, vector<tuple<int, int, int> > meetings) {
  // Initialize list of people
  vector<tuple<int, int, int>> people(n);
  for (int j = 0; j < n; j++) {
    people[j] = make_tuple(j, -1, -1);
  }

  // Infect person 0 on day 0
  get<1>(people[0]) = 0;
  get<2>(people[0]) = i + s;

  // Iterate over meetings
  for (auto &[a, b, d] : meetings) {
    // Check if either person is sick
    if (get<2>(people[a]) >= d || get<2>(people[b]) >= d) {
      // Infect the other person if they are not immune
      if (get<2>(people[a]) < d) {
        get<1>(people[b]) = d + i;
        if (get<2>(people[b]) < get<1>(people[b])) {
          get<2>(people[b]) = get<1>(people[b]) + s;
        }
      } else if (get<2>(people[b]) < d) {
        get<1>(people[a]) = d + i;
        if (get<2>(people[a]) < get<1>(people[a])) {
          get<2>(people[a]) = get<1>(people[a]) + s;
        }
      }
    }
  }

  // Count the maximum number of people sick at the same time
  int max_sick = 0;
  int current_sick = 0;
  for (int d = 0; d <= max(get<2>(people[i]) for (auto &p : people)); d++) {
    // Increment the current number of sick people
    current_sick += count_if(people.begin(), people.end(),
                             [d](auto &p) { return get<1>(p) <= d && d < get<2>(p); });
    // Update the maximum number of sick people
    max_sick = max(max_sick, current_sick);
  }
  return max_sick;
}

int main() {
  // Test with given input
  int n = 5;
  int m = 14;
  int i = 3;
  int s = 5;
  vector<tuple<int, int, int> > meetings = {
      {0, 1, 0},
      {0, 2, 1},
      {3, 0, 1},
      {4, 0, 2},
      {0, 1, 3},
      {1, 2, 3},
      {0, 4, 4},
      {0, 2, 8},
      {0, 3, 8},
      {1, 2, 10},
      {3, 4, 10},
      {3, 0, 14},
      {3, 1, 15},
      {3, 4, 16}};
  cout << pandemic_strain(n, m, i, s, meetings) << endl;
  return 0;
}
