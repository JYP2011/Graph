TARGET=test_target
all:
	g++ -g test_target.cc -I /usr/include -L /usr/local/lib -lgtest -lgtest_main -lpthread -o $(TARGET)
clean:
	rm -rf *.o $(TARGET)