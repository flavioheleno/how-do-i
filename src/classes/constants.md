# Class Constants

This chapter covers how to define a class constant.

Note that more in dept details about constants are covered in the [constants](../constants/index.html) chapter.

Code sample for this chapter, with additional examples, is available
[here](https://github.com/flavioheleno/how-do-i/code/classes/constants/).

## Userland PHP Code Snippet

The code below shows how a class constant would be declared in userland PHP code.

```php
class Hdi {
  public const HELLO = 'World!';
}
```

## Internal PHP Code

The following sections show all required code to declare and implement a class constant internally in PHP.

### PHP Stub (`hdi.stub.php`)

The stub file should not declare class constants as the stub generator script
([gen_stub.php](https://github.com/php/php-src/blob/master/build/gen_stub.php)) cannot handle it at this moment.

### Argument Information (`hdi_arginfo.h`)

Class constants are not referred to nor registered in the argument information file, so it can be skipped.

### Implementation (`hdi.c`)

The implementation below is a little bit more elaborate than what is seen in global scope constant, but it can be broken
into:
* name definition (`zend_string_init`)
  * name string (`"HELLO"`)
  * name size (`sizeof`)
  * persistent string (`0` ie. not persistent[^persistent])
* value definition (`ZVAL_NEW_STR` and `zend_string_init`)
  * value string (`"World!"`)
  * value size (`sizeof`)
  * persistent string (depends if `classEntry->type` is a `ZEND_INTERNAL_CLASS` or not)
* declaration (`zend_declare_class_constant_ex`)
  * class entry (`classEntry`)
  * visibility (`ZEND_ACC_PRIVATE`)

```c
zend_string *name = zend_string_init(
  "HELLO",
  sizeof("HELLO") - 1,
  0
);

zval value;
ZVAL_NEW_STR(
  &value,
  zend_string_init(
    "World!",
    sizeof("World!") - 1,
    classEntry->type & ZEND_INTERNAL_CLASS
  )
);

zend_declare_class_constant_ex(
  classEntry,
  name,
  &value,
  ZEND_ACC_PRIVATE,
  NULL
);
zend_string_release(name);
```

Alternatively, for public class constants, it can be simplified as:

```c
zend_declare_class_constant_string(
  classEntry,
  "HELLO",
  sizeof("HELLO") - 1,
  "World!"
);
```

Macros and Functions:
* [zend_string_init](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_string.h#L170)
* [ZVAL_NEW_STR](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L962)
* [zend_declare_class_constant_ex](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L417)
* [zend_string_release](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_string.h#L318)
* [zend_declare_class_constant_string](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L424)

Visibility options:
* [ZEND_ACC_PUBLIC](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L202)
* [ZEND_ACC_PROTECTED](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L203)
* [ZEND_ACC_PRIVATE](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L204)
* [ZEND_ACC_STATIC](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L210)

Notes:

[^persistent]: More about persistent objects in the [Zend Memory Manager](https://www.phpinternalsbook.com/php7/memory_management/zend_memory_manager.html) chapter of the PHP Internals Book.

{{#include ../FOOTER.md}}
