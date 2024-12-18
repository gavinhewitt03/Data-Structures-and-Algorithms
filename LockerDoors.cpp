// 350.002 Gavin Hewitt
// Homework Assignment 1

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/*
    There a n lockers in a hallway, numbered sequentially from 1 to n. Initially, all the
  locker doors are closed. You make r passes by the lockers, each time starting
  with locker #1.
    On the ith pass, i = 1, 2, …., r, you toggle the door of every ith locker: if the door
  is closed, you open it; if it is open, you close it. After the last pass, display the
  following output:
    (a) Locker door# and their status (open/ closed)
    (b) How many locker doors are open?
*/

int main()
{
  // create two ints to be instantiated by user input
  int n, r;
  cout << "Please input a value for n: ";
  cin >> n;
  cout << endl
       << "Please input a value for r: ";
  cin >> r;
  // creates a bool array of n size with false representing closed and true open
  int lockers[n];
  // populate array
  for (int i = 0; i < n; ++i)
    lockers[i] = false;
  // perform actual algorithm
  for (int i = 1; i <= r; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if ((j + 1) % i == 0)
        lockers[j] = !lockers[j];
    }
  }
  // print results
  int count = 0;
  for (int i = 0; i < n; ++i)
  {
    cout << "Locker " << i + 1 << ": " << (lockers[i] ? "Open" : "Closed") << endl;
    if (lockers[i])
      ++count;
  }
  cout << "Number of open lockers: " << count << "." << endl;
  return 0;
}