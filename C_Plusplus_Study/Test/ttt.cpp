#include <iostream>
#include <vector>

using namespace std;

class Knight
{
public:
    Knight() { cout << "������ ȣ��" << endl; }
    Knight(const Knight& a) { cout << "���� ������ ȣ��" << endl; }
    ~Knight() { cout << "�Ҹ��� ȣ��" << endl; }

public:
    int _hp = 100;

    void SetHp(Knight* _this, int hp)
    {
     
    }
};

int main()  
{
   
    // 
    {
        shared_ptr<Knight> knight = make_shared<Knight>();
        
        knight->SetHp(knight.get(), 1);
    }
    
    
    // �����ڰ� ȣ�� �ǰ� sethp�� �ҋ� ���� �����ڰ� ȣ���� �Ǹ� 
    // setHP ȣ�⽺�ù����� �Ѿ�� �Ҹ��ڰ� ȣ���� �ǰ�
    // cout ���� ������ Knight c�� �Ҹ��ڰ� ȣ���� �ȴ�.
    
    return 0;
}