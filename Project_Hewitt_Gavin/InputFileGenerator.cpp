// Gavin Hewitt 350 Final Project

#include<fstream>
using std::fstream;
using std::ios;

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;
using std::to_string;

#include<cstdlib>
using std::rand;
using std::srand;

// inspiration & functionality from geeks for geeks, modified to fit scope of assignment
float randFloat() {
  return 200 * (float)(rand()) / (float)(RAND_MAX) - 100; 
}

int main() {
  // seed random number generator
  srand(time(0));
  // generate 100 random floating point values from [-100.0,100.0]
  float * rand_nums = new float[100];

  for (int i = 1; i <= 25; ++i) {
    fstream file;
    string filename = "input" + to_string(i) + ".txt";

    file.open(filename, ios::out);

    if (!file) {
      cout << "Error in opening file" << endl;
      break;
    }

    for(int j = 0; j < 100; ++j) {
      rand_nums[j] = randFloat();
    }

    for(int j = 1; j < 101; ++j) {
      file << rand_nums[j - 1] << " ";
      // new line in file every 10 numbers to look more appealing
      if(j % 10 == 0)
        file << endl;
    }

    file.close();
  }

  delete[] rand_nums;
}