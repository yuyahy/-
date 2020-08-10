#include <bits/stdc++.h>
using namespace std;
#define MAX 2000

// 与えられた2つの文字列の最長共通部分列(LCS)を求める
int
SearchCommonSubsequence(string strSet1, string strSet2)
{
    // dp[i+1][j+1] = strSet1のi 文字目までとstrSet2のj文字目まででの LCS の長さ
    vector<vector<int>> dp(MAX, vector<int>(MAX));
    dp[0][0] = 0;
    string strRes = "";

    // 以下の場合が考えられる
    // 1. strSet1[i] = strSet2[j]の場合→dp[i][j]にstrSet1[i] = strSet2[j]の文字を加えると長さが+1される
    // 2. strSet1[i] != strSet2[j]の場合→dp[i+1][j],dp[i][j+1]の大きい方をそのまま採用する(長さは増えない)
    for (int i = 0; i < strSet1.size(); i++)
    {
        for (int j = 0; j < strSet2.size(); j++)
        {
            if(strSet1[i] == strSet2[j]) {
                dp[i+1][j+1] = max({dp[i][j] + 1,dp[i+1][j], dp[i][j+1]});
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[strSet1.size()][strSet2.size()];
}

int main()
{
    string strSet1, strSet2;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> strSet1 >> strSet2;

        if(strSet1.size() > strSet2.size()) swap(strSet1, strSet2);
        cout << SearchCommonSubsequence(strSet1, strSet2) << "\n";
    }    
    return 0;
}
