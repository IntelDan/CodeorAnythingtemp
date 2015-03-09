#include <stdio.h>


int generate_txt_name(char *strFileName)
{
    time_t tCurrentTime;
	struct tm *tmnow;
	time(&tCurrentTime);
	tmnow   = localtime(&tCurrentTime);

    return sprintf(strFileName, "%04d%02d%02d%02d%02d%02d.txt",
        tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday, tmnow->tm_hour,
        tmnow->tm_min, tmnow->tm_sec);
}

int main()
{
    char *strFilename[100] = {0};
    generate_txt_name(strFileName);
    printf("%s\n", strFileName);
}