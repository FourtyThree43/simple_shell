% simple_shell(1) 

# NAME

simple_shell - a simple UNIX command-line interpreter, also known as a shell

# SYNOPSIS

**simple_shell** [**command**]

# DESCRIPTION

The **simple_shell** is a command-line interpreter for UNIX-based operating systems. It is capable of reading commands from standard input, parsing them, and executing them.

# OPTIONS

The **simple_shell** does not accept any command-line options.

# COMMANDS

The **simple_shell** accepts the following commands:

- cd [DIRECTORY]: changes the current working directory to DIRECTORY
- exit [STATUS]: exits the shell with a status code of STATUS (default is 0)
- help: displays help information for the shell
- env: prints the current environment variables
- setenv [NAME] [VALUE]: sets the environment variable NAME to VALUE
- unsetenv [NAME]: unsets the environment variable NAME

# ENVIRONMENT

The **simple_shell** program does not set or use any environment variables.

# EXIT STATUS

The **simple_shell** program returns the following exit codes:

- 0: successful termination
- 1: general error
- 2: incorrect usage

# EXAMPLES

To change the current working directory to /usr/local/bin:

$ cd /usr/local/bin


To exit the shell with a status code of 1:

$ exit 1

To print help information for the shell:

$ help

To print the current environment variables:

$ env

To set an environment variable:

$ setenv MY_VAR my_value

To unset an environment variable:

$ unsetenv MY_VAR

# AUTHORS

This project was created by FourtyThree43 and Kemboiray as part of the curriculum for Alx Software Engineering.

# REPORTING BUGS

Report any bugs or issues to gihub @fourtythree43.com or @kemboiray.

# COPYRIGHT

This program is free software: you can redistribute it and/or modify it under the terms of the GNU
