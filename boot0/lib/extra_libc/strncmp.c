#include "extra_string.h"


int strncmp(const char *s1, const char *s2, unsigned int count)
{
	int val;

	while(count--)
	{
		if((val = *s1 - *s2++) != 0 || *s1++ == 0)
		{
			break;
		}
	}

	return val;

}
