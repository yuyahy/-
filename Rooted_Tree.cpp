#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 200000
#define NIL -1

struct Node {int parent, left, right;};
Node T[MAX];
int n, Depth[MAX];

// 再帰的に深さを求める
void rec(int node,int parent){
    Depth[node] = parent;
    if(T[node].right != NIL){
        // 右の兄弟に同じ深さを設定
        rec(T[node].right,parent);
    }
    if(T[node].left != NIL){
        // 最も左の子に自分の深さ+1を設定
        rec(T[node].left,parent + 1);
    }
}

void Print(int node){
    cout << "node " << node << ": ";
    cout << "parent = " << T[node].parent << ", ";
    cout << "depth = " << Depth[node] << ", ";
    
    if(T[node].parent == NIL) cout << "root, ";
    else if(T[node].left == NIL)cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    
    for(int i = 0,left = T[node].left;left != NIL;++i,left = T[left].right){
        if(i) cout << ", ";
        cout << left;
    }
    cout << "]" << endl;
}

int main() {
    // 節点の個数
    int n = 0;
    // 次数
    int iDeg = 0;
    int iNodeIdx = 0;
    int left, node, root;

    cin >> n;
    // 初期化
    for (int i = 0; i < n; ++i)
    {
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    // 各ノードに対して、
    // その節点番号、子の情報を、
    // 記憶していく
    for (int i = 0; i < n; i++)
    {
        // 節点番号、次数(子の数)を取得
        cin >> iNodeIdx >> iDeg;
        // 全ての子の情報を記憶する
        for (int k = 0; k < iDeg; k++)
        {
            cin >> node;
            if (k == 0)
            {
                // 一番左の子を取得
                T[iNodeIdx].left = node;
            }
            else
            {
                // 子の兄弟を記憶していく
                T[left].right = node;
            }
            left = node;
            // 子の親を記憶する
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
    rec(root, 0);

    // Nodeのindexごとに出力する
    for (int i = 0; i < n; ++i)
    {
        Print(i);
    }
    return 0;
}