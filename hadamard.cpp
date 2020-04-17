// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : hadamard.cpp

#include "hadamard.h"

hadamard::hadamard(const std::initializer_list<int>& a, const
  std::initializer_list<int>& b, const int size)
{
  nTrix<complex<float>> H({{complex<float>(1/root_two,0),complex<float>(1/root_two,0)},
    {complex<float>(1/root_two,0),complex<float>(-1/root_two,0)}});
  //std::cout << H << std::endl;
  nVect<nTrix<complex<float>>> gate_holder;
  kronecker<complex<float>> prod;

  for(int i = 0; i < a.size(); ++i)
  {
    gate_holder.push_back(H);
  }

  if(b.size()) //if there are control bits
  {

  }

  gate = std::accumulate(gate_holder.begin(), gate_holder.end(),
    nTrix<complex<float>>({{complex<float>(1,0)}}), prod);

  //std::cout << gate << std::endl;
}
