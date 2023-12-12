#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ���� ���� (forwarding reference)

class Knight
{
public:
	Knight() { cout << "�⺻ ������" << endl; }
	Knight(const Knight&) { cout << "���� ������" << endl; } // ���� ����
	Knight(Knight&&) noexcept { cout << "�̵� ������" << endl; } // ����ȭ�� ����
	~Knight() { cout << "�Ҹ���" << endl; }
};

void Test_RValueRef(Knight&& k) // ������ ����
{
	
}

void Test_Copy(Knight k)
{

}

template<typename T>
void Test_ForwardingRef(T&& param) // ���� ���� , ������ �տ� const�� ���̰ų� �ϸ� �������� X
{
	// �ް� ������� ����
	// ������ ������� �̵�
	// �Ѵ� ���ش�
	Test_Copy(std::forward<T>(param));
	// �ް� ������� ����
	Test_Copy(param);
	// ������ ������� �̵�
	Test_Copy(std::move(param));
}

int main()
{
	// ���� ����(universal reference)
	// ���� ���� (forwarding reference) C++17

	// &&		&�� �� �� ���� -> ������ ����
	// &&		

	Knight k1;
	
	Test_RValueRef(std::move(k1)); // rvalue_cast

	Test_ForwardingRef(k1);
	Test_ForwardingRef(std::move(k1));

	auto&& k2 = k1;
	auto&& k3 = std::move(k1);

	// ������ : ���� ���� (type deduction)�� �Ͼ ��

	// ���� ������ �����ϴ� ���
	// -----------------------------------

	Knight& k4 = k1; // �ް� ����
	Knight&& k5 = std::move(k1); // ������ ����

	// ������ : �ް��� �ƴϴ� = ���ϽĿ��� ����� ��� X
	// ������ ���� : �������� ������ �� �ִ� ���� Ÿ��
	//Test_RValueRef(std::move(k5));

	Test_ForwardingRef(k1);
	Test_ForwardingRef(std::move(k1));

	return 0;
}