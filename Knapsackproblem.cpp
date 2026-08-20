#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], value[100];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter backpack capacity: ";
    cin >> W;

    int dp[101][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "\nBackpack Weight Capacity -> ";

    for (int w = 0; w <= W; w++) {
        cout << setw(4) << w;
    }

    cout << "\n-----------------------------------\n";

    cout << "0 |";
    for (int w = 0; w <= W; w++) {
        cout << setw(4) << dp[0][w];
    }
    cout << "  <- No items\n";

    for (int i = 1; i <= n; i++) {
        cout << i << " |";

        for (int w = 0; w <= W; w++) {
            cout << setw(4) << dp[i][w];
        }

        cout << "  <- item " << i
             << " (wt=" << weight[i - 1]
             << ", val=" << value[i - 1] << ")\n";
    }

    cout << "\nMaximum value = " << dp[n][W] << endl;

    return 0;
}
