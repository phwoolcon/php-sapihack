/*
   +----------------------------------------------------------------------+
   | PHP Version 7                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2017 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Christopher CHEN <fishdrowned@gmail.com>                     |
   +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "SAPI.h"
#include "ext/standard/info.h"

#ifndef PHP_SAPIHACK_H
# define PHP_SAPIHACK_H

extern zend_module_entry sapihack_module_entry;
# define phpext_sapihack_ptr &sapihack_module_entry

# define PHP_SAPIHACK_VERSION       "0.1.0"
# define PHP_SAPIHACK_VERSION_ID    000100 /* Major 00 Minor 01 Patch 00*/
# define PHP_SAPIHACK_BUILD_DATE    __DATE__ " " __TIME__
# define PHP_SAPIHACK_AUTHOR        "Christopher CHEN <fishdrowned@gmail.com>"

# if defined(ZTS) && defined(COMPILE_DL_SAPIHACK)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif    /* PHP_SAPIHACK_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */
