#include <cassert>
#include <iostream>
#include <sstream>

#include "timespan.h"

using namespace std;
#include <iomanip>

// The purpose of this method is to test the constructor
// The precondition is that enter (minutes, hours, seconds)
// The post condtion execute the test.
void test1() {
  TimeSpan ts(1, 20, 30);
  stringstream ss;
  ss << ts;
  cout << ss.str();
  assert(ss.str() == "1:20:30");
  // reduces the values to hours,minutes,seconds.
  TimeSpan ts2(4, -20, -90);
  ss.str("");
  ss << ts2;
  assert(ss.str() == "3:38:30");

  TimeSpan ts3(1.5, 30.5, -90);
  ss.str("");
  ss << ts3;
  assert(ss.str() == "1:59:00");

  TimeSpan ts4(0, 0.07, 0);
  ss.str("");
  ss << ts4;
  assert(ss.str() == "0:00:04");
  cout << "test1 complete" << endl;
}

// The purpose of this method is to  equality, addition, subtraction,
// multiplication The precondition is that enter (minutes, hours, seconds) The
// post condtion execute the test.

void test2() {
  TimeSpan ts(1, 20, 30);
  TimeSpan ts2(1, 20, 30);
  TimeSpan ts3(0, 0, 0);
  assert(ts == ts2);
  assert(!(ts != ts2));
  assert(ts != ts3);
  assert((ts + ts + ts) == (ts2 * 3));
  assert((ts * 5) == (ts2 * 4) + ts2);
  assert((ts * 5) == ((ts2 * 6) - ts2));
  assert((ts + ts - ts) == ((ts2 * 2) - ts));
  assert((ts - ts2) == ts3);
  assert((ts3 * 5) == ts3);
  cout << "test2 complete" << endl;
}

// The purpose of this method is to  test postive time and negative time
// The precondition is that enter (minutes, hours, seconds)
// The post condtion execute the test.

void test3() {
  TimeSpan ts0(0, 0, 0);
  TimeSpan ts1(0, 0, 10);
  TimeSpan ts2 = ts0 - ts1;
  assert(ts1.isPositive() && !ts2.isPositive());
  stringstream ss;
  ss << ts2;
  assert(ss.str() == "-0:00:10");
  cout << "test3 complete" << endl;
}
// The purpose of this method is to test +=, <,>.
// The precondition is that enter (minutes, hours, seconds)
// The post condtion execute the test.
void test4() {
  TimeSpan ts0(4, 30, 96);
  TimeSpan ts1(3, 20, 83);
  TimeSpan tsCopy(ts0);
  ts0 += ts1;
  assert(ts0 != tsCopy);
  ts0 -= ts1;
  TimeSpan t4(1, 20, 30);
  TimeSpan t5(1, 20, 35);
  assert(t4 < t5);
  assert(t5 > t4);
  cout << "test 4 complete";
}

// The main function calls all test methods
int main() {
  test1();
  test2();
  test3();
  test4();
  cout << "Done." << std::endl;
  return 0;
}