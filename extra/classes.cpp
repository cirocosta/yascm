#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

class Date {
public:
  // 'explicit' lets us disallow implicit conversions
  // (e.g, declaring Date d = {10} does not make
  // much sense.)

  // explicit Date (int dd = 66, int mm = 66, int yy = 66)
  //   : d(dd), m(mm), y(yy) {}

  // not marked as explicit so that we are able to
  // perform `Date d = {1,2,3}`
  Date (int dd = today.d, int mm = today.m, int yy = today.y)
    : d(dd), m(mm), y(yy) {}

  // 'today' is part of the Class, not only of an
  // 'object (like a 'global' variable to the
  // 'objects that are constructed from this
  // 'class). ps: in multithread code we must pay
  // 'attention to this as we might run into race
  // 'conditions (must use a lock system)
  static Date today;

  // a static function is a member function that
  // is able to access members of a class but that
  // doesn't need to be invoked in a particular
  // object
  static void set_today (int dd, int mm, int yy);

  // const after the argument list indicates that
  // the function does not modify the state of the
  // object. Both const and non-const objects can
  // have a const function invoked while non-const
  // functions can only be invoked by non-const
  // instances.
  int day () const {return d;}
  int month () const {return m;}
  int year () const {return y;}

  // non-const functions (only callable from non-
  // const functions). By returning a reference to
  // the object we are able to chain method calls
  // (each non-static member knows for whom to
  // refer).  In case of non-const member
  // functions the type of 'this' is Date*. It is
  // also considered an rvalue (not allowing
  // assignement). In a const member function, the
  // type is const Date*.
  Date& add_year () {y++; return *this;}
  Date& add_month () {m++; return *this;}
  Date& add_day () {d++; return *this;}

  string get_string_rep() const;
private:
  int d, m, y;

  // mutable lets us to perform mutable actions
  // even from a const object. This should be use
  // with a great care.  ps: const does not apply
  // to objects accessed through pointers or
  // references.
  mutable bool cache_valid;
  mutable string cache;
  void compute_cache_value() const;
};

Date Date::today {100, 100, 100};

void Date::set_today (int dd, int mm, int yy)
{
  today = {dd, mm, yy};
}

// theorically this method shouldn't be able to
// modify something in the class. But, because we
// have some members that are 'mutable', then
// there's no problem if we modify then from this
// const method
string Date::get_string_rep () const
{
  if (!cache_valid) {
    cache_valid = true;
    compute_cache_value();
  }

  return cache;
}

void Date::compute_cache_value () const
{
  cache = to_string(day()) + "/" +
          to_string(month()) + "/" +
          to_string(year());
}


int main(int argc, char const *argv[])
{
  cout << "today: " << Date::today.get_string_rep() << endl;
  Date::set_today(1,1,1);
  cout << "today: " << Date::today.get_string_rep() << endl;

  const Date date {1, 2, 3};
  Date date2 {6,6,6};

  date2
    .add_year()
    .add_month()
    .add_day();

  cout << "date1: " << date.get_string_rep() << endl;
  cout << "date2: " << date2.get_string_rep() << endl;

  return 0;
}
