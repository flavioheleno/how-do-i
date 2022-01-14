dnl config.m4 for extension hdi

PHP_ARG_ENABLE(
  [hdi],
  [whether to enable hdi support],
  [
    AS_HELP_STRING(
      [--enable-hdi],
      [Enable hdi support]
    )
  ],
  [no]
)

if test "$PHP_HDI" != "no"; then
  AC_DEFINE(HAVE_HDI, 1, [ Have hdi support ])

  PHP_NEW_EXTENSION(hdi, hdi.c, $ext_shared)
fi
