#!/bin/sh

make re
make re -C tests
cd tests
sh test.sh
cd ..

exit 0
