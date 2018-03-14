#!/usr/bin/python3
# This script is used to check if the supplied guess is the flag

import hashlib, hmac
import sys

from flag_vars import hashHex

def test(guess):
	h = hashlib.sha256(bytes(guess, 'utf-8'))
	guessHex = h.hexdigest()
	correct = hmac.compare_digest(hashHex, guessHex)

	return(0 if correct else 1)


def main():
	if (len(sys.argv) < 2):
		print('Usage: %s <string_to_check>' % (sys.argv[0],))
		exit(2)
	guess = sys.argv[1]

	retval = test(guess)

	print('%s%s is %sthe correct flag!' % ('Sorry, ' if retval else '',
											'\'' + guess + '\'',
											'not ' if retval else ''))
	
	exit(retval)


if __name__ == '__main__':
	main()