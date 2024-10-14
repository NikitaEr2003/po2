#define _USE_MATH_DEFINES
#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include<mutex>

using namespace std;
void func3(int x, string& str)
{
	str += "def";
	cout << x << " " << str << endl;
}

int func4(int x)
{
	return x * 4;
}

thread_local int x = 2;

void func5()
{
	this_thread::sleep_for(100ms);
	x = x * 10;
	cout << x << endl;
}
void func6()
{
	this_thread::sleep_for(500ms);
	x = x + 10;
	cout << x << endl;
}

once_flag flag;

void print_once()
{
	cout << "!";
}

void print(size_t x)
{
	call_once(flag, print_once);
	cout << x << " ";
}


int main_t2()
{
	//string s = "abs";
	//thread t1(func3, 3, ref(s));
	//t1.join();
	//cout << s << endl;
	//int res;
	//thread t2([&]() {res = func4(20); });
	//t2.join();
	//cout << res << endl;
	//thread t3(func6);
	//thread t4(func5);
	//t3.join();
	//t4.join();

	vector<thread> TV;
	for (size_t i = 0; i < 10; i++)
	{
		TV.push_back(thread(print, i));
	}
	for (auto& t : TV)
	{
		t.join();
	}
	cout << endl;
	return 0;
}
