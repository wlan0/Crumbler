build: encoder decoder big_integer_comparator
	echo "compiled all"

encoder:
	cc simple_prefix_encoder.c ../lib/simple_prefix.o ../lib/simple_prefix_impl.o -I../include -o ../simple_prefix_encoder
	echo "compiled encoder"

decoder:
	cc simple_prefix_decoder.c ../lib/simple_prefix.o ../lib/simple_prefix_impl.o -I../include -o ../simple_prefix_decoder
	echo "compiled decoder"

big_integer_comparator:
	cc big_integer_comparator.c ../lib/big_integer_impl.o ../lib/big_integer.o -I../include -o ../big_integer_comparator
	echo "compiled big integer comparator"