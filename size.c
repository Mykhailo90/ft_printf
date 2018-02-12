 #include "ft_printf.h"

int 	is_it_size(char ch)
{
	if (ch == 'j' || ch == 'L' || ch == 'z' || ch == 't' || ch == 'h' ||
		ch == 'l')
		return (1);
	else
		return (0);
}

size_t 	len_s(char *str)
{
	size_t i;

	i = 0;
	while (is_it_size(str[i]))
		i++;
	return (i);
}

int search_hh(t_list *commands, char *str)
{
	int i;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		if (commands->size)
			commands->size = ft_strjoin(commands->size, "1");
		else
		{
			commands->size = ft_memalloc(sizeof(char) * 2);
			commands->size[0] = '1';
		}
		return (1);
	}
	return (0);
}

int search_ll(t_list *commands, char *str)
{
	int i;

	i = 0;
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		if (commands->size)
			commands->size = ft_strjoin(commands->size, "2");
		else
		{
			commands->size = ft_memalloc(sizeof(char) * 2);
			commands->size[0] = '1';
		}
		return (1);
	}
	return (0);
}

void search_size(t_list *commands, char *str)
{
	int i;
	char tmp [2];

	i = 0;
	tmp[1] = '\0';
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (is_it_size(str[i]) && (search_hh(commands, &str[i]) ||
			search_ll(commands, &str[i])))
				i++;
		else if (is_it_size(str[i]))
		{
			tmp[0] = str[i];
			if (commands->size)
				commands->size = ft_strjoin(commands->size, tmp);
			else
			{
				commands->size = ft_memalloc(sizeof(char) * 2);
				commands->size[0] = str[i];
			}
		}
		i++;
	}
}
