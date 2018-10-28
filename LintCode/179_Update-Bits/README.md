Basic bit operation.
Note:
1) Always try to add () for bit operation as its priority is very low.

2)
int set_bit(int x, int n){
	return x |= (1 << n);
}
 
int clear_bit(int x, int n){
	return x &= ~ (1 << n);
}
 
bool get_bit(int x, int n){
	return x &= (1 << n);
}
