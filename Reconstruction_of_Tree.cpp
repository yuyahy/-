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
int n, Depth[MAX], Height[MAX], root;
int Depth_MAX;

void PrintVector(vector<int> vec)
{
    cout << "PrintVector" << "\n";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << " " << vec[i] << "\n";
        }
        else
        {
            cout << " " << vec[i];
        }
    }
}

vector<int> divVector(vector<int> vec, int begin, int end) 
{
    vector<int> vec_div;
    vec_div.reserve(MAX);
    for (int i=begin; i<=end; i++) vec_div.push_back(vec[i]);
    cout << "begin = " << begin << " end = " << end << "\n";
    PrintVector(vec_div);
    return vec_div;
}

// 先行順巡回、中間順巡回の結果から関係を取得する
// 先行順巡回: 親→左部分木→右部分木の順
// 中間順巡回: 左部分木→親→右部分木の順
int ReconstructTree(vector<int> vec_inOrder, vector<int> vec_preOrder)
{
    // 先行順巡回の最初の要素は根のはず
    int rootval = vec_preOrder[0];
    vec_preOrder.erase(vec_preOrder.begin());
    int rootidx = 0;

    for (int i = 0; i < vec_inOrder.size(); i++)
    {
        if (vec_inOrder[i] == rootval) {
            rootidx = i;
            break;
        }
    }

    cout << "rootidx = " <<rootidx;

    // 中間順巡回をrootidxを中心として左右に分割する
    // 後半部分へ分割
    if (vec_preOrder.size() > 0 && rootidx < vec_inOrder.size()-1) {
        cout << "後半" << "\n";
        iNode[rootidx].right = ReconstructTree(divVector(vec_inOrder,rootidx+1,vec_inOrder.size()-1), vec_preOrder);
    }
    // 前半部分へ分割
    if (vec_preOrder.size() > 0 && rootidx >0)
    {
        cout << "前半" << "\n";
        iNode[rootidx].left = ReconstructTree(divVector(vec_inOrder, 0, rootidx), vec_preOrder);
    }

    return rootidx;
}

// 根から後行順巡回を行う
// 左部分木→右部分木→親の順
void PostOrder(int node, vector<int>& vec_inOrder)
{
    // 左部分木をチェック
    if (iNode[node].left != NIL) {
        PostOrder(iNode[node].left, vec_inOrder);
    }
    
    // 右部分木をチェック
    if (iNode[node].right != NIL)
    {
        PostOrder(iNode[node].right, vec_inOrder);
    }

    vec_inOrder.push_back(node);
}


int main() {
    // 節点の個数
    int n = 0;
    // 次数
    int iDeg = 0;
    int iNodeIdx = 0;
    int left, node;

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

    // 先行順巡回の結果を取得
    for (int i = 0; i < n; i++)
    {
        //節点番号を取得
        cin >> iNodeIdx;
        vec_preOrder.push_back(iNodeIdx);
    }

    // 先行順巡回の最初は根
    root = vec_preOrder[0];

    // 中間順巡回の結果を取得
    for (int i = 0; i < n; i++)
    {
        //節点番号を取得
        cin >> iNodeIdx;
        vec_inOrder.push_back(iNodeIdx);
    }

    ReconstructTree(vec_inOrder, vec_preOrder);

    PostOrder(root, vec_postOrder);

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

    cout << "Postorder" << "\n";
    for (int i = 0; i < vec_postOrder.size(); i++)
    {
        if (i == vec_postOrder.size() - 1)
        {
            cout << " " << vec_postOrder[i] << "\n";
        }
        else
        {
            cout << " " << vec_postOrder[i];
        }
    }

    return 0;
}