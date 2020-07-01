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

    //printf("[");
    cout << "[";

    for (i = 0; c = T[iNode].left; c != NIL, i++, c = T[c].right)
    {
        if (i) cout << ", ";//printf(", ");
        //printf("%d",c);
        cout << c;
    }
    //printf("]");
    cout << "]";
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

    for (int i = 0; i < n; i++)
    {
        // 次数を取得
        cin >> iDeg >> iNodeIdx;
        //cout << iDeg << " " << iNodeIdx <<"\n";
        for (int k = 0; k < iNodeIdx; k++)
        {
            //cout << "iDeg = " <<iDeg;
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
            T[node].parent = iDeg;
        }
    }
    // rootを探す
    //cout << "// rootを探す";
    for (int i = 0; i < n; ++i)
    {
        if (T[i].parent == NIL)
        {
            root = i;
        }
    }

    // 根からはじめて深さを代入する
    rec(root, 0);

    // 4.nodeのindexごとに出力する
    for (int i = 0; i < n; ++i)
    {
        Print(i);
    }
    return 0;
}