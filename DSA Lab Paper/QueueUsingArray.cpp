#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue()
    {
        if (front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    void display()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void maximum()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int maxVal = arr[front];
        for (int i = front + 1; i <= rear; i++)
        {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        cout << "Maximum value: " << maxVal << endl;
    }

    void reverse()
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int start = front;
        int end = rear;
        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        cout << "Queue reversed" << endl;
    }

    void search(int value)
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            if (arr[i] == value)
            {
                cout << "Value " << value << " found at index " << i << endl;
                return;
            }
        }

        cout << "Value not found in queue" << endl;
    }

    void removeValue(int value)
    {
        if (front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int pos = -1;

        for (int i = front; i <= rear; i++)
        {
            if (arr[i] == value)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Value not found, cannot remove" << endl;
            return;
        }

        for (int i = pos; i < rear; i++)
        {
            arr[i] = arr[i + 1];
        }

        rear--;
        cout << "Removed value: " << value << endl;
    }

    void copyFrom(const Queue &other)
    {
        size = other.size;
        front = other.front;
        rear = other.rear;
        arr = new int[size];
        for (int i = front; i <= rear; i++)
        {
            arr[i] = other.arr[i];
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of the queue: ";
    cin >> n;
    Queue q(n);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
       
    q.display();

    q.search(30);
    q.removeValue(30);

    q.display();

    q.maximum();
    q.dequeue();
    q.display();
    
    Queue q1(n);
    q1.copyFrom(q);
    q1.display();

    return 0;
}
