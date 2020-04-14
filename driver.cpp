#include "qreg.cpp"

int main()
{
  complex<float> noah(1,0);
  complex<float> sean(0,0);
  nVect<complex<float>> reg;

  for(int i = 0; i < 7; ++i)
  {
    reg.push_back(sean);
  }
  reg.push_back(noah);

  std::cout << reg << std::endl;

  qreg<3> reggy(reg);
  std::cout << reggy << std::endl;

  return 0;
}
