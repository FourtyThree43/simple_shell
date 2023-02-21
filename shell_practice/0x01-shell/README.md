# Simple Shell Project

This is a simple shell project that was developed as part of a course.

## Project Structure

The project is organized as follows:

.
├── AUTHORS
├── README.md
├── man_1_simple_shell
├── shell.h
├── simple_shell.c
├── built_ins
│ ├── exit.c
│ ├── env.c
│ └── ...
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


The `AUTHORS` file lists the contributors to the project. The `README.md` file you are currently reading is a brief overview of the project. The `man_1_simple_shell` file is the man page for the shell. The `shell.h` file contains function prototypes and includes all necessary headers. The `simple_shell.c` file contains the main function for the shell.

The `built_ins` folder contains files for the built-in functions of the shell, such as `exit` and `env`. The `error_handling` folder contains files for error handling functions, such as `error_handling` and `exit`. The `helpers` folder contains files for helper functions, such as `_strtok` and `_strdup`. Finally, the `execute` folder contains files for executing commands, such as `execute` and `fork_and_execute`.

## Usage

To use the simple shell, compile the files using `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`. Then, run the shell using `./hsh`.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
