If n is prime, time complexity is O(sqrt(n)) -- highest
and space complexity is O(1) -- lowest

If n is 2^m, time complexity is O(logn) -- lowest
and space complexity is O(logn) -- highest

It is because when n has many prime factors, it needs a lot of space. For example, when n is 2^m like 1024, 1024=2*2*2*2*2*2*2*2*2*2。