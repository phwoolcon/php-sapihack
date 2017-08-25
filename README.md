# php-sapihack

PHP Extension: SAPI Hack
## Use case
Headers are not used completely in CLI mode, but `headers_sent` is always set to `1`
if any content is echoed on the screen, then we get unexpected annoying error with
message `headers already sent`

Use this extension to avoid such errors and keep running smoothly in CLI mode, especially
in PHP 7.2, some `session_` functions behaves different than older versions:

* `session_name()`
* `session_set_save_handler()`
* `session_save_path()`

This check (`headers already sent`) is necessary in CGI mode, but this should not happen
in CLI mode, for example, when we running `swoole` or `phpunit`.

## Installation
```bash
git clone git@github.com:phwoolcon/php-sapihack.git
phpize
./configure --enable-sapihack
make
sudo make install
echo 'extension = sapihack.so' > /etc/php/7.2/mods-available/sapihack.ini
sudo ln -s ../../mods-available/sapihack.ini /etc/php/7.2/fpm/conf.d/20-sapihack.ini
sudo ln -s ../../mods-available/sapihack.ini /etc/php/7.2/cli/conf.d/20-sapihack.ini
service php7.2-fpm restart
```

## Documentation

### Constants
`SAPIHACK_VERSION`

`SAPIHACK_VERSION_ID`

### Functions
#### sapihack_reset_headers_sent()
**WARNING** Only use this function in CLI mode.

```php
<?php
echo 'Something has been output to STDOUT, but this is not HTTP response in CLI mode';
echo 'But `sapi_globals.headers_sent` has been set to 1';
echo 'Then you will not be able to use `session_` functions in php 7.2';
echo 'Call `sapihack_reset_headers_sent()` to help you';

// Use SAPIHACK_VERSION_ID to detect extension availablity
defined('SAPIHACK_VERSION_ID') and sapihack_reset_headers_sent();
session_name('my_app');
```
