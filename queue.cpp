#include <bits/stdc++.h>

// 空白区切り、1行の数式を取得する
std::pair<std::string, int> GetProc()
{
    std::pair<std::string, int> pProc;
    int n, quantum;
    std::string r, s;
    std::getline(std::cin, r);
    std::stringstream ss; // std::stringstream ss{r}だとエラー
    ss << r;

    if (getline(ss, s, ' '))
        pProc.first = s;
    if (getline(ss, s, ' '))
        pProc.second = std::stoi(s);

    return pProc;
}

// ラウンドロビンスケジューリングを実行
void ExecRoundRobinScheduling(std::queue<std::pair<std::string, int>> qpairProcess, int quantum)
{
    std::pair<std::string, int> pProc;
    int time = 0;
    while (qpairProcess.size() != 0)
    {
        // プロセス完了
        if (qpairProcess.front().second - quantum <= 0)
        {
            // クオンタムちょうどの残時間か、それ以外か
            time += qpairProcess.front().second - quantum < 0? qpairProcess.front().second : quantum;
            std::cout << qpairProcess.front().first << " ";
            std::cout << time << "\n";
            qpairProcess.pop();
        }
        // プロセスが終わってなければ
        // 残処理時間を計算して末尾に移動
        else
        {
            time += quantum;
            pProc.first = qpairProcess.front().first;
            pProc.second = qpairProcess.front().second - quantum;
            qpairProcess.push(pProc);
            qpairProcess.pop();
        }
    }
}

int main()
{
    static const int MAX = 1000000;
    int n, R[MAX];
    int quantum;

    std::string r, s;
    std::getline(std::cin, r);
    std::stringstream ss; // std::stringstream ss{r}だとエラー
    ss << r;

    // プロセス数、クオンタムを取得
    if (getline(ss, s, ' '))
        n = std::stoi(s);
    if (getline(ss, s, ' '))
        quantum = std::stoi(s);

    std::queue<std::pair<std::string, int>> qpairProcess;

    for (int i = 0; i < n; i++) qpairProcess.push(GetProc());

    ExecRoundRobinScheduling(qpairProcess, quantum);

    return 0;
}