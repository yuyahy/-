#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

// 計数ソート実行関数
void CountingSort(vector<int> vecA, vector<int> vecB, int k)
{
    vector<int> vecC;
    vecC.reserve(1000);

    for (int i = 0; i < k; i++)
    {
        vecC[i] = 0;
    }
    
    // vecC[i]にiの出現数を記録する
    for (int j = 1; j < vecA.size(); j++)
    {
        vecC[vecA[j]] += 1;
    }

    // vecC[i]にi以下の数の出現数を記録する
    for (int i = 1; i < k; i++)
    {
        vecC[i] = vecC[i] + vecC[i-1];
    }

    for (int j = vecA.size(); j > 1; j--) {
        vecB[vecC[vecA[j]]] = vecA[j];
        vecC[vecA[j]] -= 1;
    }
    
    
    
}

int main() {
  int n,m;
  cin >> n >> m;
  
  int r = 0;
  cout << r << endl;
}