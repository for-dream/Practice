/*
https://www.hackerrank.com/challenges/crush/problem
Devendra在9号云上看到了他的教练朝他微笑。 每次教授选出Devendra单独问他一个问题，Devendra朦胧的头脑里全是他的教练和她的微笑，以至于他无法专注于其他事情。帮助他解决这个问题：

给你一个长度为N的列表，列表的初始值全是0。对此列表，你要进行M次查询，输出列表种最终N个值的最大值。对每次查询，给你的是3个整数——a,b和k，你要对列表中从位置a到位置b范围内的（包含a和b)的全部元素加上k。 


输入格式 

第一行包含两个整数 N和 M。
接下来 M行，每行包含3个整数 a, b 和 k。
列表中的数位置编号为从1到 N。


输出格式 

单独的一行包含 最终列表里的最大值

约束条件 

3 <= N <= 10^7 
1 <= M <= 2*10^5 
1 <= a <= b <= N 
0 <= k <= 10^9

输入样例 #00:

5 3
1 2 100
2 5 100
3 4 100
输出样例 #00:

200
解释:

第一次更新后，列表变为 100 100 0 0 0， 
第二次更新后，列表变为 100 200 100 100 100。
第三次更新后，列表变为 100 200 200 200 100。
因此要求的答案是200。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int N,K,p,q,sum,i,j,max=0,x=0;

    cin>>N>>K;
    long int *a=new long int[N+1]();

    for(i=0;i<K;i++)
    {
        cin>>p>>q>>sum;
        a[p]+=sum;
        if((q+1)<=N) a[q+1]-=sum;
    }

    for(i=1;i<=N;i++)
    {
       x=x+a[i];
       if(max<x) max=x;

    }

    cout<<max;
    return 0;
}
