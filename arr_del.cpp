#include <string>
#include <iostream>
#include <algorithm>

class Arr{
public:
	Arr() = default;
	~Arr();
	int * arr = nullptr;
	int length = 0;

	void add(int el);
	void del(int n);

	std::string toString() const;
};


void Arr::add(int el){
	if(length == 0){
		length += 1;
		arr = new int[length];
		arr[0] = el;
	} else{
		int * temp = new int[length];

		for(int i = 0; i < length; i++){
			temp[i] = arr[i];
		}

		length += 1;
		delete arr;
		arr = new int [length];
		for(int i = 0; i < length-1; i++){
			arr[i] = temp[i];
		}
		arr[length-1] = el;

		delete temp;
	}
}


void Arr::del(int n){
	int * temp = new int[length];

	for(int i = 0; i < length; i++){
		temp[i] = arr[i];
	}

	delete arr;
	length -= 1;
	arr = new int [length];
	bool flag = false;
	for(int i = 0; i < length + 1; i++){
		if((i+1) == n){
			flag = true;
		} else {
			if(flag){
				arr[i-1] = temp[i];
			}
			else {
				arr[i] = temp[i];
			}
		}
	}

	delete temp;
}

std::string Arr::toString() const {
	std::string str = "";
	for(int i = 0; i < length; i++){
		str += std::to_string(arr[i]);
	}
	return str;
}

Arr::~Arr(){
	delete arr;
}

int main(){
	Arr a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);

	std::cout << a.toString() << std::endl;

	a.del(3);

	std::cout << a.toString() << std::endl;	
	return 0;
}