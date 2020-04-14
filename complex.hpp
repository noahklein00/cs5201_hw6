// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : complex.hpp

//***************************** Essentials **********************************//

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

//***************************** Accessors ***********************************//

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
complex<T> complex<T>::operator-() const
{
  complex<T> copy(*this);
  copy.m_a = -(copy.m_a);
  return copy;
}

template <typename T>
complex<T> complex<T>::operator!() const
{
  complex<T> copy(*this);
  copy.m_b = -(copy.m_b);
  return copy;
}

template <typename T>
T complex<T>::operator~() const
{
  return sqrt(m_a * m_a + m_b * m_b);
}

//***************************** Mutators ************************************//

template <typename T>
complex<T> complex<T>::operator+(const complex<T>& rhs) const
{
  complex<T> copy(*this);
  copy.m_a += rhs.m_a;
  copy.m_b += rhs.m_b;
  return copy;
}

template <typename T>
complex<T> complex<T>::operator-(const complex<T>& rhs) const
{
  complex<T> copy(*this);
  copy.m_a -= rhs.m_a;
  copy.m_b -= rhs.m_b;
  return copy;
}

template <typename T>
complex<T> complex<T>::operator*(const complex<T>& rhs) const
{
  complex<T> copy(*this);
  copy.m_a = (this -> m_a * rhs.m_a) + -(this -> m_b * rhs.m_b);
  copy.m_b = (this -> m_a * rhs.m_b) + (this -> m_b * rhs.m_a);
  return copy;
}

//***************************** Friends *************************************//

template <typename T>
std::ostream& operator<<(std::ostream& out, const complex<T>& rhs)
{
  if(rhs.m_a)
  {
    out << rhs.m_a;
    if(rhs.m_b && rhs.m_b > 0)
    {
      out << " + " << rhs.m_b << "i";
    }
    else if(rhs.m_b && rhs.m_b < 0)
    {
      out << " - " << -(rhs.m_b) << "i";
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

//***************************** Extras **************************************//
