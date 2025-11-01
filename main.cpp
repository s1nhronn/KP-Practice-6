#include <iostream>

int **make(int rows, int cols);
void output(int **mtx);
void rm(int **mtx);

int main()
{
  int rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail())
  {
    return 1;
  }
  int **mtx = nullptr;
  mtx = make(rows, cols);
  output(mtx);
  rm(mtx);
}
