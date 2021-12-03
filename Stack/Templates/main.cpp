#include <iostream>

using namespace std;

template <typename T, typename V>

class Pair{
    T x;
    V y;
public:
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }

    void setY(V y){
        this->y = y;
    }

    V getY(){
        return y;
    }

};

int main()
{
    Pair <int,double> p1;
    p1.setX(100.123);
    p1.setY(120.243);
    cout<<p1.getX()<<endl;
    cout<<p1.getY()<<endl;

    Pair <Pair<int,int> , int> p2;
    p2.setY(16);
    Pair<int, int> p4;
    p4.setX(14);
    p4.setY(15);
    p2.setX(p4);

    cout<<p2.getX().getX()<<endl;
    cout<<p2.getX().getY()<<endl;
    cout<<p2.getY()<<endl;
    return 0;
}
