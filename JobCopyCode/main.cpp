#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
void testCharArr(){
	char* c[]={"abcd","ef","gh","ijk"};
	for (int i=0;i<4;i++){ 
		printf("%c",*c[i]);//���ÿ���ַ��������ַ�aegi
		// printf("%s",*c[i]);//*c[i]ָ������ַ�,���ܰ�%s�ַ������.
		printf("\n %s \n",c[i]);//c[i]ָ������ַ���,���abcd ef gh ijk.
	}
}
int main(){
	testCharArr();
	system("pause");
	return 0;
}