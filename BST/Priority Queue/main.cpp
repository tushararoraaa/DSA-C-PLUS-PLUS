#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {

    }

    bool isEmpty()
    {
        return pq.size()==0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void Insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex>0)
        {
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex])
            {
                swap(pq[childIndex],pq[parentIndex]);
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int parentIndex = 0;
        int LChildIndex = (2*parentIndex)+1;
        int RChildIndex = (2*parentIndex)+2;

        while(LChildIndex<pq.size())
        {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[LChildIndex])
            {
                minIndex = LChildIndex;
            }
            if(RChildIndex<pq.size() && pq[minIndex] > pq[RChildIndex])
            {
                minIndex = RChildIndex;
            }
            if(minIndex == parentIndex)
            {
                break;
            }
            swap(pq[minIndex],pq[parentIndex]);
            parentIndex = minIndex;
            LChildIndex = (2*parentIndex)+1;
            RChildIndex = (2*parentIndex)+2;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue p1;
    p1.Insert(10);
    p1.Insert(20);
    p1.Insert(100);
    p1.Insert(30);
    p1.Insert(60);
    p1.Insert(200);
    p1.Insert(101);
    p1.Insert(41);

    cout<<p1.getMin()<<endl;
    while(!p1.isEmpty())
    {
        cout<<p1.removeMin()<<endl;
    }
    return 0;
}
