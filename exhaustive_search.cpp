#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

// 再帰・分割統治で与えられた整数リストから
// 与えられた整数mが作成できるかを判定する
// 整数リストの各要素に対して、選択する or しない
// の組み合わせを全探索する
bool CanCreateNumber(int i, int m, int n, vector<int> vecNum) {
    bool res = true;
    if (m==0) return true;
    if (i>=n) return false;
    // mから与えられた整数リストの各選択要素を引いていき
    // 0になった→整数リストでmが作れる
    // iがm以上になった→作れない
    res = CanCreateNumber(i+1, m, n, vecNum) || CanCreateNumber(i+1, m-vecNum[i], n, vecNum);
    return res;
}

int main() {
  int n = 0;
  int m = 0;
  int numTmp = 0;
  vector<int> vecA;

  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
      scanf("%d",&numTmp);
      vecA.push_back(numTmp);
  }

  scanf("%d",&m);
  string strRes;
  for (int j = 0; j < m; j++)
  {
      scanf("%d",&numTmp);
      strRes = (CanCreateNumber(0, numTmp, n, vecA)) ? "yes" : "no";
      printf("%s\n",strRes.c_str());
  }
  return 0;
}