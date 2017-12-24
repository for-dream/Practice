/*
https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int spaceNum=0;
         
        for(int i=0;i<length;i++)
        {
            if(str[i]==' ')
                spaceNum++;
             
        }    
         
        int newIndex=length+2*spaceNum;
        char *index=str+length;
        while(index>=str)
        {
            if(*index==' ')
            {
                str[newIndex--]='0';
                str[newIndex--]='2';
                str[newIndex--]='%';
            }
            else{
                str[newIndex--]=*index;
            }
            index--;
        }
    }
};
