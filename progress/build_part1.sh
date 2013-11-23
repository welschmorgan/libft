#!/bin/sh

ls ../src/ft_mem*.c ../src/ft_str*.c ../src/ft_is*.c ../src/ft_bzero.c ../src/ft_atoi.c ../src/ft_to*.c | sed "s/..\/src\///g" | sed "s/ft_//g" | sed "s/\.c//g" | sort | uniq > done.part1.list

exit 0
