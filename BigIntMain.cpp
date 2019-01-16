#include <iostream>
#include <stdio.h>
#include <string>
#include "BigInt.h"

using namespace std;


int main() {

	string a = "10032";
	string b = "987";
	BigInt x,y;
	BigInt myBigInt(a), myBigInt2(b),sum,mul,copy,result,sub;
	sum = myBigInt.addBigInt(myBigInt2);
	cout << "sum:";sum.printAll();
	mul = myBigInt.multiplyBigInt(myBigInt2);
	cout << "mul:";mul.printAll();
	sub = myBigInt.subBigInt(myBigInt2);
	cout << "sub:";sub.printAll();
	/*if ( sub.addBigInt(myBigInt2).isGreater(myBigInt) == -1 )
		cout << "Correct!" << endl;*/
	//myBigInt.printAll();
	//sum = myBigInt.addBigInt(myBigInt2);
	//sum.printAll();
	/*myBigInt.printAll();
	myBigInt2.printAll();
	mul = myBigInt.multiplyBigInt(myBigInt2);
	mul.printAll();
	myBigInt.printAll();
	sum = myBigInt.addBigInt(myBigInt2);
	sum.printAll();
	cout << mul.size() << endl;
	cout << myBigInt.size() << endl;
	cout << myBigInt2.size() << endl;*/
	/*FILE * file;
  	int c,operation = 0,token = 0;
  	int n = 0;
  	file=fopen ("BigInt.txt","r");
  	if (file==NULL)
		cout << "Error opening file." << endl;
	else {
		while (1){
			c = fgetc (file);
			if ( feof(file) )
				break;
			if (c == '+') {
				operation = 1;
				token++;
			}
			if (c == '-') {
				operation = 2;
				token++;
			}
			if (c == '*' || c == 'x') {
				operation = 3;
				token++;
			}
			if (c == '/') {
				operation = 4;
				token++;
			}
			if (c-'0' >= 0 && c-'9' <= 0 && token == 0)
			x.addToTail(c-'0');
			if (c-'0' >= 0 && c-'9' <= 0 && token == 1)
			y.addToTail(c-'0');
		}
	}
	switch ( operation ) {
	case 1:
		result = x.addBigInt(y);
		break;
	case 2:
		break;
	case 3:
		result = x.multiplyBigInt(y);
		break;
	case 4:
		break;
	default:
		break;
	}
	fclose(file);
	x.printAll();
	y.printAll();
	result.printAll();*/
}

/*int addBigInt(BigInt x, BigInt y) {
	int carry = 0, size_dif = 0;
	BigIntDigit *tmpx, *tmpy;
	tmpx = x.getTail();
	tmpy = y.getTail();
	if (x.size() > y.size()) {
		size_dif = x.size() - y.size();
		for (int i = 0; i < size_dif; i++)
			y.addToHead(0);
	}
	else {
		size_dif = y.size() - x.size();
		for (int i = 0; i < size_dif; i++)
			x.addToHead(0);
	}
	BigInt newBigInt;
	for  (int i = 0; i < x.size(); i++) {
		if (tmpx->info + tmpy->info > 9) {
			newBigInt.addToHead(tmpx->info + tmpy->info + carry - 10);
			carry = 1;
		}
		else {
			newBigInt.addToHead(tmpx->info + tmpy->info + carry);
			carry = 0;
		}
		tmpx = tmpx->prev;
		tmpy = tmpy->prev;
	}
	newBigInt.printAll();
		
}

int subBigInt(BigInt x, BigInt y) {
	int carry = 0, size_dif = 0;
	BigIntDigit *tmpx, *tmpy;
	tmpx = x.getTail();
	tmpy = y.getTail();
	if (x.size() > y.size()) {
		size_dif = x.size() - y.size();
		for (int i = 0; i < size_dif; i++)
			y.addToHead(0);
	}
	else {
		size_dif = y.size() - x.size();
		for (int i = 0; i < size_dif; i++)
			x.addToHead(0);
	}
	BigInt newBigInt;
	for  (int i = 0; i < x.size(); i++) {
		if (tmpx->info >= tmpy->info) {
			newBigInt.addToHead(tmpx->info - tmpy->info);
		}
		else {
			newBigInt.addToHead(tmpx->info + 10 - tmpy->info);
			carry = 0;
		}
		tmpx = tmpx->prev;
		tmpy = tmpy->prev;
	}
	newBigInt.printAll();
		
}*/
	
