#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
char s[20];
bool judge(char s[]){//�ж�������ģʽ��R233C456ģʽ �� cc12��
	int l=strlen(s);
	int ans=0;
	for(int i=1;i<l;i++)
		if((s[i]>='0'&&s[i]<='9')&&(s[i-1]>='A'&&s[i-1]<='Z'))//i-1Ϊ��ĸ,iΪ����.R233C456.
			ans++;

	if(ans==2)   return true;//ΪR233C456ģʽ���������� ����ĸ�С�
	return false;//Ϊcc12ģʽ������ĸ�� �������С�
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",s);
		if(judge(s)){//ΪR233C456ģʽ���������� ����ĸ�С�
			int l=strlen(s);
			int r=0,c=0;
			int rr=1,cc=1;
			int i,j;
			for(i=l-1;i>=0;i--){
				if(s[i]>='A'&&s[i]<='Z')//����������,����C,����for
					break;
				if(s[i]>='0'&&s[i]<='9'){
					c+=cc*(s[i]-'0');
					cc*=10;//�����ַ� ת��10����,�Ӻ���ǰ����10���ݴ�cc��
				}
			}

			for(j=i-1;j>=0;j--) {
				if(s[j]>='A'&&s[j]<='Z')//����������,����R,����for
					break;
				if(s[j]>='0'&&s[j]<='9'){
					r+=rr*(s[j]-'0');
					rr*=10;//�Ӻ���ǰ�����ݴ�rr��
				}
			}
			stack<char>st;
			while(!st.empty())
				st.pop();//����ջ��֤ջΪ�ա�
			while(c){//���ƶ�c��26����,//�����,��ջ���������
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
			while(!nt.empty())//����ջ��֤ջΪ�ա�
				nt.pop();//number����ջ
			while(!st.empty())//����ջ��֤ջΪ�ա�
				st.pop();//string��ĸջ
			for(i=0;i<l;i++){
				if(s[i]>='0'&&s[i]<='9')//��������,ֹͣ��ջ��
					break;
				st.push(s[i]);//string��ĸջ
			}
			for(j=i;j<l;j++){
				nt.push(s[j]);//number����ջ
			}
			while(!st.empty()){
				c+=cc*(st.top()-'A'+1);//'B'-'A'=1����'B'��Ӧ2.���Լ�1��
				cc*=26;//��ĸ�ַ� ת��10����,�Ӻ���ǰ����26���ݴ�cc��
				st.pop();
			}
			while(!nt.empty()){
				r+=rr*(nt.top()-'0');//'2'-'0'=2��
				rr*=10;//�����ַ� ת��10����,�Ӻ���ǰ����10���ݴ�cc��
				nt.pop();
			}
			printf("R%dC%d\n",r,c);
		}
	}
	system("pause");
	return 0;
}