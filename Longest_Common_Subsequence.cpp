#include <bits/stdc++.h>
using namespace std;

int SearchCommonSubsequence(string strSet1, string strSet2)
{
    map<std::string, bool> mapSearchedStrings;
    // 
    while(true) {
        //strSet1
    }

    pair<std::string, bool> regPair;

    for(int i=0; i<strSet1.size(); i++) {
        if(strSet2.find(strSet1[i]) != string::npos) {
            regPair = make_pair(strSet1[i], true);
        } else {
            regPair = make_pair(strSet1[i], false);
        }
        mapSearchedStrings.insert(regPair);
    }
}

int main()
{
    string strSet1, strSet2;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> strSet1;
        cin >> strSet2;
    }
    
    return 0;
}
