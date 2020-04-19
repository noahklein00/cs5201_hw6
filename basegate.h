/*! \file
 *
 * Definitions for the basegate class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef BASEGATE_H
#define BASEGATE_H

#include "complex.h"
#include "nVect.h"

typedef complex<float> cpf;

class basegate
{
  public:
    virtual nVect<cpf> operator*(const nVect<cpf>& rhs)
      const =0;
};

#endif
