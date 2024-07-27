# My_Shell v1.1

A simple shell implementation in C with basic built-in commands.

## Features
- Supports basic shell commands like `pwd`, `echo`, `cp`, `mv`, `exit`, and `help`.
- Handles input parsing and command execution.
- Error handling for invalid commands and file operations.

## Supported Commands

1. `pwd`: print working directory
2. `echo`: print a user input string on stdout 
3. `cp`: copy a file to another file (cp sourcePath targetPath)
4. `mv`: move a file to another place (mv sourcePath targetPath)
5. `exit`: print "Come Back Soon ^_-" and terminate the shell
6. `help`: print all the supported commands with a brief info about each one.

## Installation
Clone the repository and compile the code:
``bash
git clone (https://github.com/karemhamam/BasicShell/tree/master)

## Compilation

To compile the shell program, use the following command:

``bash
gcc -o myShell my_shell.c command.c
