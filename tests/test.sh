#!/bin/sh

make re
mkdir -p ./apps
mv *.app ./apps

echo -n "" > app.lst
for f in apps/*.app; do
	echo "./"$f >> app.lst
done

sh app.lst

exit 0