#!/bin/bash

declare -ir init=$1
declare -ir end=$2
declare -ir max=391

if [ "$init" -le "0" ] || [ "$end" -le "0" ]; then
	echo "The two values must be positive numbers"
	exit
fi

if [ "$end" -lt "$init" ]; then
	echo "End value must be equal of bigger than first"
	exit
fi

for (( i = $init; i <= end; i = $(( i + 1 )))); do
	if [ ! -e "problems_$i" ]; then
		wget -q http://projecteuler.net/problem=$i
		mv problem\=$i problem_$i
		echo "problem_$i downloaded"
	fi;
done

for (( i = $init; i <= $end; i = $(( i + 1 )))); do
	declare act="updated"
	if [ "$i" -lt "10" ]; then
		declare dir="00$i"
	elif [ "$i" -lt "100" ]; then
		declare dir="0$i"
	else
		declare dir="$i"
	fi
	if [ ! -d "p$dir" ]; then
		mkdir p$dir
	fi
	if [ ! -e "p$dir/README" ]; then
		touch p$dir/README
		declare act="created"	
	fi
	sed -e :a -e '$!N;s/\n//;ta' problem_$i | awk -F '<div class="problem_content" role="problem">' '{ print $2 }' | awk -F '</div>' '{ print $1 }' | sed -e 's;<p>;\n\n;g' | sed -e 's/<[^>][^>]*>//g' | awk 'FNR>2' > p$dir/README 
	echo "p$dir/README $act"; 
done

if [ "$3" = "clean" ]; then
	rm problem_*;
	echo "Files cleaned"
fi
