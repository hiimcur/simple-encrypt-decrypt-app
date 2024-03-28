#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <logLib.h>

int main()
{

    int logLevel = 0;
    printf("Select log level: ");
    scanf("%d", &logLevel);

    setLogLevel(logLevel); 

    debugLog("This is a debug message.\n");
    infoLog("This is an info message.\n");
    warningLog("This is a warning message.\n");
    errorLog("This is an error message.\n");

    return 0;
}