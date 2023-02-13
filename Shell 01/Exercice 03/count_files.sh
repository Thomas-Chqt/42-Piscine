#!/bin/sh
FILE=$(find . -type f | wc -l)
DIR=$(find . -type d | wc -l)

echo $(($FILE+$DIR))
