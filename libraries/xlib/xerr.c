#include "xerr.h"

const char *
xerr_str(int xerr)
{
    switch (xerr) {
    case XERR_NOSYS:
        return "XERR_NOSYS";
    case XERR_NOENT:
        return "XERR_NOENT";
    default:
        return "ERROR";
    }
}
