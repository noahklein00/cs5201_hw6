/*! \file
 *
 * Definitions for the baseGate class. \n
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
#include "qreg.h"
#include <numeric>

class hadamard
{
  private:
    // nTrix<complex<float>> gate;
    float root_two = 1.41421;
  public:
    nTrix<complex<float>> gate;
    hadamard(const std::initializer_list<int>& a, const
      std::initializer_list<int>& b, const int size);
    //qreg<3> operator*(const qreg<3>& state);

};

#endif
