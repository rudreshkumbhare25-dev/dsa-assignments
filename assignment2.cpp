#include <iostream>
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
    }

    void insert_specific(string val, string key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key) {
            insert_front(val);
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
            return;
        }

        if (tail->data == val) {
            remove_back();
            return;
        }

        Text* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Text not found\n";
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
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

    ~Edit() {
        while (head != NULL) {
            remove_front();
        }
    }
};

int main() {
    Edit t;

    t.insert_back("Hi!");
    t.insert_back("My");
    t.insert_back("name");
    t.insert_back("is");
    t.insert_back("rudresh.");

    t.printText();

    return 0;
}
