#!/bin/bash

DIR=`pwd`

pushd ..
echo $DIR
python checker.py sol=$DIR/release/$1.bin lang=binary problem=$1
popd
