/*
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, I, S;
vector<vector<int>> adj;
vector<int> sick;
 
void dfs(int u, int d)
{
	if (d >= I && d <= I + S)
		sick[u] = 1;
	for (auto& v : adj[u])
		dfs(v, d + 1);
}
 
int main()
{
	cin >> n >> m >> I >> S;
	adj.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(v);
	}
	sick.assign(n, 0);
	dfs(0, 0);
	cout << accumulate(sick.begin(), sick.end(), 0) << endl;
	return 0;
}
*/

/* KODEN UNDER BARE I PYTHON
N, M, I, S = map(int, input().split())
meetings = [list(map(int, input().split())) for _ in range(M)]
 
# Create a list for each person
sickness = [[0] * (1_000_000 + 1) for _ in range(N)]
 
# Count the number of sick people
num_sick = 1
 
for A, B, D in meetings:
    # Person A gets sick on day D + I
    sickness[A][D + I] += 1
    # Person B gets sick on day D
    sickness[B][D] += 1
 
for person in sickness:
    # Count the number of sick people at the current day
    num_sick += sum(person)
    # Remove recovered people
    for i in range(S, 1_000_001):
        person[i] = person[i - S]
 
print(num_sick)

*/
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
    cin >> meeting[0];
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
