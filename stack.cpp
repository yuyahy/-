#include <bits/stdc++.h>

// 空白区切り、1行の数式を取得する
std::vector<std::string> GetInputFormula()
{
    std::vector<std::string> vecstr;

    std::string r, s;
    std::getline(std::cin, r);
    std::stringstream ss;   // std::stringstream ss{r}だとエラー
    ss << r;
    while (getline(ss, s, ' '))
    {
        vecstr.push_back(s);
    }
    return vecstr;
}

// 逆ポーランド記法の数式を
// std::stackを用いて計算する
// 数値→スタックに積む
// 演算子→スタックから２つ取り出して演算
// を繰り返す
void CalcRPNbyStack(std::vector<std::string> vecstr)
{
    std::stack<int> results;
    for (std::string v : vecstr)
    {
        try
        {
            int num = std::stoi(v);
            results.push(num);
        }
        catch (const std::invalid_argument &e)
        {
            int num1 = results.top();
            results.pop();
            int num2 = results.top();
            results.pop();
            if (v == "+")
            {
                int res = num2 + num1;
                results.push(res);
            }
            else if (v == "-")
            {
                int res = num2 - num1;
                results.push(res);
            }
            else if (v == "*")
            {
                int res = num2 * num1;
                results.push(res);
            }
            // 今回は割り算は対象ではないが一応
            else if (v == "/")
            {
                int res = num2 / num1;
                results.push(res);
            }
        }
    }
    std::cout << results.top() << std::endl;
}

int main()
{
    static const int MAX = 1000000;
    int n, R[MAX];
    std::string r, s;
    std::vector<std::string> vecstr = GetInputFormula();

    CalcRPNbyStack(vecstr);

    return 0;
}