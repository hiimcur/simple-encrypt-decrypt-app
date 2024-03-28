#ifndef LOGLEVEL_H
#define LOGLEVEL_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef enum {
    NONE,
    ERROR,
    WARNING,
    INFO,
    DEBUG,
} LogLevel;

extern LogLevel currentLogLevel;

void setLogLevel(LogLevel level);
void debugLog(const char *message, ...);
void infoLog(const char *message, ...);
void warningLog(const char *message, ...);
void errorLog(const char *message, ...);

#endif // LOGLEVEL_H
