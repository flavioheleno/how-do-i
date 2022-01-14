# Constants

This chapter covers how to define a global constant.

Code sample for this chapter, with additional examples, is available
[here](https://github.com/flavioheleno/how-do-i/code/constants/).

## Userland PHP Code Snippet

The code below shows how a constant would be declared in userland PHP code.

```php
const HELLO = 'World!';
```

## Internal PHP Code

The following sections show all required code to declare and implement a constant internally in PHP.

### PHP Stub (`hdi.stub.php`)

The stub file should not declare global constants as the stub generator script
([gen_stub.php](https://github.com/php/php-src/blob/master/build/gen_stub.php)) cannot handle it at this moment.

### Argument Information (`hdi_arginfo.h`)

Constants are not referred to nor registered in the argument information file, so it can be skipped.

### Implementation (`hdi.c`)

The implementation below is very simple and straight forward:

* declaration (`REGISTER_MAIN_STRING_CONSTANT`)
  * name string (`"HELLO"`)
  * value string (`"World!"`)
  * flags (`CONST_CS` and `CONST_PERSISTENT`)

```c
REGISTER_MAIN_STRING_CONSTANT("HELLO", "World!", CONST_CS | CONST_PERSISTENT);
```

Macros and Functions:

* [REGISTER_MAIN_STRING_CONSTANT](https://github.com/php/php-src/blob/462da6e09c2eb63aeb9ba357c659d490a9bc46d9/Zend/zend_constants.h#66)

References:

* [Zend/zend_constants.h](https://github.com/php/php-src/blob/05023a281ddb62186fa47f51192ea51ba10f3a9b/Zend/zend_constants.h)

> Note that constants must be registered during the **MINIT()** stage.

{{#include ../FOOTER.md}}
