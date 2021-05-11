<?php
// use here a value of your choice at least 32 chars long
$cfg['blowfish_secret'] = '.zcpSLdc.Zzhh2WGQPZaSch/cK7US3GP'; /* YOU MUST FILL IN THIS FOR COOKIE AUTH! */

$i=0;
$i++;
//Authentication type
$cfg['Servers'][$i]['auth_type'] = 'cookie';
//Server parameters
$cfg['Servers'][$i]['host'] = 'mysql';
$cfg['Servers'][$i]['compress'] = false;
$cfg['Servers'][$i]['AllowNoPassword'] = true;

//Directories for saving/loading files from server
$cfg['TempDir'] = '/tmp';
$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';