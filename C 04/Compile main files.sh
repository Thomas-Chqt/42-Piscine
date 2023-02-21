MAIN_FILES_DIR=C_04

mkdir $MAIN_FILES_DIR
for nbr in 00 01 02 03 04 05
do
	cc -Wall -Wextra -Werror -o $MAIN_FILES_DIR/mainEx$nbr.o -c Exercice\ $nbr/main.c
done