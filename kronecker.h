/*! \file
 *
 * Definitions for the complex class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef KRONECKER_H
#define KRONECKER_H

#include "nTrix.h"

template <typename T>
class kronecker
{
  public:
    nTrix<T> operator()(const nTrix<T>& lhs, const nTrix<T>& rhs);


};

#include "kronecker.hpp"
#endif
