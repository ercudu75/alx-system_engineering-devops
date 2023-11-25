#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * infinite_while - infinite loop
 *
 * Return: always 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - entry point for program
 *
 * Return: always 0
 */
int main(void)
{
	int i, pid;
	int status = 0;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{
			printf("Zombie process created, PID: %d\n", getpid());
			exit(0);
		}
		else
			wait(&status);
	}
	infinite_while();
	return (0);
}
