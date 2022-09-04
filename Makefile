test: loadingbar.cxx test.cpp
	g++ -std=c++2a -fmodules-ts -Wall -pedantic -o test loadingbar.cxx test.cpp
