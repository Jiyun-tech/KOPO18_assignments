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
	float FXRATE_Input[]= {1233.5, 9.87, 1342.42, 193.21, 1604.97}; // 각 외화의 환율 배열로 선언 
	float FXRATE;													// 선택한 외화에 따른 환율 할당할 변수. 
	float appliedFXRATE = 0; 			// if 조건문 활용하여 선택하는 외화의 환율을 해당 변수에 할당 예정 
	int inputKRW = 0; 					// scanf로 받을 원화 
	int inputNumber = 0;  				// scanf로 받을 외화 선택 
	float outputForeignCurrency = 0; 	// 계산하여 나올 외화 환전 값 
	int outputForeignCurrencyFinal = 0; // 계산하여 나올 외화 환전 값 (10 or 100 단위 아래 절삭) 
	int returnKRW = 0; 					// 원화 거스름돈 
	int returnKRWFinal = 0; 			// 원화 거스름돈 (10원 단위 아래 절삭) 
	int returnKRW1000 = 0, returnKRW500 = 0, returnKRW100 = 0, returnKRW50 = 0, returnKRW10 = 0;
										// 원화 거스름돈 출력 단위 
	int changeForeignCurrency10000 = 0, changeForeignCurrency5000 = 0, changeForeignCurrency1000 = 0,
		changeForeignCurrency500 = 0, changeForeignCurrency200 = 0, changeForeignCurrency100 = 0,
		changeForeignCurrency50 = 0, changeForeignCurrency20 = 0, changeForeignCurrency10 = 0, 
		changeForeignCurrency5 = 0; 	// 외화 거스름돈 출력 단위 
	char currencyNameInput[5][10] = {"달러","엔","유로","위안","파운드"};	//각 외화의 이름 해당 배열로 선언 
	char *currencyName;														//선택한 외화에 따른 화폐 이름 할당할 변수. 

	while(true) { // 원화 입력 & 환전 계속 반복 
		printf("환전을 원하는 금액을 입력하세요(원화) : ");
		scanf("%d", &inputKRW);
		do {
			printf("환전을 원하는 외화 번호를 선택하세요. (1:USD, 2:JPY, 3:EURO, 4.CNY, 5:GBP) : ");
			scanf("%d", &inputNumber);
		} while (inputNumber < 1 || inputNumber > 5);
		printf("============================================================\n");
		
		
		// 환전 계산 시작 
		FXRATE = FXRATE_Input[inputNumber-1];
		outputForeignCurrency = inputKRW/FXRATE;
		if (inputNumber == 1 || inputNumber == 3 || inputNumber == 5) { // USD, EUR, GBP 
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/5*5; // 5 아래로 절삭
		} else if (inputNumber == 2) { // JPY
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/100*100; // 100 아래로 절삭
		} else if (inputNumber == 4) { // CNY
			outputForeignCurrencyFinal = ((int)outputForeignCurrency)/10*10; // 10 아래로 절삭
		}
		
		// 원화 거스름돈 계산 시작 
		returnKRW = (int)(inputKRW - outputForeignCurrencyFinal * FXRATE); 
		returnKRWFinal = returnKRW - returnKRW%10;
		
		// 원화 거스름돈 돌려주는 방법 계산 (화폐 단위별 수량) 
		returnKRW1000 = returnKRWFinal/1000;
		returnKRW500 = returnKRWFinal%1000/500;
		returnKRW100 = returnKRWFinal%1000%500/100;
		returnKRW50 = returnKRWFinal%1000%500%100/50;
		returnKRW10 = returnKRWFinal%1000%500%100%50/10;
		
		currencyName = currencyNameInput[inputNumber-1];
		
		// 출력
		printf("기준 환율 : %10.2f원/%s\n", FXRATE, currencyName);
		printf("원금 : %d 원\n", inputKRW);
		printf("*환전 결과*\n");
		printf("환전 :  %d %s\n", outputForeignCurrencyFinal, currencyName);
		printf("거스름돈 : %d 원\n", returnKRWFinal);
		printf(" ==> 1000 원 X %d개, 500원 X %d개, 100원 X %d개, 50원 X %d개, 10원 X %d개\n"
						, returnKRW1000, returnKRW500, returnKRW100, returnKRW50, returnKRW10);
		printf("============================================================\n");
		}
			
		return 0;
}
