#include <iostream>
#include <vector>

class Cell{
public:
	Cell() = default;
	Cell(char t);
	int type = 0;
	bool visited = false;
};
Cell::Cell(char type_){
	if(type_ == ' ')
			type = 0;
	else if(type_ == '#')
			type = 1;
	else if(type_ == '.')
			type = 2;
	else if(type_ == '*')
			type = 3;

	visited = false;

}

void print_vector(std::vector<int> v){
	// std::cout << v.size();
	for(int i = 0; i < v.size(); i++){
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

int main(){
	int h = 3, w = 3;
	// char m[h][w] = {
	// "    .",
	// " ##  ",
	// "   # ",
	// " *  #"
	// };
	// char m[h][w]{
	// 	"00.",
	// 	"0#0",
	// 	"000"
	// };

	int m[h][w]{
		{0, 0, 1},
		{0,2,0},
		{0,0,0}
	};

	//Cell maze[h][w];
	// std::cout << "m[1][1]" << std::endl;
	// std::cout << m[1][1] << std::endl;
	// if(m[1][1] == '#'){
	// 	std::cout << "ALARM" << std::endl;
	// }

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			std::cout << m[i][j];
			// maze[i][j] = Cell(m[i][j]);
			// std::cout << maze[i][j].type;
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

	for(int i = 0; i < h; i++){
		print_vector(ma[i]);

	}
	std::cout << std::endl;

	std::cout << ma.at(1).at(-1) << std::endl;

	std::cout << std::endl;

	std::vector<std::vector<int>> tabl;

	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			std::vector<int> temp;
			for(int k = 0; k < h*w; k++){
				// if (m[i][j-1] != '#' && m[i][j+1] != '#' && m[i-1][j] != '#' && m[i+1][j] != '#' ){
				if ( ((i*w + j + 1) == k || (i*w + j - 1) == k || ((i+1)*w + j) == k || ((i-1)*w + j) == k) && **(m + k + 1) != 2){
					temp.push_back(k);
				}
			}
			print_vector(temp);
			tabl.push_back(temp);
		}
	}

	for (int i = 0; i < h; i++){
		std::vector<int> temp;
		for (int k = 0; k < h*w; k++){
			// if ( )
		}
	}



	// std::cout << tabl[0] << std::endl;
	// print_vector(tabl[0]);

	return 0;
}