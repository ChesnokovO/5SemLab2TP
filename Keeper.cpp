#include "Keeper.h"

Keeper::Keeper() {
  count = 0;
  cout << "Keeper empty constructor\n";
}

Keeper::~Keeper() {
  cout << "Keeper destructor\n";
}

void Keeper::add(Note *new_note) {
  Note **temp = new Note*[count];
  for (int i = 0; i < count; i++) temp[i] = notes[i];

  notes = new Note*[count + 1];
  for (int i = 0; i < count; i++) {
    notes[i] = temp[i];
  }
  notes[count++] = new_note;
  delete[] temp;
}

void Keeper::print() {
  if (!count) throw std::runtime_error("the list of notes is empty");
  sort();
  for (int i = 0; i < count; i++) {
    cout << i+1 << ". " << notes[i]->describe() << "\n";
  }
}

void Keeper::print_by_month(int month) {
  if (!count) throw std::runtime_error("the list of notes is empty");
  sort();
  int j = 0;
  for (int i = 0; i < count; i++) {
    if (notes[i]->get_birthday()[1] == month) {
      cout << ++j << ". " << notes[i]->describe() << "\n";
    }
  }
  if (!j) cout << "There were no people with such a month in the date of birth\n";
}

void Keeper::remove(int num) {
  if (num > count || num <= 0) throw std::runtime_error("uncorrect num of note");
  int counter = 0;
  Note **temp = new Note*[count];

  for (int i = 0; i < count; i++) temp[i] = notes[i];
  delete notes[num-1];

  for (int i = 0; i < num-1; i++) notes[counter++] = temp[i];
  for (int i = num; i < count; i++) notes[counter++] = temp[i];
  count--;
  delete[] temp;  
}

void Keeper::free() {
  for (int i = 0; i < count; i++) {
    delete notes[i];
  }
  count = 0;
}

void Keeper::sort() {
  Note *temp;
  for (size_t i = 0; i < count - 1; i++) {
    for (size_t j = 0; j < count - i - 1; j++) {
      if (strcmp(notes[j]->get_last_name().c_str(), notes[j+1]->get_last_name().c_str()) > 0) {
        temp = notes[j];
        notes[j] = notes[j+1];
        notes[j+1] = temp;
      }
    }
  }
}

void Keeper::operator++(int d) {
  Note *note = new Note();
  cin >> *note;
  add(note);
}

void Keeper::operator--(int d) {
  int num;
  cout << "\nEnter num of note: "; cin >> num;
  remove(num);
}

Note *Keeper::operator[] (const int index) {
  if (index >= count || index < 0) throw std::runtime_error("note is not found");
  return notes[index];
}