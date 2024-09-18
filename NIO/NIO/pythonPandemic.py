from typing import List, Tuple

def pandemic_strain(n: int, m: int, i: int, s: int, meetings: List[Tuple[int, int, int]]) -> int:
    # Initialize list of people
    people = [{'id': j, 'day_infected': -1, 'day_recovered': -1} for j in range(n)]
    # Infect person 0 on day 0
    people[0]['day_infected'] = 0
    people[0]['day_recovered'] = i + s
    # Iterate over meetings
    for a, b, d in meetings:
        # Check if either person is sick
        if people[a]['day_recovered'] >= d or people[b]['day_recovered'] >= d:
            # Infect the other person if they are not immune
            if people[a]['day_recovered'] < d:
                people[b]['day_infected'] = d + i
                if people[b]['day_recovered'] < people[b]['day_infected']:
                    people[b]['day_recovered'] = people[b]['day_infected'] + s
            elif people[b]['day_recovered'] < d:
                people[a]['day_infected'] = d + i
                if people[a]['day_recovered'] < people[a]['day_infected']:
                    people[a]['day_recovered'] = people[a]['day_infected'] + s
    # Count the maximum number of people sick at the same time
    max_sick = 0
    current_sick = 0
    for d in range(max(p['day_recovered'] for p in people)):
        # Increment the current number of sick people
        current_sick += sum(p['day_infected'] <= d < p['day_recovered'] for p in people)
        # Update the maximum number of sick people
        max_sick = max(max_sick, current_sick)
    return max_sick

# Test with given input
n = 5
m = 14
i = 3
s = 5
meetings = [(0, 1, 0), (0, 2, 1), (3, 0, 1), (4, 0, 2), (0, 1, 3), (1, 2, 3), (0, 4, 4), (0, 2, 8), (0, 3, 8), (1, 2, 10), (3, 4, 10), (3, 0, 14), (3, 1, 15), (3, 4, 16)]
print(pandemic_strain(n, m, i, s, meetings))
