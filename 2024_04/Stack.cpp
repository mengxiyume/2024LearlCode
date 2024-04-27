#include <iostream>
#include <string>
using namespace std;

#include <stdlib.h>
#include <assert.h>

class Stack {
public:
    typedef char dataType;
    dataType* m_arrData;
    int m_iTop;     //存放下标，负数为没有数据
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
        return (bool)(m_iTop + 1);
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
            //匹配符号，左半入栈，右半出栈
            //无法出栈或出栈结果非匹配符号返回false
            if (curCh == '(' || curCh == '{' || curCh == '[') {
                //入栈
                st->push(curCh);
            }
            else if (curCh == ')' || curCh == '}' || curCh == ']') {
                //出栈
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

int main()
{
    Solution s;
    string str = "({{{{}}}))";
    cout << s.isValid(str) << endl;

    return 0;
}