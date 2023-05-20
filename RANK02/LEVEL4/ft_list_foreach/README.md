# EN-US

> Assignment name  : ft_list_foreach   
> Expected files   : ft_list_foreach.c, ft_list.h   
> Allowed functions:   
> 
> --------------------------------------------------------------------------------   
> 
> Write a function that takes a list and a function pointer, and applies this   
> function to each element of the list.   
> 
> It must be declared as follows:   
> 
> `void    ft_list_foreach(t_list *begin_list, void (*f)(void *));`
> 
> The function pointed to by f will be used as follows:   
> 
> `(*f)(list_ptr->data);`   
> 
> You must use the following structure, and turn it in as a file called   
> ft_list.h:   
>
> ```c
> typedef struct    s_list
> {
>     struct s_list *next;
>     void          *data;
> }                 t_list;
> ```

# PT-BR

> Assignment name  : ft_list_foreach   
> Expected files   : ft_list_foreach.c, ft_list.h   
> Allowed functions:   
> 
> --------------------------------------------------------------------------------   
>
> Escreva uam função que recebe uma lista e um ponteiro de função, e aplica   
> esta função a cada elemento da lista.   
>
> Ela deve ser declarada da seguinte forma:   
> 
> `void    ft_list_foreach(t_list *begin_list, void (*f)(void *));`
>
> A função apontada por f será usada da seguinte forma:   
> 
> `(*f)(list_ptr->data);`   
>
> Você deve usar a seguinte estrutura, e entregar como um arquivo chamado   
> ft_list.h:   
>
> ```c
> typedef struct    s_list
> {
>     struct s_list *next;
>     void          *data;
> }                 t_list;
> ```
