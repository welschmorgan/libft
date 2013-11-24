#!/bin/sh
cat libft.h | grep ft_ | cut -d'(' -f1 | cut -f2 | sed 's/*//g' | grep -v \# | sort | uniq
exit 0
