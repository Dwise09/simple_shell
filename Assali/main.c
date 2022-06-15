#include "shell.h"

/**
 * main - start shell
 *
 * Return: void
 */

/**
 * == changes ==
 * 1. added variable to hold exit status
 * 2. returns exit status or 0 if successful
 */

int main(void)
{
int return_value;
/* return value */
	
return_value = prompt();
	
if (return_value != 0)
	return (return_value);

return (0);
}
