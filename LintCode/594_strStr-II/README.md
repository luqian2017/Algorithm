Solution is based on Rabin Karp.
It use hash function to calculate the hash code of strings.

For example, source = "abcde", target = "cd".

From source side, 
hashcode(cd) = (hashcode(bc + d) - hashcode(b)*2 ) % BASE