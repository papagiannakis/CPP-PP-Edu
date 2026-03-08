# AGENT_LOG.md — Code Mentor Development Journal

This file documents three AI agent interactions that guided key implementation
decisions during the development of the `code_mentor` tool.

---

## Interaction 1 — Reading a File Line by Line and Detecting `#include`

**Question asked to the agent:**

> I need to read a .cpp source file one line at a time in C++ and check whether
> each line starts with `#include`. What is the standard way to do this with
> `ifstream`, and how do I strip leading whitespace before testing the prefix?

**Agent's answer (summary):**

The agent explained that the idiomatic approach is to open the file with
`std::ifstream` and call `std::getline` in a `while` loop, storing each line
in a `std::string`. It recommended checking `in.is_open()` before entering the
loop and throwing an exception if the file cannot be opened, since a silent
failure makes debugging very hard.  To strip leading whitespace, the agent
showed a small `trim()` helper using `std::string::find_first_not_of` and
`find_last_not_of` with the characters `" \t\r\n"`, which handles both Unix
and Windows line endings.  Finally it noted that comparing with `substr(0, 8)`
to detect `"#include"` is fragile if there is unexpected whitespace, which is
exactly why `trim()` should be applied first.

**What was implemented:**

The `Analyzer::load_file()` method opens the file with `std::ifstream`, throws
`std::runtime_error` if the open fails, and fills `lines_` via a `std::getline`
loop.  `parse_includes()` calls the file-local `trim()` helper before testing
`t.substr(0, 8) == "#include"`, then captures everything after `#include ` as
the include token.

---

## Interaction 2 — Brace Counting Edge Cases: Strings and Comments

**Question asked to the agent:**

> My nesting-depth counter counts `{` and `}` in each line, but it gets the
> wrong answer on lines like `std::string s = "{ not a brace }";` or lines
> with `//` comments that contain braces. How should I handle these edge cases?

**Agent's answer (summary):**

The agent pointed out that a naive character scan will incorrectly count braces
that appear inside string literals or after a `//` comment.  It recommended a
two-pass approach: first remove string literal content (everything between
unescaped `"` pairs on the same line), then remove everything after the first
`//` that is itself not inside a string.  It showed a simple state-machine loop
that sets an `in_string` flag on `"` and clears it on the next unescaped `"`,
skipping one extra character on `\\` (the escape prefix).  The agent also
warned that `/* */` block comments that span multiple lines need a separate
boolean state variable (`in_block_comment`) tracked across iterations of the
outer line loop.

**What was implemented:**

Two file-local helpers were written: `strip_string_literals()` (state-machine
loop that drops characters between unescaped double-quotes) and
`strip_line_comment()` (finds the first `//` not inside a string and returns
only the prefix).  In `compute_metrics()`, each line is processed through both
helpers before iterating over characters to update `current_depth`.  Block
comments are tracked with the `in_block_comment` boolean across lines.

---

## Interaction 3 — Aligned Output with `std::setw` and `std::left`

**Question asked to the agent:**

> I want my report to print key-value pairs in aligned columns, like:
>
>     Lines of code    : 47
>     Comment density  : 12%
>
> How do I use `<iomanip>` to do this in C++, and is there a way to make the
> same formatting code write to both `std::cout` and a file?

**Agent's answer (summary):**

The agent explained that `std::setw(n)` sets the minimum field width for the
*next* output operation only, so it must be repeated before each label.
`std::left` makes the padding go on the right side (left-aligning the text),
and persists until changed.  Both manipulators work on any `std::ostream`
object, not just `std::cout`, which is the key to dual output: write a private
`write_report(std::ostream& out)` method that uses `out` instead of `std::cout`
directly, and call it from both `print_to_console()` (passing `std::cout`) and
`save_to_file()` (passing an `std::ofstream`).  The agent cautioned that
`std::setw` resets after every insertion, so it should be set immediately
before the value it controls.

**What was implemented:**

`Reporter::write_report(std::ostream& out)` applies `std::left` once at the
top and uses `std::setw(W1)` (where `W1 = 20`) before each label string.  Both
`print_to_console()` and `save_to_file()` delegate to this single method,
ensuring that the console and the saved file are always identical in content.
