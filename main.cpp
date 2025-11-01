#include <iostream>
#include <new>

int **makeMatrix(int r, const size_t *lns);
void outputMatrix(const int *const *mtx, int r, const size_t *lns);
void rm(int **mtx, int r);
int **convert(const int *t, size_t n, const size_t *lns, size_t rows);

int main()
{
  size_t n = 0, rows = 0;
  std::cin >> n >> rows;
  int *t = nullptr;
  try
  {
    t = new int[n];
  } catch (const std::bad_alloc &)
  {
    return 2;
  }
  for (int i = 0; i < n; i++)
  {
    std::cin >> t[i];
  }
  if (std::cin.fail())
  {
    delete[] t;
    return 1;
  }
  size_t *lns = nullptr;
  try
  {
    lns = new size_t[rows];
  } catch (const std::bad_alloc &)
  {
    delete[] t;
    return 2;
  }
  int **result = convert(t, n, lns, rows);
  outputMatrix(result, rows, lns);
  rm(result, rows);
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

void outputMatrix(const int *const *mtx, int r, const size_t *lns)
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
