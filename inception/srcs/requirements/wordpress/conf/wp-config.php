<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'DB_NAME_' );

/** MySQL database username */
define( 'DB_USER', 'DB_USER_' );

/** MySQL database password */
define( 'DB_PASSWORD', 'DB_PASSWORD_' );

/** MySQL hostname */
define( 'DB_HOST', 'DB_HOST_' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'MS)}zgkdrj-x?b|rL#Z?JJ/efY>Yc!8b:4I7/LP7WvoKF:T`PX%=KyC(9hZsFXA8');
define('SECURE_AUTH_KEY',  'FfSX{?~Q!RA0 [mHg^@H;Ho}|u}4,fg?UPS]s%}7-AGu0g&$*r~KaZzA4+B+[Sfy');
define('LOGGED_IN_KEY',    ')_BeF~!pzU:eZqU.)-d&f+d-E}N$QTPsp:@^72oBco:T^ZNi+>>fG:OnntciVWhA');
define('NONCE_KEY',        'LT}>fIEbMH3t8Kz%.,0.?k,*JXe-k#K.$t$&EW4{k=E1zr.R;w=mS5M#9}W/wvzo');
define('AUTH_SALT',        'wk&CvKK1DWW.mIe{+ gj25-Rg<n8+SNcj!c[*3}7ZJR6W9qLd-7rqQ_95Nj$ xR-');
define('SECURE_AUTH_SALT', 'C!Qv!7bSKwFqV|dw92Mx`z#3t)`GBAp0Lv{vKA|,gg1Ao[7KXvo,v w%X7OoLPba');
define('LOGGED_IN_SALT',   'UJ]W3dyorY,J|tn91hlgLYl#G]N|XOg+--O#Gk*:lW:#U2}I){2KG<T_i[Dg)0En');
define('NONCE_SALT',       'L&#NQRVP7CKl|d5QM#7sHMl?&->5Hq}kw<sna-n9AVs&[[|i.k<SDe6+n)M8~]s7');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
