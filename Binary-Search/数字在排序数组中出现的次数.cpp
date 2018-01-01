/*
https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目描述
统计一个数字在排序数组中出现的次数。
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int low = getLow(data,k);
        int high = getHigh(data,k);
        return high - low + 1;
    }
    
    int getLow(vector<int> data,int k){
        int start = 0;
        int end = data.size() - 1;
        int mid = (start + end) / 2;
        while(start <= end){
            if(data[mid] < k){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return start;
    }
    
    int getHigh(vector<int> data,int k){
        int start = 0;
        int end = data.size() - 1;
        int mid = (start + end) / 2;
        while(start <= end){
            if(data[mid] <= k){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return end;
    }
};
