#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 200

// 行列群を保持しておく
vector<pair<int, int>> vecpairMatrix(MAX);
//int dp[MAX][MAX][MAX];
int dp[MAX];

int
MultipleMatrixChain(vector<pair<int, int>> vecpairMatrix)
{
  // 初期値
  dp[0]= 0;
  for (int i = 0; i < vecpairMatrix.size(); i++)
  {
    // M1*(M2*M3)
    int cost1 = (vecpairMatrix[i].first * vecpairMatrix[i].second * vecpairMatrix[i+2].second) +
    (vecpairMatrix[i+1].first * vecpairMatrix[i+1].second * vecpairMatrix[i+2].second);

    // (M1*M2)*M3
    int cost2 = (vecpairMatrix[i].first * vecpairMatrix[i].second * vecpairMatrix[i+1].second) +
    (vecpairMatrix[i].first * vecpairMatrix[i+2].first * vecpairMatrix[i+2].second);
    dp[i+1] = min(cost1, cost2) + dp[i];
    cout << dp[i] << endl;
  }

  // }
  // for (int i = 0; i < vecpairMatrix.size(); i++)
  // {
  //   for (int j = 0; j < vecpairMatrix.size(); j++)
  //   {
  //     for (int k = 0; k < vecpairMatrix.size(); k++)
  //     {
  //       // M1*(M2*M3)
  //       int cost1 = (vecpairMatrix[i].first * vecpairMatrix[i].second * vecpairMatrix[i+2].second) +
  //       (vecpairMatrix[i+1].first * vecpairMatrix[i+1].second * vecpairMatrix[i+2].second);

  //       // (M1*M2)*M3
  //       int cost2 = (vecpairMatrix[i].first * vecpairMatrix[i].second * vecpairMatrix[i+1].second) +
  //       (vecpairMatrix[i].first * vecpairMatrix[i+2].first * vecpairMatrix[i+2].second);
  //       dp[i+1][j+1][k+1] = min(cost1, cost2) + dp[i][j][k];
  //     }
      
  //   }
  // }
  //return dp[vecpairMatrix.size()][vecpairMatrix.size()][vecpairMatrix.size()];
  return dp[vecpairMatrix.size()];
}

int main() {
  int n;
  cin >> n;
  
  int r = 0;
  int c = 0;

  for (int i = 0; i < n; i++)
  {
      cin >> r >> c;
      vecpairMatrix[i].first = r;
      vecpairMatrix[i].second = c;
  }
  
  cout << MultipleMatrixChain(vecpairMatrix) << "\n";
}