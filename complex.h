/*! \file
 *
 * Definitions for the nTrix class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 5 \n
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

template <typename T>
class complex
{
  private:
    T m_a;
    T m_b;

  public:

    // Essential //

    complex(): m_a(1), m_b(0) {}
    complex(const T& a, const T& b): m_a(a), m_b(b) {}
    complex(const complex& rhs);
    complex& operator=(const complex& rhs);

    // Accessors //

    T real() const;
    T imag() const;

    // Mutators //


    // Friends //

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const complex<U>& rhs);

};

// Extras //

template <typename T>
std::ostream& operator<<(std::ostream& out, const complex<T>& rhs);

#include "complex.hpp"
#endif
