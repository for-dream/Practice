/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

链接：https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811
来源：牛客网

思路就是使用异或，但是与在成对出现的数字中查找一个单独的数字不同的是需要利用异或结果的最低位为1的flag将数组中的数字分为两类，
一类是与flag按位与为0，另一类为不为0，这样再分别异或一次就能够找出这两个数。很是巧妙。
其中有一个语法上容易忽略的坑：==的优先级比&高，所以&时需要加括号。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2)
            return;
        int myxor = 0;
        int flag = 1;
        for(int i = 0;i < data.size();i++)
            myxor ^= data[i];
        while((myxor & flag) == 0)
            flag <<= 1;
        *num1 = myxor;
        *num2 = myxor;
        for(int i = 0;i < data.size();i++){
            if((flag & data[i]) == 0)
                *num2 ^= data[i];
            else *num1 ^= data[i];
        }
    }
};
