#include <iostream>
#include "Note.h"
#include "Keeper.h"
#include "text.cpp"

void show_menu();
template <typename T> T input(string);
enum commands { ADD=1, PRINT, EDIT, REMOVE, REMOVE_ALL, PRINT_BY_MONTH, EXIT };

int main() {
  Keeper *keeper = new Keeper();

  Note *note_0 = new Note("Oleg", "Chesnokov", "+79123213473", new int[3]{9, 2, 2003});
  Note *note_1 = new Note("Niktia", "Smirnov", "+79314022985", new int[3]{23, 8, 2002});
  Note *note_2 = new Note("Ryan", "Gosling", "+79123213473", new int[3]{12, 11, 1980});
  keeper->add(note_0);
  keeper->add(note_1);
  keeper->add(note_2);
  
  bool is_exit = false;
  string property;
  int act, num, num2, prop_int;
  int task_num = input<int>("Select the task (1 or 2): ");
  while (task_num != 1 && task_num != 2) task_num = input<int>("Select the task (1 or 2): ");
  
  if (task_num == 1) {
    show_menu();
    while (!is_exit) {
      act = input<int>("\nEnter action: ");
      system("cls");
      show_menu();
      
      if (act == commands::ADD) { (*keeper)++; }
      else if (act == commands::PRINT) {
        try {
          keeper->print();   
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::EDIT) {
        try {
          num2 = input<int>("\nEnter num of note: ");
          num = input<int>("Enter num of edit property (1 - last_name, 2 - name, 3 - phone, 4 - birthday): ");
          cout << "Enter new value of property: ";
          if (num != 4) cin >> property;

          if (num == 1) (*keeper)[num2-1]->set_last_name(property);
          else if (num == 2) (*keeper)[num2-1]->set_name(property);
          else if (num == 3) (*keeper)[num2-1]->set_phone_number(property);
          else if (num == 4) {
            int d, m, y;
            cout << "day: "; cin >> d;
            cout << "month: "; cin >> m;
            cout << "year: "; cin >> y;
            (*keeper)[num2-1]->set_birthday(new int[3]{d, m, y});
          }
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::REMOVE) {
        try {
          (*keeper)--;
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::REMOVE_ALL) {
        try {
          keeper->free();
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::PRINT_BY_MONTH) {
        num = input<int>("\nEnter num of month: ");
        try {
          keeper->print_by_month(num);
        }
        catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::EXIT) {
        try {
          keeper->free();
          delete keeper;
          is_exit = true;
        } catch(const std::exception& e) { }
      }
    }
    
  } else if (task_num == 2) {
    text();
  }
  return 0;
}

void show_menu() {
  cout << "1 - add a new note\n2 - print a list of note\n3 - edit the note\n4 - delete the note\n" <<
  "5 - delete all notes\n6 - get by month\n7 - exit\n\n";
}

template <typename T> T input(string prompt) {
  T value;
  cout << prompt; std::cin >> value;
  while (true) {
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "You have entered wrong input" << std::endl;
      std::cin >> value;
    }
    if(!std::cin.fail()) break;
  }
  return value;
}