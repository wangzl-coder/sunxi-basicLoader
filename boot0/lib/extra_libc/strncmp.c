#include "extra_string.h"


int strncmp(const char *s1, const char *s2, unsigned int count)
{
	int val;
	const char *tmp_s1 = NULL;
	const char *tmp_s2 = NULL;
	if(s1 == NULL || s2 == NULL)
	{
		return -1;
	}
	tmp_s1 = s1;
	tmp_s2 = s2;
	while(count--)
	{
		if((val = *tmp_s1 - *tmp_s2++) != 0 || *tmp_s1++ == 0)
		{
			break;
		}
	}

	return val;

}
