#include <bits/stdc++.h>

#define MAX 200023
#define M 200017

int hash1(int key) {
    return 1 + key%(M-1);
}

int hash2(int key) {
    return key%M;
}

int hash(int key, int i) {
    return (hash1(key) + i*hash2(key)) % M;
}

void insert(std::array<int, MAX>& A, int key) {
    int j, i=0;
    while(true) {
        j = hash(key, i);
        if (A[j] == 0) {
            A[j] = key;
            return;
        } else {
            i++;
        }
    }
}

int ConvertNumFromString(char s) {
    if (s == 'A') {
        return 1;
    } else if (s == 'C') {
        return 2;
    } else if (s == 'G') {
        return 3;
    } else if (s == 'T') {
        return 4;
    } else {
        return -1;
    }
}

int RetriveNumFromString(std::string str) {
    char s[3];
    int num = 0;
    for (int i=0; i<str.length(); i++) {
        s[i] = str[i];
        num += ConvertNumFromString(s[i])*std::pow(10, str.length()-i-1);
    }
    return num;
}

bool find(std::array<int, MAX> A, int key) {
    int j, i=0;
    while(true) {
        j = hash(key, i);
        if (A[j] == key) {
            return true;
        } else if(A[j] == 0 || i>=M) {
            return false;
        } else {
            i++;
        }
    }
}

int main()
{
    int n, num_chr;
    std::array<int, MAX> Array{0 };

    // 前方一致の正規表現
    std::regex re_insert(R"(^insert.*$)") ;
    std::regex re_find(R"(^find.*$)");

    // 命令数の取得
    std::cin >> n;
    std::string s,num_ins, num_find, result;

    for (int i = 0; i < n+1; i++)
    {
        getline(std::cin,s);
        if (std::regex_match(s, re_insert)) {
            num_ins = s.substr(7);
            num_chr = RetriveNumFromString(num_ins);
            insert(Array, num_chr);
        } else if(std::regex_match(s, re_find)) {
            num_ins = s.substr(5);
            num_chr = RetriveNumFromString(num_ins);
            result = find(Array, num_chr)? "yes" : "no";
            std::cout << result << "\n";
        }
    }
    return 0;
}