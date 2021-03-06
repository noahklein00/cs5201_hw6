/*! \file
 *
 * Definitions for the nTrix class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 6 \n
 */

#ifndef NTRIX_H
#define NTRIX_H

#include "nVect.h"

//! nTrix class.
/*!
 * This class uses an array of pointers to simulate a 2D array for
 * matrix implementation
 */
template <typename T>
class nTrix
{
	private:
		short m_row; /*!< A short that is used to store the number of rows */
		short m_col; /*!< A short that is used to store the number of columns */
		T** m_matrix; /*!< A T** that simulates a 2D array of type T objects */

	public:

		// Essential //

		/*! \brief Default Constructor
		 *
		 * Description: Creates a default 2x2 matrix.
		 * \post A 2x2 matrix is initialized with no values stored.
		 */
		nTrix();

		/*! \brief Constructor
		 *
		 * Description: A constructor that accepts a std::initializer_list of
		 * std::initializer_list<T> to fill a matrix with the values specified.
		 * \param grid is a list of lists that store the values to be input
		 * into the matrix.
		 * \pre = operator must be defined for type T.
		 * \post A matrix is initialized with the dimensions and values of the
		 * list of lists passed.
		 * \throw Throws a std::domain_error object if one of the lists is
		 * not the same length as the others.
		 */
		nTrix(const std::initializer_list<std::initializer_list<T>>& grid);

		/*! \brief Constructor
		 *
		 * Description: Constructs a matrix of size num_rows x num_cols with no
		 * values stored.
		 * \param num_rows is the number of rows for the matrix.
		 * \param num_cols is the number of columns for the matrix.
		 * \post A r x c matrix is initialized with no values stored.
		 * \throw Throws a std::domain_error object if either of the
		 * dimensions are negative.
		 */
		nTrix(const short num_rows, const short num_cols);

		/*! \brief Vector Constructor
		 *
		 * Description: Allows a matrix to be constructed based on a nVect vector.
		 * The matrix is a column matrix.
		 * \param rhs is the nVect to be copied.
		 * \pre = operator needs to be defined for type T.
		 * \post A column matrix is constructed with the same values in the nVect.
		 */
		nTrix(const nVect<T>& rhs);

		/*! \brief Copy Constructor
		 *
		 * Description: Copy constructor that initializes a new matrix with the
		 * same values as the matrix passed.
		 * \param rhs is the matrix to be copied.
		 * \pre = operator needs to be defined for type T.
		 * \post A new matrix is initialized with the same values as the one passed.
		 */
		nTrix(const nTrix<T>& rhs);

		/*! \brief = operator
		 *
		 * Description: = operator for the nTrix class that sets the calling object
		 * equal to the object passed.
		 * \param rhs is the matrix to be copied.
		 * \return Returns *this with the copied values.
		 * \pre = operator needs to be defined for type T.
		 * \post The calling object is set equal to the object passed.
		 */
		nTrix<T>& operator=(const nTrix<T>& rhs);

		/*! \brief Destructor
		 *
		 * Description: Properly destructs a nTrix object to avoid memory leaks.
		 * \post The calling object is safely destructed.
		 */
		~nTrix();

		// Accessors //

		/*! \brief Row accessor
		 *
		 * Description: Returns the number of rows in a matrix.
		 * \return The number of rows in a matrix.
		 */
		short rows() const;

		/*! \brief Column accessor
		 *
		 * Description: Returns the number of columns in a matrix.
		 * \return The number of columns in a matrix.
		 */
		short cols() const;

		/*! \brief Index accessor
		 *
		 * Description: Allows the user to view the i,j-th element in the matrix.
		 * \param row_index is the row to view.
		 * \param col_index is the column member of the row to view.
		 * \return Returns a const reference to the T object at that index in the
		 * matrix.
		 * \throw Throws a std::domain_error object if either of the indexes are
		 * less than zero or greater than their respective domains that they are
		 * attempting to access.
		 */
		const T& operator()(const int row_index, const int col_index) const;

		/*! \brief One norm calculator
		 *
		 * Description: Calculates the one-norm or the maximum column sum of a
		 * matrix.
		 * \return Returns a float that represents the maximum column sum.
		 * \pre std::abs() needs to be defined for type T.
		 * \pre += operator needs to be defined for type T.
		 */
		float one_norm() const;

		/*! \brief Infinity norm calculator
		 *
		 * Description: Calculates the infinity-norm or the maximum row sum of
		 * a matrix.
		 * \return Returns a float that represents the maximum row sum.
		 * \pre std::abs() needs to be defined for type T.
		 * \pre += operator needs to be defined for type T.
		 */
		float infinity_norm() const;

		/*! \brief frobenius norm
		 *
		 * Description: Two norm calculator for matrices.
		 * \return returns the frobenius norm of the matrix as a float.
		 * \pre * operator must be defined for type T.
		 */
		float frobenius() const;

		// Mutators //

		/*! \brief Index accessor
		 *
		 * Description: Allows the user to access the i,j-th element in the matrix.
		 * \param row_index is the row to view.
		 * \param col_index is the column member of the row to view.
		 * \return Returns a reference to the T object at that index in the
		 * matrix.
		 * \throw Throws a std::domain_error object if either of the indexes are
		 * less than zero or greater than their respective domains that they are
		 * attempting to access.
		 */
		T& operator()(const int row_index, const int col_index);

		/*! \brief + operator
		 *
		 * Description: + operator overload for the nTrix class that allows for
		 * the addition of two nTrix objects.
		 * \param rhs is the nTrix to be added to the calling object.
		 * \return Returns a new matrix that is the sum of the calling object
		 * and the object passed.
		 * \pre += operator needs to be defined for type T.
		 * \throw Throws a std::invalid_argument object if the matrices are not
		 * the same size.
		 */
		nTrix<T> operator+(const nTrix<T>& rhs) const;

		/*! \brief Binary - operator
		 *
		 * Description: - operator overload for the nTrix class that allows for
		 * the subtraction of two nTrix objects.
		 * \param rhs is the nTrix to be subtracted from the calling object.
		 * \return Returns a new matrix that is the difference of the calling
		 * object and the object passed.
		 * \pre * operator must be defined for type T.
		 * \pre += operator must be defined for type T.
		 * \throw Throws a std::invalid_argument object if the matrices are not
		 * the same size.
		 */
		nTrix<T> operator-(const nTrix<T>& rhs) const;

		/*! \brief Unary - operator
		 *
		 * Description: - operator overload for the nTrix class that negates every
		 * element in the matrix.
		 * \return Returns a new nTrix with all values from the calling object
		 * negated.
		 * \pre * operator must be defined for type T.
		 */
		nTrix<T> operator-() const;

		/*! \brief * operator
		 *
		 * Description: * operator overload for the nTrix class that allows the user
		 * to multiply two nTrix objects of the same type.
		 * \param rhs is the nTrix to be multiplied with the calling object.
		 * \return Returns a new nTrix that is the product of the calling object
		 * and the object passed.
		 * \pre * operator must be defined for type T.
		 * \throw Throws a std::invalid_argument object if the two matrices are
		 * not the correct dimensions for matrix multiplication to occur.
		 */
		nTrix<T> operator*(const nTrix<T>& rhs) const;

		/*! \brief * operator
		 *
		 * Description: * operator overload for the nTrix class that allows the user
		 * to multiply a matrix with a vector.
		 * \param rhs is a nVect object to be multiplied to a nTrix.
		 * \return Returns a nVect<T> object with the values having matrix
		 * multiplicaion applied.
		 * \pre * operator must be defined for type T.
		 * \throw Throws a std::invalid_argument object if the vector and matrix
		 * are not the correct dimensions for multiplication to occur.
		 */
		nVect<T> operator*(const nVect<T>& rhs) const;

		/*! \brief Clear function
		 *
		 * Description: Allows the user to clear a nTrix object.
		 * \post All of the calling object's data is erased and the size is set to
		 * 0x0.
		 */
		void clear();

		/*! \brief invert function
		 *
		 * Description: Inverts the calling object using the Newton-Schultz
		 * iterative method for inverting a matrix.
		 * \return Returns a nTrix<float> that represents the inverted calling
		 * object.
		 * \post Calls the r_invert() function to recursively iterate the matrix.
		 * \throw Throws a std::range_error object if the object is not a square
		 * matrix.
		 */
		nTrix<float> invert() const;

		/*! \brief Transpose function
		 *
		 * Description: Calculates the transpose of a matrix.
		 * \return Returns a new nTrix<T> that is the transpose of the calling
		 * object.
		 * \pre = operator must be defined for type T.
		 */
		nTrix<T> transpose() const;

		// Friends //

		/*! \brief << operator
		 *
		 * Description: << operator overloaded to pretty print the nTrix object.
		 * \param out is the ostream object passed to the function.
		 * \param rhs is the nTrix<T> object to be output.
		 * \return Returns the ostream.
		 * \pre << operator must be defined for type T.
		 * \post Outputs the matrix to the user.
		 */
		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const nTrix<U>& rhs);

		/*! \brief >> operator
		 *
		 * Description: >> operator overloaded to extract a matrix object from
		 * the istream. The inputted matrix overloads any previously stored data
		 * in the nTrix object.
		 * \param in is the istream object passed to the function.
		 * \param rhs is the nTrix<T> object to store the input.
		 * \return Returns the istream.
		 * \pre >> operator must be defined for type T.
		 * \post Stores the input in the object passed.
		 * \throw Throws a std::range_error object if the user inputs an incorrect
		 * number of items for a column.
		 */
		template <typename U>
		friend std::istream& operator>>(std::istream& in, nTrix<U>& rhs);
};

// Extras //

/*! \brief << operator
 *
 * Description: << operator overloaded to pretty print the nTrix object.
 * \param out is the ostream object passed to the function.
 * \param rhs is the nTrix<T> object to be output.
 * \return Returns the ostream.
 * \pre << operator must be defined for type T.
 * \post Outputs the matrix to the user.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const nTrix<T>& rhs);

/*! \brief >> operator
 *
 * Description: >> operator overloaded to extract a matrix object from
 * the istream. The inputted matrix overloads any previously stored data
 * in the nTrix object.
 * \param in is the istream object passed to the function.
 * \param rhs is the nTrix<T> object to store the input.
 * \return Returns the istream.
 * \pre >> operator must be defined for type T.
 * \post Stores the input in the object passed.
 * \throw Throws a std::range_error object if the user inputs an incorrect
 * number of items for a column.
 */
template <typename T>
std::istream& operator>>(std::istream& in, nTrix<T>& rhs);

/*! \brief * operator
 *
 * Description: Scalar multiplication for a nTrix<T> object.
 * \param lhs is the nTrix<T> object to be multiplied through.
 * \param scalar is the scalar to multiply through the matrix.
 * \return Returns a new nTrix<T> object with the scalar
 * multiplied throughout.
 * \pre * operator must be defined for type T.
 */
template <typename T>
nTrix<T> operator*(const nTrix<T>& lhs, const float scalar);

/*! \brief * operator
 *
 * Description: * operator overload for the nTrix class that allows the user
 * to multiply a matrix with a vector.
 * \param lhs is a nVect object to be multiplied to a nTrix.
 * \param rhs is a nTrix object to be multiplied to a nVect.
 * \return Returns a nTrix<T> object with the proper dimensions and
 * with the values having matrix multiplicaion applied.
 * \pre * operator must be defined for type T.
 * \throw Throws a std::invalid_argument object if the two matrices are
 * not the correct dimensions for matrix multiplication to occur.
 */
template <typename T>
nTrix<T> operator*(const nVect<T>& lhs, const nTrix<T>& rhs);

/*! \brief recursive invert
 *
 * Description: Recursive part of the invert function that iteratively
 * calculates the inverse of a matrix.
 * \param A is the matrix that the user wants the inverse of.
 * \param B is the previous version of one of the matrices needed in
 * the iterative calculation.
 * \param E is one of the matrices needed in the iterative calculation.
 * \param I is the identity matrix in the proper dimension of the matrix A.
 * \param Cerror is the current frobenius norm of matrix B.
 * \param Perror is the previous frobenius norm of  matrix B.
 * \return Returns an inverted matrix A.
 * \pre =, -, and * operators need to be defined for type T.
 */
template <typename T>
nTrix<float> r_invert(const nTrix<T>& A, nTrix<float>& B,
	nTrix<float>& E, const nTrix<float>& I,  float Cerror, float Perror);


#include "nTrix.hpp"
#endif
