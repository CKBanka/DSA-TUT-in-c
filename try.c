#include<stdio.h>
#include<stdlib.h>
int main(){
	int t;
	scanf("%d",&t);
	int n,h;
	int num,max1=0,max2=0;
	int ans;
	while(t-->0){
		max1=0;
		max2=0;
		scanf("%d%d",&n,&h);
		while(n-->0){
			scanf("%d",&num);
			if(num>max1){
				max2=max1;
				max1=num;
			}
			else if(num>max2){
				max2=num;
			}
		}
		ans=h/(max1+max2);
		ans=ans*2;
		if(h%(max1+max2)>max1){
			ans=ans+2;
		}
		else if(h%(max1+max2)>0){
			ans=ans +1;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}