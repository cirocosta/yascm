- 'struct' is a class whose members are, by default, public.
- members who are not static are accessed from within a class function directly by its name (or by explicitly using the 'this' pointer as reference).
- By default objects can be copied by initialization

```c++
Date d1 = my_birthday;
Date d1 {my_birthday};
```

- Restricting access to a data structure to an explicitly declared list of function comes with the benefit of a better localization for debugging. Another great thing is that the user who wants to use that class needs only to take a look at its functions definitions (in public).

- For initialization the {} is prefered as it is explicit what it is doing (initialization). With the 'explicit' keyword for a constructor we are able to limit implicit conversions.

- Systematic use of immutable objects leads to more comprehensible code, to more errors being found early, and sometimes to improved performance.

- const member functions can be invoked for both const and non-const objects, whereas a non-const member function can be invoked only for non-const objects.
