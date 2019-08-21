========================================================================
    SHA-3 Test fixture
========================================================================

This project is for testing the SHA-3 implementation according to the 
official test vectors. The test vectors can be retrieved from the NIST 
website at https://csrc.nist.gov/Projects/cryptographic-algorithm-validation-program/Secure-Hashing#sha3vsha3vss

At the moment, this code will read one of the test .rsp files and 
test the keccak implementation with it - it will create an input file
called "tst2.txt" from the test specification, run it with output 
redirected to "op", which is then read to determine if the output
matches that specified as correct in the .rsp file.

At present, we can do the SHA_3xxxLongMsg.rsp and SHA_3xxxShortMsg.rsp
files from the byte oriented implementation test suite. I haven't 
implemented the monte carlo tests yet.
