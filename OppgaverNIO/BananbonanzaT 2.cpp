#include <iostream>
#include <algorithm>
using namespace std;


const int CITIES = 2;
const int TRAVEL_TIME_OSLO = 2;
const int TRAVEL_TIME_BERGEN = 3;



int maxProfit(int day, int city, int DAYS, int prices[][CITIES], int dp[][CITIES]) {
    if (day >= DAYS) {
        return 0;
    }
    if (dp[day][city] != -1) {
        return dp[day][city];
    }
    int travelTime = (city == 0) ? TRAVEL_TIME_OSLO : TRAVEL_TIME_BERGEN;
    int restockTime = travelTime * 2;
    int profit = max(prices[day][city] + maxProfit(day + restockTime, (city + 1) % 2, DAYS, prices, dp), maxProfit(day + 1, city, DAYS, prices, dp));
    dp[day][city] = profit;
    return profit;
}

int main() {
    int DAYS;
    cin >> DAYS;
    int prices[DAYS][CITIES];
    int dp[DAYS][CITIES];
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < CITIES; j++) {
            cin >> prices[i][j];
        }
    }
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < CITIES; j++) {
            dp[i][j] = -1;
        }
    }
    int startOslo = maxProfit(TRAVEL_TIME_OSLO, 0, DAYS, prices, dp);
    int startBergen = maxProfit(TRAVEL_TIME_BERGEN, 1, DAYS, prices, dp);
    int maxProfit = max(startOslo, startBergen);
    cout << "Maximum Profit: " << maxProfit << endl;
    return 0;
}

