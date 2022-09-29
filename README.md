# Minitalk

Этот проект состоит из:
 - Сервер, который получает данные в двоичном формате
 - Клиент, который принимает строку в качестве аргумента, переводит ее в двоичный формат и отправляет на сервер.

Данные отправляются с клиента на сервер с помощью [UNIX сигналов SIGUSR1 и SIGUSR2](https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html).

## Требования

 - [Дистрибутив Linux](https://en.wikipedia.org/wiki/Linux_distribution)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)
 

# Minitalk

This project consists of:
 - A server that receives data in binary format
 - A client that takes a string as argument, translates it to binary & sends it to the server

The data is sent from the client to the server using [UNIX signals SIGUSR1 & SIGUSR2](https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html).

## Requirements

 - [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)
