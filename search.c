#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>

const char *target_filename;

// Callback chamado para cada arquivo/diretório encontrado
int search_callback(const char *path, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    (void) sb;    // Evita warnings (parâmetro não usado)
    (void) ftwbuf; // Evita warnings (parâmetro não usado)

    // Pega apenas o nome do arquivo/diretório (depois da última '/')
    const char *filename = strrchr(path, '/');
    if (filename) filename++; // Pula a barra '/'

    // Verifica se o nome do arquivo/diretório é o que estamos procurando
    if (filename && strcmp(filename, target_filename) == 0) {
        printf("%s\n", path);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s [nome do arquivo] ou {Pasta}\n", argv[0]);
        return 1;
    }

    target_filename = argv[1];

    printf("Buscando por '%s'...\n", target_filename);
    nftw("/", search_callback, 20, FTW_PHYS | FTW_DEPTH); // Agora busca diretórios também!

    return 0;
}

