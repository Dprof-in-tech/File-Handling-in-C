#include <stdio.h>
#include <time.h>

#define MAX_LENGTH 1000
/**
 * main - Main function to read from and write to a file
 *
 * Return: Always 0 success
 */

int main()
{
	char line[MAX_LENGTH];
	FILE *file;
	int timer = 0;
	time_t start_time = time(NULL);

	file = fopen("hello.txt", "w");
	printf("Write something....... anything....You have 20 seconds\nOnce you finsh typing, hit the enter key to print!!\n");

	while (timer < 20)
	{
		fgets(line, MAX_LENGTH, stdin);
		fputs(line, file);
		timer = (int)(time(NULL) - start_time);

		if (timer >= 20)
		{
			printf("\nTime's up!\nBelow is your written text\n");
			break;
		}
	}

	fclose(file);

	file = fopen("hello.txt", "r");
	rewind(file);

	while (fgets(line, MAX_LENGTH, file) != NULL)
	{
		printf("\n%s\n", line);
	}

	fclose(file);

	return 0;
}
