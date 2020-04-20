/*! \file
 *
 * Definitions for the gatedata class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef GATEDATA_H
#define GATEDATA_H

#include "nTrix.h"
#include "kronecker.h"
#include "complex.h"
#include "nVect.h"

#include <iostream>
#include <algorithm>
#include <numeric>

typedef std::initializer_list<int> listy;
typedef complex<float> cpf;

class gatedata
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
    ~gatedata();
    nTrix<cpf> creation(const listy& a, const listy& b, const int size) const;
    nVect<cpf> operator*(const nVect<cpf>& rhs) const;

};

//std::ostream& operator<<(const std::ostream& out, const gatedata rhs);

#endif
