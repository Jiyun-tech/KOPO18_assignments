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
		printf("환전을 원하는 금액을 입력하세요(원화) : ");
		scanf("%d", &inputKRW);
		do {
			printf("환전을 원하는 외화 번호를 선택하세요. (1:USD, 2:JPY, 3:EURO, 4.CNY, 5:GBP) : ");
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
		
		printf("기준 환율 : %10.2f\n", appliedFXRATE);
		printf("원금 : %d 원\n", inputKRW);
		printf("*환전 결과*\n");
		printf("환전 :  %d ", outputForeignCurrencyFinal);
		switch (inputNumber) {
			case 1: printf("달러\n");
			break;
			case 2: printf("엔\n");
			break;
			case 3: printf("유로\n");
			break;
			case 4: printf("위안\n");
			break;
			case 5: printf("파운드\n");
			break;
		} 
	
		if (inputNumber ==1) {
			changeForeignCurrency1000 = outputForeignCurrencyFinal/1000;
			changeForeignCurrency500 = outputForeignCurrencyFinal%1000/500;
			changeForeignCurrency100 = outputForeignCurrencyFinal%1000%500/100;
			changeForeignCurrency50 = outputForeignCurrencyFinal%1000%500%100/50;
			changeForeignCurrency10 = outputForeignCurrencyFinal%1000%500%100%50/10;
			changeForeignCurrency5 = outputForeignCurrencyFinal%1000%500%100%50%10/5;
			printf(" ==> 1000달러 X %d개, 500달러 X %d개, 100달러 X %d개, 50달러 X %d개, 10달러 X %d개\n, 5달러 X %d개"
					, changeForeignCurrency1000, changeForeignCurrency500, changeForeignCurrency100
					, changeForeignCurrency50, changeForeignCurrency10, changeForeignCurrency5);
		} else if (inputNumber ==2) {
			changeForeignCurrency10000 = outputForeignCurrencyFinal/10000;
			changeForeignCurrency5000 = outputForeignCurrencyFinal%10000/5000;
			changeForeignCurrency1000 = outputForeignCurrencyFinal%10000%5000/1000;
			changeForeignCurrency500 = outputForeignCurrencyFinal%10000%5000%1000/500;
			changeForeignCurrency100 = outputForeignCurrencyFinal%10000%5000%1000%500/100;
			printf(" ==> 10000엔 X %d개, 5000엔 X %d개, 1000엔 X %d개, 500엔 X %d개, 100엔 X %d개\n"
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
			printf(" ==> 500유로 X %d개, 200유로 X %d개, 100유로 X %d개, 50유로 X %d개, 20유로 x %d개, 10유로 X %d개, 5유로 X %d\n"
					, changeForeignCurrency500, changeForeignCurrency200, changeForeignCurrency100, changeForeignCurrency50
					, changeForeignCurrency20, changeForeignCurrency10, changeForeignCurrency5);
		} else if (inputNumber ==4) {
			changeForeignCurrency100 = outputForeignCurrencyFinal/100;
			changeForeignCurrency50 = outputForeignCurrencyFinal%100/50;
			changeForeignCurrency20 = outputForeignCurrencyFinal%100%50/20;
			changeForeignCurrency10 = outputForeignCurrencyFinal%100%50%20/10;
			printf(" ==> 100위안 X %d개, 50위안 X %d개, 20위안 x %d개, 10위안 X %d개\n"
					, changeForeignCurrency100, changeForeignCurrency50, changeForeignCurrency20, changeForeignCurrency10);
		} else if (inputNumber ==5) {
			changeForeignCurrency50 = outputForeignCurrencyFinal/50;
			changeForeignCurrency20 = outputForeignCurrencyFinal%50/20;
			changeForeignCurrency10 = outputForeignCurrencyFinal%50%20/10;
			changeForeignCurrency5 = outputForeignCurrencyFinal%50%20%10/5;
			printf(" ==> 50파운드 X %d개, 20파운드 x %d개, 10파운드 X %d, 5파운드 X %d\n"
					, changeForeignCurrency50, changeForeignCurrency20, changeForeignCurrency10, changeForeignCurrency5);
		}
	
		printf("거스름돈 : %d 원\n", returnKRWFinal);
		printf(" ==> 1000 원 X %d개, 500원 X %d개, 100원 X %d개, 50원 X %d개, 10원 X %d개\n"
					, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
		printf("========================================\n");
	}
		
	return 0;
}
