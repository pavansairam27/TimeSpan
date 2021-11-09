// Pavan Sai Ram Korumilli
// css 342
// The purpose: The assignment is meant to understand operator overloaded by
// using +,-,*,<,>.

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H
#include <iomanip>
#include <iostream>

using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  // The construtor takes double hour, minute, second
  // Precondition of TimeSpan is that accepts double hours, minutes, seconds
  // Postcondition of TimeSpan is that sets hours, muntes, seconds to private
  // variable to use.
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);
  //default constructor
  TimeSpan();

  // The puropse of the method is to add two timespans by using the operator+
  // The precondtions created new object tsSum and add the new object with
  // current obj. The post condition is that adds the new object and current obj.
  // The parameters that it takes are timespan value reference.
  // It would return the new object which tsSum
  TimeSpan operator+(const TimeSpan &ts) const;

  // The puropse of the method is to subtract two timespans by using the
  // operator-
  // The precondtions created new object tsSub and substract the new object with
  // current obj. The post condition is that substracts the new object and
  // current obj.
  // The parameters that it takes are timespan value reference.
  // It would return the new object which tsSub
  TimeSpan operator-(const TimeSpan &ts) const;

  // The puropse of the method is to check to see two are equal timespans by
  // using == The precondtions is to check to see the two timespan equal. The
  // post condition is that it would check to see two timedpan are return true
  // else false
  // the parameters that it takes are timespan value .
  // It would return false
  bool operator==(const TimeSpan &ts) const;

  // The puropse of the method is to check to see two timespans are not equal by
  // using != operator The precondtions is to check to see the two timespan are
  // not equal. The post condition is that it would check to see two timespan are
  // not equal return true else false
  // the parameters that it takes are timespan value .
  // It would return false
  bool operator!=(const TimeSpan &ts) const;

  // The puropse of the method is to multiples timespans by using the operator*
  // The precondtions created new object tsSum and multiples with the user
  // number. The post condition is that multiples the new object with number.
  // The parameters that it takes are int number.
  // It would return the new object which tsLarge
  TimeSpan operator*(unsigned int number) const;

  // The puropse of the method is to add two timespans by using the operator+=
  // The precondtions add the new object with current obj.
  // The post condition is that adds the new object and current obj.
  // The parameters that it takes are timespan value reference.
  // It would return this because it is a reference type
  TimeSpan &operator+=(const TimeSpan &ts);

  // The puropse of the method is to subtract two timespans by using the
  // operator-= The precondtions created substract the new object with current
  // obj. The post condition is that substracts the new object and current obj.
  // The parameters that it takes are timespan value reference.
  // It would return reference which is this
  TimeSpan &operator-=(const TimeSpan &ts);

  // The puropse of the method is to check to see two timespans are less than by
  // using < operator The precondtions is to check to see the two timespan are
  // less than. The post condition is that it would check to see two timespan are
  // less than return true else false
  // the parameters that it takes are timespan value .
  // It would return false
  bool operator<(const TimeSpan &ts) const;

  // The puropse of the method is to check to see two timespans are greater than
  // by using > operator The precondtions is to check to see the two timespan are
  // greater than. The post condition is that it would check to see two timespan
  // are greater than return true else false
  // the parameters that it takes are timespan value .
  // It would return false
  bool operator>(const TimeSpan &ts) const;

  // The puropse of the method is to check to see two timespans are less than
  // equal by using <= operator The precondtions is to check to see the two
  // timespan are less than equal. The post condition is that it would check to
  // see two timespan are less than equal return true else false
  // the parameters that it takes are timespan value .
  // It would return false
  bool operator<=(const TimeSpan &ts) const;

  // The puropse of the method is to check to see two timespans are greater than
  // equal by using >= operator The precondtions is to check to see the two
  // timespan are greater than equal. The post condition is that it would check
  // to see two timespan are greater than equal return true else false
  // the parameters that it takes are timespan value .
  // It would return false
  bool operator>=(const TimeSpan &ts) const;

  // The purpose of this method is to use private variable hours
  // The preconditon is to take it should return hours
  // The postcondtion returns hours
  // The method returns int value
  int getHour() const;

  // The purpose of this method is to use private variable minutes
  // The preconditon is to take it should return minutes
  // The postcondtion returns minutes
  // The method returns int value
  int getMinute() const;

  // The purpose of this method is to use private variable seconds
  // The preconditon is to take it should return seconds
  // The postcondtion returns seconds
  // The method returns int value
  int getSecond() const;

  // The purpose of this method is to use private variable totalseconds
  // The preconditon is to take it should return only totalseconds
  // The postcondtion returns totalseconds
  // The method returns int value
  int getTotalNumberOfSeconds() const;

  // The purpose of the method is to hours seconds and minutes are positive
  // The precondtion is the total time is positve
  // The postcondtion is it would return true if the total time is positive.
  // The return vlaue much be true or false
  bool isPositive() const;

private:
  // Creating private variable to access all of the class
  double hours;

  // Creating private variable to access all of the class
  double minutes;

  // Creating private variable to access all of the class
  double seconds;

  // Creating private variable to access all of the class
  double totalNumberOfSeconds;

  // The purpose of the reduce is to convert the time to hours minute and
  // seconds Precondition is to covert to all seconds. Postcondition is to covert
  // back to hours, minutes and seconds.
  void reduce();
};

#endif // ASS2_TIMESPAN_H