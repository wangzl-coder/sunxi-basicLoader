#include "extra_string.h"


void *memset(void *s, int val, unsigned int count)
{
	char * tmp = NULL;

	if(s == NULL)
		return NULL;

	tmp = (char *) s;
	while(count--)
		*tmp++ = val;

	return s;

}
