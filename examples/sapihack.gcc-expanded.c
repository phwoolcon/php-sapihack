#include "php.h"
#include "SAPI.h"
#include "ext/standard/info.h"

extern zend_module_entry sapihack_module_entry;

static const zend_internal_arg_info arginfo_sapihack_reset_headers_sent[] = {
    {(const char *) (zend_uintptr_t) (-1), ((void *) 0), 0, 0, 0, 0},
};

void zif_sapihack_reset_headers_sent(zend_execute_data *execute_data, zval *return_value)
{
    if ((__builtin_expect(!!((execute_data)->This.u2.num_args == 0), 1) ? SUCCESS : zend_parse_parameters(
        (execute_data)->This.u2.num_args, ""
    )) == FAILURE) {
        return;
    }

    (sapi_globals.headers_sent) = 0;
}

int zm_startup_sapihack(int type, int module_number)
{
    zend_register_string_constant(
        ("SAPIHACK_VERSION"),
        sizeof("SAPIHACK_VERSION") - 1,
        ("0.1.0"),
        ((1 << 0) | (1 << 1)),
        module_number
    );
    zend_register_long_constant(
        ("SAPIHACK_VERSION_ID"),
        sizeof("SAPIHACK_VERSION_ID") - 1,
        (100),
        ((1 << 0) | (1 << 1)),
        module_number
    );

    return SUCCESS;
}

void zm_info_sapihack(zend_module_entry *zend_module)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "SAPI Hack Support", "enabled");
    php_info_print_table_row(2, "Version", "0.1.0");
    php_info_print_table_row(2, "Author", "Christopher CHEN <fishdrowned@gmail.com>");
    php_info_print_table_row(2, "Build Date", "Aug 25 2017" " " "19:05:30");
    php_info_print_table_end();
}

const zend_function_entry sapihack_functions[] = {
    {
        "sapihack_reset_headers_sent",
        zif_sapihack_reset_headers_sent,
        arginfo_sapihack_reset_headers_sent,
        (uint32_t)(sizeof(arginfo_sapihack_reset_headers_sent) / sizeof(struct _zend_internal_arg_info) - 1),
        0
    },
    {
        ((void *) 0),
        ((void *) 0),
        ((void *) 0),
        0,
        0
    }
};

zend_module_entry sapihack_module_entry = {
    sizeof(zend_module_entry),
    20151012,
    0,
    0,
    ((void *) 0),
    ((void *) 0),
    "sapihack",
    sapihack_functions,
    zm_startup_sapihack,
    ((void *) 0),
    ((void *) 0),
    ((void *) 0),
    zm_info_sapihack,
    "0.1.0",
    0,
    ((void *) 0),
    ((void *) 0),
    ((void *) 0),
    ((void *) 0),
    0,
    0,
    ((void *) 0),
    0,
    "API" "20151012" ",NTS"
};
