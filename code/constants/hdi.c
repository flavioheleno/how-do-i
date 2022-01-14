/* hdi extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_hdi.h"
#include "hdi_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
  ZEND_PARSE_PARAMETERS_START(0, 0) \
  ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(hdi) {
  /* const STRING_CONST = 'my-value'; */
  REGISTER_MAIN_STRING_CONSTANT("STRING_CONST", "my-value", CONST_CS | CONST_PERSISTENT);

  /* const LONG_CONST = 12345; */
  REGISTER_MAIN_LONG_CONSTANT("LONG_CONST", 12345, CONST_CS | CONST_PERSISTENT);

  /* const DOUBLE_CONST = 3.14; */
  REGISTER_MAIN_DOUBLE_CONSTANT("DOUBLE_CONST", 3.14, CONST_CS | CONST_PERSISTENT);

  /* const BOOL_CONST = false; */
  REGISTER_MAIN_BOOL_CONSTANT("BOOL_CONST", false, CONST_CS | CONST_PERSISTENT);

  /* const NULL_CONST = null; */
  REGISTER_MAIN_NULL_CONSTANT("NULL_CONST", CONST_CS | CONST_PERSISTENT);

  return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(hdi) {
  #if defined(ZTS) && defined(COMPILE_DL_HDI)
    ZEND_TSRMLS_CACHE_UPDATE();
  #endif

  return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(hdi) {
  php_info_print_table_start();
  php_info_print_table_header(2, "hdi support", "enabled");
  php_info_print_table_end();
}
/* }}} */

/* {{{ hdi_module_entry */
zend_module_entry hdi_module_entry = {
  STANDARD_MODULE_HEADER,
  "hdi",           /* Extension name */
  ext_functions,   /* zend_function_entry */
  PHP_MINIT(hdi),  /* PHP_MINIT - Module initialization */
  NULL,            /* PHP_MSHUTDOWN - Module shutdown */
  PHP_RINIT(hdi),  /* PHP_RINIT - Request initialization */
  NULL,            /* PHP_RSHUTDOWN - Request shutdown */
  PHP_MINFO(hdi),  /* PHP_MINFO - Module info */
  PHP_HDI_VERSION, /* Version */
  STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HDI
  # ifdef ZTS
    ZEND_TSRMLS_CACHE_DEFINE()
  # endif
  ZEND_GET_MODULE(hdi)
#endif
