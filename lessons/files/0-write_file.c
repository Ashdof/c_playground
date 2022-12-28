#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp = fopen("0-write_file.txt", "w");
	char *data;

	data = "Hello World! I just created a new text file.\nIt's so awesome!!!\n";

	// file procesing begins
	
	fprintf(fp, "%s", data);
	
	// end of file processing

	fclose(fp);

	return (EXIT_SUCCESS);
}
