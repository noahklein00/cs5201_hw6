#include "qreg.cpp"
#include "nTrix.h"
#include "kronecker.h"
#include "nVect.h"
#include "hadamard.cpp"
#include <numeric>

int main()
{
  // nTrix<int> noah({{1,0},{0,0}});
  // nTrix<int> sean({{1,0},{0,1}});
  // kronecker<int> prod;
  // nVect<nTrix<int>> matr_list({noah,sean});
  nVect<complex<float>> copy;
  complex<float> one(1,0);
  complex<float> zero(0,0);

  copy.push_back(one);
  for(int i = 0; i < 7; ++i)
  {
    copy.push_back(zero);
  }

  std::cout << copy << std::endl;


  hadamard testy({1,2,3},{1},2);
  qreg<3> reggy(copy);

  copy = testy.gate * copy;

  std::cout << copy << std::endl;

  // auto composed_operator = std::accumulate(matr_list.begin(), matr_list.end(),
  //   nTrix<int>({{1}}), prod);
  // std::cout << composed_operator << std::endl;
  return 0;
}
