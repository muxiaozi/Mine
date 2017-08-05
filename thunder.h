#pragma once
#include <ctime>
#include <vector>

using namespace std;

typedef enum{SHOW, FLAG, MARK, UNKNOW} ThunderType;
typedef enum{LOW, MIDDLE, HIGH} GameLevel;

typedef struct Node
{
	ThunderType type;
	int num;	//-1是雷 其他数字雷个数
	bool visited;//搜索0时判断是否访问过
}Node;

class Thunder
{
private:
	Node **_thunder;
	int height;
	int width;
	int thunder;	//这一局中雷的个数
	GameLevel level;//私有成员

private:
	void setSize(int width, int height);
	void setThunder(int num);	//设置num个地雷
	void setNum();				//设置数字
	void nullShow(int i,int j);	//(x,y)为空格，则显示周围的数字
	void showAllThunder();		//游戏结束时显示所有的雷

public:
	Thunder();//初始化数组
	~Thunder();

	int getRestFlag() const;				//显示当前还可标记的个数
	int getWidth() const;
	int getHeight() const;
	Node **getMap() const;
	Node *at(int x, int y) const;

	bool leftClick(int x, int y);
	bool rightClick(int x, int y);

	bool isValid(int x, int y);
	bool isGameOver();				//游戏是否结束

	bool showAround(int i,int j);	//显示周围的个数

	bool setLevel(int w, int h, int t);
	bool setLevel(GameLevel level);
	void reset();	//重设
	bool nextLevel();
};

