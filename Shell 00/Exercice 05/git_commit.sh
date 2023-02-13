#!/bin/sh

logs=$(git log -n 5 --pretty=oneline | tr ' ' '_' | tr '\n' ' ')

array=($logs)

for i in "${array[@]}"
do
   str=$(echo $i | tr '_' ' ')
   subArray=($str)
   echo "${subArray[0]}"
done
