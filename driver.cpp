// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 6 - Complex Numbers, Outer Products, and Quantum
//              Computing
// Filename   : driver.cpp

#include "qreg.h"
#include "gatedata.h"
#include "kronecker.h"
#include "nVect.h"
#include "nTrix.h"
#include "complex.h"

int main()
{
  //I see that there is a lot of cool inheritance/polymorphism that can be done
  //with this. I could not figure out a worthwhile way to implement it for my
  //method of calculating the gates.
  //I could not figure out any other way to do this. :(
  try
  {
    double RT = 1.414213562;
    qreg<3> grover_reg;
    qreg<3> shor_reg;
    gatedata H(nTrix<cpf>({{cpf(1/RT,0),cpf(1/RT,0)},{cpf(1/RT,0),
      cpf(-1/RT,0)}})); //Hadamard gate
    gatedata X(nTrix<cpf>({{cpf(0,0),cpf(1,0)},{cpf(1,0),cpf(0,0)}}));
      //NOT gate
    gatedata Z(nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(-1,0)}}));
      //Z gate
    gatedata S(nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(0,1)}}));
      //S gate
    gatedata T(nTrix<cpf>({{cpf(1,0),cpf(0,0)},{cpf(0,0),cpf(RT/2,RT/2)}}));
      //T gate

    //applies the different gates to the register to build the grover circuit
    grover_reg.apply({0,1,2},{},H);
    grover_reg.apply({0},{2},Z);;
    grover_reg.apply({0},{1},Z);
    grover_reg.apply({0,1,2},{},H);
    grover_reg.apply({0,1,2},{},X);
    grover_reg.apply({0},{1,2},Z);
    grover_reg.apply({0,1,2},{},X);
    grover_reg.apply({0,1,2},{},H);

    std::cout << grover_reg << std::endl;

    //applies the different gates to the register to build the shor's circuit
    shor_reg.apply({0,1,2},{},H);
    shor_reg.apply({1},{},H);
    shor_reg.apply({0},{1},S);
    shor_reg.apply({0},{},H);
    shor_reg.apply({2},{1},T);
    shor_reg.apply({2},{0},S);

    std::cout << shor_reg << std::endl;
  }
  catch(std::domain_error& e)
  {
    std::cerr << "Exception caught, index out of range: "
      << e.what() << std::endl;
  }
  catch(std::invalid_argument& e)
  {
    std::cerr << "Invalid operation of matrices of 2"
      << " different sizes" << std::endl;
  }
  catch(std::range_error& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
