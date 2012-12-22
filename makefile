build: simple_prefix.o big_integer.o
	echo "Build Completed!"

big_integer.o: big_integer_impl.o
	cc -c src/big_integer.c lib/big_integer_impl.o -I./include -o lib/big_integer.o

big_integer_impl.o: 
	cc -c src/big_integer_impl.c -I./include -o lib/big_integer_impl.o

simple_prefix.o: simple_prefix_impl.o
	cc -c src/simple_prefix.c lib/simple_prefix_impl.o -I./include -o lib/simple_prefix.o

simple_prefix_impl.o: 
	cc -c src/simple_prefix_impl.c -I./include -o lib/simple_prefix_impl.o