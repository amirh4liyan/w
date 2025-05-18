run: a_1_3.out
	./a_1_3.out < input3

run2: a_1_2.out
	./a_1_2.out < input1

run1: a_1_1.out
	./a_1_1.out < input1
	./a_1_1.out < input2

a_1_3.out: PanicCounter_Stack.cpp
	g++ PanicCounter_Stack.cpp -o a_1_3.out

a_1_2.out: PanicCounter_Queue.cpp
	g++ PanicCounter_Queue.cpp -o a_1_2.out

a_1_1.out: PanicCounter.cpp
	g++ PanicCounter.cpp -o a_1_1.out
