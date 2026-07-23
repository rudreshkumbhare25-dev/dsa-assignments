# Data Structures & Algorithms Assignments

This repository contains college course assignments and personal C++ implementations for Data Structures & Algorithms.

---

## 📊 Course Assignments

| Assignment | Topic | Description | Files |
| :--- | :--- | :--- | :--- |
| **Assignment 1** | Singly Linked List | Playlist Maker app with add, play, and deletion. | [`assignment1.cpp`](assignment1.cpp) |
| **Assignment 2** | Doubly Linked List | Text Editor with insert, delete, reverse and file persistent storage. | [`assignment2.cpp`](assignment2.cpp) |
| **Assignment 3** | Coming Soon | Description of next assignment | *Pending* |

---

## 🔧 How to Compile & Run Assignments

All implementations are written in standard C++. You can run any assignment using a terminal and a C++ compiler (like `g++`):

1. **Compile:**
   ```bash
   g++ assignmentName.cpp -o assignmentName
2. **Run:**
   ```bash
   ./assignmentName

---

## 🛠️ Personal Projects & Custom Libraries

### 📌 Custom C++ Linked List Library

A modular implementation of **Singly Linked List (SLL)** and **Doubly Linked List (DLL)** split into header and implementation files.

* **Location:** `/linkedlist-library`
* **Files:**
  * `SLL.h` / `SLL.cpp` (Singly Linked List interface & implementation)
  * `DLL.h` / `DLL.cpp` (Doubly Linked List interface & implementation)
  * `main.cpp` (Driver program for testing both lists)

**Compilation & Usage:** To compile and run the library with the test suite, navigate to the folder and run:

```bash
cd linkedlist-library
g++ SLL.cpp DLL.cpp main.cpp -o main
./main
