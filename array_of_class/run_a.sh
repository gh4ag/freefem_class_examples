#rm a.out && ff-c++ test_cout.cpp && g++ test_cout.o && ./a.out 
ff-c++ class_a.cpp  
g++ -bundle -undefined dynamic_lookup -g class_a.o -o ./class_a.dylib
#ff-c++  class_a.o -o ./class_a.dylib
