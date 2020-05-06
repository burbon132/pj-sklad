#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "tovar.h"
#include "List.h"
int main()
{
    time_t rawtime;
    struct tm* timeinfo;
    timeinfo = localtime(&rawtime);       
    int i = timeinfo->tm_mday;
    int q = timeinfo->tm_mon;
    int j = timeinfo->tm_year;
    // текущая дата, представленная в нормальной форме
    std::cout << i << q << j;
	return 0;
 
}