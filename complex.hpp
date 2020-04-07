// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 5 - Matrices, Filters, and Guidance
// Filename   : nTrix.hpp

template <typename T>
complex<T>::complex(const complex<T>& rhs)
{
  m_a = rhs.m_a;
  m_b = rhs.m_b;
}

template <typename T>
complex<T>& complex<T>::operator=(const complex<T>& rhs)
{
  m_a = rhs.m_a;
  m_b = rhs.m_b;
  return *this;
}

template <typename T>
T complex<T>::real() const
{
  return m_a;
}

template <typename T>
T complex<T>::imag() const
{
  return m_b;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const complex<T>& rhs)
{
  if(rhs.m_a)
  {
    out << rhs.m_a << " ";
    if(rhs.m_b && rhs.m_b > 0)
    {
      out << "+ " << rhs.m_b << "i";
    }
    else if(rhs.m_b && rhs.m_b < 0)
    {
      out << "- " << -(rhs.m_b) << "i";
    }
  }
  else if(rhs.m_b)
  {
    out << rhs.m_b << "i";
  }
  else
  {
    out << rhs.m_a;
  }
  return out;
}
