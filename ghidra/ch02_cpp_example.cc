#include <iostream>

using namespace std;

void demo(void);
void demo(int x);
void demo(double x);
void demo(int x, double y);
void demo(double x, int y);
void demo(char* str);

void demo(void) {}
void demo(int x) {}
void demo(double x) {}
void demo(int x, double y) {}
void demo(double x, int y) {}
void demo(char* str) {}

int main() {
  cout << "Done." << endl;
  
  return 0;
}