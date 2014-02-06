#include<iostream>
using namespace std;

class stack{
public:
  stack(int size = 1000){
    buf = new int[size];
    cur = -1;
  }
  ~stack()
  {
   delete []buf;
  }
  void push(int val){
    buf[++cur] = val;
  }
  int pop(){
    if (!isEmpty())
      return buf[cur--];
    else{
      cout<<"empty pop ge mao? "<<endl;
      return 0;
    }
  }
  bool isEmpty(){
    return cur==-1;
  }

private:
  int* buf;
  int cur;
};

class queue{
public:
  queue(){}
  ~queue(){}
  void enqueue(int val){
    s1.push(val);
  }
  int dequeue(){
    while(!s1.isEmpty())
      s2.push(s1.pop());
    return isEmpty()?0:s2.pop();
  }
  bool isEmpty(){
    return s2.isEmpty();
  }
private:
  stack s1;
  stack s2;
};
int main()
{
  queue q; 
  int a[10] = {9,1,2,3,4,5,5,6,7,8};
  for (int i=0; i<10; i++)
    q.enqueue(a[i]);
  for (int i=0; i<10; i++)
    cout<<q.dequeue()<<" ";
  return 0;
}
