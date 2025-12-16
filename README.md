# 📝 C++ CLI To-Do Application

A clean, modular, and persistent **Command Line To-Do Application** built in **C++**, following real-world software engineering practices such as separation of concerns, clean architecture, and incremental development.

This project was built phase-by-phase to simulate how production applications evolve.

---

## 🚀 Features

### ✅ Core Features
- Add new tasks
- List all tasks
- Edit tasks (with option to keep old values)
- Delete tasks by ID
- Mark tasks as completed
- Auto-save tasks to file
- Auto-load tasks on startup

### 🔍 Advanced Features
- Search tasks by keyword (title or description)
- Filter completed tasks
- Filter pending tasks

### 🧠 UX Enhancements
- Press ENTER to keep old values while editing
- Input validation for:
  - Empty titles
  - Invalid task IDs
  - Empty search keywords
- Clean and readable CLI output

---

## 🧩 Project Structure

```
.
├── main.cpp          # CLI interface & user interaction
├── TodoList.hpp      # Class declarations
├── TodoList.cpp      # Business logic & file handling
├── tasks.txt         # Persistent storage (auto-generated)
└── README.md
```

---

## 💾 Persistence

Tasks are automatically:
- **Loaded** from `tasks.txt` on program start
- **Saved** to `tasks.txt` after every modification

No manual save/load required.

---

## 🛠️ Technologies Used

- **C++ (STL)**
  - `vector`
  - `string`
  - iterators
  - file streams (`ifstream`, `ofstream`)
- Object-Oriented Programming (OOP)
- File Handling
- Clean API design with `const` correctness

---

## ▶️ How to Run

### Clone the Repository
```bash
git clone https://github.com/ayush16110/todo-cli.git
cd todo-cli
```

### Compile
```bash
g++ main.cpp TodoList.cpp -o todo
```

### Run
```bash
./todo
```

---

## 📌 Design Principles Followed

- Separation of concerns (UI vs Logic)
- No input/output in logic layer
- Safe APIs using `bool` returns and `const` correctness
- Read-only access using `const Task*`
- Incremental feature development (Phase-based)

---

## 📈 Project Phases

- **Phase 1:** Project structure & data models
- **Phase 2:** Add & list tasks
- **Phase 3:** Full CRUD operations
- **Phase 4:** File persistence (save/load)
- **Phase 5:** Search & filter features
- **Phase 6:** UX improvements & input validation

---

## 🌱 Future Improvements

- GUI using Qt
- Case-insensitive search
- Task sorting
- SQLite database integration
- Cross-platform packaging

---

## 👤 Author

**Ayush**  
B.Tech CSE Student  
Aspiring Software Engineer  

🔗 GitHub: [github.com/ayush16110](https://github.com/ayush16110)


⭐ If you find this project helpful, feel free to star the repository!
