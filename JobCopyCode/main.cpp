#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
char s[20];
bool judge(char s[]){//判断是哪种模式：R233C456模式 或 cc12。
	int l=strlen(s);
	int ans=0;
	for(int i=1;i<l;i++)
		if((s[i]>='0'&&s[i]<='9')&&(s[i-1]>='A'&&s[i-1]<='Z'))//i-1为字母,i为数字.R233C456.
			ans++;

	if(ans==2)   return true;//为R233C456模式，先数字行 后字母列。
	return false;//为cc12模式，先字母列 后数字行。
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",s);
		if(judge(s)){//为R233C456模式，先数字行 后字母列。
			int l=strlen(s);
			int r=0,c=0;
			int rr=1,cc=1;
			int i,j;
			for(i=l-1;i>=0;i--){
				if(s[i]>='A'&&s[i]<='Z')//处理完列数,遇到C,跳出for
					break;
				if(s[i]>='0'&&s[i]<='9'){
					c+=cc*(s[i]-'0');
					cc*=10;//数字字符 转成10进制,从后往前增大10的幂次cc。
				}
			}

			for(j=i-1;j>=0;j--) {
				if(s[j]>='A'&&s[j]<='Z')//处理完行数,遇到R,跳出for
					break;
				if(s[j]>='0'&&s[j]<='9'){
					r+=rr*(s[j]-'0');
					rr*=10;//从后往前增大幂次rr。
				}
			}
			stack<char>st;
			while(!st.empty())
				st.pop();//定义栈后保证栈为空。
			while(c){//类似对c求26进制,//求余后,用栈倒序输出。
				int num=c%26;
				if(num==0){
					st.push('Z');
					c--;
				}else
					st.push(num-1+'A');
				c/=26;
			}
			while(!st.empty()) {
				printf("%c",st.top());
				st.pop();
			}
			printf("%d\n",r);
		}else{
			int r=0,c=0;
			int rr=1,cc=1;
			int i,j,l=strlen(s);
			stack<char>st;
			stack<char>nt;
			while(!nt.empty())//定义栈后保证栈为空。
				nt.pop();//number数字栈
			while(!st.empty())//定义栈后保证栈为空。
				st.pop();//string字母栈
			for(i=0;i<l;i++){
				if(s[i]>='0'&&s[i]<='9')//遇到数字,停止入栈。
					break;
				st.push(s[i]);//string字母栈
			}
			for(j=i;j<l;j++){
				nt.push(s[j]);//number数字栈
			}
			while(!st.empty()){
				c+=cc*(st.top()-'A'+1);//'B'-'A'=1，但'B'对应2.所以加1。
				cc*=26;//字母字符 转成10进制,从后往前增大26的幂次cc。
				st.pop();
			}
			while(!nt.empty()){
				r+=rr*(nt.top()-'0');//'2'-'0'=2，
				rr*=10;//数字字符 转成10进制,从后往前增大10的幂次cc。
				nt.pop();
			}
			printf("R%dC%d\n",r,c);
		}
	}
	system("pause");
	return 0;
}