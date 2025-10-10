#include <stdio.h>

int main(){
    int t; scanf("%d", &t);
    int kase = 1;
    while(t--){
        long long arr[25];
        long long nums[5];
        for (int i = 0; i < 25; i++){
            scanf("%lld", &arr[i]);
        }
        for (int i = 0; i < 24; i++){
            for (int j = 0; j < 24-i; j++){
                if (arr[j] > arr[j+1]){
                    long long temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        
        nums[4] = arr[24]/2;
        nums[0] = arr[0]/2;
        nums[1] = arr[1] - nums[0];
        nums[3] = arr[23] - nums[4];
        nums[2] = arr[4] - nums[0];
        printf("Case #%d: %lld %lld %lld %lld %lld\n", kase, nums[0], nums[1], nums[2], nums[3], nums[4]);
		kase++;
		
		}

	return 0;
}