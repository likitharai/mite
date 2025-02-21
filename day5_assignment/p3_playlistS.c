#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char* name;           
    struct Song* next;    
} Song;

Song* createSong(const char* name) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->name = strdup(name); 
    return newSong;
}


void addSong(Song** head, const char* name) {
    Song* newSong = createSong(name);
    if (*head == NULL) {
        *head = newSong;
        newSong->next = *head;  
    } else {
        Song* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; 
        }
        temp->next = newSong;
        newSong->next = *head;  
    }
}

void displayCurrentSong(Song* current) {
    if (current != NULL) {
        printf("Current Song: %s\n", current->name);
    }
}

Song* nextSong(Song* current) {
    if (current != NULL) {
        return current->next;
    }
    return NULL;
}

int main() {
    Song* playlist = NULL;
    Song* currentSong = NULL;
    
    addSong(&playlist, "Song A");
    addSong(&playlist, "Song B");
    addSong(&playlist, "Song C");

    currentSong = playlist;

    
    displayCurrentSong(currentSong);
    
    currentSong = nextSong(currentSong);
    displayCurrentSong(currentSong);
    
    currentSong = nextSong(currentSong);  
    displayCurrentSong(currentSong);

    currentSong = nextSong(currentSong); 
    displayCurrentSong(currentSong);

    return 0;
}
