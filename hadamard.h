/*! \file
 *
 * Definitions for the hadamard class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef HADAMARD_H
#define HADAMARD_H

#include "nTrix.h"
#include "nVect.h"
#include "complex.h"
#include "kronecker.h"
#include "gatedata.h"
#include <numeric>
#include <algorithm>

class hadamard: public virtual basegate, public gatedata
{
  private:
    nTrix<complex<float>>* m_gate;
    double m_root_two = 1.414213562;
  public:
    hadamard();
    hadamard(const std::initializer_list<int>& a, const
      std::initializer_list<int>& b, const int size);
    virtual nVect<complex<float>> operator*(const nVect<complex<float>>& rhs)
      const;

};

#endif
