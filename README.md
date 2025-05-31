# 🦉 Criação de Corujas

Implementação em **C** de um jogo onde o objetivo é gerenciar a criação de corujas dentro de uma caverna.

Projeto desenvolvido como trabalho final da disciplina **ECOP01**.

## 🕹 Descrição do Jogo

O jogo se passa em uma **caverna**, onde durante a noite **morcegos** surgem aleatoriamente e tentam atacar suas corujas. Conforme as noites passam (rounds), o ambiente se transforma, com o crescimento de **estalagmites**, **bagas (plantas)** e **rochas**.

### Objetivo

* **Eliminar todos os morcegos**.
* **Fazer com que as corujas se reproduzam** com sucesso.

### Mecânicas Principais

* A cada **7 noites**, ocorre um **round extra (dia)**, sem aparecimento de morcegos.
* Corujas podem **procriar** caso estejam próximas e exista um **ninho**.
* O jogador pode **colher bagas** e usar **fertilizantes** para aumentá-las.
* Bagas podem ser **gastas para construir ninhos**.
* **Três corujas cercando um morcego** (em qualquer uma das 8 direções ao redor) **o derrotam**.
* Morcegos podem **destruir ninhos** e **atacar corujas**.

### Condição de Vitória

* O jogador vence quando **não houver mais morcegos** na caverna.

## 🧾 Requisitos

Para executar este projeto, é necessário:

### ✅ Ambiente de Compilação

* Compilador **C** (ex: `gcc` ou `clang`)
* Sistema operacional com suporte a terminal (Linux, macOS ou Windows com terminal)

### 📁 Arquivo Principal

* `Corujas.c`

## ▶️ Como Compilar e Executar

### Usando GCC (Linux/macOS/Windows com MinGW):

```bash
# Compilando
gcc -o corujas Corujas.c

# Executando
./corujas
```

## 🧠 Conceitos Aplicados

* Manipulação de matrizes
* Controle de fluxo e lógica de jogos
* Modularização de código em C
* Estruturas condicionais e laços
* Sistema de turnos e eventos aleatórios

## 🎓 Sobre

Este projeto foi desenvolvido como trabalho final da disciplina **ECOP01** no curso de **Engenharia da Computação** da **Universidade Federal de Itajubá (UNIFEI)**.
