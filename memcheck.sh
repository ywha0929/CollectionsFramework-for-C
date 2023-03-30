rm test
source compile.sh
valgrind --leak-check=yes -s test