#ifndef _XPRINT_H
#define _XPRINT_H

#include <stdarg.h>

#include "xfmt.h"
#include "xstream.h"

__XLIB_BEGIN_DECL

struct xprint;
typedef int (xprint_write_fn_t)(struct xprint *, const void *, size_t);
typedef int (xprint_atwrap_fn_t)(struct xprint *, const xfmt_atarg_fn_t *, const void *);

struct xprint_ops
{
    xprint_write_fn_t    *write;
    xprint_atwrap_fn_t   *atwrap;
};
typedef struct xprint_ops xprint_ops_t;

struct xprint
{
  const xprint_ops_t     xp_ops;
  void                  *xp_priv;
};
typedef struct xprint xprint_t;
#define XPRINT_INIT(ops,pr) { .xp_ops = ops, .xp_priv = (pr) }
#define XPRINT_OPS(xp)      (&((xp)->xp_ops))
#define XPRINT_PRIV(xp)     ((xp)->xp_priv)


typedef int (xprint_atarg_fn_t)(xprint_t *, const void *);
int xprintfv(xprint_t *xp, const char *format, va_list ap);
int xprintf(xprint_t *xp, const char *format, ...);

__XLIB_END_DECL

#endif /* _XPRINT_H */
