MAIN_FILES_DIR=C_02

mkdir $MAIN_FILES_DIR
for nbr in 00 01 02 03 04 05 06 07 08 09 10 11 12
do
	cc -Wall -Wextra -Werror -o $MAIN_FILES_DIR/mainEx$nbr.o -c Exercice\ $nbr/main.c
done