#include <bits/stdc++.h>
#include <string>
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
int n, Depth[MAX], Height[MAX], root;
int Depth_MAX;

//  二分木に新しい値を挿入する
void insert(int iVal)
{
    int y = NIL; // x の親
    int x = root;
    // int tmpX = iNode[x];
    // int tmpY = iNode[y];

    while (x != NIL) {
        int y = x; // 親を設定
        if (iVal < x) {
            x = iNode[x].left; // 左の子へ移動
        }
        else {
            x = iNode[x].right; // 右の子へ移動
        }
    }

    iNode[iVal].parent = y;
    //iNode[iVal].parent = y;

    if (y == NIL) { // T が空の場合
        root = iVal;
    }
    else if (iVal< y){
        iNode[y].left = iVal; // z を y の左の子にする
    }
    else {
        iNode[y].right = iVal; // z を y の右の子にする
    }
}

// 根から先行順巡回を行う
// 親→左部分木→右部分木の順
void PreOrder(int node, vector<int>& vec_inOrder)
{
    vec_inOrder.push_back(node);

    // 左部分木をチェック
    if (iNode[node].left != NIL) {
        PreOrder(iNode[node].left, vec_inOrder);
    }
    // 右部分木をチェック
    if (iNode[node].right != NIL) {
        PreOrder(iNode[node].right, vec_inOrder);
    }
}

// 根から先行順巡回を行う
// 左部分木→親→右部分木の順
void InOrder(int node, vector<int>& vec_inOrder)
{
    // 左部分木をチェック
    if (iNode[node].left != NIL) {
        InOrder(iNode[node].left, vec_inOrder);
    }
        vec_inOrder.push_back(node);

    // 右部分木をチェック
    if (iNode[node].right != NIL)
    {
        InOrder(iNode[node].right, vec_inOrder);
    }
}

void PrintVec()
{
    // 先行順巡回、 中間順巡回、後行順巡回
    vector<int> vec_preOrder, vec_inOrder;
    vec_preOrder.reserve(MAX);
    vec_inOrder.reserve(MAX);

    PreOrder(root, vec_preOrder);
    InOrder(root, vec_inOrder);

    // 結果を出力する
    cout << "Preorder" <<"\n";
    for (int i=0; i<vec_preOrder.size(); i++) {
        if (i == vec_preOrder.size() - 1) {
            cout << " " << vec_preOrder[i] <<"\n";
        } else {
            cout << " " << vec_preOrder[i];
        }
    }

    cout << "Inorder" << "\n";
    for (int i = 0; i < vec_inOrder.size(); i++)
    {
        if (i == vec_inOrder.size() - 1)
        {
            cout << " " << vec_inOrder[i] << "\n";
        }
        else
        {
             cout << " " << vec_inOrder[i];
        }
    }
}

int main() {
    // 節点の個数
    int n = 0;
    // 次数
    int iDeg = 0;
    int iNodeIdx = 0;
    int left, node;
    string strCmd;

    // 先行順巡回、 中間順巡回、後行順巡回
    vector<int> vec_preOrder, vec_inOrder, vec_postOrder;
    vec_preOrder.reserve(MAX);
    vec_inOrder.reserve(MAX);
    vec_postOrder.reserve(MAX);

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
        cin >> strCmd;
        if (strCmd == "insert") {
            cin >> iNodeIdx;
            insert(iNodeIdx);
        }
        else if (strCmd == "print") {
            PrintVec();
        }

    }
    return 0;
}