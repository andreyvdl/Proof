# EN-US

> Assignment name  : sort_list   
> Expected files   : sort_list.c   
> Allowed functions:   
> 
> --------------------------------------------------------------------------------   
> 
> Write the following functions:   
> 
> `t_list	*sort_list(t_list* lst, int (*cmp)(int, int));`   
> 
> This function must sort the list given as a parameter, using the function   
> pointer cmp to select the order to apply, and returns a pointer to the   
> first element of the sorted list.   
> 
> Duplications must remain.   
> 
> Inputs will always be consistent.   
> 
> You must use the type t_list described in the file list.h   
> that is provided to you. You must include that file   
> (#include "list.h"), but you must not turn it in. We will use our own   
> to compile your assignment.   
> 
> Functions passed as cmp will always return a value different from   
> 0 if a and b are in the right order, 0 otherwise.   
> 
> For example, the following function used as cmp will sort the list   
> in ascending order:   
> 
> ```c
> int ascending(int a, int b)   
> {   
> 	return (a <= b);   
> }   
> ```

# PT-BR

> Assignment name  : sort_list   
> Expected files   : sort_list.c   
> Allowed functions:   
> 
> --------------------------------------------------------------------------------   
>
> Escreva as seguintes funções:   
> 
> `t_list	*sort_list(t_list* lst, int (*cmp)(int, int));`   
>
> Esta função deve ordenar a lista dada como parâmetro, usando o ponteiro de   
> função cmp para selecionar a ordem a ser aplicada, e retorna um ponteiro   
> para o primeiro elemento da lista ordenada.   
>
> Duplicatas devem permanecer.   
>
> Entradas sempre serão consistentes.   
>
> Você deve usar o tipo t_list descrito no arquivo list.h   
> que é fornecido a você. Você deve incluir esse arquivo   
> (#include "list.h"), mas não deve entregá-lo. Usaremos o nosso próprio   
> para compilar sua tarefa.   
>
> Funções passadas como cmp sempre retornarão um valor diferente de   
> 0 se a e b estiverem na ordem correta, caso contrário 0.   
>
> Por exemplo, a seguinte função usada como cmp ordenará a lista   
> em ordem crescente:   
> 
> ```c
> int ascending(int a, int b)   
> {   
> 	return (a <= b);   
> }   
> ```
