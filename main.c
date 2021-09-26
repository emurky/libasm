#include	<stdio.h>
#include	<errno.h>
#include	<fcntl.h>
#include	<unistd.h>
#define BUFFER_SIZE		42

extern int	errno;

unsigned int	ft_strlen(char *str);
int				ft_write(int fd, void *buf, unsigned int nbyte);
int				ft_read(int fd, void *buf, unsigned int nbyte);
char			ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*str = "salam aleykum\n";
	char	buffer[BUFFER_SIZE + 1];
	int		fd = open("ft_strlen.s", O_RDONLY);
	
	buffer[BUFFER_SIZE] = '\0';
	printf("%d ft_strlen\n", ft_strlen((char *)str));
	ft_write(1, "\n", 1);

	ft_write(1, str, ft_strlen(str));
	perror("ft_write test");
	ft_write(1, "\n", 1);

	errno = 0;

	ft_read(fd, buffer, BUFFER_SIZE);
	ft_write(1, buffer, BUFFER_SIZE);
	ft_write(1, "\n", 1);
	perror("ft_read test");
	ft_write(1, "\n", 1);

	ft_strcpy(buffer, "salam aleykum\n");
	ft_write(1, buffer, ft_strlen(buffer));
}
