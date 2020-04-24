# BlumBlumShub
A practice in pseudorandom bit generation using prime number residue systems. This specific implementation is the Blum-Blum-Shub algorithm with a seed of 3.

Program name:blum
Author: Parker Buckley
Date Created: 3/25/2020

Purpose: This program is a practice in pseudorandom bit generation using the Blum-Blum-Shub algorithm.
	 We take two large primes, p1 and p2,  and a value x that is coprime to p1*p2. This is the seed.
	 All of the pseudorandom bits are generated by taking the least significant bit of x = x^2 in the system
	 (mod p1*p2). In this program we analyze the properties of a 100,000 bit array of peusdorandom bits for cryptographic
	 security.

Compilation and Usage:

	Build: type "make" in the command line to build the program.

	Usage: type "./blum" in the command line to run the program.

