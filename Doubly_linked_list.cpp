#include <bits/stdc++.h>

// 空白区切り、1行の数式を取得する
std::pair<std::string, int> GetCmdNum()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::pair<std::string, int> pCmdNum;
    std::string r, s;
    std::getline(std::cin, r);
    std::stringstream ss; // std::stringstream ss{r}だとエラー
    ss << r;
    if (getline(ss, s, ' '))
        pCmdNum.first = s;
    if (getline(ss, s, ' '))
        pCmdNum.second = std::stoi(s);

    return pCmdNum;
}

int main()
{
    //static const int MAX = 1000000;
    int n, x;
    std::list<int> listNums;
    std::pair<std::string, int> pCmdNum;
    std::string r, s;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //std::string str(100, ' ');
    //char str[20];
    getline(std::cin, r);
    std::stringstream ss; // std::stringstream ss{r}だとエラー
    ss << r;
    if (getline(ss, s, ' '))
    {
        n = std::stoi(s);
    }
    // scanf("%d", &n);
    //std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        pCmdNum = GetCmdNum();
        // std::cout << pCmdNum.first << std::endl;
        // std::cout << pCmdNum.second << std::endl;

        if (pCmdNum.first == "insert")
        {
            listNums.push_front(pCmdNum.second);
        }
        else if (pCmdNum.first == "delete")
        {
            for (auto it = listNums.begin(); it != listNums.end();)
            {
                // 条件一致した要素を削除する
                if (*it == pCmdNum.second)
                {
                    // 削除された要素の次を指すイテレータが返される。
                    it = listNums.erase(it);
                    break;
                }
                // 要素削除をしない場合に、イテレータを進める
                else
                {
                    ++it;
                }
            }
        }
        else if (pCmdNum.first == "deleteFirst")
        {
            listNums.pop_front();
        }
        else if (pCmdNum.first == "deleteLast")
        {
            listNums.pop_back();
        }
    }
    int cnt = 0;
    for (auto x : listNums)
    {
        if (cnt == listNums.size() - 1)
        {
            std::cout << x;
            //printf("%d", x);
        }
        else
        {
            std::cout << x << " ";
            //printf("%d ", x);
        }
        cnt++;
    }
    std::cout << "\n";
    //printf("\n");
    return 0;
}