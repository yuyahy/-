#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
constexpr int INFY = 2000000000;

// ワーシャルフロイド法
void Warshall_Floyd_Algorithm(vector<vector<llong>>& dp, int size)
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            if(dp[i][k] == INFY) continue;
            for (int j = 0; j < size; j++)
            {
                if(dp[k][j] == INFY) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    int num_vertex(0),num_edge(0);
    cin >> num_vertex >> num_edge;

    vector<vector<llong>> dp(num_vertex, vector<llong>(num_vertex, INFY));

    // ある頂点から自分に移動するコストは0
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 0; i < num_edge; i++)
    {
        llong edge1, edge2, cost;
        cin >> edge1 >> edge2 >> cost;
        
        // 辺の重みを記録する
        // 有向グラフなので逆方向は記録しない
        dp[edge1][edge2] = min(dp[edge1][edge2], cost);
    }

    // ワーシャルフロイド法でコストを求める
    Warshall_Floyd_Algorithm(dp, num_vertex);

    // 結果を表示する

    // 負の閉路があるかチェック
    for (int i = 0; i < dp.size(); i++)
    {
            if (dp[i][i] < 0) {
                cout << "NEGATIVE CYCLE" << "\n";
                return 0;
        }
    }

    // 負の経路がなければ各コストを表示する
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp.size(); j++)
        {
            string tmp = dp[i][j] == INFY? "INF" : to_string(dp[i][j]);
            if (j == dp.size() - 1)
            {
                cout << tmp << "\n";
            } else {
                cout << tmp << " ";
            }
        }
    }
    return 0;
}