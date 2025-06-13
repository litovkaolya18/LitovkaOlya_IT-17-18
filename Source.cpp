#include "Header.h"

// ��������� �� ������ ������� � �����
Queue::Queue() : Head(nullptr), Tail(nullptr), CurrentSize(0) {}

//��� ������������ ������
Queue::~Queue() 
{
    clear();
}

// ����� ��� ���������� �������� � ����� �������
void Queue::push(double value) 
{
    QueueNode* newNode = new QueueNode(value);
    if (empty())
    {
        Head = Tail = newNode;  // ������������� Head � Tail �� ����� ����
    }
    else 
    {
        Tail->Next = newNode; // ���������, ��� ������� Tail ��������� �� ����� ����
        Tail = newNode;   // ��������� Tail ��� �������� �� ����� ����
    }
    CurrentSize++;
}

// ����� ��� ���������� �������� �� ������ �������
double Queue::pop()
{
    if (empty()) 
    {
        throw QueueException("error");
    }

    //��������� ��������� �� ������ ������� ������� 
    QueueNode* tempNode = Head;
    double value = tempNode->Value;
    Head = Head->Next;

    if (Head == nullptr) 
    {
        Tail = nullptr; //��� ��� ������� ������ �����, �� tail � nullptr
    }

    delete tempNode;
    CurrentSize--;
    return value;
}

// ����� ��� ��������� �������� ������� �������� �������
double Queue::front() const 
{
    if (empty()) 
    {
        throw QueueException("error");
    }
    return Head->Value;
}

// ����� ��� ��������� �������� ���������� ��������� � �������
size_t Queue::size() const 
{
    return CurrentSize;
}

// ����� ��� ������� �������
void Queue::clear() 
{
    while (!empty()) 
    {
        pop();
    }
}

// ����� ��� ��������, ����� �� �������
bool Queue::empty() const 
{
    return Head == nullptr;
}