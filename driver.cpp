#include "qreg.h"
#include "gatedata.h"
#include "kronecker.h"
#include "nVect.h"
#include "nTrix.h"
#include "complex.h"

int main()
{
  try
  {
    double rt = 1.414213562;
    qreg<3> grover_reg;
    qreg<3> shor_reg;
    gatedata H(nTrix<cpf>({{cpf(1/rt,0),cpf(1/rt,0)},{cpf(1/rt,0),cpf(-1/rt,0)}}));
    gatedata X(nTrix<cpf>({{cpf(0,0),cpf(1,0)},{cpf(1,0),cpf(0,0)}}));
    gatedata Z(nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(-1,0)}}));
    gatedata S(nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(0,1)}}));
    gatedata T(nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(rt/2,rt/2)}}));

    grover_reg.apply({0,1,2},{},H);
    grover_reg.apply({0},{2},Z);;
    grover_reg.apply({0},{1},Z);
    grover_reg.apply({0,1,2},{},H);
    grover_reg.apply({0,1,2},{},X);
    grover_reg.apply({0},{1,2},Z);
    grover_reg.apply({0,1,2},{},X);
    grover_reg.apply({0,1,2},{},H);

    std::cout << grover_reg << std::endl;

    shor_reg.apply({0,1,2},{},H);
    shor_reg.apply({1},{},H);
    shor_reg.apply({0},{1},S);
    shor_reg.apply({0},{},H);
    shor_reg.apply({2},{1},T);
    shor_reg.apply({2},{0},S);

    std::cout << shor_reg << std::endl;
  }
  catch(std::domain_error& e)
  {
    std::cerr << "Exception caught, index out of range: "
      << e.what() << std::endl;
  }
  catch(std::invalid_argument& e)
  {
    std::cerr << "Invalid operation of matrices of 2"
      << " different sizes" << std::endl;
  }
  catch(std::range_error& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
