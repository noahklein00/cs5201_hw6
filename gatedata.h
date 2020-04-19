/*! \file
 *
 * Definitions for the gatedata class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef GATEDATA_H
#define GATEDATA_H

#include "basegate.h"
#include "nTrix.h"
#include "kronecker.h"
#include <algorithm>
#include <numeric>

typedef std::initializer_list<int> listy;

class gatedata: public virtual basegate
{
  private:
    nTrix<cpf>* m_Pnot;
    nTrix<cpf>* m_Pone;
    nTrix<cpf>* m_identity;
    nTrix<cpf>* m_gate;
    kronecker<cpf> m_prod;
  public:
    gatedata();
    gatedata(const nTrix<cpf> base);
    // gatedata(const listy& a, const listy& b, const int size, const
    //   nTrix<cpf>& gate_type);
    creation(const listy& a, const listy& b, const int size, const
      nTrix<cpf>& gate_type);
    virtual nVect<cpf> operator*(const nVect<cpf>& rhs) const;
};

#endif