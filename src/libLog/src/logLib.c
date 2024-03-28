#include "logLib.h" 

LogLevel currentLogLevel = NONE; 

void setLogLevel(LogLevel level) {
    currentLogLevel = level;
}

void debugLog(const char *message, ...) 
{
    if (currentLogLevel >= DEBUG) {
        va_list args;
        va_start(args, message);
        printf("[DEBUG] ");
        vprintf(message, args);
        va_end(args);
    }
}

void infoLog(const char *message, ...)
{
    if (currentLogLevel >= INFO) {
        va_list args;
        va_start(args, message);
        printf("[INFO] ");
        vprintf(message, args);
        va_end(args);
    }
}

void warningLog(const char *message, ...)
{
    if (currentLogLevel >= WARNING) {
        va_list args;
        va_start(args, message);
        printf("[WARNING] ");
        vprintf(message, args);
        va_end(args);
    }
}

void errorLog(const char *message, ...)
{
    if (currentLogLevel >= ERROR) {
        va_list args;
        va_start(args, message);
        printf("[ERROR] ");
        vprintf(message, args);
        va_end(args);
    }
}