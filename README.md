# alx-low_level_programming

# Shell Project
This project is a simple UNIX command-line interpreter, also known as a shell. It is capable of reading commands from standard input, parsing them, and executing them.

## 0x16. C - Simple Shell

### Pre-requisites

#### Authorized functions and macros:
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)


## Project Structure

The project is organized as follows:

```
.
├── AUTHORS
├── README.md
├── LICENSE
├── CODE_OF_CONDUCT.md
├── simple_shell.1 (man page)
├── shell.h
├── main.c
├── get_input.c
├── prompt.c
├── tokenizer.c
├── execute.c
├── free.c
├── signal_handler.c
├── built-ins Funcs:
│ ├── get_env.c
│ ├── bultins_shell_cd.c
│ ├── bultins_shell_exit.c
│ ├── bultins_shell_help.c
│ ├── bultins_set_env.c
│ └──── bultins_unset_env
├── Path Funcs:
│ ├── get_path.c
│ ├── find_in_path.c
│ ├── set_path.c
│ ├── append_to_path.c
│ └── prepend_to_path.c
├── error.c
└── utils:
  ├── utils_func1.c
  ├── utils_func2.c
  └── utils_func2.c
 
```


`AUTHORS` file lists the contributors to the project. 

`README.md` file you are currently reading is a brief overview of the project. 

`man_1_simple_shell` file is the man page for the shell.

`shell.h`: a header file that includes all the necessary libraries, function prototypes, and global variables.

`main.c`: the main file that contains the loop for getting the user input, parsing the input, and executing the command.

`prompt.c`: a file that handles the prompt display for the shell.

`execute.c`: a file that contains the functions for executing the non-built-in commands.

`tokenizer.c` : This file contains the implementation of functions for parsing user input into arguments.

`free.c`: This file contains the implementation of functions for deallocating memory.

`signal_handler.c`: This file contains the implementation of signal handler functions for handling SIGINT, SIGTSTP and SIGQUIT signals.

`builtins funcs`: These are the source code files that contains functions related to the implementations of the built-in commands (cd, exit, env, setenv, unsetenv and help).

`path funcs`: These are the source code files that contains functions related to working with the system's PATH environment variable, such as finding a command in the PATH, getting the current PATH, and setting or modifying the PATH.

`utils.c`: a file that contains utility functions for the shell, such as string manipulation functions and functions for printing error messages.

`error.c`: This file contains the implementation of functions for handling errors.

`Makefile`: a file that specifies the compilation rules for the shell.

`test_files`: These are test files for each of the implementation files in source_files. 

This tree separates the implementation files from the test files, making it easier to navigate the project and run the tests.

## Function Prototypes.

The header file declares several function prototypes for the shell program, including:

`prompt()`: prints the shell prompt

`execute()`: executes a command with arguments

`get_input()`: retrieves user input from stdin

`tokenize()`: parsing user input into arguments.

`handle_sigint()`: signal handler for SIGINT

`handle_sigstp()`: signal handler for SIGSTP

`handle_sigquit()`: signal handler for SIGQUIT

`check_for_builtin()`: checks if a command is a shell builtin

`execute_builtin()` : executes a built-in command

`print_env()`: prints environment variables

`set_env()`: sets an environment variable

`unset_env()`: unsets an environment variable

`_getenv()`: retrieves the value of an environment variable

`shell_help()`: prints help information for the shell

`shell_cd()`: changes the current working directory

`exit_shell()`: exits the shell program with a status code

`find_in_path()`: searches for a command in the directories specified by the PATH environment variable

`get_path()`: retrieves the PATH environment variable

`set_path()`: sets the PATH environment variable

`append_to_path()`: appends a directory to the PATH environment variable

`prepend_to_path()`: prepends a directory to the PATH environment variable

`free_error()`: frees memory allocated following system error

`free_tokens()`: frees memory allocated for tokens

`_puterror()`: prints an error message

`_puts()`: prints a string

`_atoi()`: converts a string to an integer

`_putchar()`: prints a character

`_strlen()`: gets the length of a string

`_strcmp()`: compares two strings

`_strcpy()`: copies a string

`_strcat()`: concatenates two strings

`_strdup()`: duplicates a string

`_strchr()`: searches a string for a character

`_strstr()`: searches for the first occurrence of a substring

`_strspn()`: gets the length of a prefix substring

## Usage

To use the simple shell, compile the files using `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`. Then, run the shell using `./hsh`.

`
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
`

This wil compile all the '.c' files and change the output's name to 'hsh'.

### Template to test output:
=============
```
$ ./hsh

($) ls

hsh main.c shell.c shell.h

$ exit
$
```

also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Man Page.

To generate a man page for the `simple_shell`, you can use the `ronn` utility. `ronn` allows you to write man pages in Markdown format and then convert them to man page format.

Once you have created the `simple_shell.1.md` file, run the following command to generate the man page:

`ronn simple_shell.1.md`

This will create a new file called `simple_shell.1`. You can view the man page by running the following command:

`man ./simple_shell.1`

## AUTHORS

This program was written by `FourtyThree43` and `Kemboiray`.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
