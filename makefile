all: afdtool
	make clean
	make afdtool

afdtool: main.c
	gcc -g -Wall -o afdtool main.c

clean:
	rm -rf afdtool