default:
	@echo "use 'make build'"
.PHONY: build
build:
	rm -rf build
	mkdir build && cd build && cmake .. && make

run-contiguous:
	./build/CS4348OS_Project3 contiguous

run-chained:
	./build/CS4348OS_Project3 chained

run-indexed:
	./build/CS4348OS_Project3 indexed

export:
	git archive --prefix=CS4348OS_Project3/ -o ../CS4348OS_Project3.tar HEAD
	gzip -f ../CS4348OS_Project3.tar

tar:
	tar -zcv --exclude .git --exclude 'cmake*' --exclude .idea -f ../CS4348OS_Project3.tar.gz -C .. CS4348OS_Project3

cs1:
	scp ../CS4348OS_Project3.tar.gz cs1:
	ssh cs1 "rm -rf CS4348OS_Project3 build"
	ssh cs1 "tar -xvf CS4348OS_Project3.tar.gz &&  mkdir build && cd build && cmake  -DCMAKE_BUILD_TYPE=Debug ../CS4348OS_Project3 && make && ./CS4348OS_Project3"
