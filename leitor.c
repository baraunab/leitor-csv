#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *arquivo = argv[1];
    
    FILE *fp = fopen(arquivo, "r");
    char *linha = NULL;
    size_t tam = 0;
    ssize_t leitura;

    if(fp == NULL) {
        printf("erro na abertura de arquivo!!");
        return 1;
    }

    while(leitura = getline(&linha, &tam, fp) != -1) {
        printf("%s", linha);
    }

    free(linha);
    fclose(fp);

}
