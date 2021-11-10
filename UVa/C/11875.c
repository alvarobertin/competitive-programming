#include <stdio.h>
int main(){
	int t = 1,z,i = 0,n = 0;
	int nums[11] = {};	
	scanf("%d",&n);
	while (i < n){
		for(z = 0; z <= t ; z++){
			scanf("%d",&nums[z]);	
			t = nums[0];
		}
		i++;
		printf("Case %d: %d\n",i,nums[t/2+1]);
	}
	return 0;
}
