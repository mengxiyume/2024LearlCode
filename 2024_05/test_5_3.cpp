#define _CRT_SECURE_NO_WARNINGS

//堆练习

//堆底层可以就是一个数组，数组堆简单而抽象

typedef int HeapDataType, HPData;

class Heap {
private:

#pragma region Values
	HPData* data;
	int size;
	size_t capacity;
#pragma endregion


public:

#pragma region 构造相关重载
	//TODO:构造与析构的处理
	Heap() {

	}
	~Heap() {

	}

#pragma endregion

#pragma region 堆结构的常规操作

	//TODO:完成堆操作的书写

#pragma endregion

};