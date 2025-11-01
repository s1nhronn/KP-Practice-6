#include <iostream>
#include <new>

int **makeMatrix(int r, const size_t *lns);
void output(const int *const *mtx, int r, const size_t *lns);
void rm(int **mtx, int r);
int **convert(const int *t, size_t n, const size_t *lns, size_t rows);

int main()
{
}

void rm(int **mtx, int r)
{
  for (size_t i = 0; i < r; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int **makeMatrix(int r, const size_t *lns)
{
  int **mtx = new int *[r];
  for (size_t i = 0; i < r; i++)
  {
    try
    {
      mtx[i] = new int[lns[i]];
    } catch (const std::bad_alloc &)
    {
      rm(mtx, i);
      throw;
    }
  }
  return mtx;
}

void output(const int *const *mtx, int r, const size_t *lns)
{
  for (size_t i = 0; i < r; i++)
  {
    for (size_t j = 0; j < lns[i]; j++)
    {
      std::cout << mtx[i][j] << ' ';
    }
    std::cout << '\n';
  }
}
