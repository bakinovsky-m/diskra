#include <iostream>
#include <vector>

bool check(int i, int j, int h, int w, std::vector<std::vector<int>> ma) {
	if(i < h && i >= 0 && j < w && j>= 0){
		if(ma[i][j] != 2){
			return true;
		}
	}
	return false;
}

int convert(int i, int j, int w){
	return (w*i + j);
}

void print_vector(std::vector<int> v){
	// std::cout << v.size();
	for(int i = 0; i < v.size(); i++){
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

// int dfs()

int main(){
	int h = 3, w = 3;

	int m[h][w] = {
		{0, 0, 1},
		{0,2,0},
		{3,0,0}
	};

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			std::cout << m[i][j];
		}
		std::cout << std::endl;
	}


	std::vector<std::vector<int>> ma;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			ma.push_back(std::vector<int>());
			ma[i].push_back(m[i][j]);
		}
	}

	// for(int i = 0; i < h; i++){
	// 	print_vector(ma[i]);

	// }
	
	std::cout << std::endl;

	std::vector<std::vector<int>> tabl;

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			std::vector<int> temp;

			if (ma[i][j] == 2){
				print_vector(temp);
				tabl.push_back(temp);
				continue;
			}

			if(check(i, j+1, h, w, ma)){
				temp.push_back(convert(i, j+1, w));
			}
			if(check(i, j-1, h, w, ma)){
				temp.push_back(convert(i, j-1, w));
			}
			if(check(i+1, j, h, w, ma)){
				temp.push_back(convert(i+1, j, w));
			}
			if(check(i-1, j, h, w, ma)){
				temp.push_back(convert(i-1, j, w));
			}
			print_vector(temp);
			tabl.push_back(temp);
		}
	}

	return 0;
}