#!/bin/bash 

writefile=$1
writestr=$2

if [ $writefile = "" ] || [ $writestr = "" ]
then
	echo "no enought arguments!"
	exit 1
fi

touch $writefile
echo $writestr > $writefile
if [ ! $? = 0 ]
then
	echo "can't create file $writefile"
	exit 1
fi

