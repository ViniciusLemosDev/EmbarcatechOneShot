# Projeto: Temporizador One-Shot

## Descrição
Este projeto implementa um sistema de temporização para acionamento de LEDs usando um botão de pressão (pushbutton). O código foi desenvolvido em linguagem C, utilizando o Raspberry Pi Pico W e o Pico SDK.

## Desenvolvido por
- Vinicius Lemos de Carvalho 

## 📌 Funcionamento
1. O usuário pressiona o botão conectado ao GPIO 5.
2. Todos os LEDs (azul, vermelho e verde) acendem simultaneamente.
3. Um temporizador inicia uma sequência de desligamento:
   - Após 3 segundos, o LED azul desliga.
   - Após 6 segundos, o LED vermelho desliga.
   - Após 9 segundos, o LED verde desliga.
4. Durante esse processo, o botão não pode ser pressionado novamente até que todos os LEDs estejam apagados.

## 🛠 Componentes Utilizados
- Raspberry Pi Pico W
- 1 × LED vermelho
- 1 × LED azul
- 1 × LED verde
- Resistores de 330Ω
- Botão de pressão 

## Requisitos
- Pico SDK instalado
- Compilador C configurado no VS Code
- Simulador Wokwi.

## 📌 Esquema de ligação (GPIOs)

| LED             | Pino GPIO    |
|-----------------|--------------|
| Vermelho            | 13       |
| Azul                | 12       |
| Verde               | 11       |
| Botão de pressão    | 5        |

## Como Compilar e Executar
1. Clone o repositório:
   ```sh
   git clone https://github.com/ViniciusLemosDev/EmbarcatechOneShot
   cd https://github.com/ViniciusLemosDev/EmbarcatechOneShot
   ```
3. Compile e Execute o código pelo simulador do Wokwi no VSCode.

## Conclusão

Este projeto demonstra o uso de temporizadores e interrupções no Raspberry Pi Pico W para controlar LEDs com base na entrada de um botão. Ele pode servir como base para aplicações mais avançadas envolvendo automação e controle de eventos. Há espaço para melhorias, como a implementação de debounce e otimizações no gerenciamento dos estados dos LEDs.
