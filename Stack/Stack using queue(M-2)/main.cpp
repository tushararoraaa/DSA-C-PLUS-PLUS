#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack{
    queue<int> q1;
    queue <int> q2;
    int curr_size;
public:
    Stack(){
        curr_size = 0;
    }
    void push(int element){
        q1.push(element);
        curr_size++;
    }
    int pop(){
        while(q1.size() != 1 ){
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        swap(q1,q2);
        curr_size--;
        return result;

    }
    int top()
    {
        if (q1.empty())
            return -1;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // last pushed element
        int temp = q1.front();

        // to empty the auxiliary queue after
        // last operation
        q1.pop();

        // push last element to q2
        q2.push(temp);

        // swap the two queues names
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }
    int size(){
        return curr_size;
    }
};

int main()
{
    Stack s1;
    s1.push(11);
    s1.push(13);
    s1.push(15);
    s1.push(17);
    s1.push(19);
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;

    return 0;
}
