/*! \file
 *
 * Definitions for the quantum register class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef QREG_H
#define QREG_H
#include "nVect.h"
#include "complex.h"

template <int size>
class qreg
{
  private:
    nVect<complex<float>>* m_register;

  public:
    qreg(nVect<complex<float>>& copy);

    template <int len>
    friend std::ostream& operator<<(std::ostream& out, const qreg<len>& rhs);
};

template <int size>
std::ostream& operator<<(std::ostream& out, const qreg<size>& rhs);

#endif
