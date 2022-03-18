#!/bin/bash

if [[ ! -f $1 ]]; then
	echo "$1 not a file!"
	exit 1;
fi

blankline=0
if [[ ! -z $2 ]]; then
	blankline=$2
fi

cat $1 | while read line; do
	if [[ ! -z $line ]]; then
		echo -e "$line"
		for i in $(seq $blankline)
		do
			echo ""
		done
	fi
done
