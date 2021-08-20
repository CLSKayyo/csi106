all: afdtool
	make clean
	make afdtool
	./afdtool --dot exemplo_afd.txt --output afd-result.dot
	./afdtool --complemento exemplo_afd.txt --output afd-complemento.dot

afdtool: main.c
	gcc -g -Wall -o afdtool main.c


clean:
	rm -rf afdtool
	rm -rf afd-result.dot
	rm -rf afd-result.txt