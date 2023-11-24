#include <iostream>
using namespace std;

// 다중 포인터

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "Bye";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	//cout << a << endl;

	// .rdata  Hello주소[H][e][l][l][o][\0]
	// .rdata  Bye주소[B][y][e][\0]
	// msg [ Hello주소 ] << 8바이트 
	const char* msg = "Hello";

	// [매개변수][RET][지역변수(msg(Hello주소)] [매개변수(a(Bye주소))][RET][지역변수]
	//SetMessage(msg);
	SetMessage(&msg);
	cout << msg << endl; 

	// 주소2[ ] << 1바이트 
	// 주소1[ 주소2 ] << 8바이트 
	// pp[ 주소1 ] << 8바이트
	const char** pp = &msg;
	
	// 다중 포인터 : 혼돈스럽다?
	// 그냥 양파까기라고 생각하면 된다
	// *을 하나씩 까면서 타고 간다고 생각하면 된다.
	const char** pp2;

	SetMessage2(msg);

	return 0;
}