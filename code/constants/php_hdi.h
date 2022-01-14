/* hdi extension for PHP */

#ifndef PHP_HDI_H
# define PHP_HDI_H

extern zend_module_entry hdi_module_entry;
# define phpext_hdi_ptr &hdi_module_entry

# define PHP_HDI_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_HDI)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_HDI_H */
