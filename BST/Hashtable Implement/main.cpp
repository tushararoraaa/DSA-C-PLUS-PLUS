#include <iostream>
#include<bits/stdc++.h>

using namespace std;

template <typename V>
class Mapnode
{
public:
    string key;
    V value;
    Mapnode *next;
    Mapnode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Mapnode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    Mapnode<V> ** buckets;
    int count;
    int numBuckets;

    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int current_coeff = 1;

        for(int i = key.length()-1; i>=0 ; i--)
        {
            hashcode += key[i]*current_coeff;
            hashcode = hashcode%numBuckets;
            current_coeff *= 37;
            current_coeff = current_coeff%numBuckets;
        }

        return hashcode%numBuckets;
    }

    void rehash(){
        Mapnode<V>** temp = buckets;
        buckets = new Mapnode<V>*[2*numBuckets];
        for(int i = 0; i<(2*numBuckets); i++){
            buckets[i] = NULL;
        }
        int oldBucketsCount = numBuckets;
        numBuckets *=2;
        count = 0;

        for(int i = 0; i<oldBucketsCount; i++){
            Mapnode<V>* head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;
                Insert(key,value);
                head = head->next;
            }
        }

        for(int i = 0; i<oldBucketsCount; i++){
            Mapnode<V> *head = temp[i];
            delete head;
        }
        delete [] temp;
    }

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new Mapnode<V>*[numBuckets];
        for(int i =0; i<numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for(int i =0; i<numBuckets; i++)
        {
            delete buckets[i];
        }
        delete [] buckets;
    }

    V GetValue(string key)
    {
        int bucketIndex = getBucketIndex(key);

        Mapnode<V> *head = buckets[bucketIndex];

        while(head!=NULL)
        {
            if(head->key == key)
            {
                return head->value ;
            }
            head= head->next;
        }
        return 0;
    }

    void Insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);

        Mapnode<V> *head = buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key == key)
            {
                head->value = value;
                return ;
            }
            head= head->next;
        }
        head = buckets[bucketIndex];
        Mapnode<V> *node = new Mapnode<V>(key,value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.0*count)/numBuckets;

        if(loadFactor>0.7){
            rehash();
        }
    }

    void Remove(string key)
    {
        int bucketIndex = getBucketIndex(key);

        Mapnode<V> *head = buckets[bucketIndex];
        Mapnode<V> *prev = NULL;
        while(head!=NULL)
        {
            if(head->key == key)
            {
                if(prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V Val = head->value;
                head->next = NULL;
                delete head;
                count--;
                return Val;
            }
            prev = head;
            head= head->next;
        }
        return 0;
    }

    int size(){
        return count;
    }
};


int main()
{
    ourmap<int> m;
    for(int i = 0; i<10; i++){
        char c = '1' + i;
        string key = "abc";
        key = key+c;
        int value = i+1;
        m.Insert(key,value);
    }
    cout<<"Size = "<<m.size()<<endl;

    for(int i = 0; i<10; i++){
        char c = '1' + i;
        string key = "abc";
        key = key+c;
        cout<<key<<" : "<<m.GetValue(key)<<endl;
    }
    return 0;
}
