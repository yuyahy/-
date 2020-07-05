#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 200000
#define NIL -1
// 二分木の子の数(葉以外)
#define BINARY_CHILDREN_NUM 2
// 二分木の子の数(葉)
#define BINARY_LEAF_CHILDREN_NUM 0


struct Node {int parent, left, right;};
Node iNode[MAX];
int n, Depth[MAX], Height[MAX];
int Depth_MAX;

// 再帰的に深さを求める
void rec(int node,int parent){
    Depth[node] = parent;
    // 二分木なので、
    // 左右どちらかだけ子がいるパターンはないはず
    if((iNode[node].right != NIL) && (iNode[node].left != NIL)){
        // 子に自分の深さ+1を記憶させる
        rec(iNode[node].left,parent + 1);
        rec(iNode[node].right,parent + 1);
    } else {
        if (parent > Depth_MAX) Depth_MAX = parent;
    }
}

// 再帰的に高さを求める
int Rec_Height(int node, int parent,int cnt_right,int cnt_left) {
    int cnt_right_tmp = cnt_right;
    int cnt_left_tmp = cnt_left;
    // 末端についたら終了
    if(iNode[node].right == NIL && iNode[node].left == NIL) {
        Height[node] = 0;
        return 1;
    }
    // それ以外の場合は再帰
    else {
        cnt_left += Rec_Height(iNode[node].left, parent, cnt_right,cnt_left);
        cnt_right += Rec_Height(iNode[node].right, parent, cnt_right,cnt_left);
    }
    Height[node] = cnt_left>cnt_right? cnt_left : cnt_right;
}

// 与えられたノードの兄弟を返す
int GetBrother(int node) {
    int iParent = 0;
    // 根の場合は兄弟なし
    if(iNode[node].parent == NIL) {
        return NIL;
    } else {
        // 与えられたノードの親を取得
        iParent = iNode[node].parent;
        // 親の子で自分ではない方が兄弟
        // 二分木なので左右だけチェックすればOK
        if(iNode[iParent].left == node) {
            return iNode[iParent].right;
        } else {
            return iNode[iParent].left;
        }
    }
}

void Print(int node){
    cout << "node " << node << ": ";
    cout << "parent = " << iNode[node].parent << ", ";
    cout << "sibling = " << GetBrother(node) << ", ";
    if (iNode[node].left == NIL) {
        cout << "degree = " << BINARY_LEAF_CHILDREN_NUM << ", ";
    } else {
        cout << "degree = " << BINARY_CHILDREN_NUM << ", ";
    }
    cout << "depth = " << Depth[node] << ", ";
    cout << "height = " << Height[node] << ", ";
    if(iNode[node].parent == NIL) cout << "root";
    else if(iNode[node].left == NIL)cout << "leaf";
    else cout << "internal node";
    cout << "\n";
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
        iNode[i].parent = iNode[i].left = iNode[i].right = NIL;
    }

    // 各ノードに対して、
    // その節点番号、子の情報を、
    // 記憶していく
    for (int i = 0; i < n; i++)
    {
        // 節点番号を取得
        cin >> iNodeIdx;
        // 全ての子の情報を記憶する
        for (int k = 0; k < BINARY_CHILDREN_NUM; k++)
        {
            cin >> node;
            if (k == 0)
            {
                // 左の子を記憶
                iNode[iNodeIdx].left = node;
            }
            else
            {
                // 右の子を記憶
                iNode[iNodeIdx].right = node;
            }
            // 子の親を記憶する
            iNode[node].parent = iNodeIdx;
        }
    }
    // rootを探す
    for (int i = 0; i < n; ++i)
    {
        if (iNode[i].parent == NIL)
        {
            root = i;
        }
    }

    // 根からはじめて深さを代入する
    rec(root, Depth_MAX);

    // 根からはじめて高さを代入する
    Rec_Height(root, Depth_MAX, 0, 0);

    // Nodeのindexごとに出力する
    for (int i = 0; i < n; ++i)
    {
        Print(i);
    }
    return 0;
}