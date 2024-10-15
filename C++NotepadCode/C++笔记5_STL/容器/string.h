#pragma once
#include <cstddef>
namespace emansis {
	class string {
	public:
#pragma region �������
		string(const char* src = "");
		~string();
#pragma endregion
#pragma region ���������
		typedef char* iterator;
		iterator begin();
		iterator end();
#pragma endregion


		const char* c_str() const;
		size_t size() const;
		char& operator[](size_t index);

	private:
		char* m_pData;
		size_t m_uCapacity;
		size_t m_uSize;
	};
}