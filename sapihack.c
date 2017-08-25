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

#include "php_sapihack.h"

/* {{{ void sapihack_reset_headers_sent()
 */
ZEND_BEGIN_ARG_INFO(arginfo_sapihack_reset_headers_sent, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION (sapihack_reset_headers_sent) {
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    SG(headers_sent) = 0;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 * Init on module load
 */
PHP_MINIT_FUNCTION (sapihack) {
    /* Define PHP constants */
    REGISTER_STRING_CONSTANT("SAPIHACK_VERSION", PHP_SAPIHACK_VERSION, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SAPIHACK_VERSION_ID", PHP_SAPIHACK_VERSION_ID, CONST_CS | CONST_PERSISTENT);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 * Present phpinfo
 */
PHP_MINFO_FUNCTION (sapihack) {
    php_info_print_table_start();
    php_info_print_table_header(2, "SAPI Hack Support", "enabled");
    php_info_print_table_row(2, "Version", PHP_SAPIHACK_VERSION);
    php_info_print_table_row(2, "Author", PHP_SAPIHACK_AUTHOR);
    php_info_print_table_row(2, "Build Date", PHP_SAPIHACK_BUILD_DATE);
    php_info_print_table_end();
}
/* }}} */

/* {{{ sapihack_functions[]
 * Register php functions
 */
const zend_function_entry sapihack_functions[] = {
        PHP_FE(sapihack_reset_headers_sent, arginfo_sapihack_reset_headers_sent)
        PHP_FE_END
};
/* }}} */

/* {{{ sapihack_module_entry
 * Register extension
 */
zend_module_entry sapihack_module_entry = {
        STANDARD_MODULE_HEADER,
        "sapihack",                     /* Extension name */
        sapihack_functions,             /* zend_function_entry */
        PHP_MINIT(sapihack),            /* PHP_MINIT - Module initialization */
        NULL,                           /* PHP_MSHUTDOWN - Module shutdown */
        NULL,                           /* PHP_RINIT - Request initialization */
        NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
        PHP_MINFO(sapihack),            /* PHP_MINFO - Module info */
        PHP_SAPIHACK_VERSION,           /* Version */
        STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SAPIHACK
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(sapihack)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */
