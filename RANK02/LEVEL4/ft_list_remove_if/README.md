# EN-US

> Assignment name  : ft_list_remove_if   
> Expected files   : ft_list_remove_if.c   
> Allowed functions: free   
> 
> --------------------------------------------------------------------------------   
> 
> Write a function called ft_list_remove_if that removes from the   
> passed list any element the data of which is "equal" to the reference data.   
> 
> It will be declared as follows :   
> 
> `void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());`   
> 
> cmp takes two void* and returns 0 when both parameters are equal.   
> 
> You have to use the ft_list.h file, which will contain:   
>
> ```sh
> $>cat ft_list.h
> typedef struct      s_list
> {
>     struct s_list   *next;
>     void            *data;
> }                   t_list;
> ```

# PT-BR

> Assignment name  : ft_list_remove_if   
> Expected files   : ft_list_remove_if.c   
> Allowed functions: free   
> 
> --------------------------------------------------------------------------------   
>
> Escreva uma função chamada ft_list_remove_if que remove da lista passada   
> qualquer elemento cujos dados sejam "iguais" aos dados de referência.   
>
> Ela será declarada da seguinte maneira :   
> 
> `void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());`   
>
> cmp leva dois void* e retorna 0 quando ambos os parâmetros são iguais.   
>
> Você tem que usar o arquivo ft_list.h, que conterá:   
>
> ```sh
> $>cat ft_list.h
> typedef struct      s_list
> {
>     struct s_list   *next;
>     void            *data;
> }                   t_list;
> ```
