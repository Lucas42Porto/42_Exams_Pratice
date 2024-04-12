#include <stdlib.h>
//#include "list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int	main(void)
{
	t_list *l1 = (t_list *)malloc(sizeof(t_list));
	t_list *l2 = (t_list *)malloc(sizeof(t_list));
	t_list *l3 = (t_list *)malloc(sizeof(t_list));
	t_list *curr;

	int a = -63;
	int b = 0;
	int c = 87;

	l1->data = a;
	l2->data = b;
	l3->data = c;

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;


	curr = sort_list(l1, &ascending);
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	free(l1);
	free(l2);
	free(l3);
}