#include <iostream>

using namespace std;

class dynamicArray{
private:
    int *data;
    int nextIndex;
    int capacity;
public:
    dynamicArray(){
        data = new int[5];
        nextIndex=0;
        capacity = 5;
    }

    dynamicArray(dynamicArray const &d){ //deep copy
        this->data = new int[d.capacity];
        for(int i = 0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int element){

    if(nextIndex==capacity){
       int *newData = new int[2*capacity];
       for(int i = 0; i<capacity; i++){
        newData[i] = data[i];
       }
       delete [] data;
       data = newData;
       capacity *= 2;
    }
    data[nextIndex] = element;
    nextIndex++;
    }

    int get(int index){
        if(index<nextIndex){
            return data[index];
        }else{
            return -1;
        }
    }

    void print(){
        for(int i =0; i<nextIndex; i++){
            cout<<data[i]<<endl;
        }
    }

    void add(int index, int element){
        if(index<nextIndex){
            data[index] = element;
        }else if(index==nextIndex){
            add(element);
        }else{
            return;
        }
    }


};

int main()
{
    dynamicArray arr1;
    arr1.add(10);
    arr1.add(20);
    arr1.add(30);
    arr1.add(40);
    arr1.add(50);
    arr1.add(60);
    arr1.add(70);

    arr1.print();

    dynamicArray arr2 = arr1;  //copy constructor with shallow copy
    arr1.add(12);
    arr2.print();

    return 0;
}
