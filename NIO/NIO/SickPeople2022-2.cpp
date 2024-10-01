#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

const int MAX_N = 100000;

// Data structure to represent a person
struct Person {
    int day_infected;   // Day when the person got infected
    int day_recovered;  // Day when the person recovered
};
bool is_sick(const Person& p, int d) {
    return p.day_infected <= d && d < p.day_recovered;
}

// Array of people in the municipality
Person people[MAX_N];

int main() {
    int n, m, i, s;
    std::cin >> n >> m >> i >> s;

    // Initialize all people as not infected
    memset(people, -1, sizeof(people));

    // Infect person 0 on day 0
    people[0].day_infected = 0;
    people[0].day_recovered = i + s;

    // Read meetings
    for (int j = 0; j < m; j++) {
        int a, b, d;
        std::cin >> a >> b >> d;

        // Check if either person is sick
        if (people[a].day_recovered >= d + i || people[b].day_recovered >= d + i) {
            // Infect the other person if they are not immune
            if (people[a].day_recovered < d + i) {
                people[b].day_infected = d + i;
                people[b].day_recovered = people[b].day_infected + s;
            }
            else if (people[b].day_recovered < d + i) {
                people[a].day_infected = d + i;
                people[a].day_recovered = people[a].day_infected + s;
            }
        }
    }

    // Find the maximum number of people sick at the same time
    int max_sick = 0;
    int current_sick = 0;
    for (int d = 0; d < 1000000; d++) {
        // Increment the current number of sick people
        current_sick += std::count_if(people, people + n, [d](const Person& p) { return is_sick(p, d); });

        // Update the maximum number of sick people
        max_sick = std::max(max_sick, current_sick);
    }

    std::cout << max_sick << std::endl;

    return 0;
}
