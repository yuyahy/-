#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
#define NOTFOUND -1
int Max = 0;
// nまでの文字列をいくつか選んで最長共通部を作ったときの長さ
//int dp[MAX];

bool 
IsInTargetString(string strFind, string strTgt)
{
    int idx;
    string strTmp = strTgt;

    for (int i = 0; i < strFind.size(); i++)
    {
        idx = strTgt.find(strFind[i]);
        if (idx != string::npos) {
            strTmp = strTgt.substr(idx+1);
            // cout << "idx = " << idx << " strFind = " << strFind
            // << " strTmp = " << strTmp <<  "\n";
        } else {
            return false;
        }
        strTgt = strTmp;
    }
    //cout <<  "\n";
    return true;
}

int
SearchCommonSubsequence(string strSet1, string strSet2)
{
    vector<vector<bool>> dp(MAX, vector<bool>(MAX));
    //vector<int> dp(MAX);
    string strRes = "";

    // nまでの文字列を
    for (int k = 0; k < strSet1.size()-1; k++)
    {
        if (strSet2.find(strSet1[k]) != string::npos) {
            dp[k][0] = true;
        } else {
            strRes = string(1, strSet1[k]);
            dp[k][0] = false;
            continue;
        }

        string strTmp = strSet2;
        int tmpMax = 0;
        for(int i=k+1; i<strSet1.size(); i++) {
            int idx = strTmp.find(strSet1[i]);
            if(dp[k][i-1] && idx != string::npos) {
                dp[k][i] = true;
                strTmp = strTmp.substr(idx+1);
                tmpMax++;
                cout << "tmpMax = " << tmpMax << endl;
            } else {
                // 見つからなかった場合はそのまま
                break;
            }
        //cout << strRes << ", " << strSet1[i] << "\n";
         //dp[k][i] = strRes.size();
        }
        Max = max(tmpMax, Max);
    }
    
    // for(int i=0; i<strSet1.size(); i++) {
    //     string strTmp = strRes;
    //     strTmp += strSet1[i];

    //     //if(strSet2.find(strTmp) != string::npos) {
    //     if(IsInTargetString(strTmp, strSet2)) {
    //         // 見つかった場合は更新a
    //         strRes = strTmp;
    //     } else {
    //         // 見つからなかった場合はそのまま
    //     }
    //     dp[i] = strRes.size();
    //     //cout << strRes << ", " << strSet1[i] << "\n";
    // }

    //auto itr = std::max_element(dp.begin(), dp.end());
    //return *itr;
    return Max;
}

int main()
{
    string strSet1, strSet2;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> strSet1 >> strSet2;

        if(strSet1.size() > strSet2.size()) swap(strSet1, strSet2);
        cout << SearchCommonSubsequence(strSet1, strSet2) << "\n";
    }    
    return 0;
}
