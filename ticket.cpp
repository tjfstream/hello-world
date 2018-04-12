#include<stdio.h>
double max_n(int* n){
	double dis = 0, max = 0, m;
	for(int i = 0; i < *n; ++i)
	{
		scanf("%lf", &dis);
		if(dis > max)
		{
		max = dis;
		m = i + 1;
		}
	}
	*n = m;
	return max;
}
int main(){
	int price, con, n;
	int point[2][100], i = 0;
	double min, m;
	double dis, dpr;
	double min_end[100] = { 0 };
	while(scanf("%d%d%d", &price, &con, &n) != EOF){
		min = price - con;
		dis = max_n(&n);
		dpr = (double)price * (1 - dis);
		if(min > dpr)
		min = dpr;
		min_end[i] = (min > dpr) ? dpr : min;
		point[0][i] = (min == price - con) ? 1 : 2;
		point[1][i] = n;
		++i;
	}
	for(int j = 0; j < i; ++j)
	if(point[0][j] == 1)
	printf("APP %.2lf\n", min_end[j]);
	else
	printf("%d %.2lf\n", point[1][j], min_end[j]); 
	return 0;
} 
