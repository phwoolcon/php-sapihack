--TEST--
sapihack_rest_headers_sent() Basic test
--SKIPIF--
<?php
if (!extension_loaded('sapihack')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(headers_sent());
echo "Send something\n";
var_dump(headers_sent());
sapihack_rest_headers_sent();
var_dump(headers_sent());
echo "Done\n";
?>
--EXPECTF--
bool(false)
Send something
bool(true)
bool(false)
Done
