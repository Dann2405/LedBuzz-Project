# Sistema de Controle de LEDs RGB e Buzzers com Raspberry Pi Pico

## Descrição do Projeto

Este projeto utiliza o **Raspberry Pi Pico** para controlar LEDs RGB e dois buzzers com base em comandos recebidos via terminal serial (**PuTTY**). O sistema foi desenvolvido em **linguagem C**, configurado para rodar no **VS Code** com o SDK do Raspberry Pi Pico instalado, e pode ser testado tanto em hardware real quanto no simulador **Wokwi**.

---

## Requisitos

- **Microcontrolador**: Raspberry Pi Pico ou Raspberry Pi Pico W.
- **Conta no Simulador wokwi**: [Wokwi](https://wokwi.com/).
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.
- **Putty**

---

## Instruções de Uso

### 1. Clone o Repositório

Clone o repositório para o seu computador:
```bash
git clone https://github.com/Dann2405/LedBuzz-Project.git
cd LedBuzz-Project
```

---

### 2. Instale as Dependências

Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. As extensões recomendadas são:

- **C/C++** (Microsoft).
- **CMake Tools**.
- **Wokwi Simulator**.
- **Raspberry Pi Pico**.

---

### 3. Configure o VS Code

Abra o projeto no Visual Studio Code e siga as etapas abaixo:

1. Certifique-se de que as extensões mencionadas anteriormente estão instaladas.
2. No terminal do VS Code, compile o código clicando em "Compile Project" na interface da extensão do Raspberry Pi Pico.
3. O processo gerará o arquivo `.uf2` na pasta biuld, que é necessário para a execução no hardware da placa de desenvolvimento da BitDogLab.

---

### 4. Teste no Simulador Wokwi Integrado ao VS Code

1. Abra o arquivo `diagram.json` no Visual Studio Code.
2. Clique no botão "Play" disponível na interface.
3. Visualize os LEDs e buzzers respondendo aos comandos enviados.

---

### 5. Teste no Hardware (Placa de desenvolvimento BitDogLab)

#### Passo a passo para utilização na placa de desenvolvimento BitDogLab:

1. Coloque o Raspberry Pi Pico em modo de programação:
   - Pressione o botão BOOTSEL (localizado na parte de trás da placa de desenvolvimento) e, em seguida, o botão RESET (localizado na frente da placa).
   - Após alguns segundos, solte o botão RESET e, logo depois, solte o botão BOOTSEL.
   - A placa entrará no modo de programação.

2. Compile o projeto no VS Code utilizando a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
   - Clique em **Compile Project**.

3. Execute o projeto clicando em **Run Project USB**, localizado abaixo do botão **Compile Project**.

3. Utilize o terminal serial (PuTTY) para enviar os seguintes comandos:
   - **`Verde`**: Liga o LED verde.
   - **`Azul`**: Liga o LED azul.
   - **`Vermelho`**: Liga o LED vermelho.
   - **`Branco`**: Liga todos os LEDs simultaneamente.
   - **`BuzzerA`**: Aciona o buzzer no GPIO 21 por 2 segundos.
   - **`BuzzerB`**: Aciona o buzzer no GPIO 10 por 2 segundos.
  
4. Caso tenha dúvidas sobre como utilizar o Putty, dê uma olhada no video Ensaio, disponível no final dessa documentação.

---

## Funcionamento do Sistema

1. **Comandos via Terminal**:
   - O sistema interpreta strings recebidas via UART e executa as ações correspondentes.

2. **Controle de LEDs RGB**:
   - LEDs são controlados nos GPIOs 11, 12 e 13, permitindo mudanças de cores individuais e simultâneas.

3. **Controle dos Buzzers**:
   - Dois buzzers conectados aos GPIOs 21 e 10 são ativados conforme o comando recebido.

---

## Divisão de Tarefas do Subgrupo

- **Líder do Projeto**:
  - Daniel Soares Oliveira Santos

- **Desenvolvedores**:
  - Wilson Oliveira Lima
  - Ana Carla Macário Santana

---

## Vídeo Ensaio

*(A ser adicionado posteriormente)*
