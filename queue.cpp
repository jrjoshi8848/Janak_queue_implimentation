#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
template <class x>
class queue
{
   public:
    int front,rear,maxSize;
    x* array;
    queue(int m) // Constructor for creating queue
       {
         front=-1;
         rear=-1;
         maxSize=m;
         array=new x[m];
        }
    bool isFull()
     {
       if(front == 0 && rear == maxSize - 1)
        {
           return true;
        }
       return false;
     }
    bool isEmpty()
     {
       if(front == -1)
         return true;
       else return false;
      }
    int enQueue(int value)
    {
       if(isFull())
          {
           cout << endl<< "\nQueue is full!!\n";
           return 0;
          }
        else {
              if(front == -1)
                front = 0;
              rear++;
              array[rear] = value;
              cout << value << " EnQueued ";
              return 0;
             }
    }
    int deQueue()
    {
         int value;
         if(isEmpty())
            {
              cout << "\nQueue is empty!!" << endl;
              return(-1);
            }
        else
            {
              value = array[front];
              if(front >= rear)
                {
                 front = -1;
                 rear = -1;
                }
              else
                {
                 front++;
                }
              cout << endl << "\nDeleted => " << value << " from queue";
              return(value);
           }
    }
    void displayQueue()
    {
     int i;
      if(isEmpty())
        {
         cout << endl << "\nQueue is Empty!!\n" << endl;
        }
     else
     {
         cout << endl << "Front = " << front;
         cout << endl << "Queue elements : ";
        for(i=front; i<=rear; i++)
        cout << array[i] << "\t";
        cout << endl << "Rear = " << rear << endl;
      }
    }
};
int main()
{
    int m,c,e,i=1;
    cout<<"Enter size of queue : ";
    cin>>m;
    queue<int> myq(m);
    while(i)
    {

    cout<<"\n\t\t\twhat would you ike to do"<<endl<<"1.Enqueue\n2.Dequeue\n3.Display Queue\n4.exit\n\n\t\tEnter choice : ";
    cin>>c;
    switch(c)
    {
      case 1:
        cout<<"Enter the element to Enqueue: ";
        cin>>e;
        myq.enQueue(e);
        break;
     case 2:
        myq.deQueue();
        break;
     case 3:
      myq.displayQueue();
      break;
     case 4:
     i=0;
     break;
    default:
        cout<<"Wrong Choice!!!!"<<endl;
        break;
    }
    }
return 0;
}
