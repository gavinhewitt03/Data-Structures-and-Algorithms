Gavin Hewitt CSCE 350 Final Project

Compile/Run instructions for my code:

This project contains two C++ files: QuickSort and InputFileGenerator; InputFileGenerator creates twenty five text files with 100 distinct random floating point values and QuickSort takes an input file of 100 values and, as you would expect from the title, uses the Quick Sort algorithm to sort them.

To execute this code, you will use the provided makefile. First, enter "make new_files" to generate input files. Then, you can run make test1, make test2, make test3, or make all to test the quick sort functionality. This code only tests and creates an output for input files 1-3; however, you can input the commands:
    g++ -std=c++17 -Wall Hewitt_Gavin_QuickSort.cpp -o Hewitt_Gavin_Quicksort
    ./Hewitt_Gavin_Quicksort inputi.txt outputi.txt
where i is the number associated with the input file you want to use to test the code on other inputs. Make clean erases input files 4-25, leaving only input and output files 1-3 for simple organization. Each output file contains the sorted input list and the duration of the quick sort algorithm on the sorted list.