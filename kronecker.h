/*! \file
 *
 * Definitions for the kronecker class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef KRONECKER_H
#define KRONECKER_H

#include "nTrix.h"

//! kronecker class.
/*!
 * This class calculates the kronecker product of two matrices passed.
 */
template <typename T>
class kronecker
{
  public:
    /*! \brief Operator ()
     *
     * Description: Operator () overload for the kronecker class that
     * allows the user to input two nTrix<T> objects, and it calculates their
     * kronecker product.
     * \param lhs is the left matrix in the calculation.
     * \param rhs is the right matrix in the calculation.
     * \return Returns the calculated kronecker product as a nTrix object.
     */
    nTrix<T> operator()(const nTrix<T>& lhs, const nTrix<T>& rhs);
};

#include "kronecker.hpp"
#endif
