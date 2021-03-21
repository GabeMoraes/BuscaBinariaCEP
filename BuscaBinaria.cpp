#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef struct _Endereco_ Endereco;

struct _Endereco_{
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char estado[72];
    char siglaEstado[2];
    char cep[8];
    char lixo[2];
};

int main(int argc, char **argv){
    FILE *arquivoCEP;
    Endereco endereco;
    long int totalBytesLidos, tamArquivo, qtdRegistro, tamRegistro = sizeof(Endereco);
    long int primeiro, ultimo, meio;
    int cepIntArg, cepIntEnd, qtdCompares = 0;
    bool cepFound = false;

    if(argc!=3){
        cout << "\nUso: BuscaBinaria [cep] [arquivo]" << endl;
        return 1;
    }

    arquivoCEP = fopen(argv[2],"r");
    fseek(arquivoCEP,0,SEEK_END);
    tamArquivo = ftell(arquivoCEP);
    cout << "\nTamanho do arquivo:  " << tamArquivo << endl;
    qtdRegistro = tamArquivo/tamRegistro;
    cout << "\nQuantidade de registros:  " << qtdRegistro << endl;
    fseek(arquivoCEP,0,SEEK_SET);       //rewind(arquivoCEP);
    primeiro = ftell(arquivoCEP);
    ultimo = qtdRegistro-1;
    meio = (primeiro+ultimo)/2;
    fseek(arquivoCEP,meio*tamRegistro,SEEK_SET);
    fread(&endereco,tamRegistro,1,arquivoCEP);
    while(cepFound!=true&&primeiro<ultimo){
        cepIntArg = atoi(argv[1]);
        cepIntEnd = atoi(endereco.cep);
        if(cepIntArg==cepIntEnd){
            qtdCompares++;
            cepFound = true;
        }
        else if(cepIntArg>cepIntEnd){
            qtdCompares++;
            primeiro = meio;
            meio = (primeiro+ultimo)/2;
            fseek(arquivoCEP,meio*tamRegistro,primeiro);
            fread(&endereco,tamRegistro,1,arquivoCEP);
        }
        else if(cepIntArg<cepIntEnd){
            qtdCompares++;
            ultimo = meio;
            meio = (primeiro+ultimo)/2;
            fseek(arquivoCEP,meio*tamRegistro,primeiro);
            fread(&endereco,tamRegistro,1,arquivoCEP);
        }
    }
    if(cepFound!=true){
            cout << "\nO CEP nao foi encontrado." << endl;
        }
    else{
        printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",endereco.logradouro,endereco.bairro,endereco.cidade,
    endereco.estado,endereco.siglaEstado,endereco.cep);
    }
    cout << "\nQuantidade de comparacoes:  " << qtdCompares << endl;

    fclose(arquivoCEP);

    return 0;
}

