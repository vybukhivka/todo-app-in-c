# C-Todo CLI

A lightweight, terminal-centric To-Do manager written in C. Compiles on any Unix-like system using standard libraries.
Tasks are stored in `~/.todo_data.txt`, making them accessible from any directory.

https://github.com/user-attachments/assets/4c07aa5b-5392-4d17-9f57-dbfddea74110

## Usage 

Run `todo` from any directory in your terminal.


```bash
# To see your current list
todo

# Update the text of an existing task by its list number.
todo edit 1 "New description"

# Marking a task as "done" removes it from the list and re-indexes the remaining items.
todo done 1
```

## Installation

You can install `todo` system-wide using the provided Makefile:

   ```bash
   git clone https://github.com/vybukhivka/c-todo
   cd c-todo
   make install
   ```
   
