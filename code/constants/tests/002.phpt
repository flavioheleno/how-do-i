--TEST--
Constant checking test
--EXTENSIONS--
hdi
--FILE--
<?php
var_dump(STRING_CONST);
var_dump(LONG_CONST);
var_dump(DOUBLE_CONST);
var_dump(BOOL_CONST);
var_dump(NULL_CONST);
?>
--EXPECT--

string(8) "my-value"
int(12345)
float(3.14)
bool(false)
NULL
