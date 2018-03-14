#!/usr/bin/python3
# This file contains variables shared throughout the various ctf scripts

charset = list(	''.join(chr(i) for i in range(ord('a'), ord('z'))) +
				''.join(str(i) for i in range(0, 10)))
flaglen = 6

hashHex = '38370347e6c3ab7da18f2c05e6ca12320f19640618bdc3e3f63918aa8a86c176'
