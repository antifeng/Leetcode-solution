
#include <stdio.h>
#include <string>

using namespace std;

void printPermuatation2(string str){

  int perm=1, digits=str.size();

	for (int i=1;i<=digits;perm*=i++);

	for (int a=0;a<perm;a++)
	{
		std::string avail = str;

		for (int b=digits,div=perm;b>0; b--) 
		{
			div=div/b;
			int index = (a/div)%b;
			printf("%c", avail[index] );
			avail.erase(index,1) ;
		}
		printf("\n");
	}
	printf("permutations:%d\n",perm);
}



void swap(string& s, int a, int b){
  char temp = s[a];
  s[a] = s[b];
  s[b] = temp;
}

void printPermutation(string str, int start, int end){

  if (start == end)
    printf("%s\n", str.c_str());

  for (int i=start; i<end; i++){
    swap(str, start, i);
    printPermutation(str, start+1, end);
    swap(str, start, i);
  }
}


int main()
{
  printf("This is a solution for permutation of string\n");
  string test("abcd");
  printPermutation(test, 0, 4);
  return 1;
}












-UU-:**--F1  permutation.c   All L24    (C/l Abbrev)------------------------------------------------------------------------------------------------------------
Find alternate file: ~/Desktop/practice/permutation/permutation.c
