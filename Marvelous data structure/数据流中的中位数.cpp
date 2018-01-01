/*
https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&tPage=4&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

class Solution {
public:
    //构造函数参数：类型；底层容器；元素大小比较标准
    priority_queue<int,vector<int>,less<int>> p;//大根堆
    priority_queue<int,vector<int>,greater<int>> q;//小根堆
    void Insert(int num)
    {
        if(p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);
        if(p.size() == q.size() + 2){//数据个数是偶数时
            q.push(p.top());
            p.pop();
        }	
        if(p.size() + 1 == q.size()){//奇数个的时候，保持中位数在p中
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    { 
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }

};
