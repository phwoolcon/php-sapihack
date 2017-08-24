--TEST--
Check if sapihack is loaded
--SKIPIF--
<?php
if (!extension_loaded('sapihack')) {
	echo 'skip';
}
?>
--FILE--
<?php 
echo 'The extension "sapihack" is available';
?>
--EXPECT--
The extension "sapihack" is available
