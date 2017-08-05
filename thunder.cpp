#include "thunder.h"
#include <QDebug>

Thunder::Thunder()
{
	_thunder = NULL;
	level = LOW;//初始化
	setLevel(level);
}

Thunder::~Thunder()
{
	if(_thunder != NULL)
	{
		for(int i = 0; i < this->height; i++)
		{
			delete []_thunder[i];
		}
		delete []_thunder;
	}
	_thunder = NULL;
}

int Thunder::getRestFlag() const
{
	int count = 0;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(_thunder[i][j].type==FLAG)
				count++;
		}
	}
	return thunder - count;
}

void Thunder::setSize(int width, int height)
{
	if(_thunder != NULL)
	{
		for(int i = 0; i < this->height; i++)
		{
			delete []_thunder[i];
		}
		delete []_thunder;
	}

	//重新分配
	_thunder = new struct Node *[height];
	for(int i = 0; i < height; i++)
	{
		_thunder[i] = new struct Node[width];
	}

	//初始化
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			_thunder[i][j].num = 0;
			_thunder[i][j].type = UNKNOW;
			_thunder[i][j].visited = false;//未访问过
		}
	}

	this->height = height;
	this->width = width;
}

int Thunder::getWidth() const
{
	return width;
}

int Thunder::getHeight() const
{
	return height;
}

Node **Thunder::getMap() const
{
	return _thunder;
}

Node *Thunder::at(int x, int y) const
{
	return &_thunder[x][y];
}

void Thunder::setThunder(int num)
{
	int temp;
	int count = 0;
	thunder = num;

	srand((unsigned)time(NULL));
	while(count<num)
	{
		temp = rand() % (height*width - 1);
		if(_thunder[temp / width][temp % width].num != -1)//-1表示已有雷，需要重新放置
		{
			_thunder[temp / width][temp % width].num = -1;//有雷的标志为-1
			count++;
		}
	}
}

void Thunder::setNum()
{
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(_thunder[i][j].num == -1)//有雷
			{
				if(i==0)//第一行
				{
					if(j==0)//左上角
					{
						if(_thunder[i+1][j].num != -1) _thunder[i+1][j].num++;//下
						if(_thunder[i][j+1].num != -1) _thunder[i][j+1].num++;//右
						if(_thunder[i+1][j+1].num != -1) _thunder[i+1][j+1].num++;//右下
					}
					else if(j==width-1)//右上角
					{
						if(_thunder[i+1][j].num != -1) _thunder[i+1][j].num++;//下
						if(_thunder[i][j-1].num != -1) _thunder[i][j-1].num++;//左
						if(_thunder[i+1][j-1].num != -1) _thunder[i+1][j-1].num++;//左下
					}
					else//第一行其他位置
					{
						if(_thunder[i+1][j].num != -1) _thunder[i+1][j].num++;//下
						if(_thunder[i][j-1].num != -1) _thunder[i][j-1].num++;//左
						if(_thunder[i][j+1].num != -1) _thunder[i][j+1].num++;//右
						if(_thunder[i+1][j-1].num != -1) _thunder[i+1][j-1].num++;//左下
						if(_thunder[i+1][j+1].num != -1) _thunder[i+1][j+1].num++;//右下
					}
				}
				else if(i==height-1)//最后一行
				{
					if(j==0)//左下角
					{
						if(_thunder[i-1][j].num != -1) _thunder[i-1][j].num++;//上
						if(_thunder[i][j+1].num != -1) _thunder[i][j+1].num++;//右
						if(_thunder[i-1][j+1].num != -1) _thunder[i-1][j+1].num++;//右上
					}
					else if(j==width-1)//右下角
					{
						if(_thunder[i-1][j].num != -1) _thunder[i-1][j].num++;//上
						if(_thunder[i][j-1].num != -1) _thunder[i][j-1].num++;//左
						if(_thunder[i-1][j-1].num != -1) _thunder[i-1][j-1].num++;//左上
					}
					else//最后一行其他位置
					{
						if(_thunder[i-1][j].num != -1) _thunder[i-1][j].num++;//上
						if(_thunder[i][j-1].num != -1) _thunder[i][j-1].num++;//左
						if(_thunder[i][j+1].num != -1) _thunder[i][j+1].num++;//右
						if(_thunder[i-1][j-1].num != -1) _thunder[i-1][j-1].num++;//左上
						if(_thunder[i-1][j+1].num != -1) _thunder[i-1][j+1].num++;//右上
					}

				}
				else if(j==0 && i>0 && i<height-1)//第一列除角位置处
				{
					if(_thunder[i-1][j].num != -1) _thunder[i-1][j].num++;//上
					if(_thunder[i+1][j].num != -1) _thunder[i+1][j].num++;//下
					if(_thunder[i][j+1].num != -1) _thunder[i][j+1].num++;//右
					if(_thunder[i-1][j+1].num != -1) _thunder[i-1][j+1].num++;//右上
					if(_thunder[i+1][j+1].num != -1) _thunder[i+1][j+1].num++;//右下
				}
				else if(j==width-1 && i>0 && i<height-1)//最后一列除角位置处
				{
					if(_thunder[i-1][j].num != -1) _thunder[i-1][j].num++;//上
					if(_thunder[i+1][j].num != -1) _thunder[i+1][j].num++;//下
					if(_thunder[i][j-1].num != -1) _thunder[i][j-1].num++;//左
					if(_thunder[i-1][j-1].num != -1) _thunder[i-1][j-1].num++;//左上
					if(_thunder[i+1][j-1].num != -1) _thunder[i+1][j-1].num++;//左下

				}
				else//其他位置
				{
					if(_thunder[i-1][j].num != -1) _thunder[i-1][j].num++;//上
					if(_thunder[i+1][j].num != -1) _thunder[i+1][j].num++;//下
					if(_thunder[i][j-1].num != -1) _thunder[i][j-1].num++;//左
					if(_thunder[i][j+1].num != -1) _thunder[i][j+1].num++;//右
					if(_thunder[i-1][j-1].num != -1) _thunder[i-1][j-1].num++;//左上
					if(_thunder[i+1][j-1].num != -1) _thunder[i+1][j-1].num++;//左下
					if(_thunder[i-1][j+1].num != -1) _thunder[i-1][j+1].num++;//右上
					if(_thunder[i+1][j+1].num != -1) _thunder[i+1][j+1].num++;//右下
				}
			}
		}
	}
}

bool Thunder::leftClick(int x, int y)
{
	int num = _thunder[x][y].num;
	ThunderType _type = _thunder[x][y].type;

	if(_type != SHOW)
	{
		if(num == -1){
			showAllThunder();
			return false; //地雷，游戏结束
		}
		else if(num != 0) _thunder[x][y].type = SHOW;//显示地雷个数
		else if(num == 0) //地雷为0
		{
			_thunder[x][y].type = SHOW;
			nullShow(x,y);//把周围的数字显现出来
		}
	}
	return true;
}

bool Thunder::rightClick(int x, int y)
{
	if(_thunder[x][y].type == UNKNOW){
		_thunder[x][y].type = FLAG;
	}else if(_thunder[x][y].type == FLAG){
		_thunder[x][y].type = MARK;
	}else if(_thunder[x][y].type == MARK){
		_thunder[x][y].type = UNKNOW;
	}else if(_thunder[x][y].type == SHOW){
		return showAround(x,y);
	}
	return true;
}

bool Thunder::nextLevel()
{
	if(level == LOW) {level = MIDDLE; setLevel(MIDDLE);}
	else if(level == MIDDLE) {level = HIGH; setLevel(HIGH);}
	else if(level == HIGH) return true;

	return false;
}

//void Thunder::nullShow(int i, int j){
//	vector<int> v;
//	v.push_back(i);
//	v.push_back(j);
//	while(!v.empty()){
//		j = v.back(); v.pop_back();
//		i = v.back(); v.pop_back();

//		for(int x = i - 1; x <= i + 1; x++){
//			if(isValid(x, j - 1) && _thunder[x][j-1].type == FLAG){
//				count++;
//			}
//			if(isValid(x, j + 1) && _thunder[x][j+1].type == FLAG){
//				count++;
//			}
//		}
//		if(isValid(i - 1, j) && _thunder[i - 1][j].type == FLAG){
//			count++;
//		}
//		if(isValid(i + 1, j) && _thunder[i + 1][j].type == FLAG){
//			count++;
//		}

//		if(_thunder[i][j].num == 0){

//		}
//	}
//}

void Thunder::nullShow(int i,int j)
{
	vector<int> v;

	v.push_back(i); v.push_back(j);
	while(v.size())
	{
		j = v.back(); v.pop_back();
		i = v.back(); v.pop_back();

		if(i==0 && j==0)//左上角
		{
			if(_thunder[i][j+1].num == 0 && _thunder[i][j+1].visited == false) {v.push_back(i); v.push_back(j+1); _thunder[i][j+1].visited = true;} _thunder[i][j+1].type = SHOW;//右
			if(_thunder[i+1][j].num == 0 && _thunder[i+1][j].visited == false) {v.push_back(i+1); v.push_back(j); _thunder[i+1][j].visited = true;} _thunder[i+1][j].type = SHOW;//下
			if(_thunder[i+1][j+1].num!=-1 && _thunder[i+1][j+1].num!=0) _thunder[i+1][j+1].type = SHOW;//右下角
		}
		else if(i==0 && j==width-1)//右上角
		{
			if(_thunder[i+1][j].num == 0 && _thunder[i+1][j].visited == false) {v.push_back(i+1); v.push_back(j); _thunder[i+1][j].visited = true;} _thunder[i+1][j].type = SHOW;//下
			if(_thunder[i][j-1].num == 0 && _thunder[i][j-1].visited == false) {v.push_back(i); v.push_back(j-1); _thunder[i][j-1].visited = true;} _thunder[i][j-1].type = SHOW;//左
			if(_thunder[i+1][j-1].num!=-1 && _thunder[i+1][j-1].num!=0) _thunder[i+1][j-1].type = SHOW;//左下角
		}
		else if(i==height-1 && j==0)//左下角
		{
			if(_thunder[i][j+1].num == 0 && _thunder[i][j+1].visited == false) {v.push_back(i); v.push_back(j+1); _thunder[i][j+1].visited = true;} _thunder[i][j+1].type = SHOW;//右
			if(_thunder[i-1][j].num == 0 && _thunder[i-1][j].visited == false) {v.push_back(i-1); v.push_back(j); _thunder[i-1][j].visited = true;} _thunder[i-1][j].type = SHOW;//上
			if(_thunder[i-1][j+1].num!=-1 && _thunder[i-1][j+1].num!=0) _thunder[i-1][j+1].type = SHOW;//右上角

		}
		else if(i==height-1 && j==width-1)//右下角
		{
			if(_thunder[i][j-1].num == 0 && _thunder[i][j-1].visited == false) {v.push_back(i); v.push_back(j-1); _thunder[i][j-1].visited = true;} _thunder[i][j-1].type = SHOW;//左
			if(_thunder[i-1][j].num == 0 && _thunder[i-1][j].visited == false) {v.push_back(i-1); v.push_back(j); _thunder[i-1][j].visited = true;} _thunder[i-1][j].type = SHOW;//上
			if(_thunder[i-1][j-1].num!=-1 && _thunder[i-1][j-1].num!=0) _thunder[i-1][j-1].type = SHOW;//左上角
		}
		else if(i==0 && j>0 && j<width-1)//第一行
		{
			if(_thunder[i+1][j].num == 0 && _thunder[i+1][j].visited == false) {v.push_back(i+1); v.push_back(j); _thunder[i+1][j].visited = true;} _thunder[i+1][j].type = SHOW;//下
			if(_thunder[i][j-1].num == 0 && _thunder[i][j-1].visited == false) {v.push_back(i); v.push_back(j-1); _thunder[i][j-1].visited = true;} _thunder[i][j-1].type = SHOW;//左
			if(_thunder[i][j+1].num == 0 && _thunder[i][j+1].visited == false) {v.push_back(i); v.push_back(j+1); _thunder[i][j+1].visited = true;} _thunder[i][j+1].type = SHOW;//右
			if(_thunder[i+1][j-1].num!=-1 && _thunder[i+1][j-1].num!=0) _thunder[i+1][j-1].type = SHOW;//左下角
			if(_thunder[i+1][j+1].num!=-1 && _thunder[i+1][j+1].num!=0) _thunder[i+1][j+1].type = SHOW;//右下角
		}
		else if(i==height-1 && j>0 && j<width-1)//最后一行
		{
			if(_thunder[i-1][j].num == 0 && _thunder[i-1][j].visited == false) {v.push_back(i-1); v.push_back(j); _thunder[i-1][j].visited = true;} _thunder[i-1][j].type = SHOW;//上
			if(_thunder[i][j-1].num == 0 && _thunder[i][j-1].visited == false) {v.push_back(i); v.push_back(j-1); _thunder[i][j-1].visited = true;} _thunder[i][j-1].type = SHOW;//左
			if(_thunder[i][j+1].num == 0 && _thunder[i][j+1].visited == false) {v.push_back(i); v.push_back(j+1); _thunder[i][j+1].visited = true;} _thunder[i][j+1].type = SHOW;//右
			if(_thunder[i-1][j-1].num!=-1 && _thunder[i-1][j-1].num!=0) _thunder[i-1][j-1].type = SHOW;//左上角
			if(_thunder[i-1][j+1].num!=-1 && _thunder[i-1][j+1].num!=0) _thunder[i-1][j+1].type = SHOW;//右上角
		}
		else if(j==0 && i>0 && i<height-1)//第一列
		{
			if(_thunder[i-1][j].num == 0 && _thunder[i-1][j].visited == false) {v.push_back(i-1); v.push_back(j); _thunder[i-1][j].visited = true;} _thunder[i-1][j].type = SHOW;//上
			if(_thunder[i+1][j].num == 0 && _thunder[i+1][j].visited == false) {v.push_back(i+1); v.push_back(j); _thunder[i+1][j].visited = true;} _thunder[i+1][j].type = SHOW;//下
			if(_thunder[i][j+1].num == 0 && _thunder[i][j+1].visited == false) {v.push_back(i); v.push_back(j+1); _thunder[i][j+1].visited = true;} _thunder[i][j+1].type = SHOW;//右
			if(_thunder[i-1][j+1].num!=-1 && _thunder[i-1][j+1].num!=0) _thunder[i-1][j+1].type = SHOW;//右上角
			if(_thunder[i+1][j+1].num!=-1 && _thunder[i+1][j+1].num!=0) _thunder[i+1][j+1].type = SHOW;//右下角
		}
		else if(j==width-1 && i>0 && i<height-1)//最后一列
		{
			if(_thunder[i-1][j].num == 0 && _thunder[i-1][j].visited == false) {v.push_back(i-1); v.push_back(j); _thunder[i-1][j].visited = true;} _thunder[i-1][j].type = SHOW;//上
			if(_thunder[i+1][j].num == 0 && _thunder[i+1][j].visited == false) {v.push_back(i+1); v.push_back(j); _thunder[i+1][j].visited = true;} _thunder[i+1][j].type = SHOW;//下
			if(_thunder[i][j-1].num == 0 && _thunder[i][j-1].visited == false) {v.push_back(i); v.push_back(j-1); _thunder[i][j-1].visited = true;} _thunder[i][j-1].type = SHOW;//左
			if(_thunder[i-1][j-1].num!=-1 && _thunder[i-1][j-1].num!=0) _thunder[i-1][j-1].type = SHOW;//左上角
			if(_thunder[i+1][j-1].num!=-1 && _thunder[i+1][j-1].num!=0) _thunder[i+1][j-1].type = SHOW;//左下角
		}
		else
		{
			if(_thunder[i-1][j].num == 0 && _thunder[i-1][j].visited == false) {v.push_back(i-1); v.push_back(j); _thunder[i-1][j].visited = true;} _thunder[i-1][j].type = SHOW;//上
			if(_thunder[i+1][j].num == 0 && _thunder[i+1][j].visited == false) {v.push_back(i+1); v.push_back(j); _thunder[i+1][j].visited = true;} _thunder[i+1][j].type = SHOW;//下
			if(_thunder[i][j-1].num == 0 && _thunder[i][j-1].visited == false) {v.push_back(i); v.push_back(j-1); _thunder[i][j-1].visited = true;} _thunder[i][j-1].type = SHOW;//左
			if(_thunder[i][j+1].num == 0 && _thunder[i][j+1].visited == false) {v.push_back(i); v.push_back(j+1); _thunder[i][j+1].visited = true;} _thunder[i][j+1].type = SHOW;//右
			if(_thunder[i-1][j-1].num!=-1 && _thunder[i-1][j-1].num!=0) _thunder[i-1][j-1].type = SHOW;//左上角
			if(_thunder[i+1][j-1].num!=-1 && _thunder[i+1][j-1].num!=0) _thunder[i+1][j-1].type = SHOW;//左下角
			if(_thunder[i-1][j+1].num!=-1 && _thunder[i-1][j+1].num!=0) _thunder[i-1][j+1].type = SHOW;//右上角
			if(_thunder[i+1][j+1].num!=-1 && _thunder[i+1][j+1].num!=0) _thunder[i+1][j+1].type = SHOW;//右下角
		}
	}
}

bool Thunder::isGameOver()
{
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(_thunder[i][j].type != SHOW && _thunder[i][j].num >= 0)//未完全显示
				return false;
		}
	}
	return true;//游戏结束
}

void Thunder::showAllThunder()
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(_thunder[i][j].num == -1)
				_thunder[i][j].type = SHOW;
		}
	}
}

bool Thunder::setLevel(int w, int h, int t)
{
	if((w>0 && w<=60) && (h>0 && h<=30) && (t>0 && t<(w*h)))
	{
		setSize(w, h);
		setThunder(t);
		setNum();
		return true;
	}else{
		return false;
	}
}

bool Thunder::setLevel(GameLevel level)
{
	switch(level)
	{
	case LOW: setSize(16,8); setThunder(20); break;
	case MIDDLE: setSize(24,12); setThunder(40); break;
	case HIGH: setSize(32,16); setThunder(90); break;
	default: return false;
	}
	setNum();
	return true;
}

bool Thunder::showAround(int i, int j){
	int count = 0;
	if(_thunder[i][j].num > 0){
		for(int x = i - 1; x <= i + 1; x++){
			if(isValid(x, j - 1) && _thunder[x][j-1].type == FLAG){
				count++;
			}
			if(isValid(x, j + 1) && _thunder[x][j+1].type == FLAG){
				count++;
			}
		}
		if(isValid(i - 1, j) && _thunder[i - 1][j].type == FLAG){
			count++;
		}
		if(isValid(i + 1, j) && _thunder[i + 1][j].type == FLAG){
			count++;
		}
	}
	if(count >= _thunder[i][j].num){
		for(int x = i - 1; x <= i + 1; x++){
			if(isValid(x, j - 1) && _thunder[x][j-1].type != FLAG){
				if(!leftClick(x, j-1)){
					return false;
				}else{
					_thunder[x][j-1].type = SHOW;
				}
			}
			if(isValid(x, j + 1) && _thunder[x][j+1].type != FLAG){
				if(!leftClick(x, j+1)){
					return false;
				}else{
					_thunder[x][j+1].type = SHOW;
				}
			}
		}
		if(isValid(i - 1, j) && _thunder[i - 1][j].type != FLAG){
			if(!leftClick(i-1, j)){
				return false;
			}else{
				_thunder[i-1][j].type = SHOW;
			}
		}
		if(isValid(i + 1, j) && _thunder[i + 1][j].type != FLAG){
			if(!leftClick(i+1, j)){
				return false;
			}else{
				_thunder[i+1][j].type = SHOW;
			}
		}
	}

	return true;
}

void Thunder::reset()
{
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			_thunder[i][j].num = 0;
			_thunder[i][j].type = UNKNOW;
			_thunder[i][j].visited = false;//未访问过
		}
	}
	setThunder(thunder);
	setNum();
}

bool Thunder::isValid(int x, int y){
	if(x < 0 || x >= height) return false;
	if(y < 0 || y >= width) return false;
	return true;
}
