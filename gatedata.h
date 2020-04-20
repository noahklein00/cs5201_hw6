/*! \file
 *
 * Definitions for the gatedata class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef GATEDATA_H
#define GATEDATA_H

#include "nTrix.h"
#include "kronecker.h"
#include "complex.h"
#include "nVect.h"

#include <iostream>
#include <algorithm>
#include <numeric>

typedef std::initializer_list<int> listy; /*!< shortened list name*/
typedef complex<float> cpf; /*!< shortened complex<float> name */

//! complex class.
/*!
 * This class stores the data for everything needed to create normal or
 * controlled quantum gates.
 */
class gatedata
{
  private:
    nTrix<cpf>* m_Pnot; /*!< A pointer to a matrix that stores the P0 matrix for
                         * calculating the controlled gates.
                         */
    nTrix<cpf>* m_Pone; /*!< A pointer to a matrix that stores the P1 matrix for
                         * calculating the controlled gates.
                         */
    nTrix<cpf>* m_identity; /*!< A pointer to a matrix that stores the identity
                             * matrix used in creating all gates.
                             */
    nTrix<cpf>* m_gate; /*!< A pointer to a matrix that stores the single qubit
                         * representation of a gate.
                         */
    kronecker<cpf> m_prod; /*!< A kronecker class that is used to calculate the
                            * expanded gates.
                            */
  public:

    /*! \brief Default constructor
     *
     * Description: Default constructor for the gatedata class that defaults all
     * of the members to their respective values and sets the gate to NULL.
     * \post A new gatedata object is initialized but does not have a default
     * gate to calculate with.
     */
    gatedata();

    /*! \brief Parameterized constructor
     *
     * Description: Parameterized constructor for the gatedata class that
     * accepts a nTrix<complex<float>> as the default gate.
     * \param base is the default gate to set this object with.
     * \post A new gatedata object is initialized and the parameter passed is
     * set as the base gate.
     * \throw Throws a std::domain_error object if the matrix passed is not
     * a 2x2.
     */
    gatedata(const nTrix<cpf> base);

    /*! \brief Destructor
     *
     * Description: Destructor for the gatedata class that safely deallocates
     * memory so no leaks occur when the object goes out of scope.
     * \post The object is safely destructed.
     */
    ~gatedata();

    /*! \brief Creation
     *
     * Description: Creates a nTrix<complex<float>> that is the representation
     * of a gate that follows all the parameters passed, using the base gate
     * stored in the object.
     * \param a is the std::initializer_list passed that holds the different
     * qubits to apply the gate to.
     * \param b is the std::initializer_list passed that holds the different
     * qubits that are supposed to control the gate.
     * \param size is the size of the register that the gate will be applied to.
     * \pre Everything for the complex and nTrix classes are defined.
     * \return The calculated gate is returned.
     * \throw Throws a std::domain_error object if there are too many applied/
     * control bits or if the user tries to apply the matrix to a qubit that is
     * also acting as a control bit or vice versa. Throws a std::range_error
     * object if the applied bit or control bits are not actual bits in the
     * register.
     */
    nTrix<cpf> creation(const listy& a, const listy& b, const int size) const;
};

#endif
