#include <iostream>

using namespace std;


class BigIntDigit {
public:
	BigIntDigit() {
		next = prev = 0;
	}
	BigIntDigit(int el, BigIntDigit *n = 0, BigIntDigit *p = 0) {
		info = el; next = n; prev = p;
	}
	int info;
	BigIntDigit *next, *prev;
};



class BigInt {
private:
	BigIntDigit *head, *tail;
	int sign_bit;
public:
	BigInt() {
		head = tail = 0;
	}
	/*~BigInt() {
		clear();
	}*/
	BigInt(string s) {
		head = tail = new BigIntDigit(s[0] - '0',0,0);
		for (int i = 1; i < s.size(); i++){
			tail = new BigIntDigit(s[i] - '0',0,tail);
			tail->prev->next = tail;
		}
	}
	/*BigInt(const BigInt &n) {
		BigIntDigit* tmp;
		tmp = n.head;
		while (tmp != 0) {
			tail = new BigIntDigit(tmp->info,0,tail);
			tail->prev->next = tail;
			tmp = tmp->next;
		}
	}*/
	void updateBigInt(BigInt n) {
		BigIntDigit* tmp;
		tmp = n.head;
		head = tail = new BigIntDigit(tmp->info,0,0);
		tmp = tmp->next;
		while (tmp != 0) {
			tail = new BigIntDigit(tmp->info,0,tail);
			tail->prev->next = tail;
			tmp = tmp->next;
		}
	}
	BigInt(int size) {
		head = tail = new BigIntDigit(0,0,0);
		for (int i = 1; i <size; i++){
			tail = new BigIntDigit(0,0,tail);
			tail->prev->next = tail;
		}
	}
	void addToTail(int a) {
		if (tail != 0) {
			tail = new BigIntDigit(a,0,tail);
			tail->prev->next = tail;
		}
		else 
			head = tail = new BigIntDigit(a,0,0);
	}
	void addToHead(int a) {
		if (head != 0) {
			head = new BigIntDigit(a,head,0);
			head->next->prev = head;
		}
		else 
			head = tail = new BigIntDigit(a,0,0);
	}
	int deleteFromTail() {
		int return_info;
		return_info = tail->info;
		if (tail == head) {
			delete head;
			head = tail = 0;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = 0;
		}
		return return_info;
	}
	int deleteFromHead() {
		int return_info;
		return_info = head->info;
		if (tail == head) {
			delete head;
			head = tail = 0;
		}
		else {
			head = head->next;
			delete head->prev;
			head->prev = 0;
		}
		return return_info;
	}
	void printAll() {
		for (BigIntDigit* tmp = head; tmp !=0; tmp = tmp->next) {
			cout << tmp->info;
		}
		cout << endl;
	}
	int returnHead() {
		if (head != 0)
			return head->info;
	}
	BigIntDigit* getTail() {
		if (tail != 0)
			return tail;
	}
	int size() {
		BigIntDigit *tmp = head;
		int cnt = 0;
		while (tmp != 0) {
			cnt++;
			tmp = tmp->next;
		}
		return cnt;
	}
	void deleteZeros(){
		BigIntDigit *tmp;
		tmp = this->head;
		while (tmp != 0 && tmp->info == 0 ) {
			this->deleteFromHead();
			tmp = tmp->next;
		}
	}
	int isGreater(BigInt y) {		// 1:x>y 0:x<y 	-1:x=y
		if ( this->size() > y.size() )
			return 1;
		else if ( y.size() > this->size() )
			return 0;
		else {
			BigIntDigit *tmpx, *tmpy;
			tmpx = this->head;
			tmpy = y.head;
			while (tmpx != 0){
				if ( tmpx->info > tmpy->info ) {
					return 1;
					break;
				}
				else if ( tmpy->info > tmpx->info ) {
					return 0;
					break;
				}
				else { 
					tmpx = tmpx->next;
					tmpy = tmpy->next;
				}
			}
			return -1;
		}

		
	}
	/*void clear() {
		BigIntDigit* tmp;
		while (head !=0){
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}*/
	BigInt addBigInt(BigInt y) {
		int carry = 0, size_dif = 0,count1=0,count2=0;
		BigIntDigit *tmpx, *tmpy;
		tmpx = this->tail;
		tmpy = y.tail;
		if (this->size() > y.size()) {
			size_dif = this->size() - y.size();
			for (int i = 0; i < size_dif; i++) {
				y.addToHead(0);
				count1++;
			}
		}
		else {
			size_dif = y.size() - this->size();
			for (int i = 0; i < size_dif; i++) {
				this->addToHead(0);
				count2++;
			}
		}
		BigInt newBigInt;
		for  (int i = 0; i < this->size(); i++) {
			if (tmpx->info + tmpy->info + carry > 9) {
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
		if (carry == 1)
			newBigInt.addToHead(1);
		this->deleteZeros();
		y.deleteZeros();
		return newBigInt;
		//newBigInt.printAll();
		
	}
	BigInt multiplyBigInt(BigInt y){
		int count = 0, info_mult,carry = 0;
		BigInt mul = 0,sum;
		BigIntDigit *tmpx, *tmpy;
		for  (tmpx = this->tail; tmpx != this->head->prev; tmpx = tmpx->prev) {
			sum = 0;
			for  (tmpy = y.tail; tmpy != y.head->prev; tmpy = tmpy->prev) {
				info_mult = tmpx->info * tmpy->info;
				if (tmpy == y.head){
						sum.addToHead( (info_mult + carry) % 10);
						if (info_mult + carry > 9)
							sum.addToHead( (info_mult + carry) / 10);
				}	
				else {
					sum.addToHead( (info_mult + carry) % 10);
					carry = (info_mult + carry) / 10;
				}
				/*if (info_mult + carry  > 9) {
					if (tmpy == y.head){
						sum.addToHead( (info_mult + carry) % 10);
						sum.addToHead(info_mult / 10);
					}
					else {
					cout << "if1 ";
					sum.addToHead( (info_mult + carry) % 10);
					carry = info_mult / 10;
					}
				}
				else {
					cout << "if2 ";
					sum.addToHead(info_mult + carry);
					carry = 0;
				}*/
			}
			carry = 0;
			sum.deleteFromTail();
			for (int k = 0; k < count; k++) {
				sum.addToTail(0);
			}
			mul = mul.addBigInt(sum);
			count++; 
		}
		return mul; 
	}

	BigInt subBigInt(BigInt y) {
		int carry = 0, size_dif;
		BigIntDigit *tmpx, *tmpy, *search;
		BigInt result;
		tmpx = this->tail;
		tmpy = y.tail;
		if (this->size() > y.size()) {
			size_dif = this->size() - y.size();
			for (int i = 0; i < size_dif; i++) {
				y.addToHead(0);
			}
		}
		//this->printAll();
		//y.printAll();
		if ( this->isGreater(y) ){
			for  (int i = 0; i < this->size(); i++) {
				if ( tmpx->info >= tmpy->info ) {
					result.addToHead(tmpx->info - tmpy->info);
				}
				else {
					search = tmpx->prev;
					while (search->info == 0 && search != 0) {
						search = search ->prev;
					}
					search->info = search->info - 1;
					search = search->next;
					while (search != tmpx){
						search->info = 9;
						search = search->next;
						
					}
					tmpx->info = tmpx->info + 10;
					result.addToHead(tmpx->info - tmpy->info);
				}
				tmpx = tmpx->prev;
				tmpy = tmpy->prev;
			}
			//this->printAll();
			//y.printAll();
			y.deleteZeros();
			result.deleteZeros();
			return result;
		}
		else {
			return -1;
		}
	}

};


