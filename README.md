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
6. [Graphics and GUI with FLTK](#graphics-and-gui-with-fltk)
7. [Ray Tracing Project](#ray-tracing-project)
8. [CMake Tutorial](#cmake-tutorial)
9. [How to Build Everything](#how-to-build-everything)
10. [How to Create Your Own Project](#how-to-create-your-own-project)
11. [VS Code Setup and AI Copilots](#vs-code-setup-and-ai-copilots)
12. [Resources](#resources)

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

These five standalone projects in `_helloWorld_*` folders each demonstrate a complete, buildable C++ pattern. They are ordered from simplest to most complex — work through them in order when starting out.

| Project | Difficulty | What you build | Key concepts |
|---------|-----------|----------------|--------------|
| [`_helloWorld_single_cmake`](#_helloworld_single_cmake--simplest-cmake-project) | ★☆☆☆☆ | Two console programs | Basic C++, CMake basics |
| [`_helloWorld_multiple_cmake_library`](#_helloworld_multiple_cmake_library--static-library) | ★★☆☆☆ | Console app + static library | Libraries, namespaces, exceptions, operator overloading |
| [`_helloWorld_unit_testing`](#_helloworld_unit_testing--unit-tests-with-google-test) | ★★☆☆☆ | Test suite + app | Exception handling, Google Test, TDD |
| [`_helloWorld_fltk_gui_chapter12`](#_helloworld_fltk_gui_chapter12--gui-window-with-fltk) | ★★★☆☆ | Graphical window with shapes | OOP, inheritance, GUI, multi-module CMake |
| [`_helloWorld_ray_tracing`](#_helloworld_ray_tracing--ray-tracing-renderer) | ★★★★☆ | 3D rendered image (PPM) | Math, header-only design, smart pointers, polymorphism |

---

### `_helloWorld_single_cmake/` — Simplest CMake project

**What it is:** The absolute starting point. Two source files, each producing a standalone console program that prints a greeting. No dependencies, no library, just C++ + CMake.

**What you run:**
```
Hello, world and welcome to HY150 !!!
```

**File layout:**
```
_helloWorld_single_cmake/
├── CMakeLists.txt       ← defines two executables
├── HelloWorld.cpp       ← prints one line
├── HelloWorld2.cpp      ← prints two lines
└── std_lib_facilities.h ← course helper header
```

**What this project teaches:**

| Topic | Where |
|-------|-------|
| The minimal C++ program (`int main()`, `return 0`) | `HelloWorld.cpp` |
| Writing to the terminal with `cout` | both `.cpp` files |
| What `#include` does and how the course header `std_lib_facilities.h` works | both `.cpp` files |
| What `using namespace std;` means | via `std_lib_facilities.h` |
| The three required CMake lines (`cmake_minimum_required`, `project`, `add_executable`) | `CMakeLists.txt` |
| How to set the C++ standard (`CMAKE_CXX_STANDARD 17`) | `CMakeLists.txt` |
| How to build two separate executables from the same project | `CMakeLists.txt` |

**CMake pattern used:**
```cmake
cmake_minimum_required(VERSION 3.1.4)
project(helloWorld_single)
set(CMAKE_CXX_STANDARD 17)
add_executable(HelloWorld.exe HelloWorld.cpp)
add_executable(HelloWorld2.exe HelloWorld2.cpp)
```
This is the smallest valid `CMakeLists.txt`. Every more complex project in the course is just an extension of this pattern.

**Build and run:**
```bash
cd Resources/Code/Programming-code/_helloWorld_single_cmake
cmake -S . -B build && cmake --build build
./build/HelloWorld.exe
./build/HelloWorld2.exe
```

---

### `_helloWorld_multiple_cmake_library/` — Static library

**What it is:** A Date class (from PPP Chapter 9.8) split into a reusable static library. The main program creates dates, compares them, and prints them. This is the first project that shows how real C++ codebases are organized.

**What you run:**
```
holiday is: 1978/7/4
 d2 is: 1821/3/25
and indeed the two dates are different!
```

**File layout:**
```
_helloWorld_multiple_cmake_library/
├── CMakeLists.txt          ← root: coordinates two targets
├── chapter.9.8.cpp         ← main program (uses the Date class)
├── std_lib_facilities.h
└── Chrono/
    ├── CMakeLists.txt       ← builds ChronoLib (STATIC)
    ├── Chrono.h             ← Date class interface
    └── Chrono.cpp           ← Date class implementation
```

**What this project teaches:**

| Topic | Where |
|-------|-------|
| Separating interface (`.h`) from implementation (`.cpp`) | `Chrono/Chrono.h` vs `Chrono.cpp` |
| Organizing code in a **namespace** (`Chrono::`) | `Chrono.h`, `Chrono.cpp` |
| Building a **static library** (`add_library(ChronoLib STATIC …)`) | `Chrono/CMakeLists.txt` |
| Linking a library to an executable (`target_link_libraries`) | root `CMakeLists.txt` |
| Exposing a library's headers (`target_include_directories`) | root `CMakeLists.txt` |
| Throwing and catching **custom exceptions** (`Date::Invalid`) | `Chrono.cpp`, `chapter.9.8.cpp` |
| Using **enums** for semantic values (`Date::Month::jan`) | `Chrono.h` |
| **Operator overloading** (`==`, `!=`, `<<`, `>>` for a class) | `Chrono.h`, `Chrono.cpp` |
| **Const-correct** class design (accessor methods marked `const`) | `Chrono.h` |
| Validating constructor arguments and throwing on bad input | `Chrono.cpp` |

**CMake pattern used:**
```cmake
# Root CMakeLists.txt
add_subdirectory(Chrono)                              # build the library first
add_executable(${PROJECT_NAME}.exe chapter.9.8.cpp)
target_include_directories(${PROJECT_NAME}.exe PUBLIC Chrono)
target_link_libraries(${PROJECT_NAME}.exe ChronoLib)  # link it in

# Chrono/CMakeLists.txt
add_library(ChronoLib STATIC Chrono.h Chrono.cpp)    # the library itself
```
This `add_subdirectory` + `add_library` + `target_link_libraries` trio is the standard CMake pattern for any project with more than one module.

**Build and run:**
```bash
cd Resources/Code/Programming-code/_helloWorld_multiple_cmake_library
cmake -S . -B build && cmake --build build
./build/Chrono-chapter9.exe
```

---

### `_helloWorld_unit_testing/` — Unit tests with Google Test

**What it is:** A simple `area()` function (PPP Chapter 5.6) that throws an exception on bad input, paired with a Google Test suite that verifies its behaviour automatically. Two executables are built: the app itself and the test runner.

**What you run (test executable):**
```
[==========] Running 2 tests from 2 test suites.
[----------] 1 test from chapter5
[ RUN      ] chapter5.area
[       OK ] chapter5.area (0 ms)
[----------] 1 test from chapter5two
[ RUN      ] chapter5two.area
[       OK ] chapter5two.area (0 ms)
[==========] 2 tests passed.
```

**File layout:**
```
_helloWorld_unit_testing/
├── CMakeLists.txt       ← builds two executables + links gtest
├── chapter5.6.1.h       ← area() function + Bad_area exception class
├── chapter.5.6.1.cpp    ← app that deliberately triggers the exception
├── mytests.cpp          ← Google Test suite
├── std_lib_facilities.h
└── googletest/          ← Google Test source (clone this once, see below)
```

**First-time setup** (clone Google Test into the folder):
```bash
cd Resources/Code/Programming-code/_helloWorld_unit_testing/
git clone https://github.com/google/googletest.git
```

**What this project teaches:**

| Topic | Where |
|-------|-------|
| Defining a **custom exception class** (`class Bad_area {}`) | `chapter5.6.1.h` |
| Throwing exceptions when preconditions fail (`throw Bad_area()`) | `chapter5.6.1.h` |
| The `try { } catch (Bad_area) { }` pattern | `chapter.5.6.1.cpp` |
| Catching multiple exception types (`catch (exception& e)`, `catch (...)`) | `chapter.5.6.1.cpp` |
| Writing a **Google Test** test case (`TEST(suite, name) { … }`) | `mytests.cpp` |
| Using `GTEST_ASSERT_EQ` to check return values | `mytests.cpp` |
| Running all tests with `RUN_ALL_TESTS()` | `mytests.cpp` |
| Adding an external library as a **CMake subdirectory** | `CMakeLists.txt` |
| Linking against `gtest` with `target_link_libraries` | `CMakeLists.txt` |
| Building two executables (app + tests) from one project | `CMakeLists.txt` |

**Key code — the test file:**
```cpp
#include <gtest/gtest.h>
#include "chapter5.6.1.h"

TEST(chapter5, area) {
    GTEST_ASSERT_EQ(area(5, 5), 25);    // 5×5 must equal 25
}
TEST(chapter5two, area) {
    GTEST_ASSERT_EQ(area(10, 20), 200); // 10×20 must equal 200
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

**CMake pattern used:**
```cmake
add_subdirectory(googletest)            # builds gtest from source
include_directories(googletest/include)

add_executable(mytests.exe mytests.cpp)
target_link_libraries(mytests.exe PRIVATE gtest)  # attach gtest to test runner

add_executable(helloWorld_unit_testing.exe chapter.5.6.1.cpp)  # app, no gtest
```

**Build and run:**
```bash
cd Resources/Code/Programming-code/_helloWorld_unit_testing
cmake -S . -B build && cmake --build build
./build/mytests.exe                          # run the tests
./build/helloWorld_unit_testing.exe          # run the app (will catch Bad_area)
```

---

### `_helloWorld_fltk_gui_chapter12/` — GUI window with FLTK

**What it is:** A graphical desktop window (from PPP Chapter 12) showing a red polygon and a "Hello World" text label. Everything needed — FLTK 1.3.5, the course `bookgui` library, and the Chapter12 program — is bundled inside and built together. This is the entry point to all GUI chapters (12–16).

**What you see:** A 600×400 window titled "Canvas" with a red polygon shape and "Hello World......!" displayed in Times Bold.

**File layout:**
```
_helloWorld_fltk_gui_chapter12/
├── CMakeLists.txt              ← top-level: chains fltk → GUI → Chapter12
├── fltk-1.3.5/                 ← FLTK toolkit source (embedded, ~3 000 files)
├── GUI/                        ← bookgui static library
│   ├── CMakeLists.txt          ← builds libookgui
│   ├── Point.h                 ← Point(x, y) type
│   ├── Graph.h / Graph.cpp     ← Shape, Line, Circle, Polygon, Text, Color …
│   ├── Window.h / Window.cpp   ← Window class (wraps Fl_Window)
│   ├── Simple_window.h/.cpp    ← adds a "Next" button to Window
│   └── GUI.h / GUI.cpp         ← Button, In_box, Out_box, Menu widgets
└── Chapter12/
    ├── CMakeLists.txt           ← links against bookgui + FLTK
    └── chapter.12.3.cpp         ← the actual program you run
```

**Build chain (CMake does this automatically):**
```
fltk-1.3.5/  →  GUI/bookgui  →  Chapter12/chapter12.3.exe
   (FLTK)       (bookgui)         (your program)
```
Each layer must be built before the next — this is managed by `add_subdirectory` order in the root `CMakeLists.txt`.

**What this project teaches:**

| Topic | Where |
|-------|-------|
| Building a **multi-module CMake project** with ordered subdirectories | root `CMakeLists.txt` |
| `target_include_directories` and `target_link_directories` for complex paths | `Chapter12/CMakeLists.txt` |
| Platform-specific linking (Cocoa on macOS, X11 on Linux) | `Chapter12/CMakeLists.txt` |
| **Namespace** as a module boundary (`Graph_lib::`) | `Graph.h`, `Window.h` |
| **Inheritance hierarchy**: `Widget` → `Button`, `Shape` → `Line`, `Polygon` | `GUI.h`, `Graph.h` |
| **Abstract base classes** (`Widget` is pure-virtual; FLTK calls back into it) | `GUI.h` |
| **Operator overloading** and const-correct accessors on Shape types | `Graph.h` |
| **FLTK event model**: callbacks, `wait_for_button()`, `Fl::run()` | `Simple_window.h`, `GUI.cpp` |
| Using `attach(shape)` / `detach()` to add/remove objects from a window | `chapter.12.3.cpp` |
| **Template container** `Vector_ref<T>` for polymorphic shape lists | `Graph.h` |

**Key program (what you write for Chapter 12):**
```cpp
int main() {
    Point tl(400, 400);
    Simple_window win(tl, 600, 400, "Canvas");

    Polygon poly;
    poly.add(Point(300, 200));
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));
    poly.set_color(Color::red);

    Text t(Point(150, 50), "Hello World......!");
    t.set_font(Graph_lib::Font::times_bold);

    win.attach(poly);
    win.attach(t);
    win.wait_for_button();
}
```

See the dedicated [Graphics and GUI with FLTK](#graphics-and-gui-with-fltk) section for full build instructions and troubleshooting.

**Build and run:**
```bash
cd Resources/Code/Programming-code/_helloWorld_fltk_gui_chapter12
cmake -S . -B build && cmake --build build
./build/Chapter12/chapter12.3.exe
```

---

### `_helloWorld_ray_tracing/` — Ray tracing renderer

**What it is:** A from-scratch 3D renderer based on Peter Shirley's *Ray Tracing in One Weekend* (free online). No external libraries needed — the program writes a PPM image to stdout. Fourteen executables, one per book chapter, each adding a new feature to the renderer.

**What you produce:** A `.ppm` image file you can view in any image viewer.

**File layout:**
```
_helloWorld_ray_tracing/
├── CMakeLists.txt               ← 14 add_executable targets
└── src/InOneWeekend/
    ├── Chapter2.2/  rt1-chapter2.2.cpp        ← first image: RGB gradient
    ├── Chapter2.3/  rt1-chapter2.3.cpp        ← progress output to stderr
    ├── Chapter3.1/  vec3.h  color.h  …        ← 3D vector class
    ├── Chapter4.2/  ray.h   …                 ← Ray class, background colour
    ├── Chapter5.2/  …                         ← sphere hit detection
    ├── Chapter6.2/  …                         ← surface normals visualised
    ├── Chapter6.8/  hittable.h  sphere.h  …   ← abstract hittable objects
    ├── Chapter7/    camera.h    …             ← camera + viewport
    ├── Chapter8/    …                         ← anti-aliasing (multi-sample)
    ├── Chapter9.1–9.5/ …                      ← diffuse materials + Lambertian
    └── _data/                                 ← shared assets
```

**Chapter-by-chapter progression:**

| Chapter | New concept introduced | C++ feature used |
|---------|----------------------|-----------------|
| 2.2 | Write a PPM image via `cout` | loops, integer casting |
| 2.3 | Progress feedback to `cerr` | `std::flush`, stderr vs stdout |
| 3.1 | `vec3` class — 3D vector math | operator overloading, `using` aliases |
| 4.2 | `ray` class — a point + direction | struct with member functions |
| 5.2 | Ray-sphere intersection (quadratic formula) | math, free functions |
| 6.2 | Surface normals as colour | normalisation, conditional |
| 6.8 | `hittable` base class + `sphere` subclass | **abstract base class**, virtual functions, `override` |
| 7 | `camera` class encapsulating the viewport | class design, encapsulation |
| 8 | Anti-aliasing — average N samples per pixel | `<random>`, loops, floating-point average |
| 9.1–9.5 | Diffuse / Lambertian material, recursive rays | `std::shared_ptr`, recursion, material polymorphism |

**What this project teaches:**

| Topic | Where |
|-------|-------|
| **Header-only library design** (all logic in `.h` files, no `.cpp`) | `vec3.h`, `ray.h`, `color.h`, `sphere.h` |
| **Operator overloading** for a math type (`+`, `-`, `*`, `/`, `[]`, `+=`) | `vec3.h` |
| **Type aliases** (`using point3 = vec3`, `using color = vec3`) | `vec3.h`, `color.h` |
| **Abstract base class** with pure-virtual method (`hittable::hit()`) | `hittable.h` |
| **Inheritance** + `override` (`sphere` implements `hittable`) | `sphere.h` |
| **`std::shared_ptr`** for polymorphic object ownership | `hittable_list.h`, chapter 9.x |
| **`const` correctness** throughout (every method that doesn't mutate is `const`) | all headers |
| **PPM image format** — output ASCII pixel data with `cout` | all chapter `.cpp` files |
| **Multiple CMake executables** from one project (14 independent targets) | `CMakeLists.txt` |
| **C++11** standard (`std::shared_ptr`, range-based for, `auto`) | `CMakeLists.txt`, headers |

**Key class — vec3 (3D vector with full operator set):**
```cpp
class vec3 {
  public:
    double e[3];
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const { return e[0]; }
    double length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }

    vec3& operator+=(const vec3& v) { e[0]+=v.e[0]; e[1]+=v.e[1]; e[2]+=v.e[2]; return *this; }
    // … also -, *, /, [], -()
};
// free functions (dot, cross, unit_vector) defined outside the class
inline double dot(const vec3& u, const vec3& v) { return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2]; }
```

**Key class — hittable (abstract interface for any object a ray can hit):**
```cpp
class hittable {
  public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;  // pure virtual
};

class sphere : public hittable {   // concrete implementation
  public:
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override { … }
};
```

See the dedicated [Ray Tracing Project](#ray-tracing-project) section for build instructions and how to view the output images.

**Build and run:**
```bash
cd Resources/Code/Programming-code/_helloWorld_ray_tracing
cmake -S . -B build && cmake --build build
./build/chapter2.2.exe > image.ppm    # redirect output to a file
xdg-open image.ppm                   # open with your system image viewer
```

---

## Graphics and GUI with FLTK

Chapters 12–16 display graphics in a desktop window. This requires three layers of software that must be built in order:

```
Your program (Chapter12/chapter.12.3.cpp)
        │  #include "Simple_window.h"
        │  #include "Graph.h"
        ▼
   bookgui  (static library built from GUI/)
   Window, Simple_window, Shape, Graph, Color, Line, Circle, Text, Image, …
        │  wraps FLTK types: Fl_Window, Fl_Widget, fl_color, …
        ▼
   FLTK 1.3.5  (static libraries: fltk, fltk_images)
   Cross-platform GUI toolkit (X11 on Linux, Cocoa on macOS, Win32 on Windows)
        │
        ▼
   OS windowing system (X11/OpenGL on Linux, Cocoa on macOS)
```

### What each layer provides

| Layer | Location | What it is |
|-------|----------|------------|
| **FLTK 1.3.5** | `fltk-1.3.5/` | Cross-platform C++ GUI toolkit. Provides windows, widgets, event loops, and image loading. Licensed under LGPL. |
| **bookgui** | `GUI/` | Stroustrup's thin wrapper over FLTK. Provides beginner-friendly classes: `Window`, `Simple_window`, `Shape`, `Line`, `Rectangle`, `Circle`, `Text`, `Image`, `Function`, `Axis`, `Button`, `In_box`, `Out_box`. |
| **Your program** | `Chapter12/` | Includes `Simple_window.h` and `Graph.h` from bookgui, links against bookgui + fltk + fltk_images. |

### Key header files in `GUI/`

| Header | Classes / types inside |
|--------|----------------------|
| `Point.h` | `Point(x, y)` — 2D integer coordinate |
| `Graph.h` | `Shape`, `Line`, `Rectangle`, `Circle`, `Ellipse`, `Polygon`, `Text`, `Image`, `Function`, `Axis`, `Color`, `Line_style`, `Font` |
| `Window.h` | `Window` — inherits `Fl_Window`; `attach(Shape&)`, `detach()` |
| `Simple_window.h` | `Simple_window` — window with a "Next" button for stepping through examples |
| `GUI.h` | `Widget`, `Button`, `In_box`, `Out_box`, `Menu` — interactive controls |

### Platform prerequisites

Install the required OS libraries **before** trying to build:

**Ubuntu / Debian:**
```bash
sudo apt update
sudo apt install build-essential cmake libx11-dev libxext-dev libxft-dev \
     libxinerama-dev libgl1-mesa-dev libglu1-mesa-dev libpng-dev libjpeg-dev zlib1g-dev
```

**Fedora / RHEL:**
```bash
sudo dnf install gcc-c++ cmake libX11-devel libXext-devel libXft-devel \
     libXinerama-devel mesa-libGL-devel mesa-libGLU-devel libpng-devel libjpeg-devel zlib-devel
```

**macOS (Homebrew):**
```bash
# Xcode command-line tools first:
xcode-select --install
# CMake:
brew install cmake
# No extra X11 libraries needed — FLTK uses Cocoa on macOS automatically.
```

**Windows (MinGW / MSYS2):**
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake
# No extra libraries needed — FLTK uses Win32 API automatically.
```

### Option A — Build the self-contained starter project (recommended for newcomers)

`_helloWorld_fltk_gui_chapter12/` bundles everything. One CMake command builds FLTK, then bookgui, then the Chapter12 example.

```bash
cd Resources/Code/Programming-code/_helloWorld_fltk_gui_chapter12

# Configure (this will take a minute — it configures FLTK too)
cmake -S . -B build

# Build all three layers
cmake --build build

# Run the example (a window opens showing a polygon and text)
./build/Chapter12/chapter.12.3        # Linux/macOS
build\Chapter12\chapter.12.3.exe      # Windows
```

What you should see: a window titled "My window" containing a red polygon and a "Hello, graphical world!" text label.

### Option B — Build Chapter12 as part of the full project

The root `Programming-code/CMakeLists.txt` already includes everything. Building it all:

```bash
cd Resources/Code/Programming-code

cmake -S . -B build
cmake --build build

# Run a Chapter12 example
./build/Chapter12/chapter12.12.3.exe
```

### Chapter 12 source files overview

| File | What it demonstrates |
|------|---------------------|
| `chapter.12.3.cpp` | First window: polygon + text label |
| `chapter.12.7.1.cpp` | Basic shapes: lines, rectangles |
| `chapter.12.7.2.cpp` | Colors and line styles |
| `chapter.12.7.3.cpp` | Circles and ellipses |
| `chapter.12.7.4.cpp` | Polylines and closed shapes |
| `chapter.12.7.5.cpp` | Text rendering and fonts |
| `chapter.12.7.6.cpp` | Displaying images (JPEG/GIF) |
| `chapter.12.7.7.cpp` | Function plotting |
| `chapter.12.7.8.cpp`–`.11` | Axes, marks, interactive widgets |

### Troubleshooting FLTK build issues

| Error | Likely cause | Fix |
|-------|-------------|-----|
| `X11/Xlib.h: No such file` | Missing X11 dev headers | Run the apt/dnf install command above |
| `GL/gl.h: No such file` | Missing OpenGL headers | `sudo apt install libgl1-mesa-dev` |
| `cannot find -lXinerama` | Missing Xinerama library | `sudo apt install libxinerama-dev` |
| `dyld: Library not loaded: libfltk` | macOS dynamic lib not found | Use the static build (default in CMake config) |
| Window doesn't appear on Linux | No display (e.g. SSH without X forwarding) | Either use `ssh -X`, or run on a machine with a monitor |

---

## Ray Tracing Project

The `_helloWorld_ray_tracing/` project implements *Ray Tracing in One Weekend* by Peter Shirley (free online at [raytracing.github.io](https://raytracing.github.io)). It requires **no external libraries** — just a C++11 compiler.

### How it works

Each executable renders a scene and writes a PPM image to **stdout**. PPM is a plain-text image format that any image viewer can open. You redirect the output to a `.ppm` file, then view it.

```
./chapter9.5.exe  >  output.ppm
         │                │
   renders scene     image file you can open
   to stdout         in any viewer
```

### Progressive chapter structure

Each chapter in the book adds one new concept. The code grows chapter by chapter:

| Executable | Source file | What it renders |
|-----------|------------|-----------------|
| `chapter2.2.exe` | `Chapter2.2/rt1-chapter2.2.cpp` | RGB gradient — tests your PPM pipeline |
| `chapter2.3.exe` | `Chapter2.3/` | Improved gradient |
| `chapter3.1.exe` | `Chapter3.1/` | Introduces `vec3` and `color` types |
| `chapter4.2.exe` | `Chapter4.2/` | First ray-sphere intersection (red sphere) |
| `chapter5.2.exe` | `Chapter5.2/` | Surface normals (coloured by normal direction) |
| `chapter6.2.exe` | `Chapter6.2/` | Ground plane + multiple objects |
| `chapter6.8.exe` | `Chapter6.8/` | Hittable list, intervals |
| `chapter7.exe` | `Chapter7/` | Anti-aliasing (multiple rays per pixel) |
| `chapter8.exe` | `Chapter8/` | Diffuse (matte) material |
| `chapter9.1.exe`–`9.5.exe` | `Chapter9.x/` | Metal materials, reflection, fuzzy reflections |

### Build and run

```bash
cd Resources/Code/Programming-code/_helloWorld_ray_tracing

# Configure (no dependencies to find — instant)
cmake -S . -B build

# Build all 14 executables
cmake --build build

# Render the simplest scene (colour gradient)
./build/chapter2.2.exe > gradient.ppm

# Render the final scene (metal spheres, anti-aliasing)
./build/chapter9.5.exe > final_scene.ppm
```

### Viewing the output images

PPM is supported by many viewers. Choose one:

**Linux:**
```bash
eog final_scene.ppm          # GNOME image viewer
display final_scene.ppm      # ImageMagick
feh final_scene.ppm          # lightweight viewer
```

**macOS:**
```bash
open final_scene.ppm         # Preview opens PPM natively
```

**Windows:**
```powershell
# IrfanView, GIMP, or convert to PNG with ImageMagick:
magick final_scene.ppm final_scene.png
```

**Any platform — convert to PNG:**
```bash
# Requires ImageMagick (sudo apt install imagemagick)
convert final_scene.ppm final_scene.png
```

Pre-rendered output images for each chapter are in `Resources/Images/` for reference.

### Understanding the core types (Chapter 3.1 onwards)

```cpp
// vec3.h — 3D vector used for positions, directions, and colours
class vec3 { double e[3]; };
using point3 = vec3;   // a position in 3D space
using color  = vec3;   // an RGB colour (0.0–1.0 per channel)

// ray.h — a ray: origin + direction
class ray {
    point3 orig;
    vec3   dir;
    point3 at(double t) const;  // point along the ray at distance t
};
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

## VS Code Setup and AI Copilots

### Required extensions

Install these from the VS Code Extensions panel (`Ctrl+Shift+X`):

| Extension | ID | Purpose |
|-----------|-----|---------|
| **C/C++** | `ms-vscode.cpptools` | IntelliSense, syntax highlighting, debugging |
| **CMake Tools** | `ms-vscode.cmake-tools` | Configure/build/run CMake projects from the IDE |
| **CMake** | `twxs.cmake` | Syntax highlighting for `CMakeLists.txt` files |
| **clangd** *(optional)* | `llvm-vs-code-extensions.vscode-clangd` | Faster, more accurate IntelliSense (alternative to cpptools) |

### Opening the project

Always open the **source root** — not a chapter subfolder — so CMake Tools can find the top-level `CMakeLists.txt`:

```
File → Open Folder → Resources/Code/Programming-code/
```

VS Code will detect `CMakeLists.txt` and prompt:
> *"Would you like to configure this project?"* → click **Yes**

### Configuring and building with CMake Tools

The project's `.vscode/settings.json` already sets the preferred generator:
```json
"cmake.preferredGenerators": ["Unix Makefiles"]
```

**Status bar controls** (bottom of VS Code window):

| Button | What it does |
|--------|-------------|
| `⚙ No Kit Selected` | Click to choose your compiler (GCC or Clang) |
| `▶ Build` | Runs `cmake --build` for the whole project |
| `▷ [target]` | Click to pick which executable to run |
| `🐛` | Launch the selected target under the debugger |

**Step by step:**

1. Click **⚙ No Kit Selected** in the status bar → choose e.g. `GCC 12.x` or `Clang 14.x`
2. CMake Tools automatically runs `cmake -S . -B build/` in the background
3. Press **F7** (or click **▶ Build**) to compile everything
4. Click **▷ [target name]** → select the executable you want → press **▶** to run it
5. Press **F5** to run the selected target inside the debugger

### Building and debugging a single file (quick mode)

The existing `.vscode/tasks.json` and `.vscode/launch.json` let you build and debug the **currently open file** directly with clang++, without going through CMake:

- **Build active file:** `Ctrl+Shift+B` → runs `clang++ -g <current file> -o <output>`
- **Debug active file:** `F5` → compiles with clang++ then launches lldb

> This quick mode is useful for single-file experiments. For multi-file projects always use CMake Tools.

### IntelliSense and `std_lib_facilities.h`

If you see red squiggles under `#include "std_lib_facilities.h"`, add the chapter folder to IntelliSense's include path. Create or edit `.vscode/c_cpp_properties.json`:

```json
{
  "configurations": [{
    "name": "Linux",
    "includePath": [
      "${workspaceFolder}/**"
    ],
    "compilerPath": "/usr/bin/clang++",
    "cppStandard": "c++17",
    "intelliSenseMode": "linux-clang-x64"
  }],
  "version": 4
}
```

The `"${workspaceFolder}/**"` glob makes every `std_lib_facilities.h` in any subfolder visible.

---

### AI Copilots for C++ (free options)

Three free setups work well with this project. All integrate into VS Code.

---

#### Option 1 — GitHub Copilot (free tier)

GitHub Copilot's **free plan** gives 2 000 code completions and 50 chat messages per month at no cost.

**Setup:**
1. Go to [github.com/features/copilot](https://github.com/features/copilot) → sign in → select the **Free** plan
2. In VS Code install: `GitHub.copilot` + `GitHub.copilot-chat`
3. Sign in with your GitHub account when prompted

**How to use with this project:**
- Start typing any C++ expression — Copilot suggests completions inline; press `Tab` to accept
- Open the **Chat panel** (`Ctrl+Alt+I`) and ask things like:
  - *"Explain what this Shape class does"*
  - *"Write a CMakeLists.txt that links against bookgui and fltk"*
  - *"What does `attach(Shape&)` do in the Window class?"*

---

#### Option 2 — Claude via Continue (free API tier)

[Continue](https://www.continue.dev) is an open-source AI assistant extension that connects to multiple AI providers, including Claude.

**Setup:**
1. Install the extension: `Continue.continue`
2. Get a free Anthropic API key at [console.anthropic.com](https://console.anthropic.com) (free tier included)
3. Open Continue settings (`~/.continue/config.json`) and add:

```json
{
  "models": [{
    "title": "Claude",
    "provider": "anthropic",
    "model": "claude-sonnet-4-5",
    "apiKey": "YOUR_API_KEY_HERE"
  }]
}
```

4. Reload VS Code

**How to use:**
- Highlight any code → right-click → **Ask Continue** to explain or refactor it
- Open the Continue panel (`Ctrl+Shift+L`) and ask questions about the codebase
- Type `@file Chapter12/chapter.12.3.cpp` in the chat to give Claude direct context from a file

---

#### Option 3 — Ollama (fully local, completely free)

[Ollama](https://ollama.com) runs open-source LLMs on your own machine. No API key, no internet needed after the initial model download. Works through Continue.

**Setup:**
1. Install Ollama from [ollama.com](https://ollama.com/download)
2. Pull a code-capable model (choose based on your RAM):

```bash
ollama pull codellama        # 4 GB — best for C++ code completion
ollama pull qwen2.5-coder    # 4 GB — strong at CMake and C++
ollama pull llama3.2         # 2 GB — general assistant, lower RAM
```

3. Ollama starts a local server automatically at `http://localhost:11434`
4. Install **Continue** (`Continue.continue`) and add to `~/.continue/config.json`:

```json
{
  "models": [{
    "title": "CodeLlama (local)",
    "provider": "ollama",
    "model": "codellama"
  }]
}
```

**How to use:**
- Same as Continue with Claude above — all inference runs locally
- Useful when working offline (e.g. in a lab without internet)
- `codellama` and `qwen2.5-coder` both understand C++17, CMakeLists.txt syntax, and FLTK-style code

**Recommended model by task:**

| Task | Recommended model |
|------|------------------|
| C++ syntax completion | `codellama` or `qwen2.5-coder` |
| Explaining code / asking questions | `llama3.2` or `qwen2.5-coder` |
| Writing CMakeLists.txt | `qwen2.5-coder` |
| Low RAM machine (< 8 GB) | `llama3.2` (2 GB) |

---

### Comparison of the three options

| | GitHub Copilot | Claude (Continue) | Ollama (local) |
|-|---------------|-------------------|----------------|
| Cost | Free (limited) / $10/mo unlimited | Free tier + pay-per-token | Completely free |
| Internet required | Yes | Yes | After first download: No |
| Code completion | Inline, very fast | Via Continue panel | Via Continue panel |
| Chat | Yes (Copilot Chat) | Yes (Continue) | Yes (Continue) |
| Privacy | Code sent to GitHub | Code sent to Anthropic | Stays on your machine |
| C++ quality | Excellent | Excellent | Good (codellama/qwen) |

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
