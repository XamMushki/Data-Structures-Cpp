#include <iostream>
using namespace std;

const int queue_size = 50;
int queue[queue_size];
int head = queue_size - 1;
int tail = queue_size - 1;

void showQueue()
{
    int h = head;
    h++;
    cout<<"Queue: ";
    while (h <= tail)
    {
        cout << queue[h] << " ";
        h++;
    }
    cout << "\n";
}

void enqueue(int item)
{
    queue[head] = item;
    head--;
    cout << "\nEnqueue --> " << item << endl;
    showQueue();
}

void dequeue()
{
    int t = tail;
    cout << "\nDequeue --> " << queue[tail] << endl;
    ;
    while (t > head)
    {
        queue[t] = queue[t - 1];
        t--;
    }
    head++;
    showQueue();
}

int main()
{

    enqueue(3);
    enqueue(2);
    enqueue(1);
    dequeue();
    enqueue(13);
    dequeue();
    return (0);
}