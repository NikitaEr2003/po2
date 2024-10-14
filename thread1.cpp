#define _USE_MATH_DEFINES
#include<iostream>
#include<thread>
#include <Windows.h>
#include "timer.h"

using namespace std;

void func1()
{
	cout << "#id = " << this_thread::get_id() << endl;
	for (int i = 0; i < 10; i++)
	{
		this_thread::sleep_for(100ms);
          consol_parameter::SetColor(15, 0);

		
		cout << i << " ";
	}
	cout << endl;
}

void func2()
{
	cout << "#id = " << this_thread::get_id() << endl;
	for (int i = 0; i < 10; i++)
	{
		this_thread::sleep_for(100ms);
          consol_parameter::SetColor(10, 0);
		cout << i << " ";
	}
	cout << endl;
}

class A
{
public:
	void funcA()
	{
		cout << __FUNCTION__ << endl;
	}
	void operator()()
	{
		cout << "Functor" << endl;
	}
};

int main_t1()
{
	cout << thread::hardware_concurrency() << endl;
	//thread t1(func1);
	//thread t2(func2);
	//if (t1.joinable())
	//{
	//	cout << "t1.joinable()" << endl;
	//}
	//t1.join();
	//t2.join();
	A obj;
	//thread t3(&A::funcA, &obj);
	//t3.join();
	//thread t4(obj);
	//t4.join();
	//thread t5([]() {cout << "lamda" << endl; });
	//t5.join();

	thread t6(func1);
	thread t7 = move(t6);
	t6 = thread(func2);
	t6.join();
	t7.join();

	return 0;
}
