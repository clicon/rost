#ifndef _ROST_MACROS_H_
#define _ROST_MACROS_H_

/* CPP Stringify */
#define STRINGIFY(s) __str(s)
#define __str(s) #s

/* CPP concat */
#define CONCAT_NX(X, Y)  X ## Y
#define CONCAT(X, Y) CONCAT_NX(X, Y)

#endif /* _ROST_MACROS_H_ */


