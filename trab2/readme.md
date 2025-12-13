# Compressão de pgm com variância
O programa implementa um algoritmo simples de variância dos pixels de uma imagem no formato **PGM (Portable Gray Map)**.
Ele calcula a variância dos pixels da imagem PGM dentro da pasta **`images`** ,e de suas subdivisões, e compara com um limiar pré-definido e as informações em um arquivo chamado `bitstream.chama`.
E descomprime o `bitstream.chama` e reconstrói a imagem dentro da subpasta **`results`**.
> [!Warning]
> Para compilar e executar corretamente, as seguintes pastas devem possuir os arquivos requeridos:


# Compressão de PGM com Variância

O programa implementa um algoritmo de compressão de imagens no formato **PGM (Portable Gray Map)** baseado na variância dos pixels.

Ele calcula a variância de regiões da imagem dentro da pasta `images` (e subpastas), compara com um limiar pré-definido e gera um arquivo binário comprimido chamado `bitstream.chama`. Em seguida, o programa descomprime esse arquivo e reconstrói a imagem na subpasta `results` para verificação.

## 📂 Estrutura de Diretórios

> [!Warning]
> **Estrutura de Arquivos Obrigatória**
> Para compilar e executar corretamente, seu projeto deve estar organizado exatamente nesta estrutura de pastas:
>
> ```text
> .
> ├── main.c               # Arquivo principal (ponto de entrada)
> ├── Makefile             # Arquivo para o comando make
> ├── decoder/
> │   ├── decoder.c
> │   └── decoder.h
> ├── encoder/
> │   ├── encoder.c
> │   └── encoder.h
> ├── pgm/
> │   ├── pgm.c
> │   └── pgm.h
> └── images/
>     ├── <imagem_entrada>.pgm        # Suas imagens de entrada (ex: img01.pgm)
>     └── results/         # Subpasta para os arquivos reconstruídos
> ```


# Compilação
Utilize o comando abaixo para gerar o executável `prog.exe` e os arquivos objetos:
```
make
```
Utilize o comando abaixo para excluir os arquivos objetos e o `prog.exe`:
```
make clean
```

# Execução
O programa recebe por linha de comando a **imagem de entrada** e o **nome da imagem reconstruída**, nesse formato:
```
./prog.exe images/img01.pgm images/results/chama.pgm
```
Essa linha de comando vai gerar um arquivo `bitstream.chama` que é a imagem `img01.pgm` da pasta `images` comprimida e em seguida vai gerar a imagem reconstruída desse arquivo nomeada de `chama.pgm` dentro da subpasta `results`.