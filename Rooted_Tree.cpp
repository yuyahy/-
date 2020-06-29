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
        //printf("%d\n",child);
        cout << child << "\n";
        child = T[iNode].right;
    }
    
}

void PrintResult(int iNode) {
    int i, c;
    // printf("node %d: ", iNode);
    // printf("parent = %d, ", T[iNode].parent);
    // printf("depth = %d, ", Depth[iNode]);
    cout << "node " << iNode <<": \n";
    cout << "parent = " << T[iNode].parent << ", \n";
    cout << "depth = " << Depth[iNode] << ", \n";

    if (T[iNode].parent != NIL) {
        //printf("root, ");
        cout << "root, ";
    } else if (T[iNode].left == NIL) {
        //printf("leaf, ");
        cout << "leaf, ";
    } else {
        //printf("internal node, ");
        cout << "internal node, ";
    }

    printf("[");

    for (i = 0; c = T[iNode].left; c != NIL, i++, c = T[c].right)
    {
        if (i) cout << ", ";//printf(", ");
        //printf("%d",c);
        cout << c;
    }
    //printf("]");
    cout << "]";
}

int main() {
  // 節点の個数
  int n = 0;
  // 次数
  int iDeg = 0;
  int iNodeIdx = 0;
  int left,node,root;

  cin >> n;
  // 初期化
  for (int i = 0; i < n; ++i)
  {
      T[i].parent = T[i].left = T[i].right = NIL;
  }

  for (int i = 0; i < n; i++)
  {
      // 次数を取得
      cin >> iDeg >> iNodeIdx;
      for (int k = 0; k < iDeg; k++)
      {
          cin >> node;
          if (k == 0)
          {
              // 一番左の子を取得
              T[i].left = node;
          }
          else
          {
              T[left].right = node;
          }
          left = node;
          T[node].parent = iNodeIdx;
      }
  }
   // rootを探す
  for (int i = 0; i < n; ++i)
  {
      if (T[i].parent == NIL)
      {
          root = i;
      }
  }

   // 根からはじめて深さを代入する
   rec(root,0);

   // 4.nodeのindexごとに出力する
    for(int i = 0;i < n;++i){
        PrintResult(i);
    }
    return 0;
}