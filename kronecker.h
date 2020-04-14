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

template <typaname T>
class kronecker
{
  private:
    nTrix<T> m_outer;
    T* m_begin;
    T* m_end;
  public:


  //! iterator class.
	/*!
	 * This class allows for iterating over the nVect
	 * object containers.
	 */
	class iterator
    {

		private:
			nTrix<T>* m_point; /*!< a nTrix<T> pointer that allows for
				* iterating over the containers.
				*/
			unsigned int m_Ridx; /*!< Integer used to display the current
				* row index of the pointer.
				*/
      unsigned int m_Cidx; /*!< Integer used to display the current
				* column index of the pointer.
				*/

		public:

			/*! \brief constructor
			 *
			 * Description: Constructs an iterator over a certain nVect
			 * object starting at a specified integer.
			 * \param a is the pointer to a nVect to be copied.
			 * \param idx is the index position of the pointer.
			 * \post Creates a new iterator object with the specified data.
			 */
			iterator(nTrix<T>* a, unsigned int row, unsigned int col):
				m_point(a), m_Ridx(row), m_Cidx(col) {}

			/*! \brief * operator
			 *
			 * Description: Accesses the data at the position the pointer
			 * is pointing to.
			 * \return Returns a reference to the data in the object pointed
			 * to by m_array at the index m_idx.
			 */
			T& operator*() { return (*m_point)(m_Ridx, m_Cidx); }

			/*! \brief -> operator
			 *
			 * Description: Allows the user to use -> syntax instead of
			 * the * operator.
			 * \return Returns a reference to the data in the object pointed
			 * to by m_array at the index m_idx.
			 */
			T& operator->() { return (*m_point)(m_Ridx, m_Cidx); }

			/*! \brief operator ++ (postfix)
			 *
			 * Description: Increments the index in stored in the iterator.
			 * \return Returns the calling object with an incremented iterator.
			 */
			iterator& operator++()
			{
			  m_Ridx++;
			  return *this;
			}

			/*! \brief operator ++ (prefix)
			 *
			 * Description: Increments the index in stored in the iterator.
			 * \return Returns a new iterator object with an incremented
			 * iterator.
			 */
			iterator operator++(int)
			{
			  iterator temp = *this;
			  m_Ridx++;
			  return temp;
			}

			/*! \brief += operator
			 *
			 * Description: Allows for jumping the iterator's index by a
			 * specified amount.
			 * \param inc only allows for forward iterating.
			 * \return Returns the calling object with an adjusted iterator.
			 */
			iterator& operator+=(const unsigned int inc)
			{
			  m_Ridx += inc;
			  return *this;
			}

			/*! \brief operator -- (postfix)
			 *
			 * Description: Decrements the index stored in the iterator.
			 * \return Returns the calling object with a decremented index.
			 */
			iterator& operator--()
			{
			  m_Ridx--;
			  return *this;
			}

			/*! \brief operator -- (prefix)
			 *
			 * Description: Decrements the index stored in the iterator.
			 * \return Returns a new iterator object with a decremented
			 * iterator.
			 */
			iterator operator--(int)
			{
			  iterator temp = *this;
			  m_Ridx--;
			  return temp;
			}

			/*! \brief -= operator
			 *
			 * Description: Allows for jumping the iterator's index by a
			 * specified amount.
			 * \param dec only allows for reverse iterating.
			 * \return Returns the calling object with an adjusted index.
			 */
			iterator& operator-=(const unsigned int dec)
			{
			  m_Ridx -= dec;
			  return *this;
			}

			/*! \brief == operator
			 *
			 * Description: Allows for logical comparison between two iterator
			 * objects.
			 * \param a is an iterator
			 * \param b is an iterator
			 * \return Returns a bool that reflects the equality of the
			 * two iterators.
			 */
			friend bool operator==(const iterator& a, const iterator& b)
			{
			  return a.m_point == b.m_point && a.m_Ridx == b.m_Ridx && a.m_Cidx
          == b.m_Cidx;
			}

			/*! \brief != operator
			*
			* Description: Allows for logical comparison between two iterator
			* objects.
			* \param a is an iterator
			* \param b is an iterator
			* \return Returns a bool that reflects the equality of the
			* two iterators.
			*/
			friend bool operator!=(const iterator& a, const iterator& b)
			{
			  return !(a == b);
			}
    };

	/*! \brief starting iterator
	 *
	 * Description: Returns an iterator pointing to the beginning of
	 * the nVect object's array.
   * \param a is the column index of the iterator.
	 * \return Returns a new iterator object that points to the start
	 * of the nVect array.
	 * \pre The first index in the vector that stores data needs to be
	 * m_arr[0].
	 */
    iterator begin(const int a) { return iterator(this, 0, a); }

	/*! \brief ending iterator
	 *
	 * Description: Returns an iterator pointing to the ending of
	 * the nVect object's array.
   * \param a is the column index of the iterator.
	 * \return Returns a new iterator object that points to the end
	 * of the nVect array.
	 */
    iterator end(const int a) { return iterator(this, m_size, a); }
}

#include "kronecker.hpp"
#endif
