#!/bin/sh


mkdir test0 test2
touch test1 test4 test5
ln test5 test3
ln -s test0 test6

echo "aaa" > test1
echo "a" > test4
echo "" > test3

touch -h -t 202306012146 test1
touch -h -t 202306012344 test3
touch -h -t 202306012343 test4
touch -h -t 202306012344 test5
touch -h -t 202306012220 test6
touch -t 202306012047 test0
touch -t 202306012245 test2

chmod -h 714 test1
chmod -h 404 test3
chmod -h 641 test4
chmod -h 404 test5
chmod -h 777 test6
chmod 715 test0
chmod 504 test2

tar -cf exo2.tar *
