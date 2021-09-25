#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int arr[100];
int bl = 0;

void arrange(int arr[],int idx,int N,int &tree_count,long long &height){
	int brr[100];
	if(idx==N){
		tree_count++;
		height += log2(arr[idx]) + 1;
		//printf("height = %d\n",height);
		printf("%d:",tree_count);
		if(idx==N){
			for(int i=1;i<N;i++){
				printf("%d,",arr[i]);
			}printf("%d\n",arr[N]);
		}
		return;
	}
	
	int cnt = 1; 
	for(int i=1;i<=idx;i++){
		if(arr[i]*2 > arr[idx]){
			brr[cnt++] = arr[i]*2;
		}
		if(arr[i]*2+1 > arr[idx]){
			brr[cnt++] = arr[i]*2+1;
		}
	}
	for(int i=1;i<cnt;i++){
		arr[idx+1] = brr[i];
		arrange(arr,idx+1,N,tree_count,height); 
	}
}
int x = 0;
long long heigh = 0;


void buildtree(int N,int &tree_count){
	int idx = 1;
	int arr[100];
	for(int i=1;i<=N;i++)arr[i] = i-1;
	arr[1] = 1;
	idx = 2;
	while(idx > 0){
		//printf("%d\n",idx);
		if(idx==N){
			for(int i=1;i<N;i++){
				if(arr[i]*2>arr[N-1]){
					arr[N] = arr[i]*2;
					tree_count++;
					printf("%d:",tree_count);
					if(idx==N){
						for(int i=1;i<N;i++){
							printf("%d,",arr[i]);
						}printf("%d\n",arr[N]);
					}

				}
				if(arr[i]*2+1>arr[N-1]){
					arr[N] = arr[i]*2+1;
					tree_count++;
					printf("%d:",tree_count);
					if(idx==N){
						for(int i=1;i<N;i++){
							printf("%d,",arr[i]);
						}printf("%d\n",arr[N]);
					}
				}
			}
		}
		int flag = 0;
		if(idx < N){
			//arr[idx] = arr[idx-1];
			for(int i=1;i<idx;i++){

				if(arr[i]*2>arr[idx]){
					flag = 1;
					arr[idx] = arr[i]*2;
					arr[idx+1] = arr[idx];
					break;
				}

				if(arr[i]*2+1>arr[idx]){
					flag = 1;
					arr[idx] = arr[i]*2+1;
					arr[idx+1] = arr[idx];
					break;
				}
			}	
		}
		if(flag)
			idx++;
		else 
			idx--;
	}
}
int main(){
	for(int i=1;i<=99;i++){arr[i]=0;}
	int n = 7;
	buildtree(7,x);
	printf("\n");
	// while(n < 18){
	// 	n++;heigh = 0;
	// 	x = 0;arr[1] = 1;
	// 	bl = n;	
	// x = 0;
	// for(int i=1;i<=99;i++){arr[i]=0;}
	// arr[1] = 1;
	// arrange(arr,1,n,x,heigh);

	// 	printf("tree_count is %d when N is %d\n",x,n);
	// 	printf("height = %lld, height/M = %f , height/M/log_2(N) = %lf  \n",heigh,heigh*1.0/x,heigh*1.0/x/log2(n));
	// 	printf("\n");
		
	// }
}
