all: print_enum_names integral_test basis_vector

print_enum_names: print_enum_names.cpp Axis.hpp
	g++ -std=c++17 print_enum_names.cpp -o print_enum_names

integral_test: integral_test.cpp Integral.hpp
	g++ -std=c++17 integral_test.cpp -o integral_test

basis_vector: basis_vector.cpp BasisVector.hpp
	g++ -std=c++17 basis_vector.cpp -o basis_vector
