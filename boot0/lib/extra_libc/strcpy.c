#include "extra_string.h"


char *strcpy(char *dest, const char *src)
{
    char * tmp_dest = NULL;
    const char * tmp_src = NULL;
    if(dest == NULL || src == NULL)
        return NULL;
    
    if(dest == src)
        return dest;

    tmp_dest = dest;
    tmp_src = src;
	while((*tmp_dest++ = *tmp_src++) != '\0');

    return dest;
}
