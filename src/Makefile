db: clr
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B cmake-build-debug && cd cmake-build-debug && make
	# ./cmake-build-debug/Multilayer_Perceptron

t:
	cmake -S . -B cmake-build-test && cd cmake-build-test && make
	# ./cmake-build-test/Multilayer_Perceptron

clr:
	cd cmake-build-debug && rm -rf *
