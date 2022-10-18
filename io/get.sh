#!/bin/bash

PROBLEMS_PATH="../../problems"

find $PROBLEMS_PATH/*/io -type d | cut -d '/' -f 4 > problems.txt
for f in $(cat problems.txt);
do
    paste <(cat $PROBLEMS_PATH/$f/io/*.in) <(cat $PROBLEMS_PATH/$f/io/*.out) > $f.io
done;
rm problems.txt
