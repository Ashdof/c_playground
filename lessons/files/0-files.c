#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp = fopen("0-file.txt", "w");

	// file procesing begins
	
	fprintf(fp, "%s", "Hello, World! I just created a new text file");
	
	// end of file processing

	fclose(fp);

	return (EXIT_SUCCESS);
}
