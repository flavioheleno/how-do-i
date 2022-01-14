# Extension

The directory structure for an extension is simple enough, given the command:

```bash
php ext_skel.php \
  --ext Hdi \
  --onlyunix
```

The structure below will be created:

```
<hdi>
 ├─ tests/          # Code tests directory
 │  ├─ 001.phpt     # Test skeleton
 │  ├─ 002.phpt     # Test skeleton
 │  └─ 003.phpt     # Test skeleton
 ├─ .gitignore      # Patterns to be ignored by git
 ├─ config.m4       # Code that will be imported by the configure script during build
 ├─ hdi.c           # Actual extension code
 ├─ hdi.stub.php    # Stub file that will be used to generate the "hdi_arginfo.h" file
 ├─ hdi_arginfo.h   # Argument information header
 └─ php_hdi.h       # Extension registration header (module entry)
```

From Zend's chapter "[2. Generating a PHP Extension Skeleton](https://www.zend.com/generating-php-extension-skeleton)":

* **config.m4** is an extension configuration script used by "phpize" or "buildconf" to add extension configuration
options into the "configure" command.
* **php_hdi.h** is a C header file that contains our common extension definitions. It's not necessary for simple
extensions with a single-source C file, but it's useful in case the implementation is spread among few files.
* **hdi.c** is the main extension implementation source. It defines all the structures that allow to plug the extension
into PHP and make all their internal functions, classes and constants to be available.



## hdi.stub.php

This stub file will be parsed by [gen_stub.php](https://github.com/php/php-src/blob/master/build/gen_stub.php) and as
result, the `hdi_arginfo.h` is generated/updated.

> Note that not all PHP constructs are supported by gen_stub.php, in each chapter additional instructions for what to
> include and what not to include in the stub file will be outlined.

## hdi_arginfo.h

This header file is automatically generated/updated by the build process and should not be manually editted.

{{#include ../FOOTER.md}}
