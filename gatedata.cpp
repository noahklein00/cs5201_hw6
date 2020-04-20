// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : gatedata.cpp

#include "gatedata.h"

gatedata::gatedata()
{
  m_Pnot = new nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(0,0)}});
  m_Pone = new nTrix<cpf>({{cpf(0,0),cpf(0,0)},{cpf(0,0),cpf(1,0)}});
  m_identity = new nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(1,0)}});
  m_gate = NULL;
}

gatedata::gatedata(const nTrix<cpf> base)
{
  if(base.rows() != 2 || base.cols() != 2)
  {
    std::cout << "Invalid size of matrix for gate operation: ";
    throw(std::domain_error(std::to_string(base.rows())));
  }
  m_Pnot = new nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(0,0)}});
  m_Pone = new nTrix<cpf>({{cpf(0,0),cpf(0,0)},{cpf(0,0),cpf(1,0)}});
  m_identity = new nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(1,0)}});
  m_gate = new nTrix<cpf>(base);
}

gatedata::~gatedata()
{
  delete m_Pnot;
  delete m_Pone;
  delete m_identity;
  delete m_gate;
}

nTrix<cpf> gatedata::creation(const listy& a, const listy& b, const int size) const
{
  if(((a.size() + b.size()) > size) || a.size() < 1)
  {
    std::cout << "Incorrect amount of control/applied bits: ";
    throw(std::domain_error(std::to_string(a.size())));
  }
  for(int i = 0; i < size; ++i)
  {
    if((std::count(a.begin(),a.end(),i) + std::count(b.begin(),b.end(),i)) > 1)
    {
      std::cout << "Cannot apply a gate to a control bit: ";
      throw(std::domain_error(std::to_string(i)));
    }
  }
  for(auto itr = a.begin(); itr != a.end(); itr++)
  {
    if(*itr >= size || *itr < 0)
    {
      std::cout << "Qubit out of range: ";
      throw(std::range_error(std::to_string(*itr)));
    }
  }
  for(auto itr = b.begin(); itr != b.end(); itr++)
  {
    if(*itr >= size || *itr < 0)
    {
      std::cout << "Control qubit out of range: ";
      throw(std::range_error(std::to_string(*itr)));
    }
  }

  nTrix<cpf> temp;

  if(b.size())
  {
    nVect<nTrix<cpf>> u_not;
    nVect<nTrix<cpf>> u_one;

    for(int i = 0; i < size; ++i)
    {
      if(std::count(a.begin(),a.end(),i)) //if that qubit is supposed to have the gate applied
      {
        u_not.push_front(*m_identity);
        u_one.push_front(*m_gate);
      }
      else if(std::count(b.begin(),b.end(),i)) //if that qubit is supposed to have the control gate applied
      {
        u_not.push_front(*m_Pnot);
        u_one.push_front(*m_Pone);
      }
      else //if that qubit is not multiplied by a gate and is not a control qubit
      {
        u_not.push_front(*m_identity);
        u_one.push_front(*m_identity);
      }
    }
    temp = (std::accumulate(u_not.begin(),
      u_not.end(),nTrix<cpf>({{cpf(1,0)}}),m_prod) +
      std::accumulate(u_one.begin(),u_one.end()
      ,nTrix<cpf>({{cpf(1,0)}}),m_prod));
  }
  else
  {
    nVect<nTrix<cpf>> holder;
    for(int i = 0; i < size; ++i)
    {
      if(std::count(a.begin(),a.end(),i))
      {
        holder.push_front(*m_gate);
      }
      else
      {
        holder.push_front(*m_identity);
      }
    }
    temp = (std::accumulate(holder.begin(),
      holder.end(),nTrix<cpf>({{cpf(1,0)}}),m_prod));
  }
  return temp;
}

nVect<cpf> gatedata::operator*(const nVect<cpf>& rhs) const
{
  return (*m_gate) * rhs;
}
