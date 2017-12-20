#rm a.out && ff-c++ test_cout.cpp && g++ test_cout.o && ./a.out 
ff-c++ class_str.cpp 
g++ -bundle -undefined dynamic_lookup -g class_str.o -o ./class_str.dylib
