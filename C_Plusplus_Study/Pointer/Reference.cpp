#include <iostream>
using namespace std;

// // ����
//
//struct StatInfo
//{
//	int hp;  // +0
//	int attack; // +4
//	int defence; // +8
//};
//
//// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
//void CreateMonster(StatInfo* info)
//{
//	info->hp = 100;
//	info->attack= 8;
//	info->defence= 5;
//}
//									// �Լ� Ż�� �� ����
//// [�Ű�����][RET][��������(info)]  [�Ű�����(info(100, 8, 5)][RET][��������]
//void CreateMonster(StatInfo info)
//{
//	info.hp = 100;
//	info.attack = 8;
//	info.defence = 5;
//}
//
//// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ���� ����
//
//// 1) �� ���� ���
//
//void PrintInfoByCopy(StatInfo info)
//{
//	cout << "-----------------------" << endl;
//	cout << "HP: " << info.hp << endl;
//	cout << "ATT: " << info.attack << endl;
//	cout << "DEF: " << info.defence << endl;
//	cout << "-----------------------" << endl;
//}
//
//// Ư�� ������ �����ϴ� ���͸� ã�� �Լ�
//StatInfo* FindMonster()
//{
//	// TODO : Heap �������� ������ ã�ƺ�
//	// ã�Ҵ�!
//	// return monster~;
//
//	return nullptr;
//}
//
//// 2) �ּ� ���� ���
//StatInfo globalInfo;
//void PrintInfoByPtr(const StatInfo* const info)
//{
//	if (info == nullptr)
//		return;
//
//	cout << "-----------------------" << endl;
//	cout << "HP: " << info->hp << endl;
//	cout << "ATT: " << info->attack << endl;
//	cout << "DEF: " << info->defence << endl;
//	cout << "-----------------------" << endl;
//
//	// �� �ڿ� ���δٸ�?
//	// StatInfo* const info
//	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
//	// info�� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�.
//
//	// �� ������ ���δٸ�?
//	// const StatInfo* info
//	// info�� '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲ� �� ����
//	// '����' �ٱ����� ���빰�� �ٲ� �� ����
//
//	// info[ �ּҰ� ]   �ּҰ� [ ������ ]
//	//info = &globalInfo;
//
//	//info->hp = 10000;
//}
//
//// StatInfo ����ü�� 1000����Ʈ¥�� ���� ����ü���?
//// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� ����Ǵ�
//// - (�ּ� ����) StatInfo*�� 8����Ʈ
//// - (���� ����) StatInfo&�� 8����Ʈ
//
//// 3 ) ���� ���� ���
//// �� ����ó�� ���ϰ� ����ϰ�!
//// �ּ� ����ó�� �ּҰ��� �̿��� ������ �ǵ帮��!
//// �ϼ������� ���!
//
//void PrintInfoByRef(StatInfo& info) 
//{
//	cout << "-----------------------" << endl;
//	cout << "HP: " << info.hp << endl;
//	cout << "ATT: " << info.attack << endl;
//	cout << "DEF: " << info.defence << endl;
//	cout << "-----------------------" << endl;
//
//}
//
//#define OUT 
//
//void ChangeInfo(OUT StatInfo& info)
//{
//	info.hp = 1000;
//}
//
//int main()
//{
//	// 4����Ʈ ������ �ٱ��ϸ� ����Ҳ���.
//	// ������ �� �ٱ��� �̸��� number��� �Ҳ�.
//	// �׷��ϱ� number���� �� �����ų�, number�� �� �ִ´ٰ� �ϸ�
//	// �������� �˾Ƶ�� �ش� �ּ�(data, stack, heap)�� 1�� �־��ָ� �ȴ�!
//	int number = 1;
//
//	// * �ּҸ� ��� �ٱ���
//	// int �� �ٱ��ϸ� ���󰡸� int�� ������(�ٱ���)�� ����
//	int* pointer = &number;
//	// pointer �ٱ��Ͽ� �ִ� �ּҸ� Ÿ�� �̵��ؼ�, �� �ָ� �ִ� �ٱ��Ͽ� 2�� �ִ´�
//	*pointer = 2;
//
//	// �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���
//	// ������ �����غ��� �����Ͷ� 100% �Ȱ���.
//	int& reference = number;
//	
//	// C++ ���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��.
//	// number��� �ٱ��Ͽ� reference��� �ٸ� �̸��� �����ٰ�~
//	// ������ reference �ٱ��Ͽ��ٰ� �� �����ų� ������,
//	// ���� number �ٱ���(�������ٰ�) �� ���� �����ų� ������ ��!
//	reference = 3;
//
//	// �׷��� ������ �� �ٸ� �̸��� ���� ������?
//	// �׳� number = 3 �̶�� �ص� �Ȱ�����...
//	// ���� ���� ����!
//
//	StatInfo info;
//	CreateMonster(&info);
//
//	// .�� Ȱ���ؼ� ����ϰ� ������ ȿ���� ������
//	PrintInfoByCopy(info);
//	
//	// ����: ȿ������ ���� // ���� : ȭ��ǥ�� ������(��뼺�� ���� ����)
//	PrintInfoByPtr(&info);
//
//	// ���� ��� ���� ���̰� �ִ�. // ���� ��ü�� �����͸� �ѱ�°Ŷ� �Ȱ���.
//	PrintInfoByRef(info);
//
//	// ������ vs ����
//	// ���� : �Ȱ���
//	// ���Ǽ� : ����
//	
//	// 1) ���Ǽ� ����
//	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
//	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִ�.
//	// ������ �ڿ������� �𸣰� ����ĥ ���� �ִ�.
//
//	// 2) �ʱ�ȭ ����
//	// ���� Ÿ���� �ٱ����� 2���� �̸� (��Ī?)
//	// -> �����ϴ� ����� ������ �ȵ�
//	// �ݸ� �����ʹ� �׳� �~ �ּҶ�� �ǹ�
//	// -> ����� �������� ���� ���� ����
//	// �����Ϳ��� '����'�� �ǹ̷�? = nullptr;
//	// ���� Ÿ���� �̷� nullptr�� ������ ����.
//
//	StatInfo* pointerStat;
//	//pointerStat = &info;
//	//PrintInfoByPtr(pointerStat);
//
//	StatInfo& referenceStat = info;
//	PrintInfoByRef(referenceStat);
//
//
//	// �׷��� �����?
//	// ��� Team By Team... ������ ���� ����.
//	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ ������ ���
//	// ex) �𸮾� �������� reference�� �ֿ�
//
//	// ���� ��ȣ ��Ÿ��)
//	// - ���� ��쵵 ����ؾ� �Ѵٸ� pointer (null üũ �ʼ�)
//	// - �ٲ��� �ʰ� �д� �뵵(readonly)�� ����ϸ� const ref& 
//	// -  �� �� �Ϲ������� ref (��������� ȣ���� �� OUT�� ���δ�)
//	// -- ��, �ٸ� ����� pointer�� ���������� �̾ ����ٸ�, ��� pointer (���� ������� �ʴ´�)
//	ChangeInfo(OUT info);
//
//	// Bonus) �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
//	// pointer [ �ּ�(&info) ]  info[ ������ ]
//	PrintInfoByRef(*pointerStat);
//
//	// Bonums) ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
//	// pointer [ �ּ� ]  reference, info[ ������ ]
//	PrintInfoByPtr(&referenceStat);
//	return 0;
//}