// Exchange Korean Won for foreign currency. (FXRate as of April 11th, 2022)
// foreign currency : USD, JPY, EUR, CNY, GBP
// print out the exchange result (exchanged foreing currency & refunded Korean Won changes)
// print out the Korean Won changes in currency units (1,000won / 500won / 100won/ 50won/ 10won)
// print out the exchanged Foreign Currency in currency units (e.g. 1000USD X 2unit, 500USD X 1unit, ...)
// use "array" to select the foreign currency to exchange
// use "do while" to return to select currency process when the user choose the wrong number

#include <stdio.h>
#include <string.h>

int main () {
	float FXRATE_Input[]= {1233.5, 9.87, 1342.42, 193.21, 1604.97}; // �� ��ȭ�� ȯ�� �迭�� ���� 
	float FXRATE;													// ������ ��ȭ�� ���� ȯ�� �Ҵ��� ����. 
	float appliedFXRATE = 0; 			// if ���ǹ� Ȱ���Ͽ� �����ϴ� ��ȭ�� ȯ���� �ش� ������ �Ҵ� ���� 
	int inputKRW = 0; 					// scanf�� ���� ��ȭ 
	int inputNumber = 0;  				// scanf�� ���� ��ȭ ���� 
	float outputForeignCurrency = 0; 	// ����Ͽ� ���� ��ȭ ȯ�� �� 
	int outputForeignCurrencyFinal = 0; // ����Ͽ� ���� ��ȭ ȯ�� �� (10 or 100 ���� �Ʒ� ����) 
	int returnKRW = 0; 					// ��ȭ �Ž����� 
	int returnKRWFinal = 0; 			// ��ȭ �Ž����� (10�� ���� �Ʒ� ����) 
	int returnKRW1000 = 0, returnKRW500 = 0, returnKRW100 = 0, returnKRW50 = 0, returnKRW10 = 0;
										// ��ȭ �Ž����� ��� ���� 
	int changeForeignCurrency10000 = 0, changeForeignCurrency5000 = 0, changeForeignCurrency1000 = 0,
		changeForeignCurrency500 = 0, changeForeignCurrency200 = 0, changeForeignCurrency100 = 0,
		changeForeignCurrency50 = 0, changeForeignCurrency20 = 0, changeForeignCurrency10 = 0, 
		changeForeignCurrency5 = 0; 	// ��ȭ �Ž����� ��� ���� 
	char currencyNameInput[5][10] = {"�޷�","��","����","����","�Ŀ��"};	//�� ��ȭ�� �̸� �ش� �迭�� ���� 
	char *currencyName;														//������ ��ȭ�� ���� ȭ�� �̸� �Ҵ��� ����. 

	while(true) { // ��ȭ �Է� & ȯ�� ��� �ݺ� 
		printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
		scanf("%d", &inputKRW);
		do {
			printf("ȯ���� ���ϴ� ��ȭ ��ȣ�� �����ϼ���. (1:USD, 2:JPY, 3:EURO, 4.CNY, 5:GBP) : ");
			scanf("%d", &inputNumber);
		} while (inputNumber < 1 || inputNumber > 5);
		printf("============================================================\n");
		
		
		// ȯ�� ��� ���� 
		FXRATE = FXRATE_Input[inputNumber-1];
		outputForeignCurrency = inputKRW/FXRATE;
		if (inputNumber == 1 || inputNumber == 3 || inputNumber == 5) { // USD, EUR, GBP 
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/5*5; // 5 �Ʒ��� ����
		} else if (inputNumber == 2) { // JPY
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/100*100; // 100 �Ʒ��� ����
		} else if (inputNumber == 4) { // CNY
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/10*10; // 10 �Ʒ��� ����
		}
		
		// ��ȭ �Ž����� ��� ���� 
		returnKRW = (int)(inputKRW - outputForeignCurrencyFinal * FXRATE); 
		returnKRWFinal = returnKRW - returnKRW%10;
		
		// ��ȭ �Ž����� �����ִ� ��� ��� (ȭ�� ������ ����) 
		returnKRW1000 = returnKRWFinal/1000;
		returnKRW500 = returnKRWFinal%1000/500;
		returnKRW100 = returnKRWFinal%1000%500/100;
		returnKRW50 = returnKRWFinal%1000%500%100/50;
		returnKRW10 = returnKRWFinal%1000%500%100%50/10;
		
		currencyName = currencyNameInput[inputNumber-1];
		
		// ���
		printf("���� ȯ�� : %10.2f��/%s\n", FXRATE, currencyName);
		printf("���� : %d ��\n", inputKRW);
		printf("*ȯ�� ���*\n");
		printf("ȯ�� :  %d %s\n", outputForeignCurrencyFinal, currencyName);
		printf("�Ž����� : %d ��\n", returnKRWFinal);
		printf(" ==> 1000 �� X %d��, 500�� X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��\n"
						, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
		printf("============================================================\n");
		}
			
		return 0;
}
