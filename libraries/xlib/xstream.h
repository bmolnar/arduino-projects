#ifndef _XSTREAM_H
#define _XSTREAM_H

#include <stdarg.h>

#include "xtypes.h"
#include "xerr.h"
#include "xfmt.h"

__XLIB_BEGIN_DECL

struct xstream;
typedef struct xstream xstream_t;

typedef int     (xstream_open_fn_t)(xstream_t *xp, const char *mode, void *userdata);
typedef ssize_t (xstream_write_fn_t)(xstream_t *xp, const void *buf, size_t size);
typedef ssize_t (xstream_read_fn_t)(xstream_t *xp, void *buf, size_t size);
typedef int     (xstream_flush_fn_t)(xstream_t *xp);
typedef int     (xstream_close_fn_t)(xstream_t *xp);

typedef struct xstream_ops {
    xstream_open_fn_t * open;
    xstream_write_fn_t *write;
    xstream_read_fn_t * read;
    xstream_flush_fn_t *flush;
    xstream_close_fn_t *close;
} xstream_ops_t;

/* xstream */
struct xstream {
    xstream_ops_t xs_ops;
    void *        xs_priv;
    void *        xs_hnd;
};

#define XSTREAM_INIT(ops,priv) { .xs_ops = (ops), .xs_priv = (priv), .xs_hnd = NULL }
#define XSTREAM_OPS(xs)        ((xs)->xs_ops)
#define XSTREAM_PRIV(xs)       ((xs)->xs_priv)
#define XSTREAM_HND(xs)        ((xs)->xs_hnd)

int xstream_open(xstream_t *xs, const char *mode, void *userdata);
int xstream_close(xstream_t *xs);
ssize_t xstream_write(xstream_t *xs, const void *buf, size_t sz);
ssize_t xstream_read(xstream_t *xs, void *buf, size_t sz);
int xstream_flush(xstream_t *xs);
xstream_t *xstream_create_open(xstream_ops_t ops, const char *mode, void *userdata);
int xstream_close_destroy(xstream_t *xs);

__XLIB_END_DECL

#endif /* _XSTREAM_H */
