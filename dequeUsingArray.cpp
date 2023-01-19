#include <iostream>
using namespace std;

// Double Ended Queue using Array

// Global
const int q_size = 50;
int deque[q_size];
int head = q_size - 1;
int tail = q_size - 1;

void show()
{
    cout << "Deque: [";
    for (int i = head + 1; i <= tail; i++)
    {
        cout << deque[i];
        if (i < tail)
        {
            cout << ", ";
        }
    }
    cout << "]\n"
         << endl;
    ;
}

// insert at head
void enqueueHead(int item)
{
    if (head > 0)
    {
        deque[head] = item;
        head--;
        cout << item << " inserted at head." << endl;
        show();
    }
    else
    {
        cout << "Overflow!!!" << endl;
    }
}
// insert at tail
void enqueueTail(int item)
{
    if (head >= 0)
    {
        for (int i = head; i <= tail; i++)
        {
            // shifting all the elements to left by one,
            // making room for the new item at tail.
            deque[i - 1] = deque[i];
        }
        // new item at tail
        deque[tail] = item;
        head--;
        cout << item << " inserted at tail." << endl;
        show();
    }
    else
    {
        cout << "Overflow!!!" << endl;
    }
}

// remove at head
void dequeueHead()
{
    if (head < tail)
    {
        cout << deque[head + 1] << " removed." << endl;
        head++;
        show();
    }
    else
    {
        cout << "Underflow!!!" << endl;
    }
}

// remove at tail
void dequeueTail()
{
    if (head < tail)
    {
        cout << deque[tail] << " removed." << endl;
        for (int i = tail; i > head; i--)
        {
            deque[i] = deque[i - 1];
        }
        head++;
        show();
    }
    else
    {
        cout << "Underflow!!!" << endl;
    }
}

// Driver code
int main()
{
    dequeueTail();

    enqueueHead(1);

    enqueueTail(2);

    dequeueTail();

    enqueueHead(3);

    enqueueHead(4);

    dequeueHead();

    enqueueTail(5);

    return (0);
}