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
#include "basegate.h"

template <int size>
class qreg
{
  private:
    nVect<complex<float>>* m_register;
    float m_measured;
    bool m_passed;
    int m_state;

  public:
    qreg();
    qreg(nVect<complex<float>>& copy);
    void operator*(const basegate& rhs);
    apply(const std::initializer_list<int> a, const std::initializer_list b, \
      const gatedata& type);

    template <int len>
    friend std::ostream& operator<<(std::ostream& out, qreg<len>& rhs);
};

template <int size>
std::ostream& operator<<(std::ostream& out, qreg<size>& rhs);

#endif