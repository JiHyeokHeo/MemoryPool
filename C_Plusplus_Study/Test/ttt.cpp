#include <iostream>
#include <vector>

using namespace std;

class Knight
{
public:
    Knight() { cout << "생성자 호출" << endl; }
    Knight(const Knight& a) { cout << "복사 생성자 호출" << endl; }
    ~Knight() { cout << "소멸자 호출" << endl; }

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
    
    
    // 생성자가 호출 되고 sethp를 할떄 복사 생성자가 호출이 되며 
    // setHP 호출스택범위를 넘어가면 소멸자가 호출이 되고
    // cout 끝난 다음에 Knight c가 소멸자가 호출이 된다.
    
    return 0;
}