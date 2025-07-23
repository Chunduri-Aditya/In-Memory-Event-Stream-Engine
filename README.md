# 📡 In-Memory Event Stream Engine

A C project that implements an event stream using singly linked lists.  
Perfect for learning **dynamic memory**, **pointer manipulation**, and **modular C design**.

---

## 🚀 Features

- Add events dynamically with `id`, `source`, and `payload`
- Print full stream contents
- Search for events by ID
- Delete specific events by ID
- Reverse the stream order
- Fully interactive CLI with memory safety

---

## 📦 File Structure

```
├── event.h          # Structure and function declarations
├── event.c          # Core logic: add, delete, search, reverse
├── event_stream.c   # Main program with menu UI
├── Makefile         # Easy build
```

---

## 🧪 Sample Run

```
--- Event Stream Menu ---
1. Add Event
2. Print Stream
3. Search Event by ID
4. Delete Event by ID
5. Reverse Stream
6. Exit
Enter your choice: 2

Event Stream:
Event ID: 6, Source: sensor-3, Payload: Temperature: 25°C
Event ID: 5, Source: light-2, Payload: Light turned on
Event ID: 3, Source: sensor-2, Payload: Humidity: 46%
Event ID: 2, Source: camera-1, Payload: Motion detected
```

---

## 🛠 Build and Run

### 🔧 Requirements

- GCC compiler (e.g., `gcc` or `clang`)
- Make utility (recommended)

---

### 🔨 Build

To build using the provided Makefile:

```bash
make
```

Or compile manually without Makefile:

```bash
gcc -o event_stream event.c event_stream.c
```

---

### ▶️ Run the Program

```bash
./event_stream
```

You'll see an interactive CLI menu:

```
--- Event Stream Menu ---
1. Add Event
2. Print Stream
3. Search Event by ID
4. Delete Event by ID
5. Reverse Stream
6. Exit
Enter your choice: _
```

---

### 🧼 Clean the Build

To remove the compiled executable:

```bash
make clean
```

Or manually:

```bash
rm event_stream
```

---

## 📚 Skills Demonstrated

- ✅ C Structures and Linked Lists  
- ✅ Modular Programming with Header Files  
- ✅ Dynamic Memory Allocation (`malloc`, `free`)  
- ✅ CLI Interaction & Input Handling  
- ✅ Pointer Manipulation and Traversal  
- ✅ Clean Code Organization using `Makefile`

---

## 📌 Author

**Aditya Chunduri**  
[LinkedIn](https://linkedin.com/in/adityachunduri)  
[GitHub](https://github.com/Chunduri-Aditya)

---
