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
class Stack
{
private:
    Node<T>* topNode;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(T value);
    void pop();
    T top();
    void display();
};

template <typename T>
Stack<T>::Stack()
{
    topNode = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return topNode == nullptr;
}

template <typename T>
void Stack<T>::push(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (isEmpty())
    {
        topNode = newNode;
    }
    else
    {
        newNode->prev = topNode;
        topNode->next = newNode;
        topNode = newNode;
    }

    cout << "Pushed: " << value << endl;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return;
    }

    Node<T>* temp = topNode;
    T poppedValue = topNode->data;
    topNode = topNode->prev;

    if (topNode != nullptr)
    {
        topNode->next = nullptr;
    }

    delete temp;
    cout << "Popped: " << poppedValue << endl;
}

template <typename T>
T Stack<T>::top()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return T();
    }
    return topNode->data;
}

template <typename T>
void Stack<T>::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    Node<T>* current = topNode;
    cout << "Stack (Top to Bottom):" << endl;
    while (current)
    {
        cout << current->data << endl;
        current = current->prev;
    }
    cout << endl;
}

int main()
{
    Stack<int> s;
    int choice, value;

    while (true)
    {
        cout << "\n===== Stack Menu =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top Element" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            cout << "Top element: " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            if (s.isEmpty())
                cout << "Stack is empty!" << endl;
            else
                cout << "Stack is not empty!" << endl;
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
