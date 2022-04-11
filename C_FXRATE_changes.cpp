#include <stdio.h>

int main () {
	const float FXRATE_USD = 1233.5, FXRATE_JPY = 9.87, FXRATE_EUR = 1342.42, 
				FXRATE_CNY = 193.21, FXRATE_GBP = 1604.97;
	int inputKRW = 0; int inputNumber = 0; int returnKRW = 0; int returnKRWFinal = 0;
	int returnKRW1000 = 0;
	int returnKRW500 = 0;
	int returnKRW100 = 0;
	int returnKRW50 = 0;
	int returnKRW10 = 0;
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputKRW);
	printf("====================\n");
	
	// KRW -> USD
	float outputUSD = inputKRW / FXRATE_USD;
	int outputUSDFinal = outputUSD/1;
	int returnUSD1000 = outputUSDFinal/1000;
	int returnUSD500 = outputUSDFinal%1000/500;
	int returnUSD100 = outputUSDFinal%1000%500/100;
	int returnUSD50 = outputUSDFinal%1000%500%100/50;
	int returnUSD20 = outputUSDFinal%1000%500%100%50/20;
	int returnUSD10 = outputUSDFinal%1000%500%100%50%20/10;
	int returnUSD5 = outputUSDFinal%1000%500%100%50%20%10/5;
	int returnUSD1 = outputUSDFinal%1000%500%100%50%20%10%5/1;
	returnKRW = inputKRW - outputUSDFinal * FXRATE_USD; 
	returnKRWFinal = returnKRW- returnKRW%10;
	returnKRW1000 = returnKRWFinal/1000;
	returnKRW500 = returnKRWFinal%1000/500;
	returnKRW100 = returnKRWFinal%1000%500/100;
	returnKRW50 = returnKRWFinal%1000%500%100/50;
	returnKRW10 = returnKRWFinal%1000%500%100%50/10;
	printf("USD ���� ȯ�� : %10.2f\n", FXRATE_USD);
	printf("ȯ�� ���\n");
	printf("�޷� : %d �޷�(1000�޷�X%d��, 500�޷�X%d��, 100�޷�X%d��, 50�޷�X%d��, 10�޷�X%d��, 5�޷�X%d��, 1�޷�X%d��)\n"
			, outputUSDFinal, returnUSD1000,returnUSD500,returnUSD100,returnUSD50,returnUSD10,returnUSD5,returnUSD1);
	printf("�Ž����� : %d�� (1000 ��X %d��, 500��X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��)\n"
			,returnKRWFinal, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
	printf("====================\n");

	// KRW -> JPY
	float outputJPY = inputKRW / FXRATE_JPY;
	int outputJPYFinal = outputJPY/1;
	returnKRW = inputKRW - outputJPYFinal * FXRATE_JPY; 
	returnKRWFinal = returnKRW- returnKRW%10;
	returnKRW1000 = returnKRWFinal/1000;
	returnKRW500 = returnKRWFinal%1000/500;
	returnKRW100 = returnKRWFinal%1000%500/100;
	returnKRW50 = returnKRWFinal%1000%500%100/50;
	returnKRW10 = returnKRWFinal%1000%500%100%50/10;
	printf("JPY ���� ȯ�� : %10.2f\n", FXRATE_JPY);
	printf("ȯ�� ���\n");
	printf("�� :  %d ��\n", outputJPYFinal);
	printf("�Ž����� : %d�� (1000 ��X %d��, 500��X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��)\n"
			,returnKRWFinal, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
	printf("====================\n");

	// KRW -> EUR
	float outputEUR = inputKRW / FXRATE_EUR;
	int outputEURFinal = outputEUR/1;
	returnKRW = inputKRW - outputEURFinal * FXRATE_EUR; 
	returnKRWFinal = returnKRW- returnKRW%10;
	returnKRW1000 = returnKRWFinal/1000;
	returnKRW500 = returnKRWFinal%1000/500;
	returnKRW100 = returnKRWFinal%1000%500/100;
	returnKRW50 = returnKRWFinal%1000%500%100/50;
	returnKRW10 = returnKRWFinal%1000%500%100%50/10;
	printf("EUR ���� ȯ�� : %10.2f\n", FXRATE_EUR);
	printf("ȯ�� ��\n");
	printf("���� : %d ����\n", outputEURFinal);
	printf("�Ž����� : %d�� (1000 ��X %d��, 500��X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��)\n"
			,returnKRWFinal, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
	printf("====================\n");	 

	// KRW -> CNY
	float outputCNY = inputKRW / FXRATE_CNY;
	int outputCNYFinal = outputCNY/1;
	returnKRW = inputKRW - outputCNYFinal * FXRATE_CNY; 
	returnKRWFinal = returnKRW- returnKRW%10;
	returnKRW1000 = returnKRWFinal/1000;
	returnKRW500 = returnKRWFinal%1000/500;
	returnKRW100 = returnKRWFinal%1000%500/100;
	returnKRW50 = returnKRWFinal%1000%500%100/50;
	returnKRW10 = returnKRWFinal%1000%500%100%50/10;
	printf("CNY ���� ȯ�� : %10.2f\n", FXRATE_CNY);
	printf("ȯ�� ���\n");
	printf("���� : %d ����\n", outputCNYFinal);
	printf("�Ž����� : %d�� (1000 ��X %d��, 500��X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��)\n"
			,returnKRWFinal, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
	printf("====================\n");

	// KRW -> GBP
	float outputGBP = inputKRW / FXRATE_GBP;
	int outputGBPFinal = outputGBP/1;
	returnKRW = inputKRW - outputGBPFinal * FXRATE_GBP; 
	returnKRWFinal = returnKRW- returnKRW%10;
	returnKRW1000 = returnKRWFinal/1000;
	returnKRW500 = returnKRWFinal%1000/500;
	returnKRW100 = returnKRWFinal%1000%500/100;
	returnKRW50 = returnKRWFinal%1000%500%100/50;
	returnKRW10 = returnKRWFinal%1000%500%100%50/10;
	printf("GBP ���� ȯ�� : %10.2f\n", FXRATE_GBP);
	printf("ȯ�� ���\n");
	printf("�Ŀ�� : %d �Ŀ��\n", outputGBPFinal);
	printf("�Ž����� : %d�� (1000 ��X %d��, 500��X %d��, 100�� X %d��, 50�� X %d��, 10�� X %d��)\n"
			,returnKRWFinal, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
}
