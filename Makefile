CC = g++
CFLAGS = -std=c++11

ALL : test_FragmentClass

test_FragmentClass : test_FragmentClass.cpp FragmentClass.o
	$(CC) $(CFLAGS) -o test_FragmentClass test_FragmentClass.cpp FragmentClass.o

FragmentClass.o : FragmentClass.cpp
	$(CC) $(CFLAGS) -c FragmentClass.cpp

.PHONY : clean
clean : 
	$(RM) *.o test_FragmentClass
