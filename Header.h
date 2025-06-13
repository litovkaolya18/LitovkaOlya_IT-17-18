#pragma once
#include <stdexcept>
#include <string>
using namespace std;

//����� Queue ��������� �������
class Queue 
{
private:
    //������������ �������� �������
    struct QueueNode 
    {
        double Value;     // �������� ��������
        QueueNode* Next; // ��������� �� ��������� ������� �������
        QueueNode(double val) : Value(val), Next(nullptr) {}
    };

    QueueNode* Head;    // ��������� �� ������ ������� (��� ����������)
    QueueNode* Tail;    // ��������� �� ����� ������� (��� ����������)
    size_t CurrentSize; // ������������ ������� ���������� ��������� � �������
     
public:
    Queue();
    ~Queue();

    void push(double value);  // ��������� � �����
    double pop();             // ��������� �� ������
    double front() const;     // ������������� ������ �������
    size_t size() const;      // ������ �������
    void clear();             // ������� �������
    bool empty() const;       // ��������� �� �������
};

// ����� ���������� QueueException ��� ��������� ������
class QueueException : public runtime_error
{
public:
    explicit QueueException(const string& message) : runtime_error(message) {}
};