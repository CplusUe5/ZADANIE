#include <iostream>
#include <vector>

//////////////////////////////////////////////
//ИГРОК
class Player
{
public:
	//Позиция игрока
	int Xpos_;
	int Ypos_;

public:
	Player(int x, int y) : Xpos_(x), Ypos_(y) {};
	
	//Методы с координатами позициями
	int GetXpos()
	{
		return  Xpos_;
	}
	int GetYpos()
	{
		return Ypos_;
	}
};

//////////////////////////////////////////////
//ПРАВИЛА
class Rules
{
protected:
	int height_;//высота карты
	int width_;//ширина карты

	std::vector<std::vector<int>>field_;//вектор карты
public:
	Rules(): height_(5), width_(10){};
	
	//создание карты
	void initMap(int Ypos, int Xpos, int Yend, int Xend)
	{
		for (int i = 0; i < height_; i++)
		{
			std::vector<int>temp;
			for (int j = 0; j < width_; j++)
			{
				if (i == 0 || i == height_ - 1 || j == 0 || j == width_ - 1)
				{
					temp.push_back(100);
				}
				else if (i == Xpos && j == Ypos)
				{
					temp.push_back(9);
				}
				else if (i == Xend && j == Yend)
				{
					temp.push_back(99);
				}
				else
				{
					temp.push_back(0);
				}
				
				
			}
			field_.push_back(temp);
		}
	}
	
	//вывод карты
	void showMap()
	{
		for (int i = 0; i < height_; i++)
		{
			for (int j = 0; j < width_; j++)
			{
				if (field_[i][j] == 100)
				{
					std::cout << "#";
				}

				if (field_[i][j] == 0)
				{
					std::cout << ".";
				}

				if (field_[i][j] == 9)
				{
					std::cout << "0";
				}
				if (field_[i][j] == 99)
				{
					std::cout << "X";
				}
				
			}
			std::cout << std::endl;
		}
	}
};

//////////////////////////////////////////////
//ПРАВИЛА ДЛЯ ПЕШКИ
class Pawn: public Rules
{
private:
	
public:
	//делаем рассчет короткого пути (ТУТ ВЫДАЁТ ОШИБКУ ПРИ ОБРАЩЕНИИ К field_[y][x])
	void cells(int x, int y)
	{
		for (int i = 0; i < height_; i++)
		{
			for (int j = 0; j < width_; j++)
			{
				if (field_[y][x] == 2)//!!!!!!!!!!!!!!?????????????????????
				{
					std::cout << "Error!";
				}
			}
		}
		
	}
};
//////////////////////////////////////////////
//ПРАВИЛА ДЛЯ КОРОЛЯ
class king : public Rules
{

};
//////////////////////////////////////////////
//ПРАВИЛА ДЛЯ ЛАДЬИ
class rook : public Rules
{

};
//////////////////////////////////////////////
//ПРАВИЛА ДЛЯ КОНЯ
class horse : public Rules
{

};

//////////////////////////////////////////////
//МИР
class World: public Rules
{
private:
	//Координаты старта игры
	int Xbegin_;
	int Ybegin_;
	//Координаты финиша
	int XEnd_;
	int YEnd_;
public:
	World() :  Xbegin_(1), Ybegin_(1), XEnd_(width_ - 2), YEnd_(height_ - 2) {};

	//ЗАПУСК ПРОГРАММЫ
	void Run()
	{
		Rules maps;//вызов правил
		Player start(Xbegin_, Ybegin_);//вызов игрока
		maps.initMap(start.GetYpos(), start.GetXpos(), XEnd_, YEnd_);//создание карты с указанием позиции игрока
		maps.showMap();//рисовка карты
		Pawn pawn;//вызов правил для пешки
		pawn.cells(start.GetYpos(), start.GetXpos());//вызов метода рассчета с с указанием позиции игрока
		
	}

};
int main()
{
	World world;
	world.Run();
}