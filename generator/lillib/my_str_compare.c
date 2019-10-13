/*
** EPITECH PROJECT, 2018
** lib
** File description:
** str_compare
*/

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

int my_str_compare(char *src, char *to_compare)
{
	int i = 0;

	if (my_strlen(src) != my_strlen(to_compare))
		return (1);
	while (src[i] != '\0') {
		if (src[i] != to_compare[i])
			return (1);
		i += 1;
	}
	return (0);
}
