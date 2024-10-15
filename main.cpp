
#include "thread"
#include <iostream>
#include <chrono>
 #include <Windows.h>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;
once_flag flag;

void print() {
  cout << "Количество логических ядер: " << thread::hardware_concurrency()<< endl;
  cout << endl
       << "\t\t\t\t" << 1000 << "\t\t\t" << 10000 << "\t\t\t" << 100000
       << "\t\t\t" << 1000'0000 << endl
       << endl;
}
void counter(vector<int> first, vector<int> second, int start, int end) {

  call_once(flag,print);
  std::transform(first.begin()+start, first.begin()+end, second.begin()+start,
                 [](int x) { return x + x; });
 
  
 
 

}

int main() 
{ 
    try {
    int index = 1;
    int temp = 1;
    
    for (int j = 1; j <= 5; j++) {
      vector<thread> thr_vec;
      int chased = 0;

      for (int i = 1000; i <= 1'000'000; i *= 10) {
        std::vector<int> vec1(i);
        std::vector<int> vec2(i);
       

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, i);

        std::generate(vec1.begin(), vec1.end(),
                      [&distrib, &gen]() { return distrib(gen); });
       
          auto start = chrono::steady_clock::now();
          int chunk = i / temp;
          
          for (int h = 0; h < temp; h++) {
            int start = chunk * h;
            int end = chunk * (h + 1);
            thr_vec.push_back(thread(counter, vec1, vec2, start, end));
          }
          auto end = chrono::steady_clock::now();
          chrono::duration<double, milli> time = end - start;
          for (auto& t : thr_vec) {
            if (t.joinable()) {
              t.join();
            }
          }
        
      

        if (index == 1) {
          cout << "Количество потоков: " << index * temp;
        }
        cout << "\t\t" << time.count() << "milsec";

        index *= 2;
      }
      temp *= 2;
      index = 1;
      cout << endl;
    }
    } catch (exception &e) {
      cout << e.what() << endl;
    }

}

