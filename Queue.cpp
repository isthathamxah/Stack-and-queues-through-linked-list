#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* prev;
    Node* next;

    Node(T value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    Node<T>* frontNode;
    Node<T>* rearNode;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void insert(T value);    
    void remove();           
    T front();
    T rear();
    void display();
};

template <typename T>
Queue<T>::Queue()
{
    frontNode = nullptr;
    rearNode = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    while (!isEmpty())
    {
        remove();
    }
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return frontNode == nullptr;
}

template <typename T>
void Queue<T>::insert(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (isEmpty())
    {
        frontNode = rearNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
        newNode->prev = rearNode;
        rearNode = newNode;
    }

    cout << "Inserted: " << value << endl;
}

template <typename T>
void Queue<T>::remove()
{
    if (isEmpty())
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    Node<T>* temp = frontNode;
    T removedValue = frontNode->data;
    frontNode = frontNode->next;

    if (frontNode != nullptr)
    {
        frontNode->prev = nullptr;
    }
    else
    {
        rearNode = nullptr;
    }

    delete temp;
    cout << "Removed: " << removedValue << endl;
}

template <typename T>
T Queue<T>::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return T();
    }
    return frontNode->data;
}

template <typename T>
T Queue<T>::rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return T();
    }
    return rearNode->data;
}

template <typename T>
void Queue<T>::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node<T>* current = frontNode;
    cout << "Queue (Front to Rear):" << endl;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Queue<int> q;
    int choice, value;

    while (true)
    {
        cout << "\n===== Queue Menu =====" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Rear Element" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.insert(value);
            break;

        case 2:
            q.remove();
            break;

        case 3:
            cout << "Front element: " << q.front() << endl;
            break;

        case 4:
            cout << "Rear element: " << q.rear() << endl;
            break;

        case 5:
            q.display();
            break;

        case 6:
            if (q.isEmpty())
                cout << "Queue is empty!" << endl;
            else
                cout << "Queue is not empty!" << endl;
            break;

        case 0:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }
}
