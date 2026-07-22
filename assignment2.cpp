#include <iostream>
#include <fstream>
using namespace std;

class Text {
public:
    string data;
    Text* next;
    Text* prev;

    Text(string val) {
        data = val;
        next = prev = NULL;
    }
};

class Edit {
    Text* head;
    Text* tail;

public:
    Edit() {
        head = tail = NULL;
    }

    void insert_front(string val) {
        Text* newText = new Text(val);
        if (head == NULL) {
            head = tail = newText;
        } else {
            newText->next = head;
            head->prev = newText;
            head = newText;
        }
    }

    void insert_back(string val) {
        Text* newText = new Text(val);
        if (head == NULL) {
            head = tail = newText;
        } else {
            tail->next = newText;
            newText->prev = tail;
            tail = newText;
        }
        cout << "Added successfully.\n";
    }

    void insert_specific(string val, string key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == key) {
            insert_front(val);
            cout << "Added successfully.\n";
            return;
        }

        Text* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Key '" << key << "' not found in list.\n";
            return;
        }

        Text* newText = new Text(val);
        newText->next = temp;
        newText->prev = temp->prev;
        
        temp->prev->next = newText;
        temp->prev = newText;
        cout << "Added successfully.\n";
    }

    void remove_front() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Text* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void remove_back() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Text* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void remove_specific(string val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            remove_front();
            cout << "'" << val << "'" << " removed.\n";
            return;
        }
        if (tail->data == val) {
            remove_back();
            cout << "'" << val << "'" << " removed.\n";
            return;
        }

        Text* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Text not found.\n";
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        cout << "'" << val << "'" << " removed.\n";
    }

    void printText() {
        if (head == NULL) {
            cout << "No text found.\n";
            return;
        }

        Text* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printTextReverse() {
        if (tail == NULL) {
            cout << "No text found.\n";
            return;
        }

        Text* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void saveToFile(string filename){
        ofstream fout(filename, ios::out);
        if (!fout.is_open()){
            cout << "File not opened correctly.\n";
            return;
        }

        Text* temp = head;
        while (temp != NULL) {
            fout << temp->data << " ";
            temp = temp->next;
        }
        fout << endl;
        fout.close();
    }

    ~Edit() {
        while (head != NULL) {
            remove_front();
        }
    }
};

int main() {
    Edit t;
    int choice;
    string input, key;

    do {
        cout << "\n----- TEXT EDITOR -----\n";
        cout << "1. Insert text at back\n";
        cout << "2. Insert text at specific position\n";
        cout << "3. Remove text\n";
        cout << "4. Display text\n";
        cout << "5. Reverse text\n";
        cout << "6. Save list to file\n";
        cout << "7. Exit\n";
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word : ";
            cin.ignore();
            getline(cin, input);
            t.insert_back(input);
            break;

        case 2:
            cout << "Enter word to insert : ";
            cin.ignore();
            getline(cin, input);
            cout << "Enter target word/key to insert before : ";
            getline(cin, key);
            t.insert_specific(input, key);

            break;

        case 3:
            cout << "Enter word to remove : ";
            cin.ignore();
            getline(cin, input);
            t.remove_specific(input);
            t.saveToFile("data.txt"); 
            break;

        case 4:
            cout << "\n--- Current Text ---\n";
            t.printText();
            break;
        
        case 5:
            cout << "\n--- Reversed Text ---\n";
            t.printTextReverse();
            break;
        
        case 6:
            t.saveToFile("data.txt");
            cout << "Saved successfully to data.txt!\n";
            break;

        case 7:
            cout << "Exiting editor...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
