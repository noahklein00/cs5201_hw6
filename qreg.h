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
#include "gatedata.h"
#include "nTrix.h"
#include "kronecker.h"

//! qreg class.
/*!
 * This class represents a quantum register by storing complex<float>s to
 * hold the information for a simulation.
 */
template <int size>
class qreg
{
  private:
    nVect<complex<float>>* m_register; /*!< A nVect<complex<float> that stores
                                        * the state of the register.
                                        */
    float m_measured; /*!< A float that holds the calculated random number
                       * to compare with the probabilities of the register.
                       */
    bool m_passed; /*!< A bool that holds whether the state has been measured.
                    */
    int m_state; /*!< An int that represents the measured state.
                  */

  public:
    // Essential //

    /*! \brief Default constructor
     *
     * Description: The default constructor for the qreg class that initializes
     * all the member variables and creates a nVect based off of the size of the
     * template parameter.
     * \post A qreg object is initialized with all its member variables.
     */
    qreg();

    /*! \brief Parameterized constructor
     *
     * Description: Parameterized constructor for the qreg class that accepts
     * a nVect<complex<float>> object that already holds information on a state.
     * \param copy is the nVect object that holds the already created state.
     * \post A qreg object is initialized with all its member variables and
     * m_register set equal to the nVect passed.
     * \throw Throws a std::domain_error object if the passed vector is the
     * incorrect size.
     */
    qreg(nVect<complex<float>>& copy);

    /*! \brief Destructor
     *
     * Description: Destructor for the qreg class that safely deallocates
     * memory.
     * \post The object is safely destructed.
     */
    ~qreg();

    /*! \brief copy constructor
     *
     * Description: Copy constructor for the qreg class that initializes a
     * new qreg object with member variables equal to those passed. Except the
     * measured state;
     * \param rhs is the object to be copied.
     * \post A qreg object is initialized with its member variables equal to
     * the passed object, except the measured state is different because the
     * user could use this to get around the probabalistic quantum measure.
     */
    qreg(const qreg& rhs);

    /*! \brief = operator
     *
     * Description: = operator overload for the qreg class that sets the
     * calling object equal to the  member variables of the object passed.
     * Except the measured state;
     * \param rhs is the object to be copied
     * \post The calling object has its member variables set equal to
     * the passed object, except the measured state is different because the
     * user could use this to get around the probabalistic quantum measure.
     */
    qreg<size>& operator=(const qreg& rhs);

    // Mutators //

    /*! \brief Binary * operator
     *
     * Description: * operator overload that allows the multiplication of the
     * register to a "quantum gate" which updates the state in the process.
     * \param rhs is the "gate" to multiply the system to.
     * \pre binary * operator needs to be defined for the complex class.
     * \post The state is advanced forward as if the gate had been applied.
     * \throw Throws a std::range_error object if the system has already been
     * measured.
     */
    void operator*(const nTrix<cpf>& rhs);

    /*! \brief gate apply
     *
     * Description: Applies a gate to the register based on the gatedata object
     * passed along with the std::initializer_lists.
     * \param a is the list of bits the gate with apply to.
     * \param b is the list of control bits for the creation of the gate.
     * \param type is the gatedata object that stores all the information for
     * creating the gate.
     * \post The state has the created gate applied to it.
     * \throw Throws a std::range_error object if the system has already been
     * measured.
     */
    void apply(const std::initializer_list<int> a, const
      std::initializer_list<int> b, const gatedata& type);

    // Friends //

    /*! \brief operator <<
     *
     * Description: Insertion operator overload for the qreg class that measures
     * the state of the system and outputs it in the proper format.
     * \param out is the ostream object.
     * \param rhs is the qreg object to be output.
     * \pre If the probability of a state is less than .00001, this is
     * interpreted as 0 to assist with floating point error.
     * \post The state is measured and output accordingly. If the system is
     * measured again it will output the same information.
     */
    template <int len>
    friend std::ostream& operator<<(std::ostream& out, qreg<len>& rhs);
};

// Extras //

/*! \brief operator <<
 *
 * Description: Insertion operator overload for the qreg class that measures
 * the state of the system and outputs it in the proper format.
 * \param out is the ostream object.
 * \param rhs is the qreg object to be output.
 * \pre If the probability of a state is less than .00001, this is
 * interpreted as 0 to assist with floating point error.
 * \post The state is measured and output accordingly. If the system is
 * measured again it will output the same information.
 */
template <int size>
std::ostream& operator<<(std::ostream& out, qreg<size>& rhs);

#include "qreg.hpp"
#endif
