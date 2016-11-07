Car Wash Simulation

For this project we created a car wash simulation program. It was to feature
at least 2 custom queues representing wash stations,
variables for simulation data and an interface for
a user.
	A custom queue class was made for this. It uses
an array of a fixed size and a circular pattern for
element storage and access.
	A custom random proportion generator, simulation
function and interface function were made in the
main car wash class. An effort was made to ensure
that simulations would be somewhat realistic.
	For example, the equation N = 2 * T / W
represents the upper bound on the number of cars
that could be washed by 2 stations in a total time
of T, where W is the time required to was a car. No
experimental results were found to exceed this upper
bound.
	The clang++ and g++ compilers were used for the
compilation of source code into a binary. Problems
were encountered when we tried to split up the class
declarations from the definitions in the car wash
class. So, we simply placed the definitions under
the declarations in each class. This does not
represent professional style, but it works for now.