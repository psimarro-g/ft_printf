

int	ft_nsep(char *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
		if (*str++ == c)
			i++;
	return (i);
}
