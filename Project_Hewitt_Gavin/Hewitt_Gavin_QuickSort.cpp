// Gavin Hewitt 350 Final Project

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

#include<fstream>
using std::ifstream;
using std::ios;
using std::fstream;

#include<sstream>
using std::istringstream;
using std::getline;

#include<string>
using std::string;
using std::to_string;

#include<cstdlib>
using std::rand;

void medianOfThree(float a[], int l, int r) {
  int m = (l + r) / 2;
  float temp = 0;
  if(a[l] < a[m]){
    if(a[m] < a[r]) { // middle is median
      temp = a[l];
      a[l] = a[m];
      a[m] = temp;
    } else { // right has to be median
      temp = a[l];
      a[l] = a[r];
      a[r] = temp;
    }
  } else { // know left is bigger than middle
    if (a[r] < a[m]) { // middle is median
      temp = a[l];
      a[l] = a[m];
      a[m] = temp;
    } else { // right is median
      temp = a[l];
      a[l] = a[r];
      a[r] = temp;
    }
  }
}

int partition(float a[], int l, int r) {
  int len = r + l;
  float p;
  if (len >= 3)
    medianOfThree(a, l, r);
  p = a[l];
  int i = l;
  int j = r + 1;
  while ( i < j ) {
    do {
      ++i;
      if(i > r)
        break;
    } while (a[i] <= p);
    do {
      --j;
      if(j <= l)
        break;
    } while(a[j] > p);
    float temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
  // undo last swap
  float temp = a[i];
  a[i] = a[j];
  a[j] = temp;
  // reuse temp to do last swap
  temp = a[l];
  a[l] = a[j];
  a[j] = temp;
  return j;
}

void quickSort(float a[], int l, int r) {
  if ( l < r ) {
    int s = partition(a, l, r);
    quickSort(a, l, s - 1);
    quickSort(a, s + 1, r);
  }
}

int main(int argc, char * argv[]) {
  float * values = new float[100];

  ifstream input_file; // read stream
  input_file.open(argv[1], ios::in); // open data
  
  int index = 0;
  for(string line ; getline(input_file, line);) { // read stream line by line
    istringstream readin(line); // stream for line
    for(int j = 0; j < 10; ++j){ // need loop to read all 10 floats
      readin >> values[index]; // read each float into pointer
      ++index; // increment index
    }
  }

  input_file.close(); // close stream

  // records the time the algorithm starts
  auto start = high_resolution_clock::now();
  quickSort(values, 0, 99);
  // records the time the algorithm ends
  auto stop = high_resolution_clock::now();

  // total time of the algorithm in nanoseconds
  auto duration = duration_cast<nanoseconds>(stop - start);

  fstream output_file; // write stream
  output_file.open(argv[2], ios::out); // open data

  // write to file
  for(int i = 1; i <= 100; ++i) {
    output_file << values[i - 1] << " ";
      // new line in file every 10 numbers to look more appealing
      if(i % 10 == 0)
        output_file << endl;
  }

  // write duration of algorithm to file
  output_file << endl << "The duration time of Quick Sort for these values was " << duration.count() << " nanoseconds." << endl;

  output_file.close(); // close stream

  delete[] values;
  
  return 0;
}