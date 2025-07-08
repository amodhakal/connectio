all:
	g++ -std=c++17 -Wall -Werror src/*.cpp -o connectio

clean:
	rm connectio

run_computer:
	make all
	./connectio computer
