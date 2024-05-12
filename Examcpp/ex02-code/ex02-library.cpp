#include <iostream>
#include "ex02-library.h"
using namespace std;

// Do not modify
void displayPlaylist(Song *s) {
    if (s == nullptr) {
        return;
    }
    cout << s->title << ", ";
    cout << s->artist << ", ";
    cout << s->genre << ", ";
    cout << s->duration << ", " << endl;
    
    displayPlaylist(s->next);
}

// Task 2(a).  Implement this function
unsigned int totalDuration(Song *s) {
    if (s == nullptr) {
        return 0;
    }

    return s->duration + totalDuration(s->next);
}

// Task 2(b).  Implement this function
Song *find(Song *s, string genre) {
    if (s == nullptr) {
        return nullptr;
    }

    if (s->genre == genre) {
        Song *newPlaylist = new Song{*s};
        newPlaylist->next = find(s->next, genre);
        return newPlaylist;
    } else {
        return find(s->next, genre);
    }
}

// Task 2(c).  Implement this function
bool shift(Song *&s, unsigned int pos, unsigned int n) {
    if (pos < 1 || s == nullptr) {
        return false;
    }
    
    Song *current = s;
    Song *previous = nullptr;
    Song *postTarget = nullptr;
    Song *preTarget = nullptr;
    
    for (unsigned int i = 1; i < pos && current != nullptr; i++) {
        previous = current;
        current = current->next;
    }
    
    if (current == nullptr || current->next == nullptr) {
        return false;
    }

    postTarget = current;
    for (unsigned int i = 0; i < n && postTarget != nullptr; i++) {
        preTarget = postTarget;
        postTarget = postTarget->next;
    }
    
    if (postTarget == nullptr || preTarget == nullptr) {
        return false;
    }

    if (previous == nullptr) {
        s = current->next;
    } else {
        previous->next = current->next;
    }
    
    current->next = postTarget->next;
    postTarget->next = current;

    return true;
}
