#include <iostream>
#include "menu.h"

using namespace std;

// prints current commands value based on his_index
// if no commands, print 0
void Menu::execute() {
    if (history_index == 0) {
        // no commands exist
        cout << "0" << endl;
    }
}

// returns true if history was primed with single op instruction 
bool Menu::initialized() {

}

// adds command in appropriate position
void Menu::add_command(Command* cmd) {
    if (history_index == history.size() - 1) {
        history.push_back(cmd);
        return;
    }

    ++history_index;
    history.at(history_index) == cmd;
}

// returns command based on history_index position
Command* Menu::get_command() {
    if (history.size() == 0) {
        // there's no command to get
        return;
    }

    return history.at(history_index);
}

void Menu::undo() {
    // if at leftmost command
    if (history.size() == 0 || history_index == 0) {
        return;
    }
    
    history_index = history_index - 1;
}

void Menu::redo() {
    // if at rightmost command
    if (history_index == history.size() - 1) {
        return;
    }

    history_index = history_index + 1;
}
