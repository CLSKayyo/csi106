Repositório criado para um trabalho da disciplina de Fundamentos Teóricos da Computação.

Instruções para utilização:
- Compilar afdtool com comando "make" caso não exista o binário na pasta
- Visualização:
	- ./afdtool --dot /arquivoDeEntrada/ --output /arquivoDeSaida/ 
- Complemento:
	- ./afdtool --complemento /arquivoDeEntrada/ --output /arquivoDeSaida/ 
- Reconhecimento de Palavra
	- ./afdtool --reconhecer /arquivoDeEntrada/  /arquivoComAsPalavras/  --output /arquivoDeSaida/
- Minimização
	- ./afdtool --minimizacao /arquivoDeEntrada/ --output /arquivoDeSaida/

Exemplos:
	./afdtool --dot afd_entrada.txt --output afd-visualizacao.dot
	./afdtool --complemento afd_entrada.txt --output afd-complemento.txt
	./afdtool --reconhecer afd_entrada.txt palavras.txt --output palavras-reconhecidas.txt
	./afdtool --minimizacao afd_entrada.txt --output afd-minimizado.txt