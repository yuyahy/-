#include <bits/stdc++.h>
using namespace std;
#define MAX 44
int Fib[MAX];

// n番目のフィボナッチ数列を求める(再帰)
// int Calc_Fibonacci(int n1, int n2, int cnt)
// {
//     cnt--;
//     int n3 = n1 + n2;
//     if(cnt == 0) {
//         return n3;
//     } else {
//         return Calc_Fibonacci(n2, n3, cnt);
//     }
// }

// n番目のフィボナッチ数列を求める(動的計画法)
int MakeFibonacci(int n)
{
    Fib[0] = Fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        Fib[i] = Fib[i-1] + Fib[i-2];
    }
    return Fib[n];
}

int main()
{
    int n = 0;
    int nRes = 0;

    scanf("%d",&n);
    // 再帰用
    // if (n==0 || n==1) {
    //     printf("1\n");
    // } else {
    //     nRes = Calc_Fibonacci(1, 1, n-1);
    //     printf("%d\n", nRes);        
    // }
    
    nRes = MakeFibonacci(n);
    printf("%d\n", nRes);  
}