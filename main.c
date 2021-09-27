#include	<stdio.h>
#include	<errno.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>

#define BUFFER_SIZE		4096

extern int	errno;

size_t			ft_strlen(const char *str);
ssize_t			ft_write(int fd, void *buf, unsigned int nbyte);
ssize_t			ft_read(int fd, void *buf, unsigned int nbyte);
char			ft_strcpy(char *dest, char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(char *str);

int	main(void)
{
	int			fd;
	int			ret_read;
	int			ret_ft_read;
	char		*strdupped = NULL;
	char		buffer[2 * BUFFER_SIZE + 1];
	char		big_buffer[10 * BUFFER_SIZE + 1];
	char		*strings[] = 
	{
		"", "Salam aleykum\n", "ooooooooochen' dlinnyi tekst\n", NULL
	};

	fd = open("main.c", O_RDONLY);


	printf("\n******************** FT_STRLEN CHECK ********************\n");
	for (int i = 0; strings[i]; i++)
	{
		printf("%4zu strlen, %4zu ft_strlen\n",
			strlen(strings[i]), ft_strlen(strings[i]));
	}
	ret_read = read(fd, big_buffer, 10 * BUFFER_SIZE);
	big_buffer[ret_read] = '\0';
	printf("%4zu strlen, %4zu ft_strlen\n\n",
		strlen(big_buffer), ft_strlen(big_buffer));
	close(fd);

	printf("\n******************** FT_STRCPY CHECK ********************\n");
	ft_strcpy(buffer, big_buffer);
	printf("ft_strcpy with a very long string:\n%s\n\n", buffer);
	ft_strcpy(buffer, "nu privet\n");
	ft_strcpy(buffer, "");
	printf("ft_strcpy with an empty string: \"%s\"\n\n", buffer);


	printf("\n******************** FT_STRCMP CHECK ********************\n");
	printf("%4d strcmp %4d ft_strcmp with empty strings\n", 
		strcmp("", ""), ft_strcmp("", ""));
	printf("%4d strcmp %4d ft_strcmp with an empty string as a first arg\n",
		strcmp("", "abc"), ft_strcmp("", "abc"));
	printf("%4d strcmp %4d ft_strcmp with an empty string as a second arg\n",
		strcmp("xyz", ""), ft_strcmp("xyz", ""));
	printf("%4d strcmp %4d ft_strcmp with equal strings\n", 
		strcmp(buffer, buffer), ft_strcmp(buffer, buffer));


	printf("\n******************** FT_WRITE CHECK *********************\n");
	printf("%4ld write %4ld ft_write – return values, print in stdout\n",
		write(1, strings[1], ft_strlen(strings[1])),
		ft_write(1, strings[1], ft_strlen(strings[1])));
	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC);
	printf("%4ld write %4ld ft_write – return values, print in file\n",
		write(fd, strings[2], ft_strlen(strings[2])),
		ft_write(fd, strings[2], ft_strlen(strings[2])));
	printf("%4ld write %4ld ft_write – return values, bad fd\n\n",
		write(-21, strings[1], ft_strlen(strings[1])),
		ft_write(-21, strings[1], ft_strlen(strings[1])));
	errno = 0;
	perror("When errno = 0: ");
	write(-21, strings[1], ft_strlen(strings[1]));
	perror("Errno after bad fd write: ");
	errno = 0;
	ft_write(-21, strings[1], ft_strlen(strings[1]));
	perror("Errno after bad fd ft_write: ");


	printf("\n********************* FT_READ CHECK *********************\n");
	printf("Type something for read()\n");
	ret_read = read(0, buffer, BUFFER_SIZE);
	buffer[ret_read] = '\0';
	printf("\nString: \"%s\", return value: %d\n\n", buffer, ret_read);
	
	printf("Type something for ft_read()\n");
	ret_ft_read = ft_read(0, buffer, BUFFER_SIZE);
	buffer[ret_ft_read] = '\0';
	printf("\nString: \"%s\", return value: %d\n\n", buffer, ret_ft_read);

	lseek(fd, 0, SEEK_SET);
	printf("Text was read from \"test.txt\" with read()");
	ret_read = read(fd, buffer, BUFFER_SIZE);
	buffer[ret_read] = '\0';
	printf("\nText: \n%s\n, return value: %d\n\n", buffer, ret_read);
	
	lseek(fd, 0, SEEK_SET);
	printf("Text was read from \"test.txt\" with ft_read()");
	ret_ft_read = ft_read(fd, buffer, BUFFER_SIZE);
	buffer[ret_ft_read] = '\0';
	printf("\nText: \n%s\n, return value: %d\n\n", buffer, ret_ft_read);

	printf("Return values with bad fds and errno printing\n");
	errno = 0;
	ret_read = read(-21, buffer, BUFFER_SIZE);
	perror("Errno after bad fd read: ");
	errno = 0;
	ret_ft_read = ft_read(-21, buffer, BUFFER_SIZE);
	perror("Errno after bad fd ft_read: ");
	printf("Return values: %4d read %4d ft_read\n\n", ret_read, ret_ft_read);
	close(fd);


	printf("\n******************** FT_STRDUP CHECK ********************\n");
	strdupped = strdup("");
	printf("Strdup with an empty string: \"%s\"\n", strdupped);
	free(strdupped);
	strdupped = ft_strdup("");
	printf("Ft_strdup with an empty string: \"%s\"\n\n", strdupped);
	free(strdupped);

	fd = open("main.c", O_RDONLY);
	ret_ft_read = ft_read(fd, big_buffer, BUFFER_SIZE * 10);
	big_buffer[BUFFER_SIZE * 10] = '\0';
	strdupped = ft_strdup(big_buffer);
	printf("Printing a very long string with ft_strdup:\n%s", strdupped);
	free(strdupped);
	close(fd);
}
