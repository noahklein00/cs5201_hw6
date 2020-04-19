/*! \file
 *
 * Definitions for the hadamard class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef ZGATE_H
#define ZGATE_H

#include "nTrix.h"
#include "nVect.h"
#include "complex.h"
#include "kronecker.h"
#include "gatedata.h"
#include <numeric>

class zgate: public virtual basegate, public gatedata
{
  private:
    nTrix<complex<float>>* m_gate;

};

#endif
