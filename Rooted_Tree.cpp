#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 200000
#define NIL -1

struct Node {int parent, left, right;};
Node T[MAX];
int n, Depth[MAX];

// 木構造の与えられた節点の深さを返す
int GetDepth(int iNode) {
    int iDepth = 0;
    while (T[iNode].parent != NIL)
    {
        iNode = T[iNode].parent;
        iDepth++;
    }
    return iDepth;
}

// 再帰的に木構造の節点の深さを求める
int rec(int iNode, int p) {
    Depth[iNode] = p;
    if (T[iNode].right != NIL) rec(T[iNode].right, p);
}

// 子のリストを表示する
void PrintChildren(int iNode) {
    int child = T[iNode].left;
    while (child != NIL)
    {
        printf("%d\n",child);
        child = T[iNode].right;
    }
    
}

void PrintResult(int iNode) {
    int i, c;
    printf("node %d: ", iNode);
    printf("parent = %d, ", T[iNode].parent);
    printf("depth = %d, ", Depth[iNode]);

    if (T[iNode].parent != NIL) {
        printf("root, ");
    } else if (T[iNode].left == NIL) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }

    printf("[");

    for (i = 0; c = T[iNode].left; c != NIL, i++, c = T[c].right)
    {
        if (i) printf(", ");
        printf("%d",c);
    }
    printf("]");
}

int main() {
  // 節点の個数
  int n = 0;
  // 次数
  int iDeg = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
      // 次数を取得
      scanf("%d", &iDeg);
      for (int k = 0; k < iDeg; k++)
      {
          if (k == 0)
          {
              // 一番左の子を取得
              scanf("%d", &T[i].left);
          }
          else
          {

          }
      }
  }
}