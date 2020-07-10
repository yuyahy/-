#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 200000
#define NIL -1
// 二分木の子の最大数(葉以外)
#define BINARY_CHILDREN_NUM 2
// 二分木の子の数(葉)
#define BINARY_LEAF_CHILDREN_NUM 0


struct Node {int parent, left, right;};
Node iNode[MAX];
int n, Depth[MAX], Height[MAX];
int Depth_MAX;

// 与えられたノードが巡回済みか判定する
bool IsNodeInVector(int node, vector<int>& vec_inOrder) {
    for (auto& x : vec_inOrder) {
        if (x == node) return true;
    }
    return false;
}

// 根から先行順巡回を行う
// 親→左部分木→右部分木の順
void PreOrder(int node, vector<int>& vec_inOrder)
{
    // 重複して節点が記録される事を避けるチェック
    if (IsNodeInVector(node, vec_inOrder))
    {
        //既に登録した節点の場合は何もしない
    }
    else
    {
        vec_inOrder.push_back(node);
    }

    if (vec_inOrder.size() == n) return;

    // 左部分木をチェック
    if (iNode[node].left != NIL && !IsNodeInVector(node, vec_inOrder)) {
        PreOrder(iNode[node].left, vec_inOrder);
    // 右部分木をチェック
    } else if (iNode[node].right != NIL && !IsNodeInVector(node, vec_inOrder)) {
        PreOrder(iNode[node].right, vec_inOrder);
    // 葉まで辿りついたら兄弟を探す
    } else {
        // 兄弟が見つかる親まで戻る
        cout << node << "\n";
        PreOrder(iNode[node].parent, vec_inOrder);
    }
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
        //節点番号を取得
        cin >> iNodeIdx;
        //全ての子の情報を記憶する
        for (int k = 0; k < BINARY_CHILDREN_NUM; k++)
        {
            cin >> node;
            //if (node == NIL) continue;
            if (k == 0)
            {
                //左の子を記憶
                iNode[iNodeIdx].left = node;
            }
            else
            {
                //右の子を記憶
                iNode[iNodeIdx].right = node;
            }
            //子の親を記憶する
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
    //rec(root, Depth_MAX);

    // 根からはじめて高さを代入する
    //Rec_Height(root);

    vector<int> vec_inOrder;
    vec_inOrder.reserve(MAX);
    PreOrder(root, vec_inOrder);

    for (int i=0; i<vec_inOrder.size(); i++) {
        if (i == vec_inOrder.size() - 1) {
            cout << vec_inOrder[i] <<"\n";
        } else {
            cout << vec_inOrder[i] <<" ";
        }
    }
    return 0;
}