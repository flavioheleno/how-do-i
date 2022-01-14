# Classes

## Userland PHP Code Snippet

The code below shows how a class would be declared in userland PHP code.

```php
class Hdi {
}
```

## Internal PHP Code

The following sections show all required code to declare a class internally in PHP.

### PHP Stub (`hdi.stub.php`)

The stub file is used to declare the class signature:

* namespace (`global`)
* name (`Hdi`)

```php
class Hdi {}
```

### Argument Information (`hdi_arginfo.h`)

This file is generated during compilation, based on the stub file contents.

### Header File (`hdi.h`)

In this file, a pointer to a `zend_class_entry` must be declared for the defined class:

```h
  extern zend_class_entry *zceHdi;
```

### Implementation (`hdi.c`)

The implementation below is elaborated and each part has its own purpose, as shown below:

```c
```

{{#include ../FOOTER.md}}
