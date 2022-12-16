#pragma once
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string.h>
#include "Note.h"

using std::string;
using std::cout;
using std::cin;

class Keeper {
private:
  Note **notes = new Note*[0];
  int count;
public:
  Keeper();
  ~Keeper();

  void add(Note *new_note);
  void print();
  void print_by_month(int month);
  void remove(int num);
  Note *get(int num);
  void free();
  void sort();

  void operator++(int d);
  void operator--(int d);
  Note *operator[] (const int index);
};