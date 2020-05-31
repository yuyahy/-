#include <bits/stdc++.h>

int main()
{
    // '\\'の位置を積む
    std::stack<int> stack_total;
    // 
    std::stack<std::pair<int, int>> stack_each;
    std::vector<int> vecRes;

    int area_total = 0;
    int area = 0;
    int idx = 0;
    int area_each = 0;
    static const int MAX = 30000;
    std::string R;
    getline(std::cin, R);
    
    for (int i = 0; i < R.length(); i++)
    {
        if (R[i] == '\\') {
            stack_total.push(i); 
        }
        else if(R[i] == '/' && stack_total.size()!=0) {
            area = i - stack_total.top();
            area_total += area;
            idx = stack_total.top();
            stack_total.pop();
            area_each = area;

            // 計算済みの面積部分が統合できる場所かチェック
            while (!stack_each.empty() && idx < stack_each.top().first) {
                area_each += stack_each.top().second;
                stack_each.pop();
            }
            stack_each.push({idx, area_each});
        }
    }
    std::cout << area_total <<"\n";
    // 一つも面積計算ができなかった場合は、
    // 改行して終了
    if (stack_each.empty()) {
        std::cout << stack_each.size() <<"\n";
        return 0;
    } else {
        std::cout << stack_each.size() <<" ";
    }

    // stackは逆順のためvectorに詰め直す
    while (!stack_each.empty()) {
        vecRes.push_back(stack_each.top().second);
        stack_each.pop();
    }
    for (int j=vecRes.size()-1; j>=0; j--) {
        if (j==0) {
            std::cout << vecRes[j] << "\n";
        } else {
            std::cout << vecRes[j] << " ";
        }
    } 
}