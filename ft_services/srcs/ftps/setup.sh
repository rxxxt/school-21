#!/bin/sh

adduser admin --disabled password
echo "admin:admin" | chpasswd
mkdir -p /home/ftp/files
chmod a-w /home/ftp
chown nobody:nogroup /home/ftp
chown admin:admin /home/ftp/files
echo "admin" | tee -a /etc/vsftpd/vsftpd.userlist

vsftpd /etc/vsftpd/vsftpd.conf