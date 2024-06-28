# MINISERV

## FUNCTIONS/FUNÇÃO

```txt
write, close, select, socket, accept, listen, send, recv, bind, strstr, strlen
strcpy, strcat, memset, bzero, malloc, realloc, free, calloc, atoi, exit,
sprintf, htons and htonl
```

## DESCRIPTION/DESCRIÇÃO

Write a program that will listen for client to connect on a certain port on
127.0.0.1 and will let clients to speak with each other.  
This program will take as first argument the port to bind to.

If no argument is given, it should write in stderr "Wrong number of arguments"
followed by a \n and exit with status 1  
If a System Calls returns an error before the program start accepting
connection, it should write in stderr "Fatal error" followed by a \n and exit
with status 1  
If you cant allocate memory it should write in stderr "Fatal error" followed by
a \n and exit with status 1

Your program must be non-blocking but client can be lazy and if they don't read
your message you must NOT disconnect them...  
Your program must not contains #define preproc  
Your program must only listen to 127.0.0.1  
The fd that you will receive will already be set to make 'recv' or 'send' to
block if select hasn't be called before calling them, but will not block
otherwise.  

The client will be given an id.  
The first client will receive the id 0 and each new client will received the
last client id + 1  
%d will be replace by this number  
A message is sent to all the client that was connected to the server: "server:
client %d just arrived\n"  
Clients must be able to send messages to your program.  
Message will only be printable characters, no need to check  
A single message can contains multiple \n  
When the server receive a message, it must resend it to all the other client
with "client %d: " before every line!  
When a client disconnect from the server:  
A message is sent to all the client that was connected to the server: "server:
client %d just left\n"  
Memory or fd leaks are forbidden

Escreva um programa que vai esperar um cliente conectar em uma certa porta em
127.0.0.1 and vai permitir que clientes se cominuquem.
Este programa tem como primeiro argumento a porta para se conectar.

Se nenhum argumento foi dado, deve escrever no stderr "Wrong number of
arguments" seguido de um \n e saia com status 1  
Se uma System Calls retornar um erro antes do programa começar a aceitar
conexão, deve escreve no stderr "Fatal error" seguido por um \n e saia com
status 1  
Se vocẽ não pode alocar memória deve escrever no stderr "Fatal error" seguido
por um \n e saia com status 1

Seu programe deve ser não-bloqueante mas o cliente pode ser preguiçoso e se eles
não lerem sua mensagem você NÃO deve disconectar eles...  
Seu programa não deve conter #define preproc  
Seu programa só deve escutar a 127.0.0.1  
O fd que você vai receber já foi feito para fazer 'recv' ou 'send' bloquear se
select não foi chamado antes de chamar eles, mas não bloqueará caso contrário.

O client deve receber um id.  
O primeiro cliente vai receber um id 0 e cada novo cliente vai receber o último
cliente id + 1  
%d vai substituir esse número  
Uma mensagem é enviada para todos os clientes que estão conectados no server:
"server: client %d just arrived\n"  
Clientes devem ser capazes de mandar mensagens para seu programa.  
Mesagem vai ter somente caracteres printaveis, não precisa checar  
Uma mensagem pode conter multiplos \n  
Quando um cliente desconecta do server:  
Uma mensagem é enviada para todos os clientes conectados no server: "server:
client %d just left\n"  
Vazamentos de memória ou fd são proibidos
