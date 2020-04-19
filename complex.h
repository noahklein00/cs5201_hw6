/*! \file
 *
 * Definitions for the complex class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

//! complex class.
/*!
 * This class uses two type T objects to store and represent a complex number.
 */
template <typename T>
class complex
{
  private:
    T m_a; /*!< A type T object that stores the real value for the complex
            * number.
            */
    T m_b; /*!< A type T object that stores the imaginary value for the complex
            * number.
            */

  public:

    // Essential //

    /*! \brief Constructor
     *
     * Description: Default constructor for the complex class that initializes
     * the real value as 1 and the imaginary value as 0.
     * \post A complex number is initialized with the values specified.
     */
    complex(): m_a(1), m_b(0) {}

    /*! \brief Constructor
     *
     * Description: Parameterized constructor for the complex class that
     * initializes the different parts with the values passed.
     * \param a is the real value for the complex number.
     * \param b is the imaginary value for the complex number.
     * \post A complex number is initialized with the values passed.
     */
    complex(const T& a, const T& b): m_a(a), m_b(b) {}

    /*! \brief Copy Constructor
     *
     * Description: A copy constructor for the complex class that initializes a
     * new complex object with the values of the complex object passed.
     * \param rhs is the complex object to be copied.
     * \pre operator = must be defined for type T.
     * \post A complex number is initialized with the same values as the object
     * passed.
     */
    complex(const complex& rhs);

    /*! \brief = operator
     *
     * Description: = operator for the complex class that sets the value of the
     * calling object equal to the values of the object passed.
     * \param rhs is the complex number to be copied.
     * \return Returns a reference to the calling object.
     * \pre = operator must be defined for type T.
     * \post The calling object is set equal to the object passed.
     */
    complex& operator=(const complex& rhs);

    /*! \brief Destructor
     *
     * Description: Placeholder function for complex destructor.
     * \post The calling object is safely desctructed.
     */
    ~complex() {}

    // Accessors //

    /*! \brief Real Accessor
     *
     * Description: Accessor for the real member for the complex class that
     * returns a copy of the real part of the calling object.
     * \return Returns a copy of m_a from the calling object.
     */
    T real() const;

    /*! \brief Imaginary Accessor
     *
     * Description: Accessor for the imaginary member for the complex class that
     * returns a copy of the imaginary part of the calling object.
     * \return Returns a copy of m_b from the calling object.
     */
    T imag() const;

    /*! \brief Additive Inverse
     *
     * Description: Returns the additive inverse of the calling object. -m_a.
     * \return Returns a T object that represents the additive inverse of the
     * complex number.
     * \pre unary - operator must be defined for type T.
     */
    complex<T> operator-() const;

    /*! \brief Complex Conjugate
     *
     * Description: Returns the complex conjugate of the calling object. -m_b.
     * \return Returns a T object that represents the complex conjugate of the
     * complex number.
     * \pre unary - operator must be defined for type T.
     */
    complex<T> operator!() const;

    /*! \brief Magnitude
     *
     * Description: Returns the magnitude of the complex number.
     * \return Returns a type T object that represents the magnitude of the
     * complex number.
     * \pre binary * operator and binary + operator must be defined for type T.
     */
    T operator~() const;

    // Mutators //

    /*! \brief Addition
     *
     * Description: Binary + operator for the complex class that calculates the
     * addition of two complex objects.
     * \param rhs is the complex object to be added to the calling object.
     * \return Returns a complex object that represents the addition of the
     * two complex objects.
     * \pre Binary += operator must be defined for type T.
     */
    complex<T> operator+(const complex<T>& rhs) const;

    /*! \brief Subtraction
     *
     * Description: Binary - operator for the complex class that calculates the
     * subtraction of two complex objects.
     * \param rhs is the complex object to be subtracted from the calling
     * object.
     * \return Returns a complex object that represents the difference of the
     * two complex objects.
     * \post -= operator must be defined for type T.
     */
    complex<T> operator-(const complex<T>& rhs) const;

    /*! \brief Multiplication
     *
     * Description: Binary * operator for the complex class that calculates the
     * product of the two complex objects.
     * \param rhs is the complex object to be multiplied to the calling object.
     * \return Returns a complex object that represents the product of the
     * two complex objects.
     * \pre Binary * operator, Binary + operator, and unary - operator must be
     * defined for type T.
     */
    complex<T> operator*(const complex<T>& rhs) const;

    /*! \brief Integer = operator
     *
     * Description: Allows the complex number to be set "equal as" a passed
     * integer.
     * \param number is the number to set the complex object "equal as".
     * \return Returns a complex object whose non-imaginary component is equal
     * to the parameter.
     * \pre Binary * operator, Binary + operator, and unary - operator must be
     * defined for type T.
     * \post The calling object is now set "equal as" the parameter
     */
    complex<T>& operator=(const int number);

    /*! \brief += operator
     *
     * Description: += operator overload to increase functionality with the
     * nTrix (and other) classes.
     * \param rhs is the complex number to add to the calling object.
     * \return Returns *this with modified data
     * \pre Binary + operator, and = operator must be defined for type T.
     * \post The calling object has the parameter added to it.
     */
    complex<T>& operator+=(const complex<T>& rhs);

    // Friends //

    /*! \brief Insertion operator
     *
     * Description: Insertion operator overload for the complex class that
     * prints the object in the proper format.
     * \param out is the ostream passed to the function.
     * \param rhs is the complex object to be output.
     * \return Returns the ostream object.
     * \pre << operator must be defined for type T.
     * \post The complex object is output to the stream.
     */
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const complex<U>& rhs);

};

// Extras //

/*! \brief Insertion operator
 *
 * Description: Insertion operator overload for the complex class that
 * prints the object in the proper format.
 * \param out is the ostream passed to the function.
 * \param rhs is the complex object to be output.
 * \return Returns the ostream object.
 * \pre << operator must be defined for type T.
 * \post The complex object is output to the stream.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const complex<T>& rhs);

#include "complex.hpp"
#endif
