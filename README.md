# search

Este script em C tem como objetivo realizar uma busca recursiva por arquivos ou diretórios em todo o sistema de arquivos, localizando um item específico fornecido pelo usuário. O script utiliza a biblioteca `ftw.h` (File Tree Walk) para realizar a varredura dos arquivos e diretórios de forma eficiente.

**Funcionalidade:**

O programa permite que o usuário busque um arquivo ou diretório específico no sistema fornecendo seu nome como argumento. Ao ser executado, o script percorre o sistema de arquivos a partir da raiz (`/`), buscando pelo nome exato do arquivo ou diretório indicado. Caso o item desejado seja encontrado, o caminho completo é impresso na tela.

**Como funciona:**

1. O usuário executa o script fornecendo o nome do arquivo ou diretório como argumento.
2. O script usa a função `nftw` (Network File Tree Walk), que percorre todos os arquivos e diretórios, aplicando a função de callback `search_callback` para cada item encontrado.
3. A função `search_callback` compara o nome de cada arquivo ou diretório com o nome fornecido pelo usuário. Se houver uma correspondência exata, o caminho completo do item é impresso.
4. O script também exibe mensagens informativas, como o nome do arquivo que está sendo buscado e o resultado da busca.

**Características:**

- **Busca recursiva**: O script percorre recursivamente todos os diretórios a partir da raiz (`/`).
- **Eficiência**: Utiliza a função `nftw`, que é otimizada para navegar por grandes estruturas de diretórios.
- **Simplicidade**: Fácil de usar e eficiente para localizar arquivos e diretórios em sistemas de arquivos complexos.
- **Segurança**: A busca é realizada de maneira segura, evitando acessos a arquivos especiais e links simbólicos (via as flags `FTW_PHYS` e `FTW_DEPTH`).

**Exemplo de uso:**

Para buscar por um arquivo ou diretório específico:

```bash
$ gcc -o search search.c -lftw
```

```bash
$ ./search nome_do_arquivo
```
