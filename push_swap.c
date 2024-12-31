#include "ft_stack.h"
#include "libft.h"

int main(int argc, char *argv[])
{
	t_stack stack;
	int	count;

	count = 1;
	stk_init(&stack);
	if(argc > 1)
	{
		if(!ft_handle_argument(argc, argv, &stack))
		{
			ft_printf("Error!\n");
			return (0);
		}
	}
	else
		ft_printf("Error!\n");
	return (0);
}
