#include "Note.h"

Note::Note() {
  cout << "Note empty constructor\n";
}

Note::~Note() {
  cout << "Note empty destructor\n";
}

Note::Note(string name, string last_name, string phone_number, int birthday[3]) {
  this->name = name;
  this->last_name = last_name;
  this->phone_number = phone_number;
  this->birthday[0] = birthday[0];
  this->birthday[1] = birthday[1];
  this->birthday[2] = birthday[2];
}

void Note::set_name(string name) {
  this->name = name;
}

void Note::set_last_name(string last_name) {
  this->last_name = last_name;
}

void Note::set_phone_number(string phone_number) {
  this->phone_number = phone_number;
}

void Note::set_birthday(int birthday[3]) {
  this->birthday[0] = birthday[0];
  this->birthday[1] = birthday[1];
  this->birthday[2] = birthday[2];
}

string Note::get_name() {
  return this->name;
}

string Note::get_last_name() {
  return this->last_name;
}

int* Note::get_birthday() {
  return this->birthday;
}

string Note::describe() {
  std::stringstream ss;
  ss << last_name << " " << name << " " << phone_number << " " << birthday[0] << "." << birthday[1] << "." << birthday[2];
  return ss.str();
}

std::istream& operator>> (std::istream &in, Note &note) {
  cout << "last_name: "; in >> note.last_name;
  cout << "name: "; in >> note.name;
  cout << "phone_number: "; in >> note.phone_number;
  int d, m, y;
  cout << "day: "; cin >> d;
  cout << "month: "; cin >> m;
  cout << "year: "; cin >> y;
  note.set_birthday(new int[3]{d, m, y});
  return in;
}