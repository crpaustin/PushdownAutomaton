g++ -c FileIO.cpp
g++ -c Machine.cpp
g++ -c main.cpp
g++ -c State.cpp
g++ -c Transition.cpp
g++ -o project FileIO.o Machine.o main.o State.o Transition.o
del FileIO.o
del Machine.o
del main.o
del State.o
del Transition.o