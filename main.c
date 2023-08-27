#include <stdio.h>
#include <stdlib.h>

#define Gold_Buy_default  1956
#define Gold_Sell_default  1926
#define Amount_default    2
#define BuyingYear        1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
<定期定量(48+4)g 一年期>
* 預設買入金價(g)固定為 1961
* 預設購買年期為一年
* 預設購買數量為 (2+2)g/月
* 每月金額為 (1961*2+600)*2=9044 /月
* 一年總金額為 9044*12 = 108528[成本]
<託售50g 一年期> 92折 (500g 9折, 1000g 88折)
* 預設賣出金價(g)為1939
* 50g價值為 1961*50+3000 = 101050
* 50g打92折後為 101050*0.92 = 92966
* 客戶每4g價值為 (1961*2+1000)*2 = 9844
* 以50g價值做預購贖回為 92966/9844 = 9.44組
* 至少需賣回10組 9844*10 = 98440
* 多於價值公司直退 98440-92966 = 5474 [A點獲利]
* 剩餘2g黃金以銀行買入價賣回公司為 2*1939 = 3878 [B點獲利]
* 公司應給客戶50g黃金價值為 1939*50 = 96950 [C點獲利]
* 加總A點+B點+C點獲利為 5474+3878+96950 = 106302[收入]
* 利潤計算: 106302-108528 = -2226
* 總收益為負的是發生什麼事了!!
<託售100g 一年期> 92折 (500g 9折, 1000g 88折)
* 預設賣出金價(g)為1939
* 100g價值為 1961*100+3500 = 199600
* 100g打92折後為 199600*0.92 = 183632
* 4g價值為 1961*4+1000+1000 = 9488
* 52g價值為 9488*13 = 123344
* (差48g價值)與92折後價差為 183632-123344 = 60288 [價差成本]
* 總收入贖回賣出價值為 1939*100=193900
* 總成本為 108528+60288 = 168816
* 總利潤為 193900-168816 = 25084
* 年化率為 (25084/168816/2)*100 = 6.46%
*/

int Cost_Month(void);
int Buy_CastFee_Sheet_OneYear(int Amount);
int Buy_CastFee_Sheet_TwoYear(int Amount);
int Buy_CastFee_Sheet_ThreeYear(int Amount);

void Memo_scanf(void)
{
  int input;

  printf("請輸入數字：");
  scanf("%d", &input);

  printf("你輸入的數字：%d\n", input);
}

void Memo_printf(void)
{
  printf("顯示字元 %c\n", 'A');
  printf("顯示字元編碼 %d\n", 'A');
  printf("顯示字元編碼 %c\n", 65);    
  printf("顯示十進位整數 %d\n", 15);
  printf("顯示八進位整數 %o\n", 15);
  printf("顯示十六進位整數 %X\n", 15);
  printf("顯示十六進位整數 %x\n", 15);    
  printf("顯示科學記號 %E\n", 0.001234);    
  printf("顯示科學記號 %e\n", 0.001234);
  
  printf("example:%6.2f\n", 19.234);
  printf("example:%-6.2f\n", 19.234);
  
  printf("%*d\n", 1, 1);
  printf("%*d\n", 2, 1);
  printf("%*d\n", 3, 1);
  
  printf("%.*s\n", 3, "Justin");
  printf("%.*s\n", 5, "Justin");
  printf("%.*s\n", 7, "Justin");

}

int main(int argc, char *argv[]) {
  int Cost;
  Cost = Cost_Month();
  printf("Cost of a month: %d", Cost);

  return 0;
}

void Cost_Year(void)
{
  int cost_m, cost_y;
  cost_m = Cost_Month();
  cost_y = cost_m*12;

  
}

int Cost_Month(void){
    int Gold, Amount, Cost;
    int CastFee;

    Gold = Gold_default;
    Amount = Amount_default;
    switch (BuyingYear)
    {
      case (1):
          CastFee = Buy_CastFee_Sheet_OneYear(Amount);
          break;
      case (2):
          CastFee = Buy_CastFee_Sheet_TwoYear(Amount);
          break;
      case (3):
          CastFee = Buy_CastFee_Sheet_ThreeYear(Amount);
          break;
    }
    Cost = (Gold * Amount)*2 + CastFee;
}

int Buy_CastFee_Sheet_OneYear(int Amount){
	switch (Amount)
	{
		case (1):
			return 360;
			break;
		case (2):
			return 600;
			break;
		case (5):
			return 900;
			break;
		case (10):
			return 1200;
			break;
		case (20):
			return 1500;
			break;
		case (50):
			return 1800;
			break;
		case (100):
			return 2100;
			break;
		case (250):
			return 4200;
			break;
		case (500):
			return 7200;
			break;
		case (1000):
			return 12000;
			break;

		default:
			return 0;
			break;

	}
}

int Buy_CastFee_Sheet_TwoYear(int Amount){
	switch (Amount)
	{
		case (1):
			return 240;
			break;
		case (2):
			return 400;
			break;
		case (5):
			return 600;
			break;
		case (10):
			return 800;
			break;
		case (20):
			return 1000;
			break;
		case (50):
			return 1200;
			break;
		case (100):
			return 1400;
			break;
		case (250):
			return 2800;
			break;
		case (500):
			return 4800;
			break;
		case (1000):
			return 8000;
			break;

		default:
			return 0;
			break;

	}
}

int Buy_CastFee_Sheet_ThreeYear(int Amount){
	switch (Amount)
	{
		case (1):
			return 120;
			break;
		case (2):
			return 200;
			break;
		case (5):
			return 300;
			break;
		case (10):
			return 400;
			break;
		case (20):
			return 500;
			break;
		case (50):
			return 600;
			break;
		case (100):
			return 700;
			break;
		case (250):
			return 1400;
			break;
		case (500):
			return 2400;
			break;
		case (1000):
			return 4000;
			break;

		default:
			return 0;
			break;

	}
}
    
