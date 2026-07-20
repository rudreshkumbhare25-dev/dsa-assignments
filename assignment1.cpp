#include <iostream>
using namespace std;

class Song{
public:
    string title;
    Song* next;

    Song(string t){
        title = t;
        next = NULL;
    }
};

class Playlist{
    Song* head;
    Song* tail;
public:
    Playlist(){
        head = tail = NULL;
    }

    void add_front(string t) {
        Song* newSong = new Song(t);
        
        if (head == NULL) {
            head = tail = newSong;
        } else {
            newSong->next = head;
            head = newSong;
        }
    }

    void add_back(string t) {
        Song* newSong = new Song(t);
        
        if (head == NULL) {
            head = tail = newSong;
        } else {
            tail->next = newSong;
            tail = newSong;
        }
    }

    void add(string t, int pos){
        if (pos < 0){
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0){
            add_front(t);
            return;
        }

        Song* temp = head;
        for(int i=0; i<pos-1 && temp!= NULL; i++){
            temp = temp->next;                  
        }

        if (temp == NULL) {
            cout << "Invalid position\n";
            return;
        }
        if (temp->next == NULL) {
            add_back(t);
            return;
        }

        Song* newNode = new Song(t);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove_front() {
        if (head == NULL) {
            cout << "No song to remove from the playlist.\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Song* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void remove_back() {
        if (head == NULL) {
            cout << "Playlist is empty. No song to remove.\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Song* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void remove_specific(string t) {
        if (head == NULL) {
            cout << "Playlist is empty. No song to remove.\n";
            return;
        }

        if (head->title == t) {
            remove_front();
            cout << "Successfully removed... " << t << endl;
            return;
        }

        Song* temp = head;
        while (temp->next != NULL && temp->next->title != t) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Song not found in the playlist.\n";
            return;
        }

        if (temp->next == tail) {
            remove_back();
            cout << "Successfully removed... " << t << endl;
            return;
        }

        Song* songToDelete = temp->next;
        temp->next = songToDelete->next;
        delete songToDelete;
    }

    void play(string s) {
        Song* temp = head;
        while(temp != NULL) {
            if(temp->title == s) {
                cout << "Now playing... " << s << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found.\n";
    }

    void displaySongs(){
        if (head == NULL) {
            cout << "No song in the playlist.\n";
            return;
        }

        Song* temp = head;
        while(temp != NULL) {
            cout << "Song name : " << temp->title << endl;
            temp = temp->next;
        }
    }

    ~Playlist() {
        while (head != NULL) {
            remove_front();
        }
    }
};

int main() {
    Playlist l;
    int choice;
    string title;

    do {
        cout << "\n----- PLAYLIST MAKER -----\n";
        cout << "1. Add songs\n";
        cout << "2. Remove songs\n";
        cout << "3. Play songs\n";
        cout << "4. Display songs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song title to add : ";
            cin.ignore();
            getline(cin, title);
            int position;
            cout << "Enter where do you want to add song (0: at the start) : ";
            cin >> position;
            l.add(title, position);
            break;
        case 2:
            cout << "Enter song title to remove : ";
            cin.ignore();
            getline(cin, title);
            l.remove_specific(title);
            break;
        case 3:
            cout << "Enter song title to play : ";
            cin.ignore();
            getline(cin, title);
            l.play(title);
            break;
        case 4:
            cout << "\n----- CURRENT PLAYLIST -----\n";
            l.displaySongs();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid title input. Try again!\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
