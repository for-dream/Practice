/*
https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue
*/

//一个会超时的版本
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
stack<int> num1;//an dui lie fang
stack<int> num2;//dao

void Enqueue(int x){
    while(!num1.empty()){
        num2.push(num1.top());
        num1.pop();
    }
    num2.push(x);
    while(!num2.empty()){
        num1.push(num2.top());
        num2.pop();
    }
}

void Dequeue(){
    num1.pop();
}

void Print(){
    cout << num1.top() << endl;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    while(n > 0){
        int op;
        cin >> op;
        if(op == 1){
            int num;
            cin >> num;
            Enqueue(num);
        }
        else if(op == 2){
            Dequeue();
        }
        else if(op == 3){
            Print();
        }
        n--;
    }
    return 0;
}

//一个不会超时的版本，超聪明！！！每次倒完都不用倒回去！！！
#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> Front,Rear;
    int Q;
    cin >> Q;
    while(Q--)
    {
        int type, x;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            Rear.push(x);
        }    
        else 
        {
           if(Front.empty())
           { // move all the elements from "Rear" stack to "Front" stack
               while(!Rear.empty())
               {
                   Front.push(Rear.top());
                   Rear.pop();
               }   
            }    
           if(!Front.empty())
           {
               if(type == 2) Front.pop();
               if(type == 3) cout << Front.top() << endl;
           }  
        }   
    }    
    return 0;
}
