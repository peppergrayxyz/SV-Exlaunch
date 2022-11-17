/*
** $Id: lfunc.h $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
*/

#ifndef lfunc_h
#define lfunc_h


#include "lobject.h"


#define sizeCclosure(n)	(cast_int(offsetof(CClosure, upvalue)) + \
                         cast_int(sizeof(TValue)) * (n))

#define sizeLclosure(n)	(cast_int(offsetof(LClosure, upvals)) + \
                         cast_int(sizeof(TValue *)) * (n))


/* test whether thread is in 'twups' list */
#define isintwups(L)	(L->twups != L)


/*
** maximum number of upvalues in a closure (both C and Lua). (Value
** must fit in a VM register.)
*/
#define MAXUPVAL	255


#define upisopen(up)	((up)->v != &(up)->u.value)


#define uplevel(up)	check_exp(upisopen(up), cast(StkId, (up)->v))


/*
** maximum number of misses before giving up the cache of closures
** in prototypes
*/
#define MAXMISS		10



/* special status to close upvalues preserving the top of the stack */
#define CLOSEKTOP	(-1)




#endif
