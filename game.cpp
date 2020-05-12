#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>
#include <time.h>
#include <sstream>
#include <math.h>
#define pi 3.141592643589
#include <unistd.h>

// g++ -c gaim.cpp / g++ gaim.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system / ./sfml-app



using namespace std;
using namespace sf;


sf::RenderWindow window(sf::VideoMode(1920, 1080), "110110011101011100011110101111001111101111110111111001001100110111010111000111101011", sf::Style::Fullscreen);

class load_object
{
public:String File;
	  Image image;
	  Texture texture;
	  Sprite sprite;
	  load_object(String F)
	  {
		  File = F;
		  image.loadFromFile("images/" + File);
		  texture.loadFromImage(image);
		  sprite.setTexture(texture);
	  }
};



const int Height_Map = 136;
const int Width_Map = 40;


String Map_Matrix[Height_Map] =
{
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000s",
	"s0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ss",
	"s0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ss",
	"s0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ss",
	"ss000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ss",
	"ss000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ss",
	"ss000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ss",
	"ss00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"ss00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"sss0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"sss0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"sss0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"sss0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"sss0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000sss",
	"sss0000000000000000000000000000000000000000000000000000000000000000000w0000000000000000000000000000000000000000000000000000000000000ssss",
	"sss000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ssss",
	"sss000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ssss",
	"sss000000000000000000000000000000000000000000000000000000000000000000000000000000000000ww000000000000000000000000000000000000000000sssss",
	"ssss00000000000000000000000000000000000000000000000000000000000000000000000000000000wwwsswww00000000000000000000000000000000000000sssss",
	"ssss000000000000000000000000000000000000000000000000000000000000000000000wwwwwwwwwwws000000sww0000000000000000000000000000000000000sssss",
	"sssss00000000000000000000000000000000000000000000000000000000wwwwwww00000000000000000000000000000000000000000000000000000000000000ssssss",
	"sssss0000000000000000000000000000000000000000000000000000000ws00000000000000000000000000ww00wwww000000000000000000000000000000000sssssss",
	"sssss0000000000000000000000wwwwwwwwww0000wwwwww0000000000ww0000000000000000000000000000wssw0000swwwwwwwwwwwwww0000000000000000000ss0ssss",
	"sssss000000000000000000000ws0000000000ww000000swwwwwwwwwws00000000000w0w00000ss0000000wssssw0000000000000000000000000000000000000sssssss",
	"sssss00000000000000000000ws00000000000ss00000000000000000000000000000s0s00000ss00000wwssssssw00000000000000000ww00000000000000000sssssss",
	"sssss0000000000000000000ws00000000000wssw000000000000000000000000000ws0sw000000000wwsssssssssb0000000000000000ssw0000000H00000000sssssss",
	"ssssss000h00000000000wwwsswwwwwb00000ssss000000000000000000000wwwwwwss0ssww000000wssssssssssssb00000000000000wsss0wwwwwwwwwwwwwwwsssssss",
	"sssssswwwwwwwwwwwwwwwssssssssssswwwwwsssswwwwwwwwwwwwwwwwwwwwwssssssss0ssssb0000wssssssssssssssbwwwwwwwwwwwwwsssswssssssssssssssssssssss",
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss0sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
};


class plane_out
{
protected:
	float dx = 0, dy = 0, x = 0, y = 0;
	bool OnGround = false;
	float Life = 100;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	plane_out(float X, float Y, load_object p) {
		x = X;
		y = Y;
		dx = 0; dy = 0;
		image = p.image;
		image.createMaskFromColor(Color(11, 10, 10));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 512, 512));
		sprite.setOrigin(256, 256);
		x = X;
		y = Y;
		sprite.scale(Vector2f(0.2, 0.2));
		sprite.setPosition(X, Y);
	}

	Sprite get_sprite()
	{
		return sprite;
	}

	float get_life()
	{
		return Life;
	}

	void mod_life(int t)
	{
		Life = t;
	}



	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	virtual void update(float time)
	{

	}
};





class plane1_out : public plane_out
{
private:
	float cur = 0;
	float cur1 = 0;
public:
	plane1_out(float X, float Y, load_object p, float Cur) : plane_out(X, Y, p) {
		cur = Cur;
		sprite.setRotation(-cur);
	}


	void update(float time)
	{
		//cur-?
		cur1 += time * 0.017;
		if (cur1 >= 4) cur1 -= 4;
		x += time * (0.69 * cos(pi / 180 * cur));
		y -= time * (0.69 * sin(pi / 180 * cur));
		if (x <= 0 || x >= 5360 || y <= 20 || y >= 1540) Life -= 1;
		else
		{
			if (Map_Matrix[int((y - 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y + 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x - 35) / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x + 35) / 40) + 1] != '0') Life = 0;
		}
		sprite.setTextureRect(IntRect((int(cur1) % 2) * 512, (int(cur1) / 2) * 512, 512, 512));
		sprite.setPosition(x, y);
	}
};



class plane2_out : public plane_out
{
private:
	float cur = 180;
	float cur1 = 0;
public:
	plane2_out(float X, float Y, load_object p, float Cur) : plane_out(X, Y, p)
	{
		cur = 180 + Cur;
		sprite.scale(Vector2f(-1, 1));
		sprite.setRotation(-cur);
	}


	void update(float time)
	{
		//cur-?
		cur1 += time * 0.017;
		if (cur1 >= 4) cur1 -= 4;
		x -= time * (0.69 * cos(pi / 180 * cur));
		y += time * (0.69 * sin(pi / 180 * cur));
		if (x <= 0 || x >= 5360 || y <= 20 || y >= 1540) Life -= 1;
		else
		{
			if (Map_Matrix[int((y - 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y + 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x - 35) / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x + 35) / 40) + 1] != '0') Life = 0;
		}
		sprite.setTextureRect(IntRect((int(cur1) % 2) * 512, (int(cur1) / 2) * 512, 512, 512));
		sprite.setPosition(x, y);
	}
};




class pl
{
	float x, y;
	int life = 1;
	float cur0 = 0, cur1 = 0, cur2 = 0;
	int see = 0;
	int f = 0;
	float check = 50;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	pl(float X, float Y, load_object p)
	{
		texture.loadFromImage(p.image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 300, 290));
		sprite.setOrigin(150, 145);
		x = X;
		y = Y;
		sprite.scale(Vector2f(0.1, 0.1));
		sprite.setPosition(x, y);
	}


	Sprite get_sprite()
	{
		return sprite;
	}


	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	int get_life()
	{
		return life;
	}


	void mod_life(int llife)
	{
		life = llife;
	}



	void update(float time)
	{
		float X, Y;
		cur0 += time * 0.01;
		if (cur0 >= check)
		{
			cur0 = 0;
			check = rand() % 10 + 1;
			see = rand() % 2 + 1;
		}
		if (see == 1)
		{
			cur1 -= time * 0.2;
			if (abs(cur1) >= 360) cur1 = (int(cur1) % 360);
			sprite.setRotation(-cur1);
			x += time * check * (0.05 * cos(pi / 180 * cur1));
			y += time * check * (0.05 * sin(pi / 180 * cur1));
		}
		if (see == 2)
		{
			cur1 += time * 0.2;
			if (abs(cur1) >= 360) cur1 = (int(cur1) % 360);
			sprite.setRotation(-cur1);
			x += time * check * (0.05 * cos(pi / 180 * cur1));
			y += time * check * (0.05 * sin(pi / 180 * cur1));
		}


		if (x <= 0 || x >= 5360 || y <= 10 || y >= 1540) life = 0;
		else
		{
			if (Map_Matrix[int((y - 15) / 40)][int(x / 40) + 1] != '0')
				if (Map_Matrix[int((y + 15) / 40)][int(x / 40) + 1] != '0') life = 0;
			if (Map_Matrix[int((y) / 40)][int((x - 15) / 40) + 1] != '0') life = 0;
			if (Map_Matrix[int((y) / 40)][int((x + 15) / 40) + 1] != '0') life = 0;
		}

		sprite.setPosition(x, y);
	}



};





class psh
{
	float x, y;
	int life = 1;
	float cur = 0;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	psh(float X, float Y, load_object p)
	{
		texture.loadFromImage(p.image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 166, 166));
		sprite.setOrigin(82, 82);
		x = X;
		y = Y;
		sprite.scale(Vector2f(1, 1));
		sprite.setPosition(x, y);
	}


	Sprite get_sprite()
	{
		return sprite;
	}


	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	int get_life()
	{
		return life;
	}


	void mod_life(int llife)
	{
		life = llife;
	}


	void update(float time)
	{
		cur += time * 0.017;
		if (cur >= 9)
		{
			life = 0;
			cur -= 9;
		}
		//cout << int(current_boom) << endl;
		sprite.setTextureRect(IntRect((int(cur) % 3) * 166, (int(cur) / 3) * 166, 166, 166));
	}

};





class coin
{
private:
	float x, y;
	float cur = 0;
	int Life = 1;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	coin(float X, float Y, load_object p) {
		x = X; y = Y;
		texture.loadFromImage(p.image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 90, 90));
		sprite.setPosition(X, Y);
		x = X;
		y = Y;
		sprite.scale(Vector2f(0.8, 0.8));
	}
	Sprite get_sprite()
	{
		return sprite;
	}
	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}
	int get_life()
	{
		return Life;
	}
	void mod_life(int life)
	{
		Life = life;
	}
	void update(float time)
	{
		cur += time * 0.017;
		if (cur >= 7)
		{
			cur -= 7;
		}
		if (int(cur) == 0)
		{
			sprite.setTextureRect(IntRect(0, 0, 90, 90));
			sprite.setOrigin(45, 45);
		}
		if (int(cur) == 1)
		{
			sprite.setTextureRect(IntRect(90, 0, 70, 90));
			sprite.setOrigin(35, 45);
		}
		if (int(cur) == 2)
		{
			sprite.setTextureRect(IntRect(160, 0, 50, 90));
			sprite.setOrigin(25, 45);
		}
		if (int(cur) == 3)
		{
			sprite.setTextureRect(IntRect(210, 0, 30, 90));
			sprite.setOrigin(15, 45);
		}
		if (int(cur) == 4)
		{
			sprite.setTextureRect(IntRect(240, 0, 50, 90));
			sprite.setOrigin(25, 45);
		}
		if (int(cur) == 5)
		{
			sprite.setTextureRect(IntRect(290, 0, 70, 90));
			sprite.setOrigin(35, 45);
		}
		if (int(cur) == 6)
		{
			sprite.setTextureRect(IntRect(360, 0, 90, 90));
			sprite.setOrigin(45, 45);
		}
	}
};



class plane
{
protected:
	float dx = 0, dy = 0, x = 0, y = 0;
	float Life = 100;
	float see = 0;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	plane(float X, float Y, load_object p) {
		x = X;
		y = Y;
		dx = 0; dy = 0;
		image = p.image;
		image.createMaskFromColor(Color(11, 10, 10));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 512, 512));
		sprite.setOrigin(256, 256);
		x = X;
		y = Y;
		sprite.scale(Vector2f(0.2, 0.2));
		sprite.setPosition(X, Y);
	}

	Sprite get_sprite()
	{
		return sprite;
	}

	float get_life()
	{
		return Life;
	}

	void mod_life(int t)
	{
		Life = t;
	}

	float get_see()
	{
		return see;
	}


	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	virtual void update(float time)
	{

	}
};





class plane1 : public plane
{
private:
	float cur = 0;
	float cur1 = 0;
public:
	plane1(float X, float Y, load_object p) : plane(X, Y, p) {

	}


	void update(float time)
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			cur += time * 0.2;
			see = cur;
			if (abs(cur) >= 360) cur = 0;
			sprite.setRotation(-cur);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			cur -= time * 0.2;
			see = cur;
			if (abs(cur) >= 360) cur = 0;
			sprite.setRotation(-cur);
		}
		cur1 += time * 0.017;
		if (cur1 >= 4) cur1 -= 4;
		x += time * (0.69 * cos(pi / 180 * cur));
		y -= time * (0.69 * sin(pi / 180 * cur));
		if (Keyboard::isKeyPressed(Keyboard::H))
		{
			Life = 100;
		}
		if (x <= 0 || x >= 5360 || y <= 20 || y >= 1540) Life -= 0.03;
		else
		{
			if (Map_Matrix[int((y - 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y + 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x - 35) / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x + 35) / 40) + 1] != '0') Life = 0;
		}
		sprite.setTextureRect(IntRect((int(cur1) % 2) * 512, (int(cur1) / 2) * 512, 512, 512));
		sprite.setPosition(x, y);
	}
};



class plane2 : public plane
{
private:
	float cur = 0;
	float cur1 = 0;
public:
	plane2(float X, float Y, load_object p) : plane(X, Y, p)
	{
		see = 180;
		sprite.scale(Vector2f(-1, 1));
	}


	void update(float time)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			cur += time * 0.2;
			see = cur + 180;
			if (abs(cur) >= 360) cur = 0;
			sprite.setRotation(-cur);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			cur -= time * 0.2;
			see = cur + 180;
			if (abs(cur) >= 360) cur = 0;
			sprite.setRotation(-cur);
		}
		cur1 += time * 0.017;
		if (cur1 >= 4) cur1 -= 4;
		x -= time * (0.69 * cos(pi / 180 * cur));
		y += time * (0.69 * sin(pi / 180 * cur));
		if (Keyboard::isKeyPressed(Keyboard::H))
		{
			Life = 100;
		}
		if (x <= 0 || x >= 5360 || y <= 20 || y >= 1540) Life -= 0.03;
		else
		{
			if (Map_Matrix[int((y - 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y + 35) / 40)][int(x / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x - 35) / 40) + 1] != '0') Life = 0;
			if (Map_Matrix[int((y) / 40)][int((x + 35) / 40) + 1] != '0') Life = 0;
		}
		sprite.setTextureRect(IntRect((int(cur1) % 2) * 512, (int(cur1) / 2) * 512, 512, 512));
		sprite.setPosition(x, y);
	}
};


class pula
{
	float x, y;
	float see;
	int life = 1;
	int id;
	int type = 0;
	float cur = 0;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	pula(float X, float Y, load_object p, float See, int Type)
	{
		see = See;
		type = Type;
		texture.loadFromImage(p.image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 259, 148));
		sprite.setOrigin(150, 90);
		x = X;
		y = Y;
		sprite.setRotation(360 - see);
		sprite.scale(Vector2f(0.15, 0.15));
		sprite.setPosition(x, y);
	}



	Sprite get_sprite()
	{
		return sprite;
	}


	float get_x()
	{
		return x;
	}

	int get_type()
	{
		return type;
	}


	float get_y()
	{
		return y;
	}

	int get_life()
	{
		return life;
	}


	void mod_life(int llife)
	{
		life = llife;
	}

	void mod_type(int Type)
	{
		type = Type;
	}


	void update(float time)
	{
		cur += time * 0.01;
		if (cur >= 2) cur -= 2;
		if (x <= 10 || x >= 5350 || y <= 20 || y >= 1540); else
		{
			if (Map_Matrix[int((y - 10) / 40)][int(x / 40) + 1] != '0' && Map_Matrix[int((y - 10) / 40)][int(x / 40) + 1] != 'h' && Map_Matrix[int((y - 10) / 40)][int(x / 40) + 1] != 'H') life = 0;
			if (Map_Matrix[int((y + 10) / 40)][int(x / 40) + 1] != '0' && Map_Matrix[int((y + 10) / 40)][int(x / 40) + 1] != 'h' && Map_Matrix[int((y + 10) / 40)][int(x / 40) + 1] != 'H') life = 0;
			if (Map_Matrix[int((y) / 40)][int((x - 10) / 40) + 1] != '0' && Map_Matrix[int((y) / 40)][int((x - 10) / 40) + 1] != 'h' && Map_Matrix[int((y) / 40)][int((x - 10) / 40) + 1] != 'H') life = 0;
			if (Map_Matrix[int((y) / 40)][int((x + 10) / 40) + 1] != '0' && Map_Matrix[int((y) / 40)][int((x + 10) / 40) + 1] != 'h' && Map_Matrix[int((y) / 40)][int((x + 10) / 40) + 1] != 'H') life = 0;
		}
		x += time * (2 * cos(pi / 180 * see));
		y -= time * (2 * sin(pi / 180 * see));
		sprite.setTextureRect(IntRect((int(cur)) * 259, 0, 259, 148));
		sprite.setPosition(x, y);
	}

};


class boom
{
	float x, y;
	int life = 1;
	float current_boom = 0;
	int vyl = 0;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	boom(float X, float Y, load_object p, float Size)
	{
		texture.loadFromImage(p.image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 530, 533));
		sprite.setOrigin(265, 266);
		x = X;
		y = Y;
		sprite.scale(Vector2f(Size, Size));
		sprite.setPosition(x, y);
	}


	Sprite get_sprite()
	{
		return sprite;
	}


	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	int get_life()
	{
		return life;
	}


	void mod_life(int llife)
	{
		life = llife;
	}


	void update(float time)
	{
		current_boom += time * 0.017;
		if (current_boom >= 6)
		{
			life = 0;
			current_boom -= 6;
		}
		//cout << int(current_boom) << endl;
		sprite.setTextureRect(IntRect((int(current_boom) % 3) * 533, (int(current_boom) / 3) * 530, 533, 530));
	}

};



struct KeyboardConfiguration
{
	Keyboard::Key up;
	Keyboard::Key right;
	Keyboard::Key left;
};

class cat
{
private:
	float dx = 0, dy = 0, x = 0, y = 0;

	bool OnGround = false;
	float Life = 100;
	int money = 0;
	float see = 0;
	int f = -1;
	Sound miay;
	Image image;
	Texture texture;
	Sprite sprite;
	enum { left, right, jump, stay } state;
	KeyboardConfiguration keyboard_config;
	float cur = 0;
public:

	cat(float X, float Y, load_object p, KeyboardConfiguration kbd_cfg, Sound M) {
		keyboard_config = kbd_cfg;
		miay = M;
		x = 0; y = 0; dx = 0; dy = 0;
		texture.loadFromImage(p.image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 180, 300, 180));
		sprite.setOrigin(150, 90);
		x = X;
		y = Y;
		sprite.scale(Vector2f(0.2, 0.2));
	}

	Sprite get_sprite()
	{
		return sprite;
	}

	float get_life()
	{
		return Life;
	}

	int get_money()
	{
		return money;
	}


	void mod_life(float t)
	{
		Life = t;
	}

	float get_see()
	{
		return see;
	}


	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	void control()
	{
		if (!Keyboard::isKeyPressed(keyboard_config.left) && !Keyboard::isKeyPressed(keyboard_config.right)
			&& OnGround) state = stay;
		if (Keyboard::isKeyPressed(keyboard_config.left)) {
			state = left;
		}
		if (Keyboard::isKeyPressed(keyboard_config.right)) {
			state = right;
		}
		if ((Keyboard::isKeyPressed(keyboard_config.up)) && OnGround) {
			state = jump;
			OnGround = false;
			dy = -1.8;
		}
		if (state == left) see = 180;
		if (state == right) see = 0;
		//cout << see << endl;
		//cout << state << endl;
	}

	void update(float time)
	{
		control();
		Life -= 0.01;
		if (OnGround == 1 && state != jump) dy = 0;
		if (state == stay) { dx = 0; dy = 0; }
		if (state == left) dx = -0.5;
		if (state == right) dx = 0.5;
		if (state != left && state != right) dx = 0;
		if (Map_Matrix[int((y + 12 + dy) / 40)][int(x / 40) + 1] != '0' && Map_Matrix[int((y + 12 + dy) / 40)][int(x / 40) + 1] != 'h' && Map_Matrix[int((y + 12 + dy) / 40)][int(x / 40) + 1] != 'H' && dy >= 0)
		{
			int i = 0;
			while (Map_Matrix[int((y + 12 + dy) / 40) - i][int(x / 40) + 1] != '0' && Map_Matrix[int((y + 12 + dy) / 40) - i][int(x / 40) + 1] != 'h' && Map_Matrix[int((y + 12 + dy) / 40) - i][int(x / 40) + 1] != 'H') i++;
			y = (int((y + 12 + dy) / 40) - i) * 40 + 40 - 13;
		}
		//cout << Life << endl;
		if (dy > 2.7 && Map_Matrix[int((y + 13 + dy) / 40)][int(x / 40) + 1] != '0' && Map_Matrix[int((y + 13 + dy) / 40)][int(x / 40) + 1] != 'h' && Map_Matrix[int((y + 13 + dy) / 40)][int(x / 40) + 1] != 'H')
		{
			Life -= dy * dy * 2;
			miay.play();
		}
		if (Life < 0) Life = 0;
		if (Map_Matrix[int((y - 12 + dy) / 40)][int(x / 40) + 1] != '0' && Map_Matrix[int((y - 12 + dy) / 40)][int(x / 40) + 1] != 'h' && Map_Matrix[int((y - 12 + dy) / 40)][int(x / 40) + 1] != 'H' && dy < 0)
		{
			int i = 0;
			dy = 0;
		}
		if (Map_Matrix[int((y + 13) / 40)][int((x) / 40) + 1] != '0' && Map_Matrix[int((y + 13) / 40)][int((x) / 40) + 1] != 'H' && Map_Matrix[int((y + 13) / 40)][int((x) / 40) + 1] != 'h')
		{
			OnGround = 1;
			if (state != jump) dy = 0;
		}
		else OnGround = 0;
		if (Map_Matrix[int(y / 40)][int((x + 30) / 40) + 1] != '0' && Map_Matrix[int(y / 40)][int((x + 30) / 40) + 1] != 'h' && Map_Matrix[int(y / 40)][int((x + 30) / 40) + 1] != 'H' && (state == right || 0))
		{
			dx = 0;
			x = int((x + 30) / 40) * 40 - 30;
		}
		else
			if (Map_Matrix[int(y / 40)][int((x - 30) / 40) + 1] != '0' && Map_Matrix[int(y / 40)][int((x - 30) / 40) + 1] != 'h' && Map_Matrix[int(y / 40)][int((x - 30) / 40) + 1] != 'H' && (state == left || 0))
			{
				dx = 0;
				x = int((x - 30) / 40) * 40 + 69;
			}

		if (!OnGround) dy += 0.04;
		x += dx * time;
		y += dy * time;
		sprite.setPosition(x, y);

		if (Keyboard::isKeyPressed(keyboard_config.right))
		{
			cur += time * 0.024;
			if (cur >= 12) cur -= 12;
			sprite.setTextureRect(IntRect((int(cur) % 4) * 300, (int(cur) / 4) * 180, 300, 180));
			if (f == 0) sprite.scale(Vector2f(-1, 1));
			f = 1;
		}
		else


			if (Keyboard::isKeyPressed(keyboard_config.left))
			{
				cur += time * 0.024;
				if (cur >= 12) cur -= 12;
				sprite.setTextureRect(IntRect((int(cur) % 4) * 300, (int(cur) / 4) * 180, 300, 180));
				if (f != 0) sprite.scale(Vector2f(-1, 1));
				f = 0;
			}
		if (!Keyboard::isKeyPressed(keyboard_config.left) && !Keyboard::isKeyPressed(keyboard_config.right) && OnGround == 1) sprite.setTextureRect(IntRect(0, 180, 300, 180));
		if (!Keyboard::isKeyPressed(keyboard_config.left) && OnGround == 0) sprite.setTextureRect(IntRect(0, 360, 300, 180));
		if (!Keyboard::isKeyPressed(keyboard_config.right) && OnGround == 0) sprite.setTextureRect(IntRect(0, 360, 300, 180));
	}

};







class screen
{
private:

	float x1, x2, y1, y2;
public:
	View view;
	screen(float X1, float Y1, float X2, float Y2)
	{
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		y2 = Y2;
		view.reset(FloatRect(x1, y1, x2, y2));
	}
	void moves(float time)
	{
		if (Keyboard::isKeyPressed(Keyboard::Numpad6)) view.move(0.4 * time, 0);
		if (Keyboard::isKeyPressed(Keyboard::Numpad4)) view.move(-0.4 * time, 0);
		if (Keyboard::isKeyPressed(Keyboard::Numpad8)) view.move(0, -0.4 * time);
		if (Keyboard::isKeyPressed(Keyboard::Numpad5)) view.move(0, 0.4 * time);
	}
};



void Center(View* view, float x, float y)
{
	float x1, y1;
	x1 = x;
	y1 = y;
	if (y < 540) y1 = 540;
	if (y > 1020) y1 = 1020;
	if (x < 480) x1 = 480;
	if (x > 4880) x1 = 4880;
	view->setCenter(x1, y1);
}




void pl_func(float time, list<pl*>* pl_list)
{
	list<pl*>::iterator it1;
	for (it1 = (*pl_list).begin(); it1 != (*pl_list).end();)
	{
		window.draw((*it1)->get_sprite());
		if ((*it1)->get_life() == 0)
		{
			it1 = (*pl_list).erase(it1); delete (*it1);
		}
		else it1++;
	}
}




void psh_func(float time, list<psh*>* psh_list)
{
	list<psh*>::iterator it1;
	for (it1 = (*psh_list).begin(); it1 != (*psh_list).end();)
	{
		psh *b = *it1;
		(b)->update(time);
		window.draw(b->get_sprite());
		if (b->get_life() == 0)
		{
			it1 = (*psh_list).erase(it1); delete b;
		}
		else it1++;
	}
}




void boom_func(float time, list<boom*>* boom_list)
{
	list<boom*>::iterator it1;
	for (it1 = (*boom_list).begin(); it1 != (*boom_list).end();)
	{
		boom *b = *it1;
		(b)->update(time);
		window.draw(b->get_sprite());
		if (b->get_life() == 0)
		{
			it1 = (*boom_list).erase(it1); delete b;
		}
		else it1++;
	}
}

class BackGround : public load_object {
private:
	float w, h;
public:
	BackGround(float W, float H) : load_object("map.png")
	{
		w = W;
		h = H;
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setPosition(0, 0);
	}
};





int double_max(int x, int y)
{
	if (x < y) return y; else return x;
}


int double_min(int x, int y)
{
	if (x < y) return x; else return y;
}

void build_ground(int h, int w, Sprite ground_sprite, Sprite house, float x, float y)
{
	float x1, y1;
	x1 = x;
	y1 = y;
	if (y < 540) y1 = 540;
	if (y > 1020) y1 = 1020;
	if (x < 480) x1 = 480;
	if (x > 4880) x1 = 4880;
	for (int i = max(0, int(y1 / 40) - 27); i < min(40, int(y1 / 40) + 27); i++)
		for (int j = max(0, int(x1 / 40) - 12); j < min(136, int(x1 / 40) + 15); j++)
		{
			if (Map_Matrix[i][j] == 's') {
				ground_sprite.setTextureRect(IntRect(40, 0, 40, 40));
				ground_sprite.setPosition((j - 1) * 40, i * 40);
				window.draw(ground_sprite);
			}
			if (Map_Matrix[i][j] == 'w') {
				ground_sprite.setTextureRect(IntRect(80, 0, 40, 40));
				ground_sprite.setPosition((j - 1) * 40, i * 40);
				window.draw(ground_sprite);
			}
			if (Map_Matrix[i][j] == 'a') {
				ground_sprite.setTextureRect(IntRect(120, 0, 40, 40));
				ground_sprite.setPosition((j - 1) * 40, i * 40);
				window.draw(ground_sprite);
			}
			if (Map_Matrix[i][j] == 'b') {
				ground_sprite.setTextureRect(IntRect(200, 0, 40, 40));
				ground_sprite.setPosition((j - 1) * 40, i * 40);
				window.draw(ground_sprite);
			}
			if (Map_Matrix[i][j] == 'h') {
				house.setOrigin(100, 160);
				house.setPosition((j - 1) * 40, i * 40);
				window.draw(house);
			}
			if (Map_Matrix[i][j] == 'H') {
				house.setOrigin(100, 160);
				house.setPosition((j - 1) * 40, i * 40);
				window.draw(house);
			}
		}
}


KeyboardConfiguration kbd_cfg1{ Keyboard::W, Keyboard::D, Keyboard::A };
KeyboardConfiguration kbd_cfg2{ Keyboard::Up, Keyboard::Right, Keyboard::Left };


int main()
{
	//КАРТИНКИ

	Clock clock;
	load_object house("house.png");//скачали обьект дом
	BackGround background(5360.0, 1560.0);//создаем обьект задний фон
	load_object ground("ground.png");//создаем обьект землю которая поможет нам использовать функцию построения земли из спрайтов
	load_object cat_F("cat.png");
	load_object clubok_F("clubok.png");
	load_object plane_F("plan.png");
	load_object plane1_F("plan1.png");
	load_object boom_F("boom.png");
	load_object torpeda_F("torpeda.png");
	load_object ball_F("ball.png");
	load_object menu("menu.png");
	load_object ball("ball.png");
	load_object plane("plan.png");
	load_object torpeda("torpeda.png");
	load_object coin_F("coin.png");
	load_object psh_F("psh.png");
	load_object plus_F("plus.png");
	load_object plane_out_F("plan_out.png");
	load_object plane1_out_F("plan1_out.png");
	ball.sprite.setTextureRect(IntRect(0, 0, 148, 148));
	torpeda.sprite.setTextureRect(IntRect(0, 0, 259, 148));
	plane.image.createMaskFromColor(Color(11, 10, 10));
	plane.texture.loadFromImage(plane.image);
	plane.sprite.setTexture(plane.texture);
	plane.sprite.setTextureRect(IntRect(0, 0, 512, 512));
	plane.sprite.setScale(Vector2f(0.1, 0.1));
	ball.sprite.setScale(Vector2f(0.2, 0.2));
	torpeda.sprite.setScale(Vector2f(0.2, 0.2));
	menu.sprite.setOrigin(315, 235);
	menu.sprite.setPosition(1260, 540);


	//ЗВУКИ
	SoundBuffer buffer,buffer1,buffer2,buffer3,buffer4,buffer5,buffer6,buffer7,buffer8,buffer9;
	Sound sound_ball_boom,sound_ww,sound_click,sound_miay,sound_wwww,sound_torpeda_boom,sound_www,sound_plane_boom,sound_coin,sound_pl;
	buffer.loadFromFile("audio/ballboom.wav");// тут загружаем в буфер что то
	sound_ball_boom.setBuffer(buffer);
	buffer1.loadFromFile("audio/ww.wav");
	sound_ww.setBuffer(buffer1);
	sound_ww.setVolume(60);
	buffer2.loadFromFile("audio/click.ogg");
	sound_click.setBuffer(buffer2);
	buffer3.loadFromFile("audio/miay.wav");
	sound_miay.setBuffer(buffer3);
	buffer4.loadFromFile("audio/www.wav");
	sound_www.setBuffer(buffer4);
	buffer5.loadFromFile("audio/wwww.wav");
	sound_wwww.setBuffer(buffer5);
	sound_wwww.setVolume(50);
	buffer6.loadFromFile("audio/torpedaboom.wav");
	sound_torpeda_boom.setBuffer(buffer6);
	buffer7.loadFromFile("audio/planeboom.wav");
	sound_plane_boom.setBuffer(buffer7);
	buffer8.loadFromFile("audio/coin.wav");
	sound_coin.setBuffer(buffer8);
	buffer9.loadFromFile("audio/dzzz.wav");
	sound_pl.setBuffer(buffer9);
	Music music_back;//создаем объект музыки
	music_back.openFromFile("audio/back1.ogg");//загружаем файл
	music_back.play();//воспроизводим музыку
	music_back.setLoop(true);
	music_back.setVolume(60);
	Music music_engine;//создаем объект музыки
	music_engine.openFromFile("audio/bzzz.ogg");
	Music music_winback;//создаем объект музыки



	//ШРИФТЫ
	Font font;
	font.loadFromFile("images/shrift.ttf");
	Text text0("", font, 20);
	Text text1("", font, 80);
	Text text2("", font, 80);
	Text text3("", font, 40);
	Text text4("", font, 40);
	Text text5("", font, 80);


	/////ПРОЧЕЕ
	int GLOB=0;
	float X_D1, X_D2, Y_D1, Y_D2;
	int Money1 = 100;
	int Money2 = 100;
	int Chose1 = 0;
	int Chose2 = 0;
	int Type1 = 0;
	int Type2 = 0;
	int Price_list1[3] = { 3,2,5 };
	int Price_list2[3] = { 3,2,5 };
	int pocket_list1[2] = { 0 };
	int pocket_list2[2] = { 0 };
	float cur0 = 0, cur1 = 0, cur2 = 0, cur3 = 0, cur4 = 0, cur5 = 0, cur6 = 0;
	float cur_coin = 0;
	float cur_pl = 0;
	View view, view1, view2;
	view.reset(FloatRect(0, 0, 1920, 1080));
	view1.setViewport(FloatRect(0, 0, 0.495f, 1.0f));
	view1.setSize(960, 1080);
	view2.setViewport(FloatRect(0.505f, 0, 0.495f, 1.0f));
	view2.setSize(960, 1080);
	list<pula*> pula_list1;
	list<pula*> pula_list2;
	list<psh*> psh_list;
	list<pula*>::iterator itp;
	list<pl*>::iterator itpl;
	list<coin*>::iterator itc;
	list<boom*> boom_list1;
	list<coin*> coin_list;
	list<pl*> pl_list;
	list<boom*> boom_list2;
	list<boom*>::iterator itb;
	cat* cat_1 = NULL;
	cat* cat_2 = NULL;
	plane2* plane_2 = NULL;
	plane1* plane_1 = NULL;
	plane2_out* plane_2_out = NULL;
	plane1_out* plane_1_out = NULL;
	bool cat1_exist=0;
	bool cat2_exist=0;
	bool plane1_exist=0;
	bool plane2_exist=0;
	int gg = 0;
	int gg1 = 0;
	int gg2 = 0;
	int bb = 0;
	int bb1 = 0;
	int bb2 = 0;
	int f1, f2;
	int I = 1;


	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1800;
		usleep(1300);




		//////////////////////////////////////main loop
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		////////////////////////////////////////////////

		if (GLOB == 0)
		{
			Money1 = 100;
			Money2 = 100;
			Price_list1[0] = 3;
			Price_list2[0] = 3;
			Vector2i pixelPos = Mouse::getPosition(window);
			Vector2f pos = window.mapPixelToCoords(pixelPos);
			cur0 += time;
			if (cur0 >= 131313)
			{
				cur0 = 131313;
				text0.setFillColor(Color::Red);
			}
			ostringstream stroka;
			stroka << int(cur0);
			text0.setString(stroka.str());
			text0.setPosition(20, 20);
			text1.setString("Play");
			text1.setPosition(640, 460);
			text2.setString("Exit");
			text2.setPosition(640, 560);

			if (text1.getGlobalBounds().contains(pos.x, pos.y))
			{
				text1.setFillColor(Color(130,130,130));
			} else text1.setFillColor(Color(255, 255, 255));

			if (text2.getGlobalBounds().contains(pos.x, pos.y))
			{
				text2.setFillColor(Color(130, 130, 130));
			}
			else text2.setFillColor(Color(255, 255, 255));
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (text2.getGlobalBounds().contains(pos.x, pos.y))
					{
						sound_click.play();
						usleep(1000);
						exit(1);
					}
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (text1.getGlobalBounds().contains(pos.x, pos.y))
					{
						sound_click.play();
						sound_click.setVolume(40);
						GLOB = 1;
						cur0 = 0;
					}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				sound_click.play();
				sound_click.setVolume(40);
				GLOB = 1;
				cur0 = 0;
			}
			window.setView(view);
			window.draw(menu.sprite);
			window.draw(text0);
			window.draw(text1);
			window.draw(text2);
		}


		if (GLOB == 1)
		{
			boom_func(time, &boom_list1);
			boom_func(time, &boom_list2);
			psh_func(time, &psh_list);
			cur0 += time*0.01*I;
			if (cur0 >= 100 || (Keyboard::isKeyPressed(Keyboard::Space)))
			{
				GLOB = 2;
				sound_click.play();
				cat_1 = new cat(230, 1300, cat_F, kbd_cfg1,sound_miay);
				cat_2 = new cat(5030, 1300, cat_F, kbd_cfg2, sound_miay);
				music_back.openFromFile("audio/back2.ogg");
				music_back.setVolume(30);
				music_back.play();
				music_back.setLoop(true);
			}
			ostringstream stroka;
			stroka << int(cur0);
			text0.setString(stroka.str()+"%");
			text0.setPosition(940, 920);
			text3.setString("W - jump\nD - moving right or\n fly clockwise\nA - moving left or\n fly counterclockwise\nS - CATapult\nC - shooting\nT - select\nR - scroll");
			text3.setPosition(240, 420);
			text4.setString("Up - jump\nRight - moving right or\n fly clockwise\nLeft - moving left or \n fly counterclockwise\nDown - CATapult\nM - shooting\nO - select\nI - scroll");
			text4.setPosition(1140, 420);
			window.setView(view);
			window.draw(text0);
			window.draw(text3);
			window.draw(text4);
		}




		if (GLOB == 2)
		{

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				music_engine.pause();
				GLOB = 3;
				if (cat_1 != NULL)
				{
					X_D1 = cat_1->get_x();
					Y_D1 = cat_1->get_y();
					delete cat_1;
					cat_1 = NULL;
				}
				if (cat_2 != NULL)
				{
					X_D2 = cat_2->get_x();
					Y_D2 = cat_2->get_y();
					delete cat_2;
					cat_2 = NULL;
				}
				if (plane_1 != NULL)
				{
					X_D1 = plane_1->get_x();
					Y_D1 = plane_1->get_y();
					delete plane_1;
					plane_1 = NULL;
				}
				if (plane_2 != NULL)
				{
					X_D1 = plane_2->get_x();
					Y_D1 = plane_2->get_y();
					delete plane_2;
					plane_2 = NULL;
				}
				if (plane_2_out != NULL)
				{
					delete plane_2_out;
					plane_2_out = NULL;
				}
				if (plane_1_out != NULL)
				{
					delete plane_1_out;
					plane_1_out = NULL;
				}
			}



			cur_coin += time * 0.01;
			if (cur_coin > 10 && coin_list.size()<25)
			{

				float ix = (rand() % 5200)+50;
				float iy = (rand() % 1400)+50;
				if (Map_Matrix[int(iy / 40)][int(ix / 40)]=='0' &&
					Map_Matrix[int((iy+40) / 40)][int(ix / 40)] == '0' &&
					Map_Matrix[int((iy-40) / 40)][int(ix / 40)] == '0' &&
					Map_Matrix[int(iy / 40)][int((ix+40) / 40)] == '0' &&
					Map_Matrix[int(iy / 40)][int((ix-40) / 40)] == '0') coin_list.push_back(new coin(ix, iy, coin_F));
				cur_coin = 0;
			}


			cur_pl += time * 0.02;
			if (cur_pl > 10 && pl_list.size() < 1)
			{

				float ix = (rand() % 5200) + 50;
				float iy = (rand() % 1400) + 50;
				if (Map_Matrix[int(iy / 40)][int(ix / 40)] == '0')
				{
					pl_list.push_back(new pl(ix, iy, plus_F));
					cur_pl = 0;
				}
				cur_pl = 0;
			}





			if (cat1_exist == 1)
			{
				cat_1 = new cat(plane_1->get_x(), plane_1->get_y(), cat_F, kbd_cfg1, sound_miay);
				plane_1_out = new plane1_out(plane_1->get_x(), plane_1->get_y(), plane_out_F, plane_1->get_see());
				delete plane_1;
				plane_1 = NULL;
				if (plane_2 == NULL) music_engine.pause();
				cat1_exist = 0;
			}
			if (cat2_exist == 1)
			{
				cat_2 = new cat(plane_2->get_x(), plane_2->get_y(), cat_F, kbd_cfg2, sound_miay);
				plane_2_out = new plane2_out(plane_2->get_x(), plane_2->get_y(), plane1_out_F, plane_2->get_see());
				delete plane_2;
				plane_2 = NULL;
				if (plane_1 == NULL) music_engine.pause();
				cat2_exist = 0;
			}
			if (plane1_exist == 1)
			{
				if (plane_2 == NULL)
				{
					music_engine.play();//воспроизводим музыку
					music_engine.setLoop(true);
				}
				plane_1 = new plane1(230, 1300, plane_F);
				plane1_exist = 0;
			}
			if (plane2_exist == 1)
			{

				if (plane_1 == NULL)
				{
					music_engine.play();//воспроизводим музыку
					music_engine.setLoop(true);
				}
				plane_2 = new plane2(5030, 1300, plane1_F);
				plane2_exist = 0;
			}

			if (plane_2_out != NULL)
			{
				plane_2_out->update(time);
			}
			if (plane_1_out != NULL)
			{
				plane_1_out->update(time);
			}
			if (plane_1_out != NULL) if (plane_1_out->get_life() <= 0)
			{
				boom_list1.push_back(new boom(plane_1_out->get_x(), plane_1_out->get_y(), boom_F, 2));
				sound_plane_boom.play();
				if (cat_2 != NULL) if (sqrt(pow(plane_1_out->get_x() - cat_2->get_x(), 2) + pow(plane_1_out->get_y() - cat_2->get_y(), 2)) <= 180)
				{
					cat_2->mod_life(cat_2->get_life() - int((180 - sqrt(pow(plane_1_out->get_x() - cat_2->get_x(), 2) + pow(plane_1_out->get_y() - cat_2->get_y(), 2)))) * 2);
				}
				if (cat_1 != NULL) if (sqrt(pow(plane_1_out->get_x() - cat_1->get_x(), 2) + pow(plane_1_out->get_y() - cat_1->get_y(), 2)) <= 180)
				{
					cat_1->mod_life(cat_1->get_life() - int((180 - sqrt(pow(plane_1_out->get_x() - cat_1->get_x(), 2) + pow(plane_1_out->get_y() - cat_1->get_y(), 2)))) * 2);
				}
				delete plane_1_out;
				plane_1_out = NULL;
			}


			if (plane_2_out != NULL) if (plane_2_out->get_life() <= 0)
			{
				boom_list2.push_back(new boom(plane_2_out->get_x(), plane_2_out->get_y(), boom_F, 2));
				sound_plane_boom.play();
				if (cat_2 != NULL) if (sqrt(pow(plane_2_out->get_x() - cat_2->get_x(), 2) + pow(plane_2_out->get_y() - cat_2->get_y(), 2)) <= 180)
				{
					cat_2->mod_life(cat_2->get_life() - int((180 - sqrt(pow(plane_2_out->get_x() - cat_2->get_x(), 2) + pow(plane_2_out->get_y() - cat_2->get_y(), 2)))) * 2);
				}
				if (cat_1 != NULL) if (sqrt(pow(plane_2_out->get_x() - cat_1->get_x(), 2) + pow(plane_2_out->get_y() - cat_1->get_y(), 2)) <= 180)
				{
					cat_1->mod_life(cat_1->get_life() - int((180 - sqrt(pow(plane_2_out->get_x() - cat_1->get_x(), 2) + pow(plane_2_out->get_y() - cat_1->get_y(), 2)))) * 2);
				}
				delete plane_2_out;
				plane_2_out = NULL;
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if (cat_1 != NULL)
			{
				if (Keyboard::isKeyPressed(Keyboard::C) && gg == 0)
				{
					pula_list1.push_back(new pula(cat_1->get_x(), cat_1->get_y(), clubok_F, cat_1->get_see(), 0));
					sound_ww.play();
					gg = 1;
				}
				if (!Keyboard::isKeyPressed(Keyboard::C) && gg == 1)
				{
					gg = 0;
				}
				if (Map_Matrix[int((cat_1->get_y()) / 40)][int(cat_1->get_x() / 40) + 1] == 'h')
				{
					if (Keyboard::isKeyPressed(Keyboard::R) && gg1==0)
					{
						sound_click.play();
						Chose1++;
						gg1 = 1;
					}
					if (!Keyboard::isKeyPressed(Keyboard::R) && gg1 == 1)
					{
						gg1 = 0;
					}
					Chose1 = Chose1 % 3;
					if (Keyboard::isKeyPressed(Keyboard::T) && Chose1==0 && Price_list1[0]>0 && plane_1_out == NULL)
					{
						sound_click.play();
						Price_list1[0]--;
						cat_1->mod_life(0);
						plane1_exist = 1;
					}
					if (Chose1 == 1 && Money1>=Price_list1[1])
					{
						cur1 += time * 0.003;
						cur2 += time * 0.01;
						if (Keyboard::isKeyPressed(Keyboard::T) && (gg2 == 0 || (cur1>1 && cur2>1)))
						{
							sound_click.play();
							gg2 = 1;
							cur2=0;
							Money1 -= Price_list1[1];
							pocket_list1[0]++;
						}
						if (!Keyboard::isKeyPressed(Keyboard::T) && gg2 == 1)
						{
							gg2 = 0;
						}
						if (!Keyboard::isKeyPressed(Keyboard::T))
						{
							cur1 = 0;
							cur2 = 0;
						}
					}
					if (Chose1 == 2 && Money1 >= Price_list1[2])
					{
						cur1 += time * 0.003;
						cur2 += time * 0.01;
						if (Keyboard::isKeyPressed(Keyboard::T) && (gg2 == 0 || (cur1 > 1 && cur2 > 1)))
						{
							sound_click.play();
							gg2 = 1;
							cur2 = 0;
							Money1 -= Price_list1[2];
							pocket_list1[1]++;
						}
						if (!Keyboard::isKeyPressed(Keyboard::T) && gg2 == 1)
						{
							gg2 = 0;
						}
						if (!Keyboard::isKeyPressed(Keyboard::T))
						{
							cur1 = 0;
							cur2 = 0;
						}
					}
					f1 = 1;
				}
				else
				{
					f1 = 0;
					Chose1 = 0;
				}
			}
			//cout << pocket_list1[0] << " " << pocket_list1[1] << endl;
			if (cat_1 != NULL) if (cat_1->get_life() <= 0)
			{
				X_D1 = cat_1->get_x();
				Y_D1 = cat_1->get_y();
				if (plane1_exist==0) psh_list.push_back(new psh(X_D1, Y_D1, psh_F));
				delete cat_1;
				cat_1 = NULL;
			}




			if (cat_1 != NULL)
			{
				ostringstream stroka1, stroka11;
				stroka1 << int(cat_1->get_life());
				stroka11 << Money1;
				text3.setOutlineColor(Color(0, 0, 0));
				text3.setOutlineThickness(1);
				text3.setString("C - " + stroka11.str() + "\nHP - " + stroka1.str());
				text3.setPosition(view1.getCenter().x - 450, view1.getCenter().y - 510);
				window.setView(view1);
				window.draw(background.sprite);//рисуем задний фон
				build_ground(Height_Map, Width_Map, ground.sprite, house.sprite, cat_1->get_x(), cat_1->get_y());//функция построения землN
				cat_1->update(time);
				window.draw(cat_1->get_sprite());
				if (cat_2 != NULL) window.draw(cat_2->get_sprite());
				if (plane_2 != NULL) window.draw(plane_2->get_sprite());
				if (plane_1_out != NULL)
				{
					window.draw(plane_1_out->get_sprite());
				}
				if (plane_2_out != NULL)
				{
					window.draw(plane_2_out->get_sprite());
				}
				for (itp = pula_list2.begin(); itp != pula_list2.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					itp++;
				}
				boom_func(time, &boom_list2);
				boom_func(time, &boom_list1);
				psh_func(time, &psh_list);
				pl_func(time, &pl_list);
				for (itc = (coin_list).begin(); itc != (coin_list).end();)
				{
					coin *b = *itc;
					(b)->update(time);
					if (sqrt(pow(cat_1->get_x() - (b)->get_x(), 2) + pow(cat_1->get_y() - (b)->get_y(), 2)) < 40)
					{
						(b)->mod_life(0);
						sound_coin.play();
						Money1+=2;
					}
					window.draw(b->get_sprite());
					if (b->get_life() == 0)
					{
						itc = (coin_list).erase(itc); delete b;
					}
					else itc++;
				}
				for (itpl = (pl_list).begin(); itpl != (pl_list).end();)
				{
					pl *b = *itpl;

					if (sqrt(pow(cat_1->get_x() - (b)->get_x(), 2) + pow(cat_1->get_y() - (b)->get_y(), 2)) < 40)
					{
						(b)->mod_life(0);
						sound_pl.play();
						cat_1->mod_life(cat_1->get_life() + (rand() % 90) + 10);
					}
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_life() == 0)
					{
						itpl = (pl_list).erase(itpl); delete b;
					}
					else itpl++;
				}
				window.draw(text3);
				if (f1)
				{
					ostringstream stroka1, stroka11, stroka111;
					stroka1 << Price_list1[0];
					stroka11 << Price_list1[1];
					stroka111 << Price_list1[2];
					text1.setString("*");
					text1.setFillColor(Color::Red);
					text1.setPosition(view1.getCenter().x - 50 +60*Chose1, view1.getCenter().y - 60);
					text3.setOutlineColor(Color(0, 0, 0));
					text3.setOutlineThickness(1);
					text3.setString(stroka1.str() + "  " + stroka11.str() + "C  " + stroka111.str() + "C");
					text3.setPosition(view1.getCenter().x -50, view1.getCenter().y + 30);
					ball.sprite.setPosition(view1.getCenter().x+10, view1.getCenter().y);
					torpeda.sprite.setPosition(view1.getCenter().x+60, view1.getCenter().y);
					plane.sprite.setPosition(view1.getCenter().x-60, view1.getCenter().y-10);
					window.draw(text3);
					window.draw(text1);
					window.draw(ball.sprite);
					window.draw(torpeda.sprite);
					window.draw(plane.sprite);
				}
				for (itp = pula_list1.begin(); itp != pula_list1.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_type() == 0)
					{
						if (cat_2 != NULL) if (sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)) <= 30)
						{
							b->mod_life(0);
							sound_miay.play();
							cat_2->mod_life(cat_2->get_life() - 10);
						}
						if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50)
						{
							b->mod_life(0);
							plane_2->mod_life(plane_2->get_life() - 2);
						}
					}
					else if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50) b->mod_life(0);
					if ((b)->get_x() <= 10 || (b)->get_x() >= 5350 || (b)->get_y() <= 20 || (b)->get_y() >= 1540)
					{
						itp = pula_list1.erase(itp); delete b;
					}
					else//нужно для того чтобы в следующем if не обращаться к несуществующему обьекту
						if (b->get_life() == 0)
						{
							if (b->get_type() == 1)
							{
								if (cat_2 != NULL) if (sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)) <= 60)
								{
									sound_miay.play();
									cat_2->mod_life(cat_2->get_life() - int((60 - sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)))));
								}
								if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50)
								{
									plane_2->mod_life(plane_2->get_life() - 13);
								}
								boom_list1.push_back(new boom(b->get_x(), b->get_y(), boom_F, 0.25));
								sound_ball_boom.play();
							}
							if (b->get_type() == 2)
							{
								if (cat_2 != NULL) if (sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)) <= 120)
								{
									sound_miay.play();
									cat_2->mod_life(cat_2->get_life() - int((120 - sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)))));
								}
								if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50)
								{
									plane_2->mod_life(plane_2->get_life() - 21);
								}
								boom_list1.push_back(new boom(b->get_x(), b->get_y(), boom_F, 1));
								sound_torpeda_boom.play();
							}
							itp = pula_list1.erase(itp); delete b;
						}
						else itp++;
				}


				Center(&view1, cat_1->get_x(), cat_1->get_y());
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////


			if (cat_2 != NULL)
			{
				if (Keyboard::isKeyPressed(Keyboard::M) && bb == 0)
				{
					pula_list2.push_back(new pula(cat_2->get_x(), cat_2->get_y(), clubok_F, cat_2->get_see(), 0));
					sound_ww.play();
					bb = 1;
				}
				if (!Keyboard::isKeyPressed(Keyboard::M) && bb == 1)
				{
					bb = 0;
				}
				if (Map_Matrix[int((cat_2->get_y()) / 40)][int(cat_2->get_x() / 40) + 1] == 'H')
				{
					if (Keyboard::isKeyPressed(Keyboard::I) && bb1 == 0)
					{
						sound_click.play();
						Chose2++;
						bb1 = 1;
					}
					if (!Keyboard::isKeyPressed(Keyboard::I) && bb1 == 1)
					{
						bb1 = 0;
					}
					Chose2 = Chose2 % 3;
					if (Keyboard::isKeyPressed(Keyboard::O) && Chose2 == 0 && Price_list2[0] > 0 && plane_2_out==NULL)
					{
						sound_click.play();
						Price_list2[0]--;
						cat_2->mod_life(0);
						plane2_exist = 1;
					}
					if (Chose2 == 1 && Money2 >= Price_list2[1])
					{
						cur4 += time * 0.003;
						cur5 += time * 0.01;
						if (Keyboard::isKeyPressed(Keyboard::O) && (bb2 == 0 || (cur4 > 1 && cur5 > 1)))
						{
							sound_click.play();
							bb2 = 1;
							cur5 = 0;
							Money2 -= Price_list2[1];
							pocket_list2[0]++;
						}
						if (!Keyboard::isKeyPressed(Keyboard::O) && bb2 == 1)
						{
							bb2 = 0;
						}
						if (!Keyboard::isKeyPressed(Keyboard::O))
						{
								cur4 = 0;
								cur5 = 0;
						}
					}
					if (Chose2 == 2 && Money2 >= Price_list2[2])
					{
						cur4 += time * 0.003;
						cur5 += time * 0.01;
						if (Keyboard::isKeyPressed(Keyboard::O) && (bb2 == 0 || (cur4 > 1 && cur5 > 1)))
						{
							sound_click.play();
							bb2 = 1;
							cur5 = 0;
							Money2 -= Price_list2[2];
							pocket_list2[1]++;
						}
						if (!Keyboard::isKeyPressed(Keyboard::O) && bb2 == 1)
						{
							bb2 = 0;
						}
						if (!Keyboard::isKeyPressed(Keyboard::O))
						{
							cur4 = 0;
							cur5 = 0;
						}
					}
					f2 = 1;
				}
				else
				{
					f2 = 0;
					Chose2 = 0;
				}
			}
			//cout << pocket_list2[0] << " " << pocket_list2[1] << endl;



			if (cat_2 != NULL) if (cat_2->get_life() <= 0)
			{
				X_D2 = cat_2->get_x();
				Y_D2 = cat_2->get_y();
				if (plane2_exist==0) psh_list.push_back(new psh(X_D2, Y_D2, psh_F));
				delete cat_2;
				cat_2 = NULL;
			}




			if (cat_2 != NULL)
			{
				ostringstream stroka2, stroka22;
				stroka2 << int(cat_2->get_life());
				stroka22 << Money2;
				text4.setOutlineColor(Color(0, 0, 0));
				text4.setOutlineThickness(1);
				text4.setString("C - " + stroka22.str() + "\nHP - " + stroka2.str());
				text4.setPosition(view2.getCenter().x + 280, view2.getCenter().y - 510);
				window.setView(view2);
				window.draw(background.sprite);//рисуем задний фон
				build_ground(Height_Map, Width_Map, ground.sprite, house.sprite, cat_2->get_x(), cat_2->get_y());//функция построения земли
				window.draw(cat_2->get_sprite());
				cat_2->update(time);
				if (cat_1 != NULL) window.draw(cat_1->get_sprite());
				if (plane_1 != NULL) window.draw(plane_1->get_sprite());
				if (plane_2_out != NULL)
				{
					window.draw(plane_2_out->get_sprite());
				}
				if (plane_1_out != NULL)
				{
					window.draw(plane_1_out->get_sprite());
				}
				for (itp = pula_list1.begin(); itp != pula_list1.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					itp++;
				}
				boom_func(time, &boom_list1);
				boom_func(time, &boom_list2);
				psh_func(time, &psh_list);
				for (itc = (coin_list).begin(); itc != (coin_list).end();)
				{
					coin *b = *itc;
					(b)->update(time);
					if (sqrt(pow(cat_2->get_x() - (b)->get_x(), 2) + pow(cat_2->get_y() - (b)->get_y(), 2)) < 40)
					{
						(b)->mod_life(0);
						sound_coin.play();
						Money2+=2;
					}
					window.draw(b->get_sprite());
					if (b->get_life() == 0)
					{
						itc = (coin_list).erase(itc); delete b;
					}
					else itc++;
				}
				for (itpl = (pl_list).begin(); itpl != (pl_list).end();)
				{
					pl *b = *itpl;

					if (sqrt(pow(cat_2->get_x() - (b)->get_x(), 2) + pow(cat_2->get_y() - (b)->get_y(), 2)) < 40)
					{
						(b)->mod_life(0);
						sound_pl.play();
						cat_2->mod_life(cat_2->get_life() + (rand() % 90) + 10);
					}
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_life() == 0)
					{
						itpl = (pl_list).erase(itpl); delete b;
					}
					else itpl++;
				}
				window.draw(text4);
				if (f2)
				{
					ostringstream stroka1, stroka11, stroka111;
					stroka1 << Price_list2[0];
					stroka11 << Price_list2[1];
					stroka111 << Price_list2[2];
					text1.setString("*");
					text1.setFillColor(Color::Red);
					text1.setPosition(view2.getCenter().x - 50 + 60 * Chose2, view2.getCenter().y - 60);
					text4.setOutlineColor(Color(0, 0, 0));
					text4.setOutlineThickness(1);
					text4.setString(stroka1.str() + "  " + stroka11.str() + "C  " + stroka111.str() + "C");
					text4.setPosition(view2.getCenter().x - 50, view2.getCenter().y + 30);
					ball.sprite.setPosition(view2.getCenter().x, view2.getCenter().y);
					torpeda.sprite.setPosition(view2.getCenter().x + 60, view2.getCenter().y);
					plane.sprite.setPosition(view2.getCenter().x - 60, view2.getCenter().y - 10);
					window.draw(text4);
					window.draw(text1);
					window.draw(ball.sprite);
					window.draw(torpeda.sprite);
					window.draw(plane.sprite);
				}
				for (itp = pula_list2.begin(); itp != pula_list2.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_type() == 0)
					{
						if (cat_1 != NULL) if (sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)) <= 30)
						{
							b->mod_life(0);
							sound_miay.play();
							cat_1->mod_life(cat_1->get_life() - 10);
						}
						if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50)
						{
							b->mod_life(0);
							plane_1->mod_life(plane_1->get_life() - 2);
						}
					}
					else if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50) b->mod_life(0);
					if ((b)->get_x() <= 10 || (b)->get_x() >= 5350 || (b)->get_y() <= 20 || (b)->get_y() >= 1540)
					{
						itp = pula_list2.erase(itp); delete b;
					}
					else//нужно для того чтобы в следующем if не обращаться к несуществующему обьекту
						if (b->get_life() == 0)
						{
							if (b->get_type() == 1)
							{
								if (cat_1 != NULL) if (sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)) <= 60)
								{
									sound_miay.play();
									cat_1->mod_life(cat_1->get_life() - int((60 - sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)))));
								}
								if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50)
								{
									plane_1->mod_life(plane_1->get_life() - 13);
								}
								boom_list2.push_back(new boom(b->get_x(), b->get_y(), boom_F, 0.25));
								sound_ball_boom.play();
							}
							if (b->get_type() == 2)
							{
								if (cat_1 != NULL) if (sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)) <= 120)
								{
									sound_miay.play();
									cat_1->mod_life(cat_1->get_life() - int((120 - sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)))));
								}
								if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50)
								{
									plane_1->mod_life(plane_1->get_life() - 21);
								}
								boom_list2.push_back(new boom(b->get_x(), b->get_y(), boom_F, 1));
								sound_torpeda_boom.play();
							}
							itp = pula_list2.erase(itp); delete b;
						}
						else itp++;
				}

				Center(&view2, cat_2->get_x(), cat_2->get_y());
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (plane_1 != NULL)
			{
				if (Keyboard::isKeyPressed(Keyboard::C) && gg == 0)
				{
					if (Chose1 == 0)
					{
						pula_list1.push_back(new pula(plane_1->get_x(), plane_1->get_y(), clubok_F, plane_1->get_see(), 0));
						sound_ww.play();

					}
					if (Chose1 == 1 && pocket_list1[0] > 0)
					{
						pula_list1.push_back(new pula(plane_1->get_x(), plane_1->get_y(), ball_F, plane_1->get_see(), 1));
						sound_www.play();
						pocket_list1[0]--;
					}
					if (Chose1 == 2 && pocket_list1[1] > 0)
					{
						pula_list1.push_back(new pula(plane_1->get_x(), plane_1->get_y(), torpeda_F, plane_1->get_see(), 2));
						sound_wwww.play();
						pocket_list1[1]--;
					}
					gg = 1;
				}
				if (!Keyboard::isKeyPressed(Keyboard::C) && gg == 1)
				{
					gg = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::S) && plane_1->get_x()>60 && plane_1->get_x() < 5300 && plane_1->get_y() > 60)
				{
					cat1_exist = 1;
				}
				if (Keyboard::isKeyPressed(Keyboard::R) && gg1 == 0)
				{
					sound_click.play();
					Chose1++;
					Chose1 %= 3;
					gg1 = 1;
				}
				if (!Keyboard::isKeyPressed(Keyboard::R) && gg1 == 1)
				{
					gg1 = 0;
				}
			}




			if (plane_1 != NULL) if (plane_1->get_life() <= 0)
			{
				boom_list1.push_back(new boom(plane_1->get_x(), plane_1->get_y(), boom_F, 2));
				sound_plane_boom.play();
				if (plane_2 == NULL) music_engine.pause();
				X_D1 = plane_1->get_x();
				Y_D1 = plane_1->get_y();
				if (cat_2 != NULL) if (sqrt(pow(X_D1 - cat_2->get_x(), 2) + pow(Y_D1 - cat_2->get_y(), 2)) <= 180)
				{
					cat_2->mod_life(cat_2->get_life() - int((180 - sqrt(pow(X_D1 - cat_2->get_x(), 2) + pow(Y_D1 - cat_2->get_y(), 2))))*2);
				}
				delete plane_1;
				plane_1 = NULL;
			}



			if (plane_1!=NULL)
			{
				ostringstream stroka1, stroka11, stroka111;
				stroka1 << int(plane_1->get_life());
				stroka11 << Money1;
				if (Chose1 == 0) stroka111 << "&";
				if (Chose1 == 1) stroka111 << pocket_list1[0];
				if (Chose1 == 2) stroka111 << pocket_list1[1];
				text3.setOutlineColor(Color(0, 0, 0));
				text3.setOutlineThickness(1);
				text3.setString("C - " + stroka11.str() + "\nHP - " + stroka1.str() + "\n" + stroka111.str());
				text3.setPosition(view1.getCenter().x - 450, view1.getCenter().y - 510);


				window.setView(view1);
				window.draw(background.sprite);//рисуем задний фон
				build_ground(Height_Map, Width_Map, ground.sprite, house.sprite, plane_1->get_x(), plane_1->get_y());//функция построения землN
				if (cat_2 != NULL) window.draw(cat_2->get_sprite());
				if (plane_2 != NULL) window.draw(plane_2->get_sprite());
				if (plane_2_out != NULL)
				{
					window.draw(plane_2_out->get_sprite());
				}
				for (itp = pula_list2.begin(); itp != pula_list2.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					itp++;
				}
				window.draw(plane_1->get_sprite());
				plane_1->update(time);
				boom_func(time, &boom_list1);
				boom_func(time, &boom_list2);
				psh_func(time, &psh_list);
				for (itc = (coin_list).begin(); itc != (coin_list).end();)
				{
					coin *b = *itc;
					(b)->update(time);
					if (sqrt(pow(plane_1->get_x() - (b)->get_x(), 2) + pow(plane_1->get_y() - (b)->get_y(), 2)) < 70)
					{
						(b)->mod_life(0);
						sound_coin.play();
						Money1+=2;
					}
					window.draw(b->get_sprite());
					if (b->get_life() == 0)
					{
						itc = (coin_list).erase(itc); delete b;
					}
					else itc++;
				}
				for (itpl = (pl_list).begin(); itpl != (pl_list).end();)
				{
					pl *b = *itpl;

					if (sqrt(pow(plane_1->get_x() - (b)->get_x(), 2) + pow(plane_1->get_y() - (b)->get_y(), 2)) < 60)
					{
						(b)->mod_life(0);
						sound_pl.play();
						plane_1->mod_life(plane_1->get_life() + (rand() % 40) + 10);
					}
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_life() == 0)
					{
						itpl = (pl_list).erase(itpl); delete b;
					}
					else itpl++;
				}
				window.draw(text3);
				for (itp = pula_list1.begin(); itp != pula_list1.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_type() == 0)
					{
						if (cat_2 != NULL) if (sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)) <= 30)
						{
							b->mod_life(0);
							sound_miay.play();
							cat_2->mod_life(cat_2->get_life() - 10);
						}
						if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50)
						{
							b->mod_life(0);
							plane_2->mod_life(plane_2->get_life() - 2);
						}
					} else if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50) b->mod_life(0);
					if ((b)->get_x() <= 10 || (b)->get_x() >= 5350 || (b)->get_y() <= 20 || (b)->get_y() >= 1540)
					{
						itp = pula_list1.erase(itp); delete b;
					}
					else//нужно для того чтобы в следующем if не обращаться к несуществующему обьекту
						if (b->get_life() == 0)
						{
							if (b->get_type() == 1)
							{
								if (cat_2 != NULL) if (sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)) <= 60)
								{
									sound_miay.play();
									cat_2->mod_life(cat_2->get_life() - int((60- sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)))));
								}
								if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50)
								{
									plane_2->mod_life(plane_2->get_life() - 13);
								}
								boom_list1.push_back(new boom(b->get_x(), b->get_y(), boom_F, 0.25));
								sound_ball_boom.play();
							}
							if (b->get_type() == 2)
							{
								if (cat_2 != NULL) if (sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)) <= 120)
								{
									sound_miay.play();
									cat_2->mod_life(cat_2->get_life() - int((120 - sqrt(pow(b->get_x() - cat_2->get_x(), 2) + pow(b->get_y() - cat_2->get_y(), 2)))));
								}
								if (plane_2 != NULL) if (sqrt(pow(b->get_x() - plane_2->get_x(), 2) + pow(b->get_y() - plane_2->get_y(), 2)) <= 50)
								{
									plane_2->mod_life(plane_2->get_life() - 21);
								}
								boom_list1.push_back(new boom(b->get_x(), b->get_y(), boom_F, 1));
								sound_torpeda_boom.play();
							}
							itp = pula_list1.erase(itp); delete b;
						}
						else itp++;
				}



			Center(&view1, plane_1->get_x(), plane_1->get_y());
			}



		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if (plane_2 != NULL)
			{
				if (Keyboard::isKeyPressed(Keyboard::M) && bb == 0)
				{
					if (Chose2 == 0)
					{
						pula_list2.push_back(new pula(plane_2->get_x(), plane_2->get_y(), clubok_F, plane_2->get_see(), 0));
						sound_ww.play();

					}
					if (Chose2 == 1 && pocket_list2[0] > 0)
					{
						pula_list2.push_back(new pula(plane_2->get_x(), plane_2->get_y(), ball_F, plane_2->get_see(), 1));
						sound_www.play();
						pocket_list2[0]--;
					}
					if (Chose2 == 2 && pocket_list2[1] > 0)
					{
						pula_list2.push_back(new pula(plane_2->get_x(), plane_2->get_y(), torpeda_F, plane_2->get_see(), 2));
						sound_wwww.play();
						pocket_list2[1]--;
					}
					bb = 1;
				}
				if (!Keyboard::isKeyPressed(Keyboard::M) && bb == 1)
				{
					bb = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::Down) && plane_2->get_x() > 60 && plane_2->get_x() < 5300 && plane_2->get_y() > 60)
				{
					cat2_exist = 1;
				}
				if (Keyboard::isKeyPressed(Keyboard::I) && bb1 == 0)
				{
					sound_click.play();
					Chose2++;
					Chose2 %= 3;
					bb1 = 1;
				}
				if (!Keyboard::isKeyPressed(Keyboard::I) && bb1 == 1)
				{
					bb1 = 0;
				}
			}


			if (plane_2 != NULL) if (plane_2->get_life() <= 0)
			{
				boom_list2.push_back(new boom(plane_2->get_x(), plane_2->get_y(), boom_F, 2));
				sound_plane_boom.play();
				if (plane_1 == NULL) music_engine.pause();
				X_D2 = plane_2->get_x();
				Y_D2 = plane_2->get_y();
				if (cat_1 != NULL) if (sqrt(pow(X_D2 - cat_1->get_x(), 2) + pow(Y_D2 - cat_1->get_y(), 2)) <= 180)
				{
					cat_1->mod_life(cat_1->get_life() - int((180 - sqrt(pow(X_D2 - cat_1->get_x(), 2) + pow(Y_D2 - cat_1->get_y(), 2)))) * 2);
				}
				delete plane_2;
				plane_2 = NULL;
			}


			if (plane_2 != NULL)
			{

				ostringstream stroka1, stroka11, stroka111;
				stroka1 << int(plane_2->get_life());
				stroka11 << Money2;
				if (Chose2 == 0) stroka111 << "&";
				if (Chose2 == 1) stroka111 << pocket_list2[0];
				if (Chose2 == 2) stroka111 << pocket_list2[1];
				text4.setOutlineColor(Color(0, 0, 0));
				text4.setOutlineThickness(1);
				text4.setString("C - " + stroka11.str() + "\nHP - " + stroka1.str() + "\n" + stroka111.str());
				text4.setPosition(view2.getCenter().x + 280, view2.getCenter().y - 510);


				window.setView(view2);
				window.draw(background.sprite);//рисуем задний фон
				build_ground(Height_Map, Width_Map, ground.sprite, house.sprite, plane_2->get_x(), plane_2->get_y());//функция построения землN
				if (cat_1 != NULL) window.draw(cat_1->get_sprite());
				if (plane_1 != NULL) window.draw(plane_1->get_sprite());
				if (plane_1_out != NULL)
				{
					window.draw(plane_1_out->get_sprite());
				}
				if (plane_2_out != NULL)
				{
					window.draw(plane_2_out->get_sprite());
				}
				for (itp = pula_list1.begin(); itp != pula_list1.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					itp++;
				}
				window.draw(plane_2->get_sprite());
				plane_2->update(time);
				boom_func(time, &boom_list2);
				boom_func(time, &boom_list1);
				psh_func(time, &psh_list);
				for (itc = (coin_list).begin(); itc != (coin_list).end();)
				{
					coin *b = *itc;
					(b)->update(time);
					if (sqrt(pow(plane_2->get_x() - (b)->get_x(), 2) + pow(plane_2->get_y() - (b)->get_y(), 2)) < 70)
					{
						(b)->mod_life(0);
						sound_coin.play();
						Money2 += 2;
					}
					window.draw(b->get_sprite());
					if (b->get_life() == 0)
					{
						itc = (coin_list).erase(itc); delete b;
					}
					else itc++;
				}
				for (itpl = (pl_list).begin(); itpl != (pl_list).end();)
				{
					pl *b = *itpl;

					if (sqrt(pow(plane_2->get_x() - (b)->get_x(), 2) + pow(plane_2->get_y() - (b)->get_y(), 2)) < 60)
					{
						(b)->mod_life(0);
						sound_pl.play();
						plane_2->mod_life(plane_2->get_life() + (rand() % 40) + 10);
					}
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_life() == 0)
					{
						itpl = (pl_list).erase(itpl); delete b;
					}
					else itpl++;
				}
				window.draw(text4);
				for (itp = pula_list2.begin(); itp != pula_list2.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					(b)->update(time);
					if (b->get_type() == 0)
					{
						if (cat_1 != NULL) if (sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)) <= 30)
						{
							b->mod_life(0);
							sound_miay.play();
							cat_1->mod_life(cat_1->get_life() - 10);
						}
						if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50)
						{
							b->mod_life(0);
							plane_1->mod_life(plane_1->get_life() - 2);
						}
					}
					else if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50) b->mod_life(0);
					if ((b)->get_x() <= 10 || (b)->get_x() >= 5350 || (b)->get_y() <= 20 || (b)->get_y() >= 1540)
					{
						itp = pula_list2.erase(itp); delete b;
					}
					else//нужно для того чтобы в следующем if не обращаться к несуществующему обьекту
						if (b->get_life() == 0)
						{
							if (b->get_type() == 1)
							{
								if (cat_1 != NULL) if (sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)) <= 60)
								{
									sound_miay.play();
									cat_1->mod_life(cat_1->get_life() - int((60 - sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)))));
								}
								if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50)
								{
									plane_1->mod_life(plane_1->get_life() - 13);
								}
								boom_list2.push_back(new boom(b->get_x(), b->get_y(), boom_F, 0.25));
								sound_ball_boom.play();
							}
							if (b->get_type() == 2)
							{
								if (cat_1 != NULL) if (sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)) <= 120)
								{
									sound_miay.play();
									cat_1->mod_life(cat_1->get_life() - int((120 - sqrt(pow(b->get_x() - cat_1->get_x(), 2) + pow(b->get_y() - cat_1->get_y(), 2)))));
								}
								if (plane_1 != NULL) if (sqrt(pow(b->get_x() - plane_1->get_x(), 2) + pow(b->get_y() - plane_1->get_y(), 2)) <= 50)
								{
									plane_1->mod_life(plane_1->get_life() - 21);
								}
								boom_list2.push_back(new boom(b->get_x(), b->get_y(), boom_F, 1));
								sound_torpeda_boom.play();
							}
							itp = pula_list2.erase(itp); delete b;
						}
						else itp++;
				}



				Center(&view2, plane_2->get_x(), plane_2->get_y());
			}


			if (cat_1 == NULL && plane_1 == NULL && cat1_exist == 0 && plane1_exist == 0)
			{
				window.setView(view1);
				for (itc = (coin_list).begin(); itc != (coin_list).end();)
				{
					coin *b = *itc;
					(b)->mod_life(0);
					if (b->get_life() == 0)
					{
						itc = (coin_list).erase(itc); delete b;
					}
					else itc++;
				}
				window.draw(background.sprite);//рисуем задний фон
				build_ground(Height_Map, Width_Map, ground.sprite, house.sprite, X_D1, Y_D1);//функция построения землN
				if (cat_2 != NULL) window.draw(cat_2->get_sprite());
				if (plane_2 != NULL) window.draw(plane_2->get_sprite());
				if (plane_1_out != NULL) window.draw(plane_1_out->get_sprite());
				if (plane_2_out != NULL) window.draw(plane_2_out->get_sprite());
				for (itpl = pl_list.begin(); itpl != pl_list.end();)
				{
					pl *b = *itpl;
					(b)->mod_life(0);
					if (b->get_life() == 0)
					{
						itpl = pl_list.erase(itpl); delete b;
					}
					else itpl++;
				}
				for (itp = pula_list1.begin(); itp != pula_list1.end();)
				{
					pula *b = *itp;
					(b)->update(time);
					//window.draw(b->get_sprite());
					if (b->get_life() == 0)
					{
						itp = (pula_list1).erase(itp); delete b;
					} else
					{
						window.draw(b->get_sprite());
						itp++;
					}

				}

				for (itp = pula_list2.begin(); itp != pula_list2.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					itp++;
				}
				boom_func(time, &boom_list1);
				boom_func(time, &boom_list2);
				psh_func(time, &psh_list);
			}



			if (cat_2 == NULL && plane_2 == NULL && cat2_exist == 0 && plane2_exist == 0)
			{
				window.setView(view2);
				for (itc = (coin_list).begin(); itc != (coin_list).end();)
				{
					coin *b = *itc;
					(b)->mod_life(0);
					if (b->get_life() == 0)
					{
						itc = (coin_list).erase(itc); delete b;
					}
					else itc++;
				}
				window.draw(background.sprite);//рисуем задний фон
				build_ground(Height_Map, Width_Map, ground.sprite, house.sprite, X_D2, Y_D2);//функция построения землN
				for (itp = pula_list1.begin(); itp != pula_list1.end();)
				{
					pula *b = *itp;
					window.draw(b->get_sprite());
					itp++;
				}

				for (itp = pula_list2.begin(); itp != pula_list2.end();)
				{
					pula *b = *itp;
					(b)->update(time);
					if (b->get_life() == 0)
					{
						itp = (pula_list2).erase(itp); delete b;
					} else
					{
						window.draw(b->get_sprite());
						itp++;
					}
				}
				if (cat_1 != NULL) window.draw(cat_1->get_sprite());
				if (plane_1 != NULL) window.draw(plane_1->get_sprite());
				if (plane_1_out != NULL) window.draw(plane_1_out->get_sprite());
				if (plane_2_out != NULL) window.draw(plane_2_out->get_sprite());
				for (itpl = pl_list.begin(); itpl != pl_list.end();)
				{
					pl *b = *itpl;
					(b)->mod_life(0);
					if (b->get_life() == 0)
					{
						itpl = pl_list.erase(itpl); delete b;
					}
					else itpl++;
				}
				boom_func(time, &boom_list1);
				boom_func(time, &boom_list2);
				psh_func(time, &psh_list);
			}

















			if ((cat_1 == NULL && plane_1 == NULL && cat1_exist == 0 && plane1_exist == 0) || (cat_2 == NULL && plane_2 == NULL && cat2_exist == 0 && plane2_exist == 0))
			{
				music_back.pause();
				cur3 += time * 0.01;
				cur_pl = 0;
				cur_coin = 0;
				if (cur3 > 20)
				{
					cur3 = 0;
					GLOB = 3;
					text1.setFillColor(Color::Red);
					text2.setFillColor(Color(255, 255, 255));
					sound_click.play();
					music_winback.openFromFile("audio/winback.ogg");
					music_winback.play();
					music_winback.setLoop(true);
				}
			}



		}

		if (GLOB == 3)
		{
			music_engine.pause();
			cur3 = 0;
			for (itp = pula_list1.begin(); itp != pula_list1.end();)
			{
				pula *b = *itp;
				(b)->mod_life(0);
				if (b->get_life() == 0)
				{
					itp = pula_list1.erase(itp); delete b;
				}
				else itp++;
			}

			for (itp = pula_list2.begin(); itp != pula_list2.end();)
			{
				pula *b = *itp;
				(b)->mod_life(0);
				if (b->get_life() == 0)
				{
					itp = pula_list2.erase(itp); delete b;
				}
				else itp++;
			}
			window.setView(view);
			text1.setString("WINER");
			text2.setString("LOSER");
			if (plane_2_out != NULL)
			{
				delete plane_2_out;
				plane_2_out = NULL;
			}
			if (plane_1_out != NULL)
			{
				delete plane_1_out;
				plane_1_out = NULL;
			}
			if (plane_1 == NULL && cat_1 == NULL && plane_2 == NULL && cat_2 == NULL)
			{
				text3.setString("...");
				text3.setPosition(view.getCenter().x-15, view.getCenter().y);
				window.draw(text3);
			}
			if (plane_1 == NULL && cat_1 == NULL && (plane_2 != NULL || cat_2 != NULL))
			{
				text1.setPosition(view.getCenter().x + 200, view.getCenter().y);
				text2.setPosition(view.getCenter().x - 450, view.getCenter().y);
				window.draw(text1);
				window.draw(text2);
			}
			if (plane_2 == NULL && cat_2 == NULL && (plane_1 != NULL || cat_1 != NULL))
			{
				text1.setPosition(view.getCenter().x - 450, view.getCenter().y);
				text2.setPosition(view.getCenter().x + 200, view.getCenter().y);
				window.draw(text1);
				window.draw(text2);
			}

			cur6 += time * 0.01;
			if (cur6 > 15)
			{
				text3.setString("Press Escape");
				text3.setPosition(view.getCenter().x - 125, view.getCenter().y+450);
				window.draw(text3);
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				I = 10;
				delete cat_1;
				delete plane_1;
				cat_1 = NULL;
				plane_1 = NULL;
				delete cat_2;
				delete plane_2;
				cat_2 = NULL;
				plane_2 = NULL;
				pocket_list1[1] = 0;
				pocket_list2[1] = 0;
				pocket_list1[0] = 0;
				pocket_list2[0] = 0;
				GLOB = 0;
				music_winback.pause();
				music_back.openFromFile("audio/back1.ogg");//загружаем файл
				music_back.setVolume(100);
				music_back.play();//воспроизводим музыку
				music_back.setLoop(true);
			}
		}

		window.display();//рисуем все что задано выше
		window.clear();
	}
}
