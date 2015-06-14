//
// graphic.cpp for Zappy in /home/chaulv_c//rendu/c/zappy/clientsrc
//
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
//
// Started on  Wed Jun  8 14:00:16 2011 chris chaulvet
// Last update Sun Jul 10 18:41:32 2011 inan asan
//

#include "client.hh"
#include "Convstr.hpp"

Graphic::Graphic(int height, int width)
  : _height(height), _width(width), _view_x(width), _view_y(height)
{
  this->_flag = true;
  this->App = new sf::RenderWindow(sf::VideoMode(this->_height, this->_width)
				   , "Zappy | NT Editon", sf::Style::Close);
  this->_linemate.LoadFromFile("./client_v3/images/linemate.jpg");
  this->_deraumere.LoadFromFile("./client_v3/images/deraumere.jpg");
  this->_sibur.LoadFromFile("./client_v3/images/sibur.jpg");
  this->_mendiane.LoadFromFile("./client_v3/images/mendiane.jpg");
  this->_phiras.LoadFromFile("./client_v3/images/phiras.jpg");
  this->_thystame.LoadFromFile("./client_v3/images/thystame.jpg");
  this->_food.LoadFromFile("./client_v3/images/food.png");
  this->_floor.LoadFromFile("./client_v3/images/floor.jpg");
  this->_info.LoadFromFile("./client_v3/images/info.jpg");
  this->_p.LoadFromFile("./client_v3/images/player.png");
  this->aff_x_min = 0;
  this->aff_y_min = 0;
  this->clic = false;
}

Graphic::~Graphic()
{
  delete this->App;
}

void		Graphic::aff_msg(std::string msg)
{
  sf::Font				gretoon;
  static std::vector<std::string>	m;
  int					i = 0;
  int					y = 595;

  if (!gretoon.LoadFromFile("./client_v3/Adolphus.ttf"))
    return;
  if (msg != "")
    m.push_back(msg);
  if (m.size() > 10)
    m.erase(m.begin());
  while (i < m.size())
    {
      sf::String Text(m[i], gretoon, 15);
      Text.SetColor(sf::Color(255, 0, 0));
      Text.Move(920, y);
      this->App->Draw(Text);
      i++;
      y += 15;
    }
}

void		Graphic::aff_ress(int x, int y, sf::Image img)
{
  sf::Sprite Sprite(img);

  Sprite.SetX(x);
  Sprite.SetY(y);
  this->App->Draw(Sprite);
}


void		Graphic::setMapBlock(std::list<t_block> *map)
{
  this->_map = *map;
}

void		Graphic::setPlayers(std::list<t_players> *player)
{
  this->_players = *player;
}

void		Graphic::setEgg(std::list<t_egg> *egg)
{
  this->_egg = *egg;
}

void		Graphic::aff_info(t_block *block)
{
  sf::Font	gretoon;
  std::string	info;
  static t_block*	old;

  if (!gretoon.LoadFromFile("./client_v3/Adolphus.ttf"))
    return;
  if (block != NULL)
    old = block;

  if (old != NULL)
    {
      info = "BLOCK " + nb_to_string(old->x) + " - " + 
	nb_to_string(old->y) + "\n\n " + nb_to_string(old->sibur) +
	"\n\n " + nb_to_string(old->thystame) +
	"\n\n " + nb_to_string(old->phiras) +
	"\n\n " + nb_to_string(old->mendiane) +
	"\n\n " + nb_to_string(old->linemate) +
	"\n\n " + nb_to_string(old->deraumere) +
	"\n\n " + nb_to_string(old->food);
      sf::String Text(info, gretoon, 17);
      Text.SetColor(sf::Color(255, 255, 255));
      Text.Move(1020, 0);
      this->App->Draw(Text);

      info = "x" + nb_to_string(this->_players.size());
      sf::String Text3(info, gretoon, 16);
      Text3.SetColor(sf::Color(255, 255, 255));
      Text3.Move(1010, 290);
      this->App->Draw(Text3);

      info = "x" + nb_to_string(this->_egg.size());
      sf::String Text4(info, gretoon, 16);
      Text4.SetColor(sf::Color(255, 255, 255));
      Text4.Move(1010, 322);
      this->App->Draw(Text4);

      std::list<t_players>::iterator it;
      int y = 400;
      it = this->_players.begin();
      for(unsigned int i = 0; i < this->_players.size(); i++)
	{
	  if (it->x == old->x && it->y == old->y)
	    {
	      info = "Player " + nb_to_string(it->id) + " - lvl:  " + nb_to_string(it->level) + " - team : " + it->team_name;
	      sf::String Text2(info, gretoon, 14);
	      Text2.SetColor(sf::Color(0, 255, 0));
	      Text2.Move(900, y);
	      this->App->Draw(Text2);
	      y += 20;
	      if (i == 6)
		return;
	    }
	  it++;
	}
    }
}

void		Graphic::getIt(int x, int y)
{
  std::list<t_block>::iterator it = this->_map.begin();
  
  this->clic = true;
  for( ; it != this->_map.end(); it++)
    {
      if (((*it).x) == ((x / CSIZE) + this->aff_x_min) &&
	  (((*it).y) == ((y / CSIZE) + this->aff_y_min)))
	{
	  this->aff_info(&(*it));
	  return;
	}
    }
}

void		Graphic::display(t_block *block)
{
  static		int x = 0;
  static		int y = 0;

  if ((block->x >= this->aff_x_min && block->x <= (this->aff_x_min+14)) &&
      (block->y >= this->aff_y_min && block->y <= (this->aff_y_min+14)))
    {
      block->x -= this->aff_x_min;
      block->y -= this->aff_y_min;
      this->aff_ress(block->x * CSIZE, block->y * CSIZE, this->_floor);
      if (block->linemate > 0)
	this->aff_ress((block->x * CSIZE), (block->y * CSIZE), this->_linemate);
      if (block->deraumere > 0)
	this->aff_ress((block->x * CSIZE) + 15, (block->y * CSIZE), this->_deraumere);
      if (block->sibur > 0)
	this->aff_ress((block->x * CSIZE) + 30, (block->y * CSIZE), this->_sibur);
      if (block->mendiane > 0)
	this->aff_ress((block->x * CSIZE), (block->y * CSIZE) + 15, this->_mendiane);
      if (block->phiras > 0)
	this->aff_ress((block->x * CSIZE) + 15, (block->y * CSIZE) + 15, this->_phiras);
      if (block->thystame > 0)
	this->aff_ress((block->x * CSIZE) + 30, (block->y * CSIZE) + 15, this->_thystame);
      if (block->food > 0)
	this->aff_ress((block->x * CSIZE) + 0, (block->y * CSIZE) + 30, this->_food);
    }
}

void		Graphic::display2(t_players *player)
{
  if ((player->x >= this->aff_x_min && player->x <= (this->aff_x_min+14)) &&
      (player->y >= this->aff_y_min && player->y <= (this->aff_y_min+14)))
    {
      player->x -= this->aff_x_min;
      player->y -= this->aff_y_min;
      sf::Sprite Sprite(this->_p);
      Sprite.SetX(player->x * CSIZE);
      Sprite.SetY((player->y * CSIZE) + 30);
      this->App->Draw(Sprite);
      return;
    }
}

void		Graphic::display3(t_egg *egg)
{
  if ((egg->x >= this->aff_x_min && egg->x <= (this->aff_x_min+14)) &&
      (egg->y >= this->aff_y_min && egg->y <= (this->aff_y_min+14)))
    {
      egg->x -= this->aff_x_min;
      egg->y -= this->aff_y_min;
      sf::Image Image;
      Image.LoadFromFile("./client_v3/egg.png");
      sf::Sprite Sprite(Image);
      
      Sprite.SetX(egg->x * CSIZE + 30);
      Sprite.SetY((egg->y * CSIZE) + 30);
      this->App->Draw(Sprite);
      return;
    }
}

void		Graphic::refresh_screen(int x, int y, std::list<t_players> p, std::list<t_block> m, std::list<t_egg> e)
{
  std::list<t_egg>::iterator it3;
  std::list<t_players>::iterator it2;
  std::list<t_block>::iterator it;

  it = m.begin();
  for(unsigned int i = 0; i < m.size(); i++)
    {
      if ((it->x == x) && (it->y == y))
	{
	  this->display(&(*it));
	  break;
	}
      it++;
    }
  it2 = p.begin();
  for(unsigned int i = 0; i < p.size(); i++)
    {
      if ((it2->x == x) && (it2->y == y))
	{
	  this->display2(&(*it2));
	  break;
	}
      it2++;
    }
  it3 = e.begin();
  for(unsigned int i = 0; i < e.size(); i++)
    {
      if ((it3->x == x) && (it3->y == y))
	{
	  this->display3(&(*it3));
	  return;
	}
      it3++;
    }
}

void		Graphic::refresh_screen2(std::list<t_players> p, std::list<t_block> m, std::list<t_egg> e)
{
  std::list<t_egg>::iterator it3;
  std::list<t_players>::iterator it2;
  std::list<t_block>::iterator it;

  it = m.begin();
  for(unsigned int i = 0; i < m.size(); i++)
    {
      this->display(&(*it));
      it++;
    }
  it2 = p.begin();
  for(unsigned int i = 0; i < p.size(); i++)
    {
      this->display2(&(*it2));
      it2++;
    }
  it3 = e.begin();
  for(unsigned int i = 0; i < e.size(); i++)
    {
      this->display3(&(*it3));
      it3++;
    }
}

sf::RenderWindow *	Graphic::getApp() const
{
  return (this->App);
}

bool			Graphic::getFlag()
{
  return (this->_flag);
}

sf::Image *	Graphic::getInfo()
{
  return (&(this->_info));
}

void			Graphic::input()
{
  bool			flag = false;
  sf::Event		Event;
  
  while (App->GetEvent(Event))
    {
      const sf::Input& Input = App->GetInput();

      if (Input.IsMouseButtonDown(sf::Mouse::Left))
	{
	  int Mx = Input.GetMouseX();
	  int My = Input.GetMouseY(); 

	  this->getIt(Mx, My);
	}
      if (Event.Type == sf::Event::Closed || (flag == true))
	{
	  std::cout << "Closing Game..." << std::endl;
	  this->_flag = false;
	  App->Close();
	  exit(EXIT_SUCCESS);
	}
      
      if (Event.Type == sf::Event::KeyPressed)
	{
	  if (Event.Key.Code == sf::Key::Escape)
	    {
	      this->_flag = false;
	    }
	  else if (Event.Key.Code == sf::Key::Up)
	    {
	      if (((this->aff_y_min * (-1))) < 14)
		{
		  this->move = true;
		  this->aff_y_min--;
		}
	    }
	  else if (Event.Key.Code == sf::Key::Right)
	    {
	      if ((this->aff_x_min  + 1) < this->_map_max_x)
		{
		  this->move = true;
		  this->aff_x_min++;
		}
	    }
	  else if (Event.Key.Code == sf::Key::Left)
	    {
	      if (((this->aff_x_min) * (-1))  < 14)
		{
		  this->move = true;
		  this->aff_x_min--;
		}
	    }
	  else if (Event.Key.Code == sf::Key::Down)
	    {
	      if ((this->aff_y_min + 1)  < this->_map_max_y)
		{
		  this->move = true;
		  this->aff_y_min++;
		}
	    }
	  else if (Event.Key.Code == sf::Key::F5)
	    {
	      sf::Image Screen = this->App->Capture();
	      Screen.SaveToFile("./screenshot.jpg");
	    }
	}
    }
}
