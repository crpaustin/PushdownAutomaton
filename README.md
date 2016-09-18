# Pushdown Automaton
Project for CSC 2710 - Foundation of Computer Science.

### Usage
To use the program, simply run compile.bat. This requires g++. Once it runs, you will be asked to type in the name of the input file. You may then type an input for the Pushdown Automaton, and run it all the way through or step by step. After it runs through everything, it will return if the input was accepted or rejected by the language L(M) for the Pushdown Automaton given by the input file.

### What it does
This program takes a text file input and uses that to create a two-stack Pushdown Automaton with language L(M). The first line of the input takes the alphabet of the language, with each character being separated by a space. The second line takes an integer representing the number of states in the Pushdown Automaton. The third line takes the list of final states which are labeled 0 through the number of states minus 1, separated by spaces. The rest of the input is as many lines as there are states. Each line contains a number of strings, separated by spaces, that is equal to the number of characters in the alphabet of the Pushdown Automaton. Each string contains 5 pieces, separated by commas. The first piece is an integer 0 through the number of states minus 1, which represents which state to go to next. The second piece is the character to push onto the first stack or ! if nothing is to be pushed. The third piece is the character to pop from the first stack or ! if nothing is to be popped. The fourth piece is the character to push onto the second stack of ! if nothing is to be pushed. The fifth piece is the character to pop from the second stack or ! if nothing is to be popped.

Once the input has been read, it creates the Pushdown Automaton using a set of classes which I built for the program. Once it has created the Pushdown Automaton, the user may then input a word into the language. The program will ask the user whether he or she wants to run the test all the way through or step by step. If the user chooses to run it all the way through, the program will only tell the user if the word was accepted or rejected by the language L(M). If the user runs it step by step, it will present the user with the current state, current top value for each stack, and the current remaining input. The user may then choose to walk another step through the program, or to run the rest of the program and only return the output.

### Input Files Given
Test 1 (test1.txt):
L(M) = {a<sup>n</sup>b<sup>m</sup>c<sup>n</sup>d<sup>m</sup> | n,m >= 0}

Test 2 (test2.txt):
L(M) = {a<sup>n</sup>b<sup>m</sup>c<sup>m</sup>d<sup>n+1</sup> | n,m >= 0}

Test 3 (test3.txt):
L(M) = {a<sup>n</sup>b<sup>n</sup>c<sup>n</sup> | n >= 0}
