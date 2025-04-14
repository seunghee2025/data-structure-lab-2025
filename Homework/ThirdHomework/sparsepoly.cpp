#include "sparsepoly.hpp"

int main() {
	// 희소 다항식 A와 B 생성
	SparsePoly A;
	SparsePoly B;

	// 다항식 A 입력 후 확인
	A.read();
	A.display("Poly A: ");

	// 다항식 B 입력 후 확인
	B.read();
	B.display("Poly B: ");

	// A와 B를 더한 값을 C에 저장 후 확인
	SparsePoly C;
	C.add(A, B);
	C.display("Poly C: ");
}