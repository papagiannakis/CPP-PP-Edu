# C++ Programming — Principles and Practice: Educational Resources

**Course:** HY150 — University of Crete & ICS-FORTH
**Instructor:** Prof. George Papagiannakis
**Period:** 2012–present
**Textbook:** *Programming: Principles and Practice Using C++* (2nd ed.) — Bjarne Stroustrup

> This repository contains all source code, examples, and supporting materials for the HY150 introductory C++ programming course. It follows Stroustrup's textbook chapter by chapter, from "Hello World" to advanced topics like containers, algorithms, graphics, and ray tracing.

---

## Table of Contents

1. [Where to Start](#where-to-start)
2. [Repository Structure](#repository-structure)
3. [Visual Hierarchy](#visual-hierarchy)
4. [Chapter Guide](#chapter-guide)
5. [Example Projects](#example-projects)
6. [CMake Tutorial](#cmake-tutorial)
7. [How to Build Everything](#how-to-build-everything)
8. [How to Create Your Own Project](#how-to-create-your-own-project)
9. [Resources](#resources)

---

## Where to Start

**If you are a first-year student, follow these steps:**

1. **Read** chapters 2–5 of Stroustrup's book alongside the code in `Chapter02`–`Chapter05`.
2. **Try** the simplest standalone example first: [`_helloWorld_single_cmake/`](Resources/Code/Programming-code/_helloWorld_single_cmake/).
3. **Build** that example using the CMake steps below to verify your environment works.
4. **Create your own folder** for exercises (see [How to Create Your Own Project](#how-to-create-your-own-project)).
5. **Progress** chapter by chapter — each folder maps directly to a textbook chapter.

**Prerequisites:**
- A C++ compiler: GCC 9+ / Clang 11+ / MSVC 2019+
- [CMake](https://cmake.org/download/) 3.10 or newer
- A terminal (Linux/macOS) or PowerShell/Git Bash (Windows)
- Optional: [VS Code](https://code.visualstudio.com/) with the C/C++ extension

---

## Repository Structure

```
CPP-PP-Edu/
├── README.md                          ← You are here
├── CPP-PP-Edu.ipynb                   ← Full course syllabus (Jupyter notebook)
├── LICENSE                            ← Apache 2.0
└── Resources/
    ├── Code/
    │   └── Programming-code/          ← ALL source code lives here
    │       ├── CMakeLists.txt         ← Root build file (builds all chapters)
    │       ├── Chapter02/ … Chapter27/← One folder per textbook chapter
    │       ├── GUI/                   ← Shared FLTK GUI library classes
    │       ├── fltk-1.3.5/            ← FLTK graphics library (embedded source)
    │       ├── _helloWorld_single_cmake/        ← Starter: simplest CMake project
    │       ├── _helloWorld_multiple_cmake_library/ ← Starter: CMake with a library
    │       ├── _helloWorld_fltk_gui_chapter12/  ← Starter: GUI window example
    │       ├── _helloWorld_ray_tracing/         ← Starter: ray tracing in a weekend
    │       └── _helloWorld_unit_testing/        ← Starter: Google Test example
    ├── Docs/
    │   └── FLTK 1.3.pdf               ← FLTK library reference manual
    ├── Papers/                        ← Related research papers
    │   ├── Becker2023.pdf
    │   ├── Brown2024.pdf
    │   └── Lau2023.pdf
    ├── Slides/                        ← Course presentation slides
    │   └── others/
    │       ├── CMake.pptx             ← CMake tutorial slides
    │       ├── 00_Versioning.pptx
    │       └── 00_Versioning_Git.pptx
    └── Images/                        ← Diagrams and screenshots
        ├── How_To_Build_Examples/
        ├── How_To_Debug/
        └── *.png                      ← Ray tracing output images
```

---

## Visual Hierarchy

```
Programming-code/  (root CMakeLists.txt — builds everything)
│
├── BEGINNER (Chapters 2–7: Core C++ Basics)
│   ├── Chapter02/   Hello World, first programs, output
│   ├── Chapter03/   Variables, types, type conversions
│   ├── Chapter04/   Computation, loops, conditions
│   ├── Chapter05/   Errors and exceptions
│   ├── Chapter06/   Writing functions
│   └── Chapter07/   Completing a program (calculator project)
│
├── INTERMEDIATE (Chapters 8–11: Data and I/O)
│   ├── Chapter08/   Pointers, arrays, references
│   ├── Chapter09/   Classes and custom types
│   ├── Chapter10/   Input/output streams and files
│   └── Chapter11/   Customizing I/O, formatting
│
├── GRAPHICS (Chapters 12–16: GUI and Visualization)
│   ├── Chapter12/   Graphics basics with FLTK
│   ├── Chapter13/   Object-oriented programming
│   ├── Chapter14/   Design and class composition
│   ├── Chapter15/   Graphs and visual data
│   ├── Chapter16/   Graphing functions
│   └── GUI/         Shared: Window, Graph, Shape classes
│
├── ADVANCED (Chapters 17–21: Containers and Algorithms)
│   ├── Chapter17/   Vectors and free store (dynamic memory)
│   ├── Chapter18/   Vectors and arrays
│   ├── Chapter19/   Vector container internals
│   ├── Chapter20/   Standard containers (map, list, etc.)
│   └── Chapter21/   Algorithm design and STL algorithms
│
├── EXPERT (Chapters 22–27: Specialized Topics)
│   ├── Chapter22/   Ideals and history of C++
│   ├── Chapter23/   Text processing and regular expressions
│   ├── Chapter24/   Numerics and scientific computing
│   ├── Chapter25/   Embedded systems programming
│   ├── Chapter26/   Testing and program correctness
│   └── Chapter27/   The C programming language
│
└── STARTER PROJECTS (self-contained examples)
    ├── _helloWorld_single_cmake/          Simplest possible CMake project
    ├── _helloWorld_multiple_cmake_library/ CMake project with a static library
    ├── _helloWorld_fltk_gui_chapter12/    First GUI window with FLTK
    ├── _helloWorld_ray_tracing/           Ray tracing renderer (weekend project)
    └── _helloWorld_unit_testing/          Unit tests with Google Test
```

---

## Chapter Guide

Each chapter folder contains:
- One `.cpp` file per textbook section (e.g., `chapter.3.4.cpp` = section 3.4)
- A `CMakeLists.txt` that compiles each file into its own executable
- A `std_lib_facilities.h` header (Stroustrup's standard helper header)
- Some chapters include `.in` files (sample input for programs that read from stdin)

| Chapter | Topic | Key Concepts |
|---------|-------|-------------|
| **02** | Hello, World! | `cout`, `#include`, first programs |
| **03** | Objects, Types, Values | `int`, `double`, `string`, type safety, `cin` |
| **04** | Computation | `if`, `while`, `for`, functions, vectors |
| **05** | Errors | Exceptions, `try`/`catch`, input validation |
| **06** | Writing Functions | Function arguments, return values, recursion |
| **07** | Completing a Program | Calculator project, testing, debugging |
| **08** | Pointers & Arrays | `*`, `&`, arrays, `new`/`delete`, stack vs heap |
| **09** | Classes | `class`, constructors, member functions, `struct` |
| **10** | Streams and Files | `ifstream`, `ofstream`, stream state, file I/O |
| **11** | Customizing I/O | Format flags, `stringstream`, locale |
| **12** | A Display Model | FLTK windows, shapes, colors, coordinates |
| **13** | OOP | Inheritance, polymorphism, virtual functions |
| **14** | Graphing Functions | Designing class hierarchies |
| **15** | Graphing Data | Plotting real data, visual data analysis |
| **16** | Graphing Functions | Function objects, lambdas in graphics |
| **17** | Vector & Free Store | `vector` internals, `new`/`delete`, RAII |
| **18** | Vectors & Arrays | Copying, moving, array vs vector trade-offs |
| **19** | Vector Container | Templates, iterators, `allocator` |
| **20** | Containers & Algorithms | `map`, `list`, STL containers, iterators |
| **21** | Algorithms | STL algorithms, `sort`, `find`, function objects |
| **22** | Ideals & History | C++ design philosophy (no build config) |
| **23** | Text Manipulation | `string`, `regex`, text processing |
| **24** | Numerics | Matrices, random numbers, scientific computing |
| **25** | Embedded Systems | Real-time constraints, bit manipulation |
| **26** | Testing | Correctness proofs, test design, Google Test |
| **27** | The C Language | C vs C++, C compatibility, system programming |

---

## Example Projects

These standalone projects in `_helloWorld_*` folders each demonstrate a complete, buildable pattern.

### `_helloWorld_single_cmake/` — Simplest start
Two `.cpp` files, one `CMakeLists.txt`. **Start here.**
```
_helloWorld_single_cmake/
├── CMakeLists.txt
├── HelloWorld.cpp
├── HelloWorld2.cpp
└── std_lib_facilities.h
```

### `_helloWorld_multiple_cmake_library/` — Project with a library
Shows how to split code into a reusable static library (the `Chrono` library).
```
_helloWorld_multiple_cmake_library/
├── CMakeLists.txt
├── chapter.9.8.cpp          ← main program
└── Chrono/
    ├── CMakeLists.txt        ← builds ChronoLib static library
    ├── Chrono.cpp
    └── Chrono.h
```

### `_helloWorld_fltk_gui_chapter12/` — First GUI window
Opens a graphical window using FLTK. Requires the `fltk-1.3.5` library to build first.

### `_helloWorld_ray_tracing/` — Ray tracing renderer
Implements Peter Shirley's *Ray Tracing in One Weekend* in C++. Each `src/InOneWeekend/` subfolder adds more features. Output images are in `Resources/Images/`.

### `_helloWorld_unit_testing/` — Unit tests with Google Test
Shows how to write and run automated tests. Requires cloning Google Test first:
```bash
cd Resources/Code/Programming-code/_helloWorld_unit_testing/
git clone https://github.com/google/googletest.git
```

---

## CMake Tutorial

CMake is a **build system generator** — it reads `CMakeLists.txt` files and generates the actual build files (Makefiles on Linux/macOS, Visual Studio projects on Windows).

### How CMake works — the big picture

```
Your source files (.cpp, .h)
        +
CMakeLists.txt  (your build instructions)
        │
        ▼
   cmake (configure)   ──→  generates Makefile / .sln / build.ninja
        │
        ▼
   cmake --build .     ──→  compiles your code
        │
        ▼
   Executable (.exe / no extension on Linux)
```

### Key CMake commands you will use

| Command | What it does |
|---------|-------------|
| `cmake_minimum_required(VERSION 3.10)` | Minimum CMake version needed |
| `project(MyProject)` | Names the project |
| `set(CMAKE_CXX_STANDARD 17)` | Use C++17 |
| `add_executable(myapp main.cpp)` | Compile `main.cpp` into `myapp` |
| `add_library(mylib STATIC lib.cpp)` | Compile `lib.cpp` into a static library |
| `target_link_libraries(myapp mylib)` | Link `mylib` into `myapp` |
| `add_subdirectory(Chapter02)` | Include another folder's CMakeLists.txt |
| `target_include_directories(myapp PUBLIC include/)` | Add a header search path |

### The two-step build process

CMake always uses two steps:

**Step 1 — Configure** (run once, or when CMakeLists.txt changes):
```bash
cmake -S <source-dir> -B <build-dir>
```
- `-S` points to the folder containing `CMakeLists.txt`
- `-B` points to the folder where build files will go (keep this separate from source)

**Step 2 — Build** (run every time you change `.cpp` files):
```bash
cmake --build <build-dir>
```

### Why a separate build directory?

Always build **outside** the source tree. This keeps generated files away from your code:
```
Programming-code/   ← source (clean, only .cpp/.h/CMakeLists.txt)
build/              ← generated (Makefiles, .o files, executables) — never commit this
```

---

## How to Build Everything

### Build all chapters at once

```bash
# 1. Go to the root of the source code
cd /path/to/CPP-PP-Edu/Resources/Code/Programming-code

# 2. Create a build directory and configure
cmake -S . -B build

# 3. Compile everything
cmake --build build

# 4. Find your executables
ls build/Chapter02/
ls build/Chapter03/
# ... and so on
```

### Build a single chapter

```bash
cd /path/to/CPP-PP-Edu/Resources/Code/Programming-code

# Configure only Chapter03
cmake -S Chapter03 -B build_ch03

# Build it
cmake --build build_ch03

# Run an executable
./build_ch03/chapter03.3.1.exe
```

### Build a starter project

```bash
cd /path/to/CPP-PP-Edu/Resources/Code/Programming-code/_helloWorld_single_cmake

cmake -S . -B build
cmake --build build

./build/HelloWorld.exe
```

### On Windows (using Developer Command Prompt or PowerShell)

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\HelloWorld.exe
```

### Troubleshooting common errors

| Error | Cause | Fix |
|-------|-------|-----|
| `cmake: command not found` | CMake not installed | Install from cmake.org |
| `No CMAKE_CXX_COMPILER` | No C++ compiler found | Install GCC (`sudo apt install g++`) or Xcode command-line tools |
| `fatal error: std_lib_facilities.h` | Header not found | Copy `std_lib_facilities.h` into your project folder |
| `undefined reference to main` | Missing `main()` function | Make sure your `.cpp` has `int main()` |

---

## How to Create Your Own Project

Follow these steps to add your own exercises or experiments.

### Step 1 — Create your folder

```bash
mkdir /path/to/CPP-PP-Edu/Resources/Code/Programming-code/MyExercises
cd MyExercises
```

### Step 2 — Write your C++ file

Create `exercise1.cpp`:
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "My first C++ exercise!" << endl;
    return 0;
}
```

### Step 3 — Write your CMakeLists.txt

Create `CMakeLists.txt` in the same folder:
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyExercises)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add one line per .cpp file you want to compile:
add_executable(exercise1 exercise1.cpp)
# add_executable(exercise2 exercise2.cpp)
```

### Step 4 — (Optional) Add it to the main build

Open `Programming-code/CMakeLists.txt` and add one line:
```cmake
add_subdirectory(MyExercises)
```
Now `cmake --build build` will also compile your code.

### Step 5 — Build and run

```bash
# From Programming-code/ root
cmake -S . -B build
cmake --build build

# Or build just your folder
cmake -S MyExercises -B build_mine
cmake --build build_mine
./build_mine/exercise1
```

### Step 6 — Using Stroustrup's header

Most textbook examples use a helper header. Copy it into your folder:
```bash
cp /path/to/Programming-code/Chapter02/std_lib_facilities.h MyExercises/
```

Then in your `.cpp`:
```cpp
#include "std_lib_facilities.h"

int main() {
    // Now you can use Stroustrup's simplified types and error handling
    cout << "Hello!" << endl;
}
```

---

## Resources

| Resource | Location | Description |
|----------|----------|-------------|
| Course Syllabus | [`CPP-PP-Edu.ipynb`](./CPP-PP-Edu.ipynb) | Full lecture schedule and topics |
| FLTK Manual | `Resources/Docs/FLTK 1.3.pdf` | Graphics library reference |
| CMake Slides | `Resources/Slides/others/CMake.pptx` | Visual CMake introduction |
| Git/Versioning Slides | `Resources/Slides/others/00_Versioning_Git.pptx` | Git workflow for students |
| Ray Tracing Book | [`raytracing.github.io`](https://raytracing.github.io) | Free online textbook (used in `_helloWorld_ray_tracing`) |
| Stroustrup's Book | [informit.com](https://www.informit.com/store/programming-principles-and-practice-using-c-plus-plus-9780321992789) | Primary textbook |
| Research Papers | `Resources/Papers/` | Becker2023, Brown2024, Lau2023 |

---

*Copyright Prof. George Papagiannakis — University of Crete & ICS-FORTH, 2012–present. Apache 2.0 License.*
