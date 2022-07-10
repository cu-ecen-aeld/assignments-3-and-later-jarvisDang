#!/bin/bash 

filesdir=$1
searchstr=$2

if [ $filesdir = "" ] || [ $searchstr = "" ]
then
	echo "no enought arguments!"
	exit 1
fi

if [ ! -d $filesdir ]
then
	echo "$searchstr is not directory."
	exit 1
fi

#X is the number of files in the directory and all subdirectories
X=`find $filesdir -type f   | wc -l`
#Y is the number of matching lines found in respective files.

Y=`grep $searchstr -R $filesdir | wc -l`
echo "The number of files are $X and the number of matching lines are $Y"









