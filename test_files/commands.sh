#!/bin/bash

#$ ./hsh < commands.sh
ls -l; pwd; echo "Hello, world!"; date

ls && echo "success"
pwd || echo "failure"
echo "Hello" || echo "World" && echo "Goodbye"
echo "Testing" && false || echo "Success"
