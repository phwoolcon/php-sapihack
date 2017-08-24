PHP_ARG_ENABLE(sapihack, whether to enable sapihack support,
[  --enable-sapihack          Enable sapihack support], no)

if test "$PHP_SAPIHACK" != "no"; then
  AC_DEFINE(HAVE_SAPIHACK, 1, [ Have sapihack support ])
  PHP_NEW_EXTENSION(sapihack, sapihack.c, $ext_shared)
fi
