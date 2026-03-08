# Free AI Agents in VS Code for CPP-PP-Edu
### A Tutorial for First-Year C++ Students — HY150

**Course:** HY150 — University of Crete & ICS-FORTH
**Textbook:** *Programming: Principles and Practice Using C++* — Bjarne Stroustrup

---

## What is an AI Agent?

An **AI coding agent** is more than autocomplete. Unlike a simple suggestion tool that predicts the next line, an agent can:

- Read your entire codebase context
- Reason about multi-step problems
- Write, refactor, and debug code autonomously
- Explain *why* something is wrong, not just flag it

Think of it as a senior programmer sitting next to you 24/7 — one that has read every C++ textbook ever written, never gets tired, and never judges your question.

The tools below are **completely free** for students. You do not need a credit card.

---

## Part 1 — Prerequisites

Before installing any AI tool, make sure your VS Code environment is working with the CPP-PP-Edu codebase.

### 1.1 Clone the Repository

```bash
git clone https://github.com/your-org/CPP-PP-Edu.git
cd CPP-PP-Edu
```

Open it in VS Code:

```bash
code .
```

### 1.2 Required VS Code Extensions (Non-AI)

Install these first from the Extensions panel (`Ctrl+Shift+X` / `Cmd+Shift+X`):

| Extension | Publisher | Why You Need It |
|-----------|-----------|-----------------|
| C/C++ | Microsoft | Syntax highlighting, IntelliSense, debugging |
| CMake Tools | Microsoft | Build system integration |
| C/C++ Extension Pack | Microsoft | Bundles the above + extras |

### 1.3 Verify Your Build Works

```bash
cd Resources/Code/Programming-code/_helloWorld_single_cmake
mkdir build && cd build
cmake ..
make
./HelloWorld
```

You should see `Hello, World!`. If not, fix your compiler setup before adding AI tools — the AI cannot help you if it cannot see your files build correctly.

---

## Part 2 — Free AI Agent Options

### Option A: GitHub Copilot (Recommended for Students)

**Cost:** Free with GitHub Student Developer Pack (verified .edu email)

#### Step 1 — Get GitHub Student Developer Pack

1. Go to [education.github.com/pack](https://education.github.com/pack)
2. Sign in with your GitHub account
3. Click **"Get student benefits"**
4. Upload your university ID or use your institutional `.edu` email
5. Wait for approval (usually 1–3 days)

#### Step 2 — Install the Extension

In VS Code Extensions panel, search for **"GitHub Copilot"** and install it. Also install **"GitHub Copilot Chat"**.

#### Step 3 — Sign In

Press `Ctrl+Shift+P` → type `GitHub Copilot: Sign In` → follow the browser prompt.

#### Step 4 — Enable Agent Mode (The Important Part)

GitHub Copilot has two modes:

| Mode | What It Does |
|------|--------------|
| **Inline suggestions** | Autocomplete as you type |
| **Chat / Agent mode** | You ask questions, it reasons and acts |

To open the **Agent (Chat) panel**:
- Click the chat icon in the sidebar, or
- Press `Ctrl+Alt+I` (Windows/Linux) / `Cmd+Option+I` (macOS)

Switch to **Agent mode** by clicking the dropdown at the bottom of the chat panel and selecting `Agent`.

In Agent mode, Copilot can:
- Run terminal commands on your behalf
- Edit multiple files at once
- Search your codebase for symbols and patterns
- Write and run tests

#### Step 5 — Configure Copilot for C++

Add this to your `.vscode/settings.json` in the CPP-PP-Edu workspace:

```json
{
  "github.copilot.chat.codeGeneration.instructions": [
    {
      "text": "This is a C++ educational codebase following Bjarne Stroustrup's 'Programming: Principles and Practice Using C++' 2nd edition. Use C++17. Follow the coding style in existing files. Use CMakeLists.txt for new source files. Prefer simple, readable code for first-year students. Do not use advanced STL features beyond Chapter 20 unless asked."
    }
  ]
}
```

---

### Option B: Claude Code (VS Code Integration)

**Cost:** Free tier available; best free option if you already use Claude

#### Step 1 — Install the Extension

Search for **"Claude Code"** in the Extensions panel and install it.

Or install via terminal:

```bash
npm install -g @anthropic/claude-code
```

#### Step 2 — Get a Free API Key

1. Go to [console.anthropic.com](https://console.anthropic.com)
2. Create an account (free tier included)
3. Navigate to **API Keys** → **Create Key**
4. Copy the key

#### Step 3 — Configure the Extension

In VS Code settings (`Ctrl+,`), search for `Claude` and paste your API key, or set it in your shell:

```bash
export ANTHROPIC_API_KEY="your-key-here"
```

#### Step 4 — Open Claude in the Sidebar

Click the Claude icon in the Activity Bar. You now have a full agent that can read your CPP-PP-Edu files, write CMake targets, debug compile errors, and explain Stroustrup's examples.

---

### Option C: Continue.dev (Fully Local / Offline Option)

**Cost:** 100% free, no API key needed, runs models on your machine

This is the best option if you have privacy concerns or a slow internet connection.

#### Step 1 — Install Continue

Search **"Continue"** in Extensions panel and install it.

#### Step 2 — Install Ollama (Local Model Runner)

```bash
# macOS
brew install ollama

# Linux
curl -fsSL https://ollama.com/install.sh | sh
```

#### Step 3 — Pull a Free C++ Model

```bash
# Good balance of speed and intelligence (4GB RAM needed)
ollama pull codellama:7b

# Better reasoning, slower (8GB RAM needed)
ollama pull deepseek-coder:6.7b

# Best free local model for C++ (16GB RAM needed)
ollama pull deepseek-coder:33b
```

#### Step 4 — Configure Continue for CPP-PP-Edu

Open `~/.continue/config.json` and add:

```json
{
  "models": [
    {
      "title": "CodeLlama 7B (Local)",
      "provider": "ollama",
      "model": "codellama:7b",
      "apiBase": "http://localhost:11434"
    }
  ],
  "contextProviders": [
    { "name": "codebase" },
    { "name": "tree" },
    { "name": "problems" }
  ],
  "customCommands": [
    {
      "name": "explain-stroustrup",
      "prompt": "Explain this C++ code as if teaching a first-year student using Stroustrup's PPP book. Reference the relevant chapter if possible.",
      "description": "Explain code in Stroustrup PPP style"
    }
  ]
}
```

Start Ollama before coding:

```bash
ollama serve
```

---

## Part 3 — Using AI Agents Effectively with CPP-PP-Edu

### 3.1 The Right Mindset

> **AI agents are your thinking partner, not your answer machine.**

If you paste an exercise and ask the agent to solve it, you learn nothing and your exam grade will show it. Instead:

- Ask the agent to **explain** a concept you don't understand
- Ask it to **review** code you already wrote
- Ask it to **suggest** why a test is failing, then fix it yourself first
- Ask it to **compare** two approaches and explain the tradeoffs

### 3.2 Prompting Strategies for C++ Students

**For debugging a compile error:**
```
I'm getting this error in Chapter05/chapter.5.3.2.cpp:
[paste error]

I'm a first-year student using Stroustrup PPP Chapter 5.
Explain what this error means in simple terms.
Do NOT give me the fix — just explain the cause.
```

**For understanding existing code:**
```
Read Resources/Code/Programming-code/Chapter09/ and explain what
the class design pattern is. What chapter of Stroustrup does this
correspond to? What would break if I removed the destructor?
```

**For getting unstuck on an exercise:**
```
I'm trying to implement exercise 5.9 from Stroustrup PPP.
Here's what I've written so far: [paste code]
I'm stuck on handling the case where the user enters a non-integer.
Give me a hint only — not the full solution.
```

**For CMake issues (very common for beginners):**
```
I added a new .cpp file called my_calculator.cpp to Chapter05/.
What lines do I need to add to the CMakeLists.txt in that folder
to make it compile with the existing setup?
```

### 3.3 Attaching Context (Critical Skill)

AI agents work much better when you give them the right files as context. In any agent chat panel:

- **GitHub Copilot:** Type `#file:` followed by the file path, or drag-drop files into chat
- **Claude Code:** The agent reads your full workspace automatically
- **Continue:** Press `@` to open the context picker, then choose files, the whole codebase, or even git diff

Example with file context:
```
@CMakeLists.txt @Chapter05/chapter.5.5.cpp
Why does the CMake target for chapter 5.5 fail to link
when I add a second .cpp file?
```

### 3.4 Workflow: Build → Error → Agent → Fix → Understand

1. **Write** your code following the chapter examples
2. **Build** with CMake: `cmake --build build/`
3. **Copy** the exact error message (all of it, including the file path and line number)
4. **Paste** into the agent with context about what you expected
5. **Read** the agent's explanation carefully
6. **Fix** the code yourself based on the explanation
7. **Ask** the agent: "Does my fix make sense? What could go wrong with this approach?"

---

## Part 4 — Agent-Specific Tips for CPP-PP-Edu

### Understanding the `std_lib_facilities.h` Header

Every chapter uses a custom header. When the agent asks about it, give it this context:

```
This project uses std_lib_facilities.h from Stroustrup's PPP textbook.
It includes common standard headers and defines helpers like error().
The file is at Resources/Code/Programming-code/Chapter05/std_lib_facilities.h
```

### CMake Structure Awareness

The CPP-PP-Edu codebase uses **per-chapter CMakeLists.txt** files with a top-level CMake. When asking for help with build setup, always share the relevant `CMakeLists.txt` content with the agent.

### Debugging with FLTK/GUI (Chapter 12+)

If you reach the graphics chapters, tell the agent:

```
This project uses FLTK for GUI (Chapter 12 of Stroustrup PPP).
The GUI wrapper classes are in Resources/Code/Programming-code/GUI/.
I'm on macOS/Linux/Windows. [pick yours]
```

---

## Part 5 — Project Assignment

### "C++ Code Mentor" — An AI-Powered Learning Tool

**Difficulty:** Medium
**Estimated Time:** 2–3 weeks
**Prerequisites:** Chapters 8–11 (functions, classes, vectors, streams)

---

### Project Description

You will build a **command-line C++ code analysis tool** that reads `.cpp` source files from the CPP-PP-Edu chapters, analyzes their structure, and generates a **student-readable report**. You will use an AI agent throughout — not to write the code for you, but as a **research and debugging partner** for tasks that would otherwise require hours of manual documentation reading.

This project is designed so that **you cannot complete it without actively collaborating with an AI agent**. The required techniques span across multiple C++ topics that are too spread out to master alone in 2 weeks without AI-assisted research.

---

### What the Tool Does

```
$ ./code_mentor Resources/Code/Programming-code/Chapter05/chapter.5.5.cpp

=== CPP-PP-Edu Code Mentor Report ===
File: chapter.5.5.cpp
Chapter: 5 (inferred from path)

--- Structure Summary ---
Functions found : 3
  - int main()
  - double sqrt_approx(double)
  - void print_result(double, double)

Includes detected : 2
  - <iostream>
  - "std_lib_facilities.h"

--- Complexity Metrics ---
Lines of code     : 47
Comment density   : 12% (5 comment lines)
Deepest nesting   : 3 (for loop inside if inside main)

--- Beginner Warnings ---
[W1] Line 18: Raw loop detected. Consider if a range-for would be clearer.
[W2] Line 31: Magic number 0.001 — consider naming this constant.
[W3] No input validation found for user-facing function sqrt_approx().

--- Chapter Concepts Detected ---
[OK] Function definition (Ch. 8)
[OK] Pass by value (Ch. 8)
[OK] while-loop (Ch. 4)
[MISSING] No use of references — expected in Chapter 8+ exercises.

Report saved to: report_chapter.5.5.txt
```

---

### Required C++ Features (What You Must Learn and Use)

| Feature | Chapter in PPP | Used For |
|---------|---------------|----------|
| File I/O with `ifstream` | Ch. 10 | Reading `.cpp` files line by line |
| `std::string` operations | Ch. 11 | Parsing lines for keywords |
| `std::vector` | Ch. 4 | Storing function names, warnings |
| Classes and structs | Ch. 9 | `AnalysisResult`, `FunctionInfo` structs |
| Function decomposition | Ch. 8 | Separate functions for each analysis step |
| Command-line arguments (`argc`, `argv`) | Ch. 8 | Accepting the file path as input |
| `std::map` | Ch. 21 | Mapping keyword names to counts |
| Output formatting | Ch. 10 | Generating the report file |

---

### Why This Requires an AI Agent

The following sub-problems are intentionally difficult to solve from just the textbook. You are **expected** to use your AI agent to research and prototype each one, then implement it yourself:

#### Challenge 1 — Parsing C++ Source Code as Text

Reading a `.cpp` file and correctly identifying function signatures, `#include` lines, and comment lines requires string manipulation techniques not fully covered until Chapter 11. You will need to ask your agent:

> "How do I write a C++ function that reads a file line by line and checks if a line starts with `#include`? I know about `ifstream` from Chapter 10 but I'm not sure how to strip whitespace before comparing."

Use the agent's explanation to write the parsing yourself.

#### Challenge 2 — Counting Nesting Depth

Counting `{` and `}` characters to find the deepest nesting level requires maintaining a counter across lines — a stateful parsing problem. Your agent will help you think through the edge cases (strings containing `{`, comments with `}`). Ask it:

> "What edge cases will break a simple brace-counter in C++ source? I want to find the deepest nesting depth. I don't want a full solution, just the list of edge cases I need to handle."

#### Challenge 3 — Inferring the Chapter Number

The file path contains `Chapter05` or `chapter.5.5`. You need to extract the number. Ask your agent:

> "I have a `std::string` file path like `Chapter05/chapter.5.5.cpp`. What C++ string methods can I use to extract '5' as the chapter number? I know `find()` and `substr()` exist but haven't used them much."

#### Challenge 4 — Generating a Formatted Report File

Writing a clean, aligned text report to a file is harder than it looks. `std::setw()` and `std::left` from `<iomanip>` are needed. Ask your agent:

> "I want to print a table with aligned columns to a `std::ofstream`. I've seen `printf` with format specifiers but I want to use C++ streams. What headers and manipulators do I need?"

---

### Deliverables

1. **`code_mentor.cpp`** — Main program entry point (handles `argc`/`argv`)
2. **`analyzer.h` / `analyzer.cpp`** — Class or struct definitions + parsing logic
3. **`reporter.h` / `reporter.cpp`** — Report formatting and file output
4. **`CMakeLists.txt`** — Build file that compiles all three modules (multi-file CMake, see `_helloWorld_multiple_cmake_library/` for reference)
5. **`AGENT_LOG.md`** — A 1-page log of 3 specific AI agent interactions that helped you. For each: paste the question you asked, summarize the agent's answer, and explain what you implemented based on it.

---

### Grading Criteria

| Criterion | Points |
|-----------|--------|
| Correct file reading and parsing | 20 |
| Function name detection works on 5 test files | 20 |
| At least 2 beginner warnings correctly detected | 15 |
| Multi-file CMake build compiles cleanly | 15 |
| Report output is readable and formatted | 15 |
| `AGENT_LOG.md` shows genuine AI collaboration | 15 |

**Bonus (+10):** Detect the use of `using namespace std;` (a common beginner antipattern) and warn the student about it, citing Stroustrup's recommendation.

---

### Getting Started

```bash
# 1. Create your project folder in the repo
mkdir -p Resources/Code/Programming-code/MyProjects/code_mentor
cd Resources/Code/Programming-code/MyProjects/code_mentor

# 2. Copy the multi-file CMake template as a starting point
cp -r ../_helloWorld_multiple_cmake_library/* .

# 3. Open in VS Code
code .

# 4. Ask your AI agent to explain the template structure
# In the chat panel:
# "@CMakeLists.txt Explain what each line in this CMakeLists.txt does.
#  I'm a first-year student. I want to add analyzer.cpp and reporter.cpp
#  as separate compiled units linked to one executable."
```

---

### A Note on Academic Integrity

Using an AI agent to **understand and learn** is encouraged. Using it to **generate code you submit without understanding** is academic dishonesty and will be obvious during the oral examination.

Your `AGENT_LOG.md` is proof of honest collaboration. The best logs show that you used the agent to get unstuck, not to bypass the work entirely.

> "The purpose of this project is not to build a perfect tool. It is to practice using AI agents the way professional C++ engineers do: as an accelerator for your own thinking, not a replacement for it."

---

*Tutorial written for HY150 — University of Crete | March 2026*
