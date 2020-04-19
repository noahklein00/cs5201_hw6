#include "qreg.cpp"
#include "gatedata.h"

int main()
{
  qreg<3> grover_reg;
  qreg<3> shor_reg;
  gatedata grover[8];
  gatedata shor[6];

  double rt = 1.414213562;
  nTrix<cpf> X({{cpf(0,0),cpf(1,0)},{cpf(1,0),cpf(0,0)}});
  nTrix<cpf> Z({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(-1,0)}});
  nTrix<cpf> H({{cpf(1/rt,0),cpf(1/rt,0)},{cpf(1/rt,0),cpf(-1/rt,0)}});
  nTrix<cpf> S({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(0,1)}});
  nTrix<cpf> T({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(rt/2,rt/2)}});
  gatedata hads({0,1,2},{},3,H);
  gatedata zone({0},{2},3,Z);
  gatedata ztwo({0},{1},3,Z);
  gatedata xes({0,1,2},{},3,X);
  gatedata zthree({0},{1,2},3,Z);
  gatedata hadtwo({1},{},3,H);
  gatedata sone({0},{1},3,S);
  gatedata hadthree({0},{},3,H);
  gatedata tone({2},{1},3,T);
  gatedata stwo({2},{0},3,S);

  grover[0] = hads;
  grover[1] = zone;
  grover[2] = ztwo;
  grover[3] = hads;
  grover[4] = xes;
  grover[5] = zthree;
  grover[6] = xes;
  grover[7] = hads;

  shor[0] = hads;
  shor[1] = hadtwo;
  shor[2] = sone;
  shor[3] = hadthree;
  shor[4] = tone;
  shor[5] = stwo;

  for(int i = 0; i < 8; i++)
  {
    grover_reg * grover[i];
  }

  std::cout << grover_reg << std::endl;

  for(int i = 0; i < 5; i++)
  {
    shor_reg * shor[i];
  }

  std::cout << shor_reg << std::endl;
  return 0;
}
