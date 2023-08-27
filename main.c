#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
<定期定量(48+4)g 一年期>
* 預設買入金價(g)固定為 1961
* 預設購買年期為一年
* 預設購買數量為 (2+2)g/月
* 每月金額為 (1961*2+600)*2=9044 /月
* 一年總金額為 9044*12 = 108528[成本]

<託售50g 一年期4g一單位> 92折 (500g 9折, 1000g 88折)
* 預設賣出金價(g)為1939
* 50g價值為 1961*50+3000 = 101050
* 50g打92折後為 101050*0.92 = 92966
* 客戶每4g價值為 (1961*2+1000)*2 = 9844
* 以50g價值做預購贖回為 92966/9844 = 9.44組
* 至少需賣回10組*4g=(40g) 9844*10 = 98440
* 多於價值公司直退 98440-92966 = 5474 [A點獲利]
* 剩餘52-40=12g黃金以銀行買入價賣回公司為 12*1939 = 23268 [B點獲利]
* 公司應給客戶50g黃金價值為 1939*50 = 96950 [C點獲利]
* 加總A點+B點+C點獲利為 5474+23268+96950 = 125692[收入]
* 利潤計算: 125692-108528 = 17164

<託售50g 一年期2g一單位> 92折 (500g 9折, 1000g 88折)
* 客戶每2g價值為 (1961*2+1000) = 4922
* 以50g價值做預購贖回為 92966/4922 = 18.88組
* 至少需賣回19組*2g=(38g) 4922*19 = 93518
* 多於價值公司直退 93518-92966 = 552 [A點獲利]
* 剩餘52-38=14g黃金以銀行買入價賣回公司為 12*1939 = 27146 [B點獲利]
* 公司應給客戶50g黃金價值為 1939*50 = 96950 [C點獲利]
* 加總A點+B點+C點獲利為 552+27146+96950 = 124648[收入]
* 利潤計算: 124648-108528 = 16120

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


// #define Gold_Buy_default  1961
// #define Gold_Sell_default  1939
// #define Amount_default    2
// #define sets_default      2
// #define BuyingYear        1

/*----------------- functions prototype ------------------*/
void Setting_Input(void);
void Memo_printf(void);
/*----------------- 定期定量 functions prototype ------------------*/
void Cost_Year(void);
int Cost_Month(void);
int Buy_CastFee_Sheet_OneYear(int Amount);
int Buy_CastFee_Sheet_TwoYear(int Amount);
int Buy_CastFee_Sheet_ThreeYear(int Amount);
/*----------------- 託售計算 functions prototype ------------------*/
void Sell_Main(int cost_y);
float Sell_50g_less(void);
void Sell_100g_over(void);
int Sell_CastFee_Sheet(int Amount);

/* variables prototype */
int Gold_Buy_default, Gold_Sell_default, Amount_default;
int sets_default, BuyingYear;

void Setting_Input(void)
{
  printf("please key in the price of buying Gold: ");
  scanf("%d", &Gold_Buy_default);
  printf("please key in the price of selling Gold: ");
  scanf("%d", &Gold_Sell_default);
  printf("please key in the amount of buying Gold: ");
  scanf("%d", &Amount_default);
  printf("please key in the set of buying Gold: ");
  scanf("%d", &sets_default);
  printf("please key in the year of buying Gold: ");
  scanf("%d", &BuyingYear);
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

  Setting_Input();

  // Cost = Cost_Month();
  // printf("Cost of a month: %d\r\n", Cost);
  // Cost = Cost*12;
  // printf("Cost of a Year: %d\r\n", Cost);

  Cost_Year();

  return 0;
}

/*----------------------定期定量計算--------------------*/
void Cost_Year(void)
{
  int cost_m, cost_y;
  cost_m = Cost_Month();
  printf("Cost of a month: %d\r\n", cost_m);
  cost_y = cost_m*12;
  printf("Cost of a Year: %d\r\n", cost_y);

  Sell_Main(cost_y);
  
}

int Cost_Month(void){
    int Gold, Amount, Cost;
    int CastFee;

    Gold = Gold_Buy_default;
    Amount = Amount_default;
    // printf("Gold: %d\r\n", Gold);
    // printf("Amount: %d\r\n", Amount);

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
    Cost = (Gold * Amount + CastFee) * sets_default;
    // printf("sets_default: %d\r\n", sets_default);
    // printf("CastFee: %d\r\n", CastFee);
    // printf("Cost: %d\r\n", Cost);

    return Cost;
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

/*------------------------託售計算-----------------------*/
void Sell_Main(int cost_y)
{
  // int valueof50g;
  // float t1, valueof50g_92;
  int CastFee, Amount=50;;
  float valueof50g_92;

  int income_5g=0, income_year=0, set_int;
  float set;
  int refund, restGold, value50g, restincome;
  int TotalIncome, TotalProfit;

  //50g成本
  valueof50g_92 = Sell_50g_less();

  //5g價值
  printf("----------the value of 5g gold--------\r\n");
  CastFee = Sell_CastFee_Sheet(Amount_default);
  printf("CastFee: %d\r\n", CastFee);
  income_5g = Gold_Buy_default * Amount_default + CastFee;
  printf("income_5g: %d\r\n", income_5g);
  set = (float)(valueof50g_92/income_5g);
  printf("set: %.2f\r\n", set);
  set_int = (int)set+1;
  printf("set_int: %d\r\n", set_int);

  //多餘金額直退[A點獲利]
  printf("----------[profit by A]--------\r\n");
  refund = income_5g * set_int - (int)valueof50g_92;
  printf("refund: %d\r\n", refund);

  //剩餘黃金賣回公司[B點獲利]
  printf("----------[profit by B]--------\r\n");
  restGold = Amount_default * (sets_default * 13 - set_int);
  printf("restGold: %d\r\n", restGold);
  restincome = restGold * Gold_Sell_default;
  printf("restincome: %d\r\n", restincome);

  //50g黃金賣回公司價值[C點獲利]
  printf("----------[profit by C]--------\r\n");
  value50g = Gold_Sell_default * Amount;
  printf("value50g: %d\r\n", value50g);

  //總收入
  TotalIncome = refund + restincome + value50g;
  printf("TotalIncome: %d\r\n", TotalIncome);

  //總獲利
  TotalProfit = TotalIncome - cost_y;
  printf("TotalProfit: %d\r\n", TotalProfit);
}

float Sell_50g_less(void)
{
  int valueof50g;
  int CastFee, Amount=50;
  float t1, valueof50g_92;

  //50g成本
  printf("----------50g gold price calculate--------\r\n");
  CastFee = Sell_CastFee_Sheet(Amount);
  printf("CastFee: %d\r\n", CastFee);
  valueof50g = (Gold_Buy_default*Amount+CastFee);
  printf("Gold_Buy_default: %d\r\n", Gold_Buy_default);
  printf("Amount: %d\r\n", Amount);
  printf("CastFee: %d\r\n", CastFee);
  printf("valueof50g: %d\r\n", valueof50g);

  t1 = (float)(valueof50g*23);
  printf("t1: %.2f\r\n", t1);
  valueof50g_92 = (float)(t1/25);  
  printf("valueof50g_92: %.2f\r\n", valueof50g_92);

  return valueof50g_92;
}

void Sell_100g_over(void)
{

}

int Sell_CastFee_Sheet(int Amount){
	switch (Amount)
	{
		case (1):
			return 600;
			break;
		case (2):
			return 1000;
			break;
		case (5):
			return 1500;
			break;
		case (10):
			return 2000;
			break;
		case (20):
			return 2500;
			break;
		case (50):
			return 3000;
			break;
		case (100):
			return 3500;
			break;
		case (250):
			return 7000;
			break;
		case (500):
			return 12000;
			break;
		case (1000):
			return 20000;
			break;

		default:
			return 0;
			break;

	}
}

