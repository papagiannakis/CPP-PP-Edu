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
A fully self-contained project that opens a graphical window. Everything needed is bundled inside (FLTK + bookgui + a Chapter12 example). See the dedicated [Graphics and GUI with FLTK](#graphics-and-gui-with-fltk) section for full build instructions and dependency explanation.
```
_helloWorld_fltk_gui_chapter12/
├── CMakeLists.txt        ← top-level: chains fltk → GUI → Chapter12
├── fltk-1.3.5/           ← FLTK library (full source, embedded)
├── GUI/                  ← bookgui static library (Window, Graph, Shape, …)
└── Chapter12/
    ├── CMakeLists.txt
    └── chapter.12.3.cpp  ← draws a polygon + text in a window
```

### `_helloWorld_ray_tracing/` — Ray tracing renderer
Implements Peter Shirley's *Ray Tracing in One Weekend* in C++. No external dependencies — output is a PPM image written to stdout. See the dedicated [Ray Tracing Project](#ray-tracing-project) section for full build and run instructions.
```
_helloWorld_ray_tracing/
├── CMakeLists.txt                 ← 14 executables (one per book chapter)
└── src/InOneWeekend/
    ├── Chapter2.2/  rt1-chapter2.2.cpp   ← PPM color gradient (start here)
    ├── Chapter2.3/  rt1-chapter2.3.cpp
    ├── Chapter3.1/  vec3.h color.h …     ← vectors and color math
    ├── Chapter4.2/  ray.h …              ← ray-sphere intersection
    ├── Chapter5.2/ … Chapter9.5/         ← materials, anti-aliasing, cameras
    └── _data/                            ← shared data
```

### `_helloWorld_unit_testing/` — Unit tests with Google Test
Shows how to write and run automated tests. Requires cloning Google Test first:
```bash
cd Resources/Code/Programming-code/_helloWorld_unit_testing/
git clone https://github.com/google/googletest.git
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
