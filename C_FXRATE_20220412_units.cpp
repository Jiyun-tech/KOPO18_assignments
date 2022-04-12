// Exchange Korean Won for foreign currency. (FXRate as of April 11th, 2022)
// foreign currency : USD, JPY, EUR, CNY, GBP
// print out the exchange result (exchanged foreing currency & refunded Korean Won changes)
// print out the Korean Won changes in currency units (1,000won / 500won / 100won/ 50won/ 10won)
// print out the exchanged Foreign Currency in currency units (e.g. 1000USD X 2unit, 500USD X 1unit, ...)
// use "if" to select the foreign currency to exchange
// use "do while" to return to select currency process when the user choose the wrong number


#include <stdio.h>
#include <string.h>

int main () {
	const float FXRATE_USD = 1233.5, FXRATE_JPY = 9.87 /*100JPY*/, FXRATE_EUR = 1342.42, 
				FXRATE_CNY = 193.21, FXRATE_GBP = 1604.97;
	float appliedFXRATE = 0; 
	int inputKRW = 0; 
	int inputNumber = 0; 
	float outputForeignCurrency = 0;
	int outputForeignCurrencyFinal = 0;
	int returnKRW = 0; 
	int returnKRWFinal = 0;
	int returnKRW1000 = 0, returnKRW500 = 0, returnKRW100 = 0, returnKRW50 = 0, returnKRW10 = 0;
	int changeForeignCurrency10000 = 0, changeForeignCurrency5000 = 0, changeForeignCurrency1000 = 0,
		changeForeignCurrency500 = 0, changeForeignCurrency200 = 0, changeForeignCurrency100 = 0,
		changeForeignCurrency50 = 0, changeForeignCurrency20 = 0, changeForeignCurrency10 = 0, 
		changeForeignCurrency5 = 0;
//	string currencyName;

	while(true) {
		printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
		scanf("%d", &inputKRW);
		do {
			printf("ȯ���� ���ϴ� ��ȭ ��ȣ�� �����ϼ���. (1:USD, 2:JPY, 3:EURO, 4.CNY, 5:GBP) : ");
			scanf("%d", &inputNumber);
		} while (inputNumber < 1 || inputNumber > 5);
		printf("========================================\n");
		
		if (inputNumber ==1) {
			appliedFXRATE = FXRATE_USD;
		} else if (inputNumber ==2) {
			appliedFXRATE = FXRATE_JPY;
		} else if (inputNumber ==3) {
			appliedFXRATE = FXRATE_EUR;
		} else if (inputNumber ==4) {
			appliedFXRATE = FXRATE_CNY;
		} else if (inputNumber ==5) {
			appliedFXRATE = FXRATE_GBP;
		}
		
		outputForeignCurrency = inputKRW / appliedFXRATE;
		if (inputNumber == 1 || inputNumber == 3 || inputNumber == 5) {
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/5*5;
		} else if (inputNumber == 2) {
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/100*100;
		} else if (inputNumber == 4) {
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/10*10;
		}	
		returnKRW = inputKRW - outputForeignCurrencyFinal * appliedFXRATE; 
		returnKRWFinal = returnKRW - returnKRW%10;
		
		returnKRW1000 = returnKRWFinal/1000;
		returnKRW500 = returnKRWFinal%1000/500;
		returnKRW100 = returnKRWFinal%1000%500/100;
		returnKRW50 = returnKRWFinal%1000%500%100/50;
		returnKRW10 = returnKRWFinal%1000%500%100%50/10;
		
		printf("���� ȯ�� : %10.2f\n", appliedFXRATE);
		printf("���� : %d ��\n", inputKRW);
		printf("*ȯ�� ���*\n");
		printf("ȯ�� :  %d ", outputForeignCurrencyFinal);
		switch (inputNumber) {
			case 1: printf("�޷�\n");
			break;
			case 2: printf("��\n");
			break;
			case 3: printf("����\n");
			break;
			case 4: printf("����\n");
			break;
			case 5: printf("�Ŀ��\n");
			break;
		} 
	
		if (inputNumber ==1) {
			changeForeignCurrency1000 = outputForeignCurrencyFinal/1000;
			changeForeignCurrency500 = outputForeignCurrencyFinal%1000/500;
			changeForeignCurrency100 = outputForeignCurrencyFinal%1000%500/100;
			changeForeignCurrency50 = outputForeignCurrencyFinal%1000%500%100/50;
			changeForeignCurrency10 = outputForeignCurrencyFinal%1000%500%100%50/10;
			changeForeignCurrency5 = outputForeignCurrencyFinal%1000%500%100%50%10/5;
			printf(" ==> 1000�޷� X %d��, 500�޷� X %d��, 100�޷� X %d��, 50�޷� X %d��, 10�޷� X %d��\n, 5�޷� X %d��"
					, changeForeignCurrency1000, changeForeignCurrency500, changeForeignCurrency100
					, changeForeignCurrency50, changeForeignCurrency10, changeForeignCurrency5);
		} else if (inputNumber ==2) {
			changeForeignCurrency10000 = outputForeignCurrencyFinal/10000;
			changeForeignCurrency5000 = outputForeignCurrencyFinal%10000/5000;
			changeForeignCurrency1000 = outputForeignCurrencyFinal%10000%5000/1000;
			changeForeignCurrency500 = outputForeignCurrencyFinal%10000%5000%1000/500;
			changeForeignCurrency100 = outputForeignCurrencyFinal%10000%5000%1000%500/100;
			printf(" ==> 10000�� X %d��, 5000�� X %d��, 1000�� X %d��, 500�� X %d��, 100�� X %d��\n"
					, changeForeignCurrency10000, changeForeignCurrency5000, changeForeignCurrency1000
					, changeForeignCurrency500, changeForeignCurrency100);
		} else if (inputNumber ==3) {
			changeForeignCurrency500 = outputForeignCurrencyFinal/500;
			changeForeignCurrency200 = outputForeignCurrencyFinal%500/200;
			changeForeignCurrency100 = outputForeignCurrencyFinal%500%200/100;
			changeForeignCurrency50 = outputForeignCurrencyFinal%500%200%100/50;
			changeForeignCurrency20 = outputForeignCurrencyFinal%500%200%100%50/20;
			changeForeignCurrency10 = outputForeignCurrencyFinal%500%200%100%50%20/10;
			changeForeignCurrency5 = outputForeignCurrencyFinal%500%200%100%50%20%10/5;
			printf(" ==> 500���� X %d��, 200���� X %d��, 100���� X %d��, 50���� X %d��, 20���� x %d��, 10���� X %d��, 5���� X %d\n"
					, changeForeignCurrency500, changeForeignCurrency200, changeForeignCurrency100, changeForeignCurrency50
					, changeForeignCurrency20, changeForeignCurrency10, changeForeignCurrency5);
		} else if (inputNumber ==4) {
			changeForeignCurrency100 = outputForeignCurrencyFinal/100;
			changeForeignCurrency50 = outputForeignCurrencyFinal%100/50;
			changeForeignCurrency20 = outputForeignCurrencyFinal%100%50/20;
			changeForeignCurrency10 = outputForeignCurrencyFinal%100%50%20/10;
			printf(" ==> 100���� X %d��, 50���� X %d��, 20���� x %d��, 10���� X %d��\n"
					, changeForeignCurrency100, changeForeignCurrency50, changeForeignCurrency20, changeForeignCurrency10);
		} else if (inputNumber ==5) {
			changeForeignCurrency50 = outputForeignCurrencyFinal/50;
			changeForeignCurrency20 = outputForeignCurrencyFinal%50/20;
			changeForeignCurrency10 = outputForeignCurrencyFinal%50%20/10;
			changeForeignCurrency5 = outputForeignCurrencyFinal%50%20%10/5;
			printf(" ==> 50�Ŀ�� X %d��, 20�Ŀ�� x %d��, 10�Ŀ�� X %d, 5�Ŀ�� X %d\n"
					, changeForeignCurrency50, changeForeignCurrency20, changeForeignCurrency10, changeForeignCurrency5);
		}
	
		printf("�Ž����� : %d ��\n", returnKRWFinal);
		printf(" ==> 1000 �� X %d��, 500�� X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��\n"
					, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
		printf("========================================\n");
	}
		
	return 0;
}