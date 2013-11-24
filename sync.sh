#!/bin/sh

rm -rf $HOME/Rendu/algo1/libft/*
mkdir -p $HOME/Rendu/algo1/libft
cp Makefile $HOME/Rendu/algo1/libft
cp auteur $HOME/Rendu/algo1/libft
cp libft.h $HOME/Rendu/algo1/libft
cp -r src $HOME/Rendu/algo1/libft

git add .
git commit -am "Backup Update"
git push github
git push origin

exit 0
