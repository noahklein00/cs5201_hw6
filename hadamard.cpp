// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : hadamard.cpp

#include "hadamard.h"

hadamard::hadamard()
{
  m_gate = new nTrix<complex<float>>({{complex<float>(1/m_root_two,0),
    complex<float>(1/m_root_two,0)},
    {complex<float>(1/m_root_two,0),
    complex<float>(-1/m_root_two,0)}});
}

hadamard::hadamard(const std::initializer_list<int>& a, const
  std::initializer_list<int>& b, const int size)
{
  if((a.size() + b.size()) != size)
  {
    std::cout << "Invalid number of apply and control bits: ";
    throw(std::length_error(std::to_string(a.size())));
  }
  m_gate = new nTrix<complex<float>>({{complex<float>(1/m_root_two,0),
    complex<float>(1/m_root_two,0)},
    {complex<float>(1/m_root_two,0),
    complex<float>(-1/m_root_two,0)}});

  nVect<nTrix<complex<float>>> gate_holder;
  kronecker<complex<float>> prod;

  for(int i = 0; i < a.size(); ++i)
  {
    gate_holder.push_back(*m_gate);
  }

  nVect<int> a_list(a);
  nVect<int> b_list(b);

  for(int i = 0; i < size; ++i)
  {
    // if(*std::find(a.begin(),a.end(),i) == i)
    // {
    //   std::cout << "hello" << std::endl;
    // }
    // if(*std::find(b.begin(),b.end(),i) == i)
    // {
    //   std::cout << "bye" << std::endl;
    // }
    //std::cout << *std::find(a_list.begin(),a_list.end(),i) << std::endl;
  }

  (*m_gate) = std::accumulate(gate_holder.begin(), gate_holder.end(),
    nTrix<complex<float>>({{complex<float>(1,0)}}), prod);

  //std::cout << gate << std::endl;
}

nVect<complex<float>> hadamard::operator*(const nVect<complex<float>>& rhs)
  const
{
  return (*m_gate) * rhs;
}
