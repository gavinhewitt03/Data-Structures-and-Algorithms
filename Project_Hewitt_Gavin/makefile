flags = -std=c++11 -Wall

all: test1 test2 test3

test1 : Hewitt_Gavin_QuickSort.cpp input1.txt
	g++ $(flags) $< -o Hewitt_Gavin_QuickSort
	./Hewitt_Gavin_QuickSort $(word 2, $^) output1.txt

test2 : Hewitt_Gavin_QuickSort.cpp input2.txt
	g++ $(flags) $< -o Hewitt_Gavin_QuickSort
	./Hewitt_Gavin_QuickSort $(word 2, $^) output2.txt

test3 : Hewitt_Gavin_QuickSort.cpp input3.txt
	g++ $(flags) $< -o Hewitt_Gavin_QuickSort
	./Hewitt_Gavin_QuickSort $(word 2, $^) output3.txt

new_files : InputFileGenerator.cpp
	g++ $(flags) $< -o InputFileGenerator
	./InputFileGenerator

clean:
	for i in $$(seq 4 25); do \
		rm input$$i.txt; \
	done
