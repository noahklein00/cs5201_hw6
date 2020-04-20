// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : qreg.cpp

//#include "qreg.h"

template <int size>
qreg<size>::qreg()
{
  srand(clock());
  nVect<complex<float>> temp;
  temp.push_back(complex<float>(1,0));
  for(int i = 0; i < (std::pow(2,size)-1); i++)
  {
    temp.push_back(complex<float>(0,0));
  }
  m_register = new nVect<complex<float>>(temp);
  m_measured = (rand()%100000 + 1)/100000.00;
  m_passed = false;
  m_state;
}

template <int size>
qreg<size>::qreg(nVect<complex<float>>& copy)
{
  srand(clock());
  m_register = new nVect<complex<float>>(copy);
  m_measured = (rand()%100000 + 1)/100000.00;
  m_passed = false;
  m_state;
}

template <int size>
qreg<size>::~qreg()
{
  delete m_register;
}

template <int size>
void qreg<size>::operator*(const nTrix<cpf>& rhs)
{
  if(!m_passed)
  {
    (*m_register) = rhs * (*m_register);
  }
  else
  {
    std::cout << "State already measured." << std::endl;
  }
  return;
}

template <int size>
void qreg<size>::apply(const std::initializer_list<int> a, const
  std::initializer_list<int> b, const gatedata& type)
{
  (*this) * type.creation(a,b,size);
  return;
}

template <int size>
std::ostream& operator<<(std::ostream& out, qreg<size>& rhs)
{
  float total = 0.0;
  float added;

  for(int i = 0; i < std::pow(2,size); ++i)
  {
    if((~(*rhs.m_register)[i] < .00001) && (~(*rhs.m_register)[i] > -.00001))
    {
      (*rhs.m_register)[i] = complex<float>(0,0);
    }
  }

  out << "Probabilities:";
  for(int i = 0; i < std::pow(2,size); ++i)
  {
    added = ~(*rhs.m_register)[i];
    out << " " << added;
    total += added;
    if(total >= rhs.m_measured && !rhs.m_passed)
    {
      rhs.m_state = i;
      rhs.m_passed = true;
    }
  }
  out << std::endl << "Measured State: ";
  int binaryNum[size] = {0};
  int i = 0;
  while(rhs.m_state > 0)
  {
    binaryNum[i] = rhs.m_state % 2;
    rhs.m_state = rhs.m_state / 2;
    i++;
  }
  for(int j = size - 1; j >= 0; j--)
  {
    std::cout << binaryNum[j];
  }
  return out;
}
