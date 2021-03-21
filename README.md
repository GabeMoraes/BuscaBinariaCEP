# BuscaBinariaCEP
Projeto de busca binária em disco, desenvolvido na linguagem C++, para a aula de Organização de Estruturas de Arquivos.

## Sobre a versão:
Versão 1.0 (primeira versão)

## Compilação:
O código fonte deve ser compilado utilizando um compilador de C++ que compreenda o padrão C++11 ou superior, para gerar o arquivo executável.

## Uso:
O programa deve ser utilizado através do terminal (linha de comando), da seguinte forma:

_BuscaBinaria_ _[cep]_ _[arquivo]_

onde _BuscaBinaria_ é o nome do arquivo executável, _cep_ é o CEP a ser buscado, e _arquivo_ é a string que representa o caminho completo do arquivo, dentro do sistema de arquivos.

## Input:
O argumento _cep_ deve ser uma string contendo 8 caracteres em sequência, que representam os numeros que compõem o CEP desejado, sem hífen.

## Output:
Informações sobre o endereço associado ao CEP buscado.

A saída do programa, caso tenha sido bem-sucedido, deverá aparecer no seguinte formato:

Tamanho do arquivo: Y (em bytes)

Quantidade de registros: Z (quantidade de endereços)
_Linha contendo o logradouro_
_Linha contendo o bairro_
_Linha contendo a cidade_
_Linha contendo o estado_
_Linha contendo a sigla do estado_
_Linha contendo o CEP completo_

Quantidade de comparações: W (quantidade de comparações feitas pelo algoritmo até encontrar o CEP buscado).

## Precauções

**O arquivo contendo os CEPs deve estar estruturado da mesma forma que o arquivo "cep_ordenado.dat", disponível no Dropbox.**

**O CEP buscado deve existir no arquivo de dados. Caso contrário, o programa entrará em um loop infinito ainda não solucionado (correção do bug deverá ser implementada na versão 1.1). Caso isso ocorra, pressionar as teclas Ctrl + C deverá interromper a execução do programa em loop.**





