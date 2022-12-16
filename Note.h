#pragma once
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;

class Note {
private:
  string name;
  string last_name;
  string phone_number;
  int birthday[3];
public:
  Note();
  ~Note(); 
  Note(string name, string last_name, string phone_number, int birthday[3]);

  void set_name(string name);
  void set_last_name(string last_name);
  void set_phone_number(string phone_number);
  void set_birthday(int birthday[3]);
  string get_name();
  string get_last_name();
  int* get_birthday();
  string describe();

  friend std::istream& operator>> (std::istream &in, Note &note);
};