/* using backtracking */
#include <iostream>
using namespace std;
bool is_subset(int a[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    else
        return is_subset(a, n - 1, sum) || is_subset(a, n - 1, sum - a[n - 1]);
}
int main()
{
    int n;
    cout << "enter the no of elements in the array:";
    cin >> n;
    int a[n];
    cout << "enter the elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum & 1)
        cout << "can't divide the set" << endl;
    else if (is_subset(a, n, sum / 2))
        cout << "Yes we can divide the set of equal sum" << endl;

    return 0;
}
// time complexity is tc=O(2^n) space complexity O(n) auxillary stack space
/* using dynamic programming memoization */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>> dp;
bool is_subset(int a[], int n, int sum, vector<vector<int>> dp)
{
    if (sum == 0)
        return true;
    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];
    if (a[n - 1] > sum)
        return dp[n][sum] = is_subset(a, n - 1, sum, dp);
    else
        return dp[n][sum] = is_subset(a, n - 1, sum, dp) || is_subset(a, n - 1, sum - a[n - 1], dp);
}
int main()
{
    int n;
    cout << "enter the no of elements in the array:";
    cin >> n;
    int a[n];
    cout << "enter the elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum & 1)
        cout << "can't divide the set" << endl;
    else
    {
        dp.resize(n + 1, vector<int>(sum / 2. - 1));
        if (is_subset(a, n, sum / 2, dp))
            cout << "Yes we can divide the set of equal sum" << endl;
    }
    return 0;
}
// time complexity is O(n*sum)
/* dynamic programming tabulation method */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, i, j;
    cout << "enter the no of elements in the array:";
    cin >> n;
    int a[n];
    cout << "enter the elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum & 1)
        cout << "can't divide the set" << endl;
    else
    {
        bool dp[n + 1][sum / 2 + 1];
        for (i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (j = 1; j <= sum / 2; j++)
        {
            dp[0][j] = false;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= sum / 2; j++)
            {

                if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else if (a[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
        if (dp[n][sum / 2])
            cout << "Yes we can divide the set of equal sum" << endl;

        for (int i = 0; i <= n; i++)
        {
            for (j = 0; j <= sum / 2; j++)
                cout << dp[i][j];
            cout << endl;
        }
        return 0;
    }
}
// time complexity and space complexity is O(n*sum)