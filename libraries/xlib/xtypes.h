#ifndef _XTYPES_H
#define _XTYPES_H

#include <xdefs.h>
#include <xconfig.h>

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

__XLIB_BEGIN_DECL

#ifndef HAVE_SSIZE_T
typedef long ssize_t;
#endif /* HAVE_SSIZE_T */

#ifndef HAVE_IOVEC
struct iovec {
    void * iov_base;
    size_t iov_len;
};
#endif /* HAVE_IOVEC */

__XLIB_END_DECL

#endif /* _XTYPES_H */
