#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
   private:
    int queue[MAX_SIZE];
    int head, tail;

   public:
    Queue() {
        head = MAX_SIZE - 1;
        tail = MAX_SIZE - 1;
    }

    void enqueue(int data) {  // insert
        if (head >= 0) {
            cout << data << " inserted." << endl;
            queue[head] = data;
            head--;
        } else {
            cout << "Queue Full!!!" << endl;
        }
    }

    void dequeue() {  // remove
        if (head != tail) {
            cout << queue[tail] << " removed." << endl;
            for (int i = tail; i > head; i--) {
                queue[i] = queue[i - 1];
            }
            head++;

        } else {
            cout << "Queue Empty!!!" << endl;
        }
    }
    void printQueue() {
        cout << "Queue: [";
        for (int i = head + 1; i <= tail; i++) {
            cout << queue[i];
            if (i < tail) {
                cout << ", ";
            }
        }
        cout << "]\n" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.printQueue();

    q.enqueue(2);
    q.printQueue();

    q.enqueue(3);
    q.printQueue();

    q.dequeue();
    q.printQueue();

    q.dequeue();
    q.printQueue();
    return 0;
}