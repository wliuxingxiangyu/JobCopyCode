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
		printf("%c",*c[i]);//输出每个字符串的首字符aegi
		// printf("%s",*c[i]);//*c[i]指向的是字符,不能按%s字符串输出.
		printf("\n %s \n",c[i]);//c[i]指向的是字符串,输出abcd ef gh ijk.
	}
}
int main(){
	testCharArr();
	system("pause");
	return 0;
}