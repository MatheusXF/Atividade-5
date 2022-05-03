# Atividade 05 infra Software


## Codigo: 
Na função main é criada uma thread principal, onde é recebido a grandeza da matriz, e posteriormente todos os elementos dessa matriz, após o recebimento desses dados na thread principal é criado um array de threads que terá tamanho igual ao número de linhas que a matriz recebida possui. Para cada uma dessas threads vai ser dado uma linha da matriz, e elas vão para a função soma que realizará a soma de todos os elementos daquela linha  para incrementar a variável global 'count'. Para que mais de uma thread não possa alterar essa variável ao mesmo tempo gerando algum tipo de erro, foi utilizado mutex lock antes de alterar o valor da variável e foi dado unlock logo após a alteração. Após isso, é realizado o print do valor final da variável count, que será igual a soma de todos os elementos da matriz.

## Makefile:

Makefile simples que realiza apenas 3 funções. 

### make que gerará o binário: 
> gcc main.c -o main -lpthread

### make run que roda o binário gerado:
> ./main

### clean que limpa esse binário gerado: 
> $(RM) main
