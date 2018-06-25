
#include <iostream>
#include <string.h>

const char SIGNATURE[] = "HSSC";

int encode(std::istream& inp, std::ostream& outp) {
	// TODO...
	std::cerr << "Encoding!" << std::endl;
	return 0;
}

int decode(std::istream& inp, std::ostream& outp) {
	auto start = inp.tellg();
	char testSignature[5];
	inp.get(testSignature, 5);
	if (strcmp(testSignature, SIGNATURE)) {
		inp.seekg(start);
		return -1;
	}

	// TODO...
	std::cerr << "Decoding!" << std::endl;
	return 0;
}

int main() {
	if (decode(std::cin, std::cout) == -1) {
		return encode(std::cin, std::cout);
	}
}

