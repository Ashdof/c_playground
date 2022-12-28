#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE *file_name;
	char words[1000];

	file_name = fopen("0-write_file.txt", "r");
	printf("%s\n", fgets(words, 500, file_name));

	fclose(file_name);

	return (EXIT_SUCCESS);
}
