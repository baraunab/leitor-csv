#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct {
    char nome[MAX];
    char codigo[MAX];
} Municipio;

int main(int argc, char *argv[]) {
    char *arquivo = argv[1];

    FILE *fp = fopen(arquivo, "r");

    if(fp == NULL) {
        printf("erro na abertura de arquivo!!");
        return 1;
    }

    char registro[256];
    Municipio municipio[62];
    memset(municipio, 0, sizeof(municipio));

    for (int i = 0; i < 62; i++) {
        fgets(registro, sizeof(registro), fp);
        sscanf(registro, "%[^,],%s", municipio[i].nome, municipio[i].codigo);
        printf("%s | %s\n", municipio[i].nome, municipio[i].codigo);
    }

    fclose(fp);
}
