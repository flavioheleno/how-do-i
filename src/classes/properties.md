# Class Properties

This chapter covers how to define a class property.

Code sample for this chapter, with additional examples, is available
[here](https://github.com/flavioheleno/how-do-i/code/classes/properties/).

## Userland PHP Code Snippet

The code below shows how a class property would be declared in userland PHP code.

```php
class Hdi {
  public int $value;
}
```

## Internal PHP Code

The following sections show all required code to declare and implement a class property internally in PHP.

### PHP Stub (`hdi.stub.php`)

The stub file may or may not declare class properties, but the stub generator script
([gen_stub.php](https://github.com/php/php-src/blob/master/build/gen_stub.php)) will not produce any output related to
them as they are implementation specific.

### Argument Information (`hdi_arginfo.h`)

Class properties are not referred to nor registered in the argument information file, so it can be skipped.

### Implementation (`hdi.c`)

```c
zend_string *propName = zend_string_init("value", sizeof("value") - 1, false);
zval propDefaultValue;
/* default property value (undefined) */
ZVAL_UNDEF(&propDefaultValue);

zend_declare_typed_property(
  classEntry,
  propName,
  &defaultValue,
  ZEND_ACC_PRIVATE,
  NULL,
  (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG)
);
zend_string_release(propName);
```

Macros and Functions:
* [ZVAL_UNDEF](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L912)
* [zend_string_init](https://github.com/php/php-src/blob/4a4ae45a0bcb82b01a4386433b2e4ee45862fc01/Zend/zend_string.h#L169)
* [zend_string_release](https://github.com/php/php-src/blob/4a4ae45a0bcb82b01a4386433b2e4ee45862fc01/Zend/zend_string.h#L317)
* [ZEND_TYPE_INIT_MASK](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L262)

Visibility options:
* [ZEND_ACC_PUBLIC](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L202)
* [ZEND_ACC_PROTECTED](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L203)
* [ZEND_ACC_PRIVATE](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L204)
* [ZEND_ACC_STATIC](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L210)
* [ZEND_ACC_READONLY](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L223)

Type options:
* [MAY_BE_NULL](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#L25)
* [MAY_BE_BOOL](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#L28)
* [MAY_BE_LONG](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#L29)
* [MAY_BE_DOUBLE](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#30)
* [MAY_BE_STRING](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#31)
* [MAY_BE_ARRAY](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#32)
* [MAY_BE_OBJECT](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#33)
* [MAY_BE_RESOURCE](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#34)
* [MAY_BE_ANY](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#35)
* [MAY_BE_REF](https://github.com/php/php-src/blob/1ffbb7372a1481cfeaf770fd67e19b05aee83e3d/Zend/zend_type_info.h#36)

## Manipulating Property Values

### Update/Set a Property

Updating a property value is straight forward:
* update function (`zend_update_property_long`)
  * class entry (`classEntry`)
  * object reference (`Z_OBJ_P(ZEND_THIS)` ie. `$this`)
  * property name string (`"value"`)
  * property name size (`sizeof`)
  * value (`42`)

```c
zend_update_property_long(
  classEntry,
  Z_OBJ_P(ZEND_THIS),
  "value",
  sizeof("value") - 1,
  42
);
```

> Note that for static properties, `zend_update_property_long` must be replaced by its static version
(`zend_update_static_property_long`), that does not have an object argument.

Macros and Functions:
* [zend_update_property_long](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L457)
* [zend_update_static_property_long](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L468)
* [Z_OBJ_P](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L857)
* [ZEND_THIS](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L481)

### Read a Property

Reading a property value requires a bit more leg work:
* read function (`zend_read_property`)
  * class entry (`classEntry`)
  * object reference (`Z_OBJ_P(ZEND_THIS)` ie. `$this`)
  * property name string (`"value"`)
  * property name size (`sizeof`)
  * ???
  * ???

```c
zval rv;
zval *value = zend_read_property(
  classEntry,
  Z_OBJ_P(ZEND_THIS),
  "value",
  sizeof("value") - 1,
  true,
  &rv
);
```

> Note that for static properties, `zend_read_property` must be replaced by its static version
(`zend_read_static_property`), that does not have an object argument.

Macros and Functions:
* [zend_read_property](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L474)
* [zend_read_static_property](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L477)
* [Z_OBJ_P](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L857)
* [ZEND_THIS](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L481)

{{#include ../FOOTER.md}}
