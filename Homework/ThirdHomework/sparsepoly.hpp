#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101    // 다항식 처리 가능한 최대 차수 +1

class SparsePoly {
	int numTerms;     // 다항식 항의 개수
	std::vector<int> exponents;        // 각 항의 차수 저장 벡터
	std::vector<float> coefficients;   // 각 항의 계수 저장 벡터

public:
	//생성자
	SparsePoly(){}

	// 다항식 입력 함수
	void read() {
		printf("항의 개수를 입력하세요 : ");
		scanf_s("%d", &numTerms);
		for (int i = 0; i < numTerms; i++) {
			float coef;
			int exp;

			printf("%d번째 항의 계수와 차수를 입력하세요 (예: 계수 차수 ): ", i + 1);
			scanf_s("%f %d", &coef, &exp);

			coefficients.push_back(coef);
			exponents.push_back(exp);
		}
	}

	// 다항식 출력 함수
    void display(const char* str) {
        printf("%s", str);

        for (int i = 0; i < numTerms; i++) {
            float coef = coefficients[i];
            int exp = exponents[i];

            // 항 사이에 + 또는 - 부호 출력
            if (i > 0) {
                if (coef >= 0)
                    printf(" + ");
                else
                    printf(" - ");
                coef = fabs(coef); // 이미 부호 출력했으므로 절댓값 사용
            }
            else {
                // 첫 항이 음수일 경우 - 붙이기
                if (coef < 0) {
                    printf("-");
                    coef = fabs(coef);
                }
            }
             printf("%.2fx^%d", coef, exp); // 일반 항     
        }

        printf("\n");
    }


	//다항식 덧셈 함수
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        numTerms = 0;
        coefficients.clear();
        exponents.clear();

        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] == b.exponents[j]) {
                float sumCoef = a.coefficients[i] + b.coefficients[j];
                if (sumCoef != 0) {
                    coefficients.push_back(sumCoef);
                    exponents.push_back(a.exponents[i]);
                    numTerms++;
                }
                i++;
                j++;
            }
            else if (a.exponents[i] > b.exponents[j]) {
                coefficients.push_back(a.coefficients[i]);
                exponents.push_back(a.exponents[i]);
                i++;
                numTerms++;
            }
            else { // b.exponents[j] > a.exponents[i]
                coefficients.push_back(b.coefficients[j]);
                exponents.push_back(b.exponents[j]);
                j++;
                numTerms++;
            }
        }

        // 남은 항들 처리
        while (i < a.numTerms) {
            coefficients.push_back(a.coefficients[i]);
            exponents.push_back(a.exponents[i]);
            i++;
            numTerms++;
        }

        while (j < b.numTerms) {
            coefficients.push_back(b.coefficients[j]);
            exponents.push_back(b.exponents[j]);
            j++;
            numTerms++;
        }
    }

};