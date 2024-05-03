#include <iostream>
#include <string>
using namespace std;

#include <stdlib.h>
#include <assert.h>

class Stack {
public:
    typedef int dataType;
    dataType* m_arrData;
    int m_iTop;     //����±꣬����Ϊû������
    int m_nCapacity;
    void push(dataType x) {
        if (m_nCapacity == 0 || (m_iTop + 1 >= m_nCapacity && m_nCapacity != 0)) {
            dataType* newData = (dataType*)realloc(m_arrData, sizeof(dataType) * (!m_nCapacity ? 4 : m_nCapacity * 2));
            assert(newData);
            m_arrData = newData;
            m_nCapacity = (!m_nCapacity ? 4 : m_nCapacity * 2);
        }
        m_iTop++;
        m_arrData[m_iTop] = x;
    }
    void pop() {
        assert(m_iTop >= 0);
        m_iTop--;
    }
    dataType top() {
        assert(m_iTop >= 0);
        return m_arrData[m_iTop];
    }
    int size() {
        return m_iTop + 1;
    }
    bool empty() {
        return !(bool)(m_iTop + 1);
    }

    Stack() {
        m_arrData = nullptr;
        m_iTop = -1;
        m_nCapacity = 0;
    }
    ~Stack() {
        if (m_arrData) {
            free(m_arrData);
            m_arrData = nullptr;
        }
    }
};

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();

        Stack* st = new Stack();
        for (int i = 0; i < len; i++) {
            char curCh = s.at(i);
            //ƥ����ţ������ջ���Ұ��ջ
            //�޷���ջ���ջ�����ƥ����ŷ���false
            if (curCh == '(' || curCh == '{' || curCh == '[') {
                //��ջ
                st->push(curCh);
            }
            else if (curCh == ')' || curCh == '}' || curCh == ']') {
                //��ջ
                if (st->size() == 0) {
                    delete st;
                    return false;
                }
                char topCh = st->top();
                st->pop();
                if (((topCh == '(' && curCh != ')') ||
                     (topCh == '{' && curCh != '}') ||
                     (topCh == '[' && curCh != ']'))) {
                    delete st;
                    return false;
                }
            }
        }
        bool ret = true;
        if (st->size()) {
            ret = false;;
        }

        delete st;
        return ret;
    }
};

class MyQueue {
private:
    Stack* outputStack;
    Stack* inputStack;

public:

    MyQueue() {
        outputStack = new Stack();
        inputStack = new Stack();
    }
    ~MyQueue() {
        delete(outputStack);
        delete(inputStack);
        inputStack = outputStack = nullptr;
    }

    void push(int x) {
        inputStack->push(x);
    }

    int pop() {
        int retQueueFrontData = this->peek();
        outputStack->pop();
        return retQueueFrontData;
    }

    int peek() {
        if (outputStack->empty()) {
            //������ĿҪ����Բ������������ȵ������
            while (!inputStack->empty()) {
                int newQueueBackData = inputStack->top();
                inputStack->pop();
                outputStack->push(newQueueBackData);
            }
        }
        int retQueueFrontData = outputStack->top();
        return retQueueFrontData;
    }

    bool empty() {
        return (inputStack->empty() && outputStack->empty());
    }
};

void test_01() {
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue->peek() << endl; // return 1
    cout << myQueue->pop() << endl; // return 1, queue is [2]
    cout << myQueue->empty() << endl; // return false
}

//int main() {
//    //Solution s;
//    //string str = "({{{{}}}))";
//    //cout << s.isValid(str) << endl;
//
//    test_01();
//
//    return 0;
//}