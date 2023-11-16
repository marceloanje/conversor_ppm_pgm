## Conversor de Imagem para Tons de Cinza

### Descrição

Este trabalho prático explora os conceitos fundamentais do desenvolvimento em linguagem C/C++, com foco na implementação de um programa para converter imagens coloridas (formato PPM) para tons de cinza (formato PGM). A conversão é realizada através da obtenção das componentes vermelha, verde e azul de cada pixel (no espaço de cores RGB) e, em seguida, aplicando uma fórmula para calcular o tom de cinza correspondente. 

### Principais Funcionalidades

- **Conversão de Imagem:** Transformação de imagens no formato PPM para tons de cinza no formato PGM usando a fórmula padrão.

---

### Complexidade Temporal e Espacial

#### Complexidade Temporal

A complexidade temporal do programa é \( O(n^2) \), onde \( n \) representa o número de pixels na imagem. Isso significa que o tempo de execução do programa aumenta quadrativamente à medida que o número de pixels aumenta.

#### Complexidade Espacial

A complexidade espacial do programa é \( O(n^2) \), refletindo que a quantidade de memória necessária para processar a imagem cresce quadrativamente com o número de pixels.

Essas métricas de complexidade oferecem insights valiosos sobre o desempenho do programa à medida que o tamanho da imagem aumenta.

---

### Instruções de Execução

Para compilar e executar este programa, siga estas etapas:

#### Requisitos

Certifique-se de ter os seguintes requisitos instalados no seu sistema:

- **GCC**: Um compilador C++ para compilar o código.
- **Make**: Uma ferramenta de automação de compilação.

#### Passos

1. **Clone o Repositório**
   ```bash
   git clone https://github.com/marceloanje/conversor_ppm_pgm.git
   ```

2. **Navegue até a pasta do Projeto**
   ```bash
   cd conversor_ppm_pgm
   ```

3. **Compilação e Exucução**       
   Execute o comando make na pasta raiz do projeto para compilar e executar o código.
   ```bash
   make
   ```

---

### Mais Detalhes

Um documento PDF contendo detalhes adicionais sobre o sistema está disponível [aqui](). Esse documento oferece uma visão mais abrangente do projeto, incluindo descrições detalhadas, especificações técnicas e outras informações relevantes.
