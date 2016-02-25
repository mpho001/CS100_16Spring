#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu() {
    history_index = -1;
}

// prints current commands value based on his_index
// if no commands, print 0

void Menu::execute() {
    if (history.size() == 0 || history_index == -1) {
        // no commands exist
        cout << "no commands exist: 0" << endl;
        return;
    }
    
    cout << history.at(history_index)->execute() << endl;
}

// returns true if history was primed with single op instruction 
bool Menu::initialized() {
   if (history.size() > 0) {
      return true;
   }
   return false; 
}

// adds command in appropriate position
void Menu::add_command(Command* cmd) {
    if (history.size() == 0) {
        history.push_back(cmd);
        ++history_index;
        cout << "index: " << history_index << endl;
    }

    else if (history_index == (int) history.size() - 1) {
        history.push_back(cmd);
        ++history_index;
    }
    
    else {
        ++history_index;
        history.at(history_index) = cmd;
    }
}

// returns command based on history_index position
Command* Menu::get_command() {
    if (history.size() == 0) {
        // there's no command to get
        cout << "there's no command" << endl;
        exit(0);
    }

    return history.at(history_index);
}

void Menu::undo() {
    // if at leftmost command or are no commands
    if (history.size() == 0 || history_index == -1) {
        cout << "Can't undo" << endl;
        return;
    }
    
    history_index = history_index - 1;
}

void Menu::redo() {
    // if at rightmost command or there are no commands
    if (history.size() == 0 || history_index == (int) history.size() - 1) {
        cout << "Can't redo" << endl;
        return;
    }

    history_index = history_index + 1;
}
