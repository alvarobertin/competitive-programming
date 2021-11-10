#include <stdio.h>
int main(){
	int n,i = 0;	

	while (scanf("%d",&n) != EOF){
		int z;
		long long int multp = 1, multn = 1, mayor = 0;
		int nums[18];
		for (z = 0; z < n; ++z){
			scanf("%d",&nums[z]);
		}
		for (z = 0; z < n; ++z){
			if(nums[z] != 0){
				multp *= nums[z];
				multn *= nums[z];
				if(multp >= mayor){
					mayor = multp;
				}
				else{
					multp = 1;
				}
				if(multn >= mayor){
					mayor = multn;
				}
			}
			else{
				multn = 1;
				multp = 1;
			}
		}
		multp = 1; multn = 1;
		for (z = n - 1; z >= 0; --z){
			if(nums[z] != 0){
				multp *= nums[z];
				multn *= nums[z];
				if(multp >= mayor){
					mayor = multp;
				}
				else{
					multp = 1;
				}
				if(multn >= mayor){
					mayor = multn;
				}
			}
			else{
				multn = 1;
				multp = 1;
			}
		}
		i++;
		printf("Case #%d: The maximum product is %lli.\n",i,mayor);
		printf("\n");
	}
	return 0;
}