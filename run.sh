#!/bin/sh
echo Codigo Sequencial >> run.txt
for i in 1 2 3 4 5 6 7 8 9 10; do
    ./exS.x 10000 10000 $j >> run.txt
done

echo -e "--------------------" >> run.txt

echo Codigo Paralelo >> run.txt
for j in 2 4 6 8; do
    echo Threads: $j >> run.txt
    for i in 1 2 3 4 5 6 7 8 9 10; do
        ./exP.x 10000 10000 $j >> run.txt
    done
done