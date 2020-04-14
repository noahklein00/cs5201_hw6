// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : qreg.cpp

#include "qreg.h"

template <int size>
qreg<size>::qreg(nVect<complex<float>>& copy)
{
  m_register = new nVect<complex<float>>(copy);
}

template <int size>
std::ostream& operator<<(std::ostream& out, const qreg<size>& rhs)
{
  float total = 0.0;
  float added;
  srand(clock());
  float measured = (rand()%100000 + 1)/100000.00;
  bool passed = false;
  int state;

  out << "Probabilities:";
  for(int i = 0; i < std::pow(2,size); ++i)
  {
    added = ~(*rhs.m_register)[i];
    out << " " << added;
    total += added;
    if(total >= measured && !passed)
    {
      state = i;
      passed = true;
    }
  }
  out << std::endl << "Measured State: ";

  int binaryNum[size] = {0};
  int i = 0;
  while(state > 0)
  {
    binaryNum[i] = state % 2;
    state = state / 2;
    i++;
  }
  for(int j = size - 1; j >= 0; j--)
  {
    std::cout << binaryNum[j];
  }
  return out;
}
