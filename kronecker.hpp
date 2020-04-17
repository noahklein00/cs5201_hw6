// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : kronecker.hpp

template <typename T>
nTrix<T> kronecker<T>::operator()(const nTrix<T>& lhs, const nTrix<T>& rhs)
{
  nTrix<T> outer_prod(lhs.rows() * rhs.rows(), lhs.cols() * rhs.cols());

  for(int i = 0; i < lhs.rows(); ++i)
  {
    for(int j = 0; j < lhs.cols(); ++j)
    {
      for(int k = 0; k < rhs.rows(); ++k)
      {
        for(int l = 0; l < rhs.cols(); ++l)
        {
          outer_prod(((i)*rhs.rows()) + k,((j)*rhs.cols() + l)) =
            lhs(i,j) * rhs(k,l);
        }
      }
    }
  }
  return outer_prod;
}
