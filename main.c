#include	<stdio.h>

unsigned int	ft_strlen(char *str);

int	main(void)
{
	const char	*str = "salam aleykum";
	printf("%d ft_strlen\n", ft_strlen((char *)str));
}
