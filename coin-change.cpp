/* unbounded knapsack brutforce(recursion)*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int coin_change(vector<int> v, int n, int amt)
{
  if (amt == 0)
    return 0; // If amount=0 then we dont have to include any coin
  if (n == 0 && amt > 0)
    return 1e5; // if amt is greater than 0 and if we don't have any coins then we return infinity
  if (v[n - 1] > amt)
    return coin_change(v, n - 1, amt); // if the current amt is greater than the required we skip it
  return min(1 + coin_change(v, n, amt - v[n - 1]), coin_change(v, n - 1, amt));
  // as it is a bounded knapsack we include it and call the function with same item and we call the function by excluding it and find the minium of it
}
int main()
{
  int n, i, amt;
  cout << "Enter the no of denominations:";
  cin >> n;
  vector<int> v(n);
  cout << "Entet the denominations:";
  for (i = 0; i < n; i++)
    cin >> v[i];
  cout << "Entet the amount:";
  cin >> amt;
  cout << "The minimum no of coins are: " << coin_change(v, n, amt);

  return 0;
}
/* time complexity is O(2^n) and space complexity is O(n)(recursive stack space) */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int coin_change(vector<int> v, int n, int amt, vector<vector<int>> &dp)
{
  if (amt == 0)
    return 0; // If amount=0 then we dont have to include any coin
  if (n == 0 && amt > 0)
    return 1e5; // if amt is greater than 0 and if we don't have any coins then we return infinity
  if (dp[n][amt] != -1)
    return dp[n][amt];
  if (v[n - 1] > amt)
    return dp[n][amt] = coin_change(v, n - 1, amt, dp);
  else // if the current amt is greater than the required we skip it
    return dp[n][amt] = min(1 + coin_change(v, n, amt - v[n - 1], dp), coin_change(v, n - 1, amt, dp));
}
int main()
{
  int n, i, amt;
  cout << "Enter the no of denominations:";
  cin >> n;
  vector<int> v(n);
  cout << "Enter the denominations:";
  for (i = 0; i < n; i++)
    cin >> v[i];
  cout << "Enter the amount:";
  cin >> amt;
  vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));
  if (coin_change(v, n, amt, dp) > 1e4)
    cout << "Minimum no of coins are :-1";
  else
    cout << "Minimum no of coins are :" << dp[n][amt];
  return 0;
}
// /* time complexity is O(n*amt) and space complexity is O(n) */
// /*----------------------------------------------------------------*/
// /* dynamic programming tabulation method*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
  int n, i, j, amt;
  cout << "Enter the no of denominations:";
  cin >> n;
  vector<int> v(n);
  cout << "Enter the denominations:";
  for (i = 0; i < n; i++)
    cin >> v[i];
  cout << "Enter the amount:";
  cin >> amt;
  vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));
  for (i = 0; i < n; i++)
    dp[i][0] = 0;

  for (j = 1; j <= amt; j++)
    dp[0][j] = 1e5;

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= amt; j++)
    {
      if (v[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = min(1 + dp[i][j - v[i - 1]], dp[i - 1][j]);
    }
  }
  if (dp[n][amt] > 1e4)
    cout << "Minimum no of coins are:-1";
  else
    cout << "Minimum no of coins are :" << dp[n][amt];

  return 0;
}
/* time complexity and space complexity is O(n*w) */