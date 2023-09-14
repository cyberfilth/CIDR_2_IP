# CIDR_2_IP
Convert a netmask in CIDR notation to a list of IP addresses.

Compile with:
```sh
gcc -Os -s -o CIDR_2_IP CIDR_2_IP.c
```
Use on the commandline like this:
```
./CIDR_2_IP 192.168.0.2/27
```
Example output
```
CIDR netmask supplied was 192.168.0.2/27
IP addresses
------------
192.168.0.0
192.168.0.1
192.168.0.2
192.168.0.3
192.168.0.4
192.168.0.5
192.168.0.6
--SNIP--
```
