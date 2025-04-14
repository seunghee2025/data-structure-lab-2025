#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101    // ���׽� ó�� ������ �ִ� ���� +1

class SparsePoly {
	int numTerms;     // ���׽� ���� ����
	std::vector<int> exponents;        // �� ���� ���� ���� ����
	std::vector<float> coefficients;   // �� ���� ��� ���� ����

public:
	//������
	SparsePoly(){}

	// ���׽� �Է� �Լ�
	void read() {
		printf("���� ������ �Է��ϼ��� : ");
		scanf_s("%d", &numTerms);
		for (int i = 0; i < numTerms; i++) {
			float coef;
			int exp;

			printf("%d��° ���� ����� ������ �Է��ϼ��� (��: ��� ���� ): ", i + 1);
			scanf_s("%f %d", &coef, &exp);

			coefficients.push_back(coef);
			exponents.push_back(exp);
		}
	}

	// ���׽� ��� �Լ�
    void display(const char* str) {
        printf("%s", str);

        for (int i = 0; i < numTerms; i++) {
            float coef = coefficients[i];
            int exp = exponents[i];

            // �� ���̿� + �Ǵ� - ��ȣ ���
            if (i > 0) {
                if (coef >= 0)
                    printf(" + ");
                else
                    printf(" - ");
                coef = fabs(coef); // �̹� ��ȣ ��������Ƿ� ���� ���
            }
            else {
                // ù ���� ������ ��� - ���̱�
                if (coef < 0) {
                    printf("-");
                    coef = fabs(coef);
                }
            }
             printf("%.2fx^%d", coef, exp); // �Ϲ� ��     
        }

        printf("\n");
    }


	//���׽� ���� �Լ�
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

        // ���� �׵� ó��
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