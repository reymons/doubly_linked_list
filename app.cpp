#include <iostream>
#include "linked_list.h"

void run_tests();
void play_list_game();

int main() {
  run_tests();
  play_list_game();
  return 0;
}

void run_tests() {
  linked_list<int> list;
  list << 1 << 2 << 3;
  list.remove(list[0]);
  list.add(5);

  assert(list.size() == 3);
  assert(list[1]->value() == 3);
  assert(list.m_head_node->value() == 2);
  assert(list.m_tail_node->value() == 5);
}

void play_list_game() {
  using namespace std;
  linked_list<int> list;

  while (true) {
    cout << "\n===[List commands]===\n\n";
    cout << "1. Add\n2. Remove\n3. Print\n\n";
    uint16_t command;
    cin >> command;
    if (command != 1 && command != 2 && command != 3) {
      cout << "\nOnly 1, 2 or 3\n"; 
      continue;
    }
    cout << "\n";
    switch (command) {
      case 1:
        cout << "Number: ";
        int number;
        cin >> number;
        list << number;
        break;
      case 2:
        cout << "Index: ";
        uint32_t index;
        cin >> index;
        list.remove(list[index]);
        break;
      case 3:
        // TODO: add case 3;
        break;
    }
  }
}