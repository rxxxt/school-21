<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         ' l1-<V8V=B++?T|5/oHr]Sh5AX} e%CrizE%,L?,`7]$4t`-e5+w@4J n2lGkElU');
define('SECURE_AUTH_KEY',  '+Cqn5;|AXmR]aunT&,a/H+5+iZfm]K=[KZNl9$U-Op$%&1y`|P|]6TD@IiafG(_=');
define('LOGGED_IN_KEY',    'X>&hc<BijmT^s7B2<#R-0%9C44A}~Kl-hjf>07mU|[Zs[RmWLy&$lyJ0^ W3P}Kw');
define('NONCE_KEY',        '|y6mn@W-*4-c4Z,UAg-Ks)?__]^]`x,b/N$kV00*0|&K+od`ot9`s8#erHTCVXF-');
define('AUTH_SALT',        'j`*jnZq!{}o,FkyzPO~wh4,~||?.*ZL^e<=1a+0{KlWHXWd4#X99mgNQTXe%[S:`');
define('SECURE_AUTH_SALT', 'Zk;&+~4Rk2xovFq]}@pKd7D+qGK2$+C/VTAY7.}Zw}b.b<Ue3%vVA(ISH|dBo&|y');
define('LOGGED_IN_SALT',   '$&p$FCi.d3 MF&( BMySD#!@3`+2?h$,B_YgCib_PLMT3qu!ef<#JV+vvZ:fU|;b');
define('NONCE_SALT',       'KUXI?A1ustx5; qZ#vcpXO4WpBB1jP:OwcJ#YXz&)u5&}J*8j}tb-SW+XVqVqh|6');

/**#@-*/

/**
 * WordPress Database Table prefix.
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
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );