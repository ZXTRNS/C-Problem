#include <stdio.h>
#include <string.h>

int main(){
	int TC;
	double kwh, priceAwal, newKwh, tax, priceAkhir, tambahan, gabungan, rata2;
	char type[10];
	scanf("%d", &TC);
	
	for (int i=1; i<=TC; i++){
		scanf("%lf %s", &kwh, &type);
		
		if (strcmp (type, "Urban") == 0){
			tax = 0.10;
		} else if (strcmp (type, "Rural") == 0){
			tax = 0.05;
		} else if (strcmp (type, "Suburban") == 0){
			tax = 0;
		}
		
		if (kwh <= 100){
			priceAwal = kwh * 0.10;
			tambahan = priceAwal * tax;
			priceAkhir = priceAwal + tambahan;
			
			printf("Household %d: $%.2lf\n", i, priceAkhir);
		} else if (kwh > 100 && kwh <= 300){
			newKwh = kwh - 100.00;
			priceAwal = 10.00 + (newKwh * 0.15);
			tambahan = priceAwal * tax;
			priceAkhir = priceAwal + tambahan;
			
			printf("Household %d: $%.2lf\n", i, priceAkhir);
		} else if (kwh > 300){
			newKwh = kwh - 300.00;
			priceAwal = 40.00 + (newKwh * 0.20);
			tambahan = priceAwal * tax;
			priceAkhir = priceAwal + tambahan;
			
			printf("Household %d: $%.2lf\n", i, priceAkhir);
		}
		gabungan += priceAkhir;	
	}
	printf("Total bill: $%.2lf\n", gabungan);
	rata2 = gabungan / TC;
	printf("Average bill per household: $%.2lf\n", rata2);
	
	
	return 0;
}
