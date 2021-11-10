#include <stdio.h>
#include <math.h>
int main(void)
{
	int cases;
	scanf("%d",&cases);

	while(cases--){
		double res;
		long long int eu;
    scanf("%lld",&eu);

		res = ((sqrt(1 + 8*eu)) - 1);
    res = res/2;
    int var = res;
		printf("%d\n", var);
	}
	return 0;
}