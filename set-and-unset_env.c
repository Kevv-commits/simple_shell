#include "main.h"

/**
 * _setenv - set environment variable
 * @sev: struct of shell variable
 * Return: void
 */

void _setenv(sev_t *sev)
{
list_t **mt = &(sev->mem);
char **av = sev->p_input;
char *variabl, *value, *new;

variabl = av[1];
value = av[2];

if (variabl && value)
{
	new = _strcat(variabl, "=", mt);
	new = _strcat(new, value, mt);

if (!_setenv_helper(sev, variabl, value))
	add_node(&(sev->env), NULL, _strdup(new, mt));
}
else
{
	sev->errmsg = "Usage: setenv VARIABLE VALUE\n";
	sev->error = 1;
}
}

/**
 * _unsetenv - rmv env var
 * @sev: struct of shell vars
 * Return: void
 */

void _unsetenv(sev_t *sev)
{
list_t *ev = sev->env;
unsigned int i = 0, index_count = 0, found = 0;
char **av = sev->p_input;
char *variabl, *envar;

variabl = av[1];

	if (variabl)
{
	for (; ev; ev = ev->next)
	{
	  envar = ev->value;
	for (i = 0; i < _strlen(variabl); i++)
	{
		if (variabl[i] != envar[i])
			break;
	}
		if (!variabl[i])
	{
	      found = 1;
		break;
}
	  index_count++;
	}

if (found)
	delete_node_at_index(&(sev->env), index_count);
else
	{
	  sev->errmsg = "Unable to find VARIABLE\n";
	  sev->error = 1;
	}
}
else
{
sev->errmsg = "Usage: unsetenv VARIABLE\n";
sev->error = 1;
}
}
