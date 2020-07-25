#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long llong;

// 二分木の定義
struct Node {
    int key;
    Node *left, *right, *parent;
    };
// 根・葉を定義
Node *root, *NIL;

//  二分木に新しい値を挿入する
void insert(int key)
{
    Node *x, *y, *z;
    // 初期化
    z = new Node;
    z->key = key;
    z->left = NIL;
    z->right = NIL;
    y = NIL;
    x = root;

    // 根から適切な位置までたどる
    while (x != NIL) {
        y = x; // 親を設定
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    z->parent = y;

    // 要素を配置する場所を決定する
    if (y == NIL) { // T が空の場合
        root = z;
    }
    else if (z->key < y->key){
        y->left = z; // z を y の左の子にする
    }
    else {
        y->right = z; // z を y の右の子にする
    }
}

// キーが存在するか確認する
bool find(Node* node, int key)
{
    while (node != NIL) {
        if (node->key == key) return true;

        // 二分木の特性を利用して場合分け
        // 探すキーと現在のキーの子の左右の大小を比較する

        // 終了
        if (node->key == key) {
            return true;
        } else if (node->key < key)
        {
            // 右の子ノードよりキーが大きければ右へ
            node = node->right;
        } else {
            // 左の子ノードよりキーが小さければ左へ
            node = node->left;
        }
    }
    return false;
}

void DeleteNoChildren(Node* node, int key, bool isRight)
{
        if (isRight)
        {
            node->parent->right = NIL;
        }
        else
        {
            node->parent->left = NIL;
        }
        node = NIL;
        return;
}

void DeleteOneChild(Node* node, int key, bool isRight, bool ischildright)
{
        // 自身が親に対して右、子を右にだけ持つ場合
        if (isRight && ischildright) {
            node->parent->right = node->right;
            node->right->parent = node->parent;
        } else if(!isRight && ischildright) {
            node->parent->left = node->right;
            node->right->parent = node->parent;
        } else if(isRight && !ischildright) {
            node->parent->right = node->left;
            node->left->parent = node->parent;
        } else {
            node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        node = NIL;
        return;
}

// 次節点を求める
Node* next_node(Node *node) {
  Node *x;
  
  // 右部分木を保つ場合は
  // その中で最小のキーを持つノードが次節点
  if (node->right != NIL) {
    x = node->right;
    while (x->left != NIL) {
      x = x->left;
    }
  // 右部分木がない場合は
  // 親を辿っていって最初にでてくる左部分木が次節点
  } else {    
    x = node;    
    while (x->parent != NIL && x == x->parent->right) {
      x = x->parent;
    }
    x = x->parent;
  }
  return x;
}

// 指定されたキーを探し削除する
void Binary_Tree_delete(Node* node, int key) 
{
    // 指定キーの場所を探す
    while (node != NIL) {
    // 二分木の特性を利用して場合分け
    // 探すキーと現在のキーの子の左右の大小を比較する

        // 終了
        if (node->key == key) {
            break;
        } else if (node->key < key)
        {
            // 右の子ノードよりキーが大きければ右へ
            node = node->right;
        } else {
            // 左の子ノードよりキーが小さければ左へ
            node = node->left;
        }
    }

    bool isright;
    // 指定キーが親の左右どちらの子か判定する
    if (node->parent != NIL) {
        isright = (node->parent->right->key == node->key)? true : false;
    }

    // 指定キー配下に子がいない場合
    Node* ParentNode = node->parent;
    if (node->right == NIL && node->left == NIL)
    {
        DeleteNoChildren(node, key, isright);
        return;
    }

    // 指定キー配下に一個だけ子がいる場合
    Node* ChildNode_right = node->right;
    bool isChildright;
    if (node->right != NIL && node->left == NIL)
    {
        DeleteOneChild(node, key, isright, true);
        return;

    } else if(node->right == NIL && node->left != NIL) {
        DeleteOneChild(node, key, isright, false);
        return;
    }

    // 指定キー配下に二個子がいる場合
    if (node->right != NIL && node->left != NIL) {
        // 指定キーの次節点を得る
        Node* tgtnode;


        tgtnode = next_node(node);

        node->key = tgtnode->key;

        bool istgtright = false;

        if (tgtnode->parent->right != NIL && tgtnode->parent->right->key == tgtnode->key) {
            istgtright = true;
        }

        if (tgtnode->right == NIL && tgtnode->left == NIL)
        {
            DeleteNoChildren(tgtnode, tgtnode->key, istgtright);
            return;
        }

        else if (tgtnode->right != NIL && tgtnode->left == NIL)
        {
            DeleteOneChild(tgtnode, tgtnode->key, istgtright, true);
            return;
        }

        else if (tgtnode->right == NIL && tgtnode->left != NIL)
        {
            DeleteOneChild(tgtnode, tgtnode->key, istgtright, false);
            return;
        }
    }
    return;
}

// 根から先行順巡回を行う
// 親→左部分木→右部分木の順
void PreOrder(Node* node)
{
    cout << " " << node->key;

    // 左部分木をチェック
    if (node->left != NIL) {
        PreOrder(node->left);
    }
    // 右部分木をチェック
    if (node->right != NIL) {
        PreOrder(node->right);
    }
}

// 根から中間順巡回を行う
// 左部分木→親→右部分木の順
void InOrder(Node* node)
{
    // 左部分木をチェック
    if (node->left != NIL) {
        InOrder(node->left);
    }
    cout << " " << node->key;

    // 右部分木をチェック
    if (node->right != NIL)
    {
        InOrder(node->right);
    }
}

void PrintVec()
{
    // 先行順巡回、 中間順巡回
    InOrder(root);
    cout << "\n";
    PreOrder(root);
    cout << "\n";
}

int main() {
    // 節点の個数
    int n = 0;
    // 次数
    int iDeg = 0;
    int iNodeIdx = 0;
    int left, node;
    string strCmd,strRes;
    bool bRet = false;

    cin >> n;

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
        else if(strCmd == "find") {
            cin >> iNodeIdx;
            bRet = find(root, iNodeIdx);
            strRes = bRet? "yes" : "no";
            cout << strRes << "\n";
        }
        else if (strCmd == "delete") {
            cin >> iNodeIdx;
            Binary_Tree_delete(root, iNodeIdx);
        }
    }
    return 0;
}