#!/bin/sh

clear

die ()
{
	echo $@
	exit 1
}
success ()
{
	echo $@
	exit 0
}

check_part()
{
	echo "" > progress/success_$1.log
	errs=""

	for i in `cat ./progress/todo.$1.list`
	do
		if [ ! -f "./src/ft_$i.c" ]; then
			echo "$1: Missing function ft_$i"
			errs=$errs" "$i
		else
			echo "$1: Function ft_$i found !" > progress/success_$1.log
		fi
	done

	if [ ! -z $errs ]; then
		die "$1: There was errors: "$errs
	else
		echo "$1: No errors encountered"
	fi
}

check_part "part1"
check_part "part2"
check_part "part3"

exit 0
