# Class Methods

This chapter covers how to define a class method.

Note that details such as [method arguments](../functions/arguments/index.html) and
[method return values](../functions/return-values/index.html) are covered in the [functions](../functions/index.html)
chapter.

Code sample for this chapter, with additional examples, is available
[here](https://github.com/flavioheleno/how-do-i/code/classes/methods/).

## Userland PHP Code Snippet

The code below shows how a class method would be declared and implemented in userland PHP code.

```php
class Hdi {
  public function sayHello(): string {
    return 'Hello World!';
  }
}
```

## Internal PHP Code Snippet

The sections below show all required code to declare and implement a class method internally in PHP.

### PHP Stub (`hdi.stub.php`)

The stub file is used to declare the method signature:

* visibility (`public`)
* name (`sayHello`)
* argument list (`()`)
* return type (`string`)

```php
class Hdi {
  public function sayHello(): string {}
}
```

### Argument Information (`hdi_arginfo.h`)

This file is generated during compilation, based on the stub file contents.

The argument information header is the standard/default file where all class methods details are defined:
* declaration (`ZEND_METHOD`)
  * class name (`Hdi`)
  * method name (`sayHello`)
* class method list (`class_Hdi_methods[]` variable)
  * entry registration (`ZEND_ME`)
    * class name (`Hdi`)
    * method name (`sayHello`)
    * argument information (`arginfo_class_Hdi_sayHello`)
    * visibility (`ZEND_ACC_PUBLIC`)
* argument declaration (`ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX`)
  * argument information name (`arginfo_class_Hdi_sayHello`)
  * return reference (`0` ie. return by value)
  * required arguments (`0` ie. no required arguments)
  * return type (`IS_STRING`)
  * allow null (`0` ie. not allowed)

```h
/* This is a generated file, edit the .stub.php file instead. */
/* NOTE: Only relevant code is shown below! */
ZEND_METHOD(Hdi, sayHello);

static const zend_function_entry class_Hdi_methods[] = {
  ZEND_ME(Hdi, sayHello, arginfo_class_Hdi_sayHello, ZEND_ACC_PUBLIC)
  ZEND_FE_END
};

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Hdi_sayHello, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()
```

Macros and Functions:
* [ZEND_METHOD](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L73)
* [ZEND_ME](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L88)
* [ZEND_FE_END](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L119)
* [ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L194)
* [ZEND_END_ARG_INFO](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L208)

Visibility options:
* [ZEND_ACC_PUBLIC](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L202)
* [ZEND_ACC_PROTECTED](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L203)
* [ZEND_ACC_PRIVATE](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L204)
* [ZEND_ACC_STATIC](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_compile.h#L210)

Type options:
* [IS_LONG](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L539)
* [IS_DOUBLE](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L540)
* [IS_STRING](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L541)
* [IS_ARRAY](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L542)
* [IS_OBJECT](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L543)
* [IS_RESOURCE](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L544)
* [IS_REFERENCE](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L545)
* [IS_CALLABLE](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L550)
* [IS_ITERABLE](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L551)
* [IS_VOID](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L552)
* [IS_STATIC](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L553)
* [IS_MIXED](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L554)
* [IS_NEVER](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L555)
* [\_IS_BOOL](https://github.com/php/php-src/blob/d56ec0a624aa6d5e944795977752edc54c5e3f42/Zend/zend_types.h#L564)

### Implementation (`hdi.c`)

The implementation below is quite simple and straight forward:
* declaration (`PHP_METHOD`)
  * class name (`Hdi`)
  * method name (`sayHello`)
* parameter parsing (`ZEND_PARSE_PARAMETERS_NONE`)
* return (`RETURN_STR`)
  * value string (`"Hello World!"`)

```c
/* {{{ Hdi: function sayHello(): string */
PHP_METHOD(Hdi, sayHello) {
  ZEND_PARSE_PARAMETERS_NONE();

  RETURN_STR("Hello World!");
}
/* }}} */
```

Macros and Functions:
* [PHP_METHOD](https://github.com/php/php-src/blob/1c33ddb5e5598c5385c4c965992c6e031fd00dd6/main/php.h#L367)
* [ZEND_PARSE_PARAMETERS_NONE](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L1407)
* [RETURN_STR](https://github.com/php/php-src/blob/32e2d97a265a3137eaa642857156e5d49521d846/Zend/zend_API.h#L832)

{{#include ../FOOTER.md}}
