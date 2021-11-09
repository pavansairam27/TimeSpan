//
// Created by Pavan Sai Ram Korumilli
//
#include "timespan.h"
#include <cmath>
#include <iomanip>
// The purpose of the method is to print out the output of the class.
// the method takes ostream out and class timespan to print
// Precondition:checks to see the totalnumberofseconds are less that zero
// Postcondition: converts hours minutes and seconds to positive and adds - in
// front the value that returns is the out.
ostream &operator<<(ostream &out, const TimeSpan &ts) {
  if (ts.totalNumberOfSeconds < 0) {
    out << "-" << abs(ts.getHour()) << ":" << setw(2) << setfill('0')
        << abs(ts.getMinute()) << ":" << setw(2) << setfill('0')
        << abs(ts.getSecond());
  } else {
    out << ts.getHour() << ":" << setw(2) << setfill('0') << ts.getMinute()
        << ":" << setw(2) << setfill('0') << ts.getSecond();
  }
  return out;
}

//setting the constructor to default

TimeSpan:: TimeSpan() = default;

// The purposr of the constructor is set the private varible to paramenters
// The method takes hours, minutes, seconds as parameters
// Precondition of TimeSpan is that accepts double hours, minutes, seconds
// Postcondition of TimeSpan is that sets hours, muntes, seconds to private
// variable to use and reduces them to time.
TimeSpan::TimeSpan(double hour, double minute, double second) {
  hours = hour;
  minutes = minute;
  seconds = second;
  reduce();
}
// The purpose of the reduce is to convert the time to hours minute and seconds
// Precondition is to covert to all seconds.
// Postcondition is to covert back to hours, minutes and seconds.
void TimeSpan::reduce() {
  totalNumberOfSeconds = ((hours * 3600) + (minutes * 60) + seconds);
  int roundSecond = int(totalNumberOfSeconds);
  hours = totalNumberOfSeconds / 3600;
  minutes = (roundSecond / 60) % 60;
  seconds = roundSecond % 60;
}

// The purpose of this method is to use private variable hours
// The preconditon is to take it should return hours
// The postcondtion returns hours
// The method returns int value
int TimeSpan::getHour() const { return hours; }

// The purpose of this method is to use private variable minutes
// The preconditon is to take it should return minutes
// The postcondtion returns minutes
// The method returns int value
int TimeSpan::getMinute() const { return minutes; }

// The purpose of this method is to use private variable seconds
// The preconditon is to take it should return seconds
// The postcondtion returns seconds
// The method returns int value
int TimeSpan::getSecond() const { return seconds; }
// The purpose of this method is to use private variable totalseconds
// The preconditon is to take it should return only totalseconds
// The postcondtion returns totalseconds
// The method returns int value
int TimeSpan::getTotalNumberOfSeconds() const { return totalNumberOfSeconds; }

// The purpose of the method is to hours seconds and minutes are positive
// The precondtion is the total time is positve
// The postcondtion is it would return true if the total time is positive.
// The return vlaue much be true or false
bool TimeSpan::isPositive() const {
  if (totalNumberOfSeconds > 0) {
    return true;
  }
  return false;
}

// The puropse of the method is to add two timespans by using the operator+
// The precondtions created new object tsSum and add the new object with current
// obj.
// like tssum hours = hours+ ts.hours;
// The post condition is that adds the new object and current obj.
// The parameters that it takes are timespan value reference.
// It would return the new object which tsSum

TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  double hoursOfSum = this->getHour() + ts.getHour();
  double minutesOfSum = this->getMinute() + ts.getMinute();
  double secondsOfSum = this->getSecond() + ts.getSecond();
  TimeSpan tsSum(hoursOfSum, minutesOfSum, secondsOfSum);
  return tsSum;
}

// The puropse of the method is to subtract two timespans by using the operator-
// The precondtions created new object tsSub and substract the new object with
// current obj.
// like tsSub hours = hours -  ts.hours;
// The post condition is that substracts the new object and current obj.
// The parameters that it takes are timespan value reference.
// It would return the new object which tsSub
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  double hoursOfSub = this->getHour() - ts.getHour();
  double minutesOfSub = this->getMinute() - ts.getMinute();
  double secondsOfSub = this->getSecond() - ts.getSecond();
  TimeSpan tsSub(hoursOfSub, minutesOfSub, secondsOfSub);
  return tsSub;
}

// The puropse of the method is to multiples timespans by using the operator*
// The precondtions created new object tsSum and multiples with the user number.
// like tsLarge hours =ts.hours*number;
// The post condition is that multiples the new object with number.
// The parameters that it takes are int number.
// It would return the new object which tsLarge
TimeSpan TimeSpan::operator*(unsigned int number) const {
  double hoursOfLarge = this->getHour() * number;
  double minutesOfLarge = this->getMinute() * number;
  double secondsOfLarge = this->getSecond() * number;
  TimeSpan tsLarge(hoursOfLarge, minutesOfLarge, secondsOfLarge);
  return tsLarge;
}

// The puropse of the method is to check to see two are equal timespans by using
// == The precondtions is to check to see the two timespan equal. The post
// condition is that it would check to see two timedpan are return true else
// false
// the parameters that it takes are timespan value .
// It would return false
bool TimeSpan::operator==(const TimeSpan &ts) const {
  if ((ts.hours == hours) && (ts.minutes == minutes) &&
      (ts.seconds == seconds)) {
    return true;
  }
  return false;
}

// The puropse of the method is to check to see two timespans are not equal by
// using != operator The precondtions is to check to see the two timespan are not
// equal. The post condition is that it would check to see two timespan are not
// equal return true else false
// the parameters that it takes are timespan value .
// It would return false
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  if (!(ts.hours == hours && ts.minutes == minutes && ts.seconds == seconds)) {
    return true;
  }
  return false;
}

// The puropse of the method is to add two timespans by using the operator+=
// The precondtions add the new object with current obj.
// like hours = hours+ ts.hours;
// The post condition is that adds the new object and current obj.
// The parameters that it takes are timespan value reference.
// It would return this because it is a reference type
TimeSpan &TimeSpan::operator+=(const TimeSpan &ts) {
  hours = ts.hours + hours;
  minutes = ts.minutes + minutes;
  seconds = ts.seconds + seconds;

  return *this;
}

// The puropse of the method is to subtract two timespans by using the
// operator-= The precondtions created substract the new object with current obj.
// like hours = hours -  ts.hours;
// The post condition is that substracts the new object and current obj.
// The parameters that it takes are timespan value reference.
// It would return reference which is this
TimeSpan &TimeSpan::operator-=(const TimeSpan &ts) {
  hours = ts.hours - hours;
  minutes = ts.minutes - minutes;
  seconds = ts.seconds - seconds;

  return *this;
}

// The puropse of the method is to check to see two timespans are less than by
// using < operator The precondtions is to check to see the two timespan are less
// than. The post condition is that it would check to see two timespan are less
// than return true else false
// the parameters that it takes are timespan value .
// It would return false

bool TimeSpan::operator<(const TimeSpan &ts) const {
  if (totalNumberOfSeconds < ts.totalNumberOfSeconds) {
    return true;
  }
  return false;
}
// The puropse of the method is to check to see two timespans are greater than
// by using > operator The precondtions is to check to see the two timespan are
// greater than. The post condition is that it would check to see two timespan
// are greater than return true else false
// the parameters that it takes are timespan value .
// It would return false

bool TimeSpan::operator>(const TimeSpan &ts) const {
  if (totalNumberOfSeconds > ts.totalNumberOfSeconds) {
    return true;
  }
  return false;
}

// The puropse of the method is to check to see two timespans are less than
// equal by using <= operator The precondtions is to check to see the two
// timespan are less than equal. The post condition is that it would check to see
// two timespan are less than equal return true else false
// the parameters that it takes are timespan value .
// It would return false

bool TimeSpan::operator<=(const TimeSpan &ts) const {
  if (this->getTotalNumberOfSeconds() <= ts.totalNumberOfSeconds) {
    return true;
  }
  return false;
}
// The puropse of the method is to check to see two timespans are greater than
// equal by using >= operator The precondtions is to check to see the two
// timespan are greater than equal. The post condition is that it would check to
// see two timespan are greater than equal return true else false
// the parameters that it takes are timespan value .
// It would return false
bool TimeSpan::operator>=(const TimeSpan &ts) const {
  if (totalNumberOfSeconds >= ts.totalNumberOfSeconds) {
    return true;
  }
  return false;
}
