// KOPO18 ������ (2022.04.13)
// ��&�� �Է¹޾� �޷� ����ϱ�
// ����: 1900�� 1�� 1�� = ������ 

#include <stdio.h>

int main() {
	
	int inputYear;				// �Է� ���� ���� ��. 
	int inputMonth;				// �Է� ���� �� ��. 
	
	int leapYearNumber; 		// 1900��~(inputYear-1)���� ���� ���� 
	int daysFrom1900; 			// 1900��~(inputYear-1)���� �� ��¥ ���� (1900.01.01 = 1) 
	int daysFromThisYear;		// inputYear�� ù �� ~  (inputMonth-1)���� �� �ϼ�. 
	int firstDayOfinputMonth; 	// 1900��~(inputYear inputMonth.01) ���� �� �ϼ�. => inputYear-Month�� ù��° ���� ���� �������� ��� �� ���. 
	int daysOfinputMonth;		// �Է� ���� ���� ��¥ ����. 
	
	int inputYearDays[12];		// inputYear�� ���� �ϼ� �Է��� �迭. 
	int normalYearDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 	// ��� 
	int leapYearDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		// ���� 
	
	printf("���� �Է� : ");
	scanf("%d", &inputYear);
	printf("�� �Է� : ");
	scanf("%d", &inputMonth);
	
	// ************************************************************
	// <inputYear, inputMonth�� ù ��° ���� ����ϱ� ����!>
	
	// 1900��~ (inputYear-1) ���� �� ��¥ ���� (���� : 1900.01.01 => 1, 1900.01.02 => 2) 
	// *����) 1900���� 4�� ���������, 100�� ����̱⵵ �ϹǷ� & 400�� ����� �ƴϹǷ� ������ �ƴ�. 
	// 1. 1900�� ~  (inputYear-1) ���� �� ���� ���� ���ϱ� 
	if (inputYear > 2000) {
		leapYearNumber = ((inputYear - 1900 - 1)/4 + 1) - ((inputYear - 1900 - 1)/100+1) + ((inputYear - 2000 - 1)/400+1);
	} else {
		leapYearNumber = ((inputYear - 1900 - 1)/4 + 1) - ((inputYear - 1900 - 1)/100+1);
	}
	// 2. 1900�� ~  (inputYear-1) ���� �� ��¥ �� ���ϱ� (���� ����Ͽ� ���� ����ŭ ��¥ �����ֱ�) 
	daysFrom1900 = 365*(inputYear - 1899 - 1) + (leapYearNumber * 1);
	
	// 3. inputYear 1�� 1�� ~ (inputMonth-1)���� ��¥ ���� ���ϱ� 
	// 3-1. inputYear ���� or ��� ���� Ȯ���Ͽ� inputYear�� ���� ��¥ �� �ֱ� 
	if ( (inputYear%4 == 0 && inputYear%100 != 0) || inputYear%400 == 0) {
		for (int indexA = 1; indexA <= 12; indexA++) {
			inputYearDays[indexA-1] = leapYearDays[indexA-1];
		}
	} else {
		for (int indexB = 1; indexB <= 12; indexB++) {
			inputYearDays[indexB-1] = normalYearDays[indexB-1];
		}
	}
	// 3-2.  inputYear�� 1������ ~ inputMonth �� ������ ��¥ ���ϱ�.
	if (inputMonth > 1) { 	// 1���� �ƴ� ��� -> 1�� ~ (inputMonth-1)���� ���� ��¥ ����. 
		daysFromThisYear = 0;
		for (int indexC = 1; indexC <= inputMonth-1; indexC++) {
			daysFromThisYear = daysFromThisYear + inputYearDays[indexC-1];
		}
	} else { 				// 1���� ��� -> 0 
			daysFromThisYear = 0;
	}
	
	// 4. 1900����� inputYear�� inputMonth ù ��° ������ �� ��¥ �� (=> firstDayOfinputMonth)
	// (1900.01.01 = 1, 1900.01.2 = 2, ...) 
	firstDayOfinputMonth = daysFrom1900 + daysFromThisYear + 1; 
	// *����) 1900.01.01 = 1 (��), 1900.01.2 = 2 (ȭ), ...
	// ==> if (firstDayOfinputMonth % 7 == 1) ==> firstDayOfinputMonth�� ������!
	// ==> 0 �� 1 �� 2 ȭ 3 �� 4 �� 5�� 6 �� 
	
	// <inputYear, inputMonth�� ù ��° ���� ����ϱ� ��!>
	// ************************************************************
	
	
	// inputYear�� inputMonth�� ��ĥ���� �ִ��� Ȯ�� ==> daysOfinputMonth
	// ������ ��� & ����� ��� ����� Ȯ�� 
	if ( (inputYear%4 == 0 && inputYear%100 != 0) || inputYear%400 == 0) {
		daysOfinputMonth = leapYearDays[inputMonth-1];
	} else {
		daysOfinputMonth = normalYearDays[inputMonth-1];
	}
	
	// ********** �޷� ����Ʈ ����
	printf("\n======= %d�� %d�� =======\n", inputYear, inputMonth);
	printf("��\t��\tȭ\t��\t��\t��\t��\n");
	// �ش� �� ���� ���Ͽ� ���� ���� (\t) ���.
	// (firstDayOfinputMonth % 7) => 0 �� 1 �� 2 ȭ 3 �� 4 �� 5�� 6 �� 
	for (int indexD = 0; indexD < (firstDayOfinputMonth % 7); indexD++) {
		if (indexD == 6) {
			break;
		} else {
			printf("\t");
		}
	}
		
	// ��¥ �μ� => ����� ��¥ �μ� �� ���� & �� �� ���� ��¥ �μ� �� tab 
	// (indexE % 7) => 0 �� 1 �� 2 ȭ 3 �� 4 �� 5�� 6 �� 
	for (int indexE = firstDayOfinputMonth; indexE < firstDayOfinputMonth+daysOfinputMonth; indexE++) {
		if (indexE%7 == 6) { 	// �����
			printf("%d\n", indexE-firstDayOfinputMonth+1);
		} else {				// ����� �� ����
			printf("%d\t", indexE-firstDayOfinputMonth+1);
		}
	}
	// �޷� ������Ʈ ���� ********** 
	
	return 0;
} 
