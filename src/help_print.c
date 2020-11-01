#include "test.h"

static char help_print(int i)
{
	switch (i) {
		case FLAG_LWR_L:
			return 'l';
		case FLAG_ONE:
			return '1';
		case FLAG_LWR_M:
			return 'm';
		case FLAG_UPR_A:
			return 'A';
		case FLAG_LWR_A:
			return 'a';
		case FLAG_LWR_D:
			return 'd';
		case FLAG_UPR_R:
			return 'R';
		case FLAG_LWR_F:
			return 'f';
		case FLAG_LWR_R:
			return 'r';
		case FLAG_UPR_S:
			return 'S';
		case FLAG_LWR_T:
			return 't';
		case FLAG_LWR_C:
			return 'c';
		case FLAG_LWR_U:
			return 'u';
		case FLAG_UPR_U:
			return 'U';
		case FLAG_UPR_T:
			return 'T';
		case FLAG_UPR_F:
			return 'F';
		case FLAG_LWR_P:
			return 'p';
		case FLAG_LWR_N:
			return 'n';
		case FLAG_LWR_O:
			return 'o';
		case FLAG_LWR_G:
			return 'g';
		case FLAG_LWR_I:
			return 'i';
		case FLAG_LWR_K:
			return 'k';
		case FLAG_LWR_S:
			return 's';
		case FLAG_LWR_H:
			return 'h';
		case 31:
			return 'X';
		default:
			return '-';
	}
}

static void print_flag(unsigned f)
{
	int		i;

	i = 31;
	while (i >= 0)
	{
		printf("%d", (f & 1 << i ? 1 : 0));
		if (i && !(i % 8))
			printf("_");
		i--;
	}
	printf("\n");
	i = 31;
	while (i >= 0)
	{
		printf("%c", help_print(i));
		if (i && !(i % 8))
			printf("_");
		i--;
	}
	printf("\n");
}

static void print_heap(t_heap *heap)
{
	int i;
	t_item	*item = NULL;

	if (heap) item = heap->item;
	if (item)
	{
		printf("%d %d %d\n", heap->first, heap->last, heap->size);
		if (item->arg)
		{
			i = 0;
			while (i < heap->last)
			{
				if ((item + i)->arg)
					printf("%s\n", (item + i)->arg);
				i++;
			}
		}
		printf("\n");
		if (item->out)
		{
			i = 0;
			while (i < heap->last)
			{
				if ((item + i)->out)
					printf("%s\n", (item + i)->out);
				i++;
			}
		}
	}
	else
		printf("Empty heap\n");
}

static void print_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		print_heap(tmp->data);
		tmp = tmp->next;
	}
}

void	print(t_ls *ls)
{
	print_flag(ls->flags);
	printf("Count of args: %d ", ls->count);
	printf("Status: %d\n", ls->exit);
	print_stack(ls->stack);
}