#rm a.out && ff-c++ test_cout.cpp && g++ test_cout.o && ./a.out 
ff-c++ class_d.cpp 
g++ -bundle -undefined dynamic_lookup -g class_d.o -o ./class_d.dylib
