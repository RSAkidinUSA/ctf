#!/usr/bin/python3
# This file contains variables shared throughout the various ctf scripts

charset = list(	''.join(chr(i) for i in range(ord('a'), ord('z'))) +
				''.join(chr(i) for i in range(ord('A'), ord('Z'))) +
				''.join(str(i) for i in range(0, 10)))

hashHex = 'ae655d1c47229494afd00920346645bcf74138e3e6d947154cdc3b0171590db5'
