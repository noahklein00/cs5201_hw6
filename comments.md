-3 Magnitude logic is incorrect - you are returning the squared magnitude, not the magnitude
(it's the Pythagorean theorem)

-2 Instructions specified to use the C++ random utils, not those from the C standard library

-3 No need for dynamic memory inside your quantum register class, or your gatedata class

-2 P_0/P_1 are the same for all instances of your gate class - they should
probably be static variables, ditto for identity matrix

-2 `a` and `b` are not good names for your creation function - the name of a variable
should generally indicate what it's for

-2 "Everything for the complex and nTrix classes are defined." - what is "everything"?

-2 Should be some degree of inheritance/polymorphism


Your score is:
84
