#!/bin/sh

mkdir -p ./apps
mv *.app ./apps

echo "\c" > app.lst
for f in apps/*.app; do
	echo "./"$f >> app.lst
done

sh app.lst
rm -f app.lst

exit 0
