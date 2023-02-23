# Simple Shell Project

This is a simple shell project that was developed as part of a course.

## Project Structure

The project is organized as follows:

```
.
├── AUTHORS
├── README.md
├── simple_shell.1 (man page)
├── shell.h
├── main.c
├── built_ins.c
│ ├── shell_exit
│ ├── shell_cd
│ └── shell_env
├── error_handling
│ ├── error_handling.c
│ ├── exit.c
│ └── ...
├── helpers
│ ├── _strtok.c
│ ├── _strdup.c
│ └── ...
└── execute
  ├── execute.c
  ├── fork_and_execute.c
  └── ...
```

`AUTHORS` file lists the contributors to the project. 

`README.md` file you are currently reading is a brief overview of the project. 

`man_1_simple_shell` file is the man page for the shell.

`shell.h`: a header file that includes all the necessary libraries, function prototypes, and global variables.

`main.c`: the main file that contains the loop for getting the user input, parsing the input, and executing the command.

`prompt.c`: a file that handles the prompt display for the shell.

`helpers.c`: a file that contains helper functions for the shell, such as string manipulation functions and functions for printing error messages.

`builtins.c`: a file that contains the implementations of the built-in commands (cd, exit, env).

`path.c`: a file that contains functions for handling the PATH environment variable and searching for executables in the directories listed in PATH.

`execute.c`: a file that contains the functions for executing the non-built-in commands.

`Makefile`: a file that specifies the compilation rules for the shell.


## Usage

To use the simple shell, compile the files using `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`. Then, run the shell using `./hsh`.

## Man Page.

To generate a man page for the `simple_shell`, you can use the `ronn` utility. `ronn` allows you to write man pages in Markdown format and then convert them to man page format.

Once you have created the `simple_shell.1.md` file, run the following command to generate the man page:

`ronn simple_shell.1.md`

This will create a new file called `simple_shell.1`. You can view the man page by running the following command:

`man ./simple_shell.1`

## License

This project is licensed under the MIT License - see the LICENSE file for details.

