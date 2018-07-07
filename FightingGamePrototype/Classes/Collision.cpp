#include "Collision.h"

bool Collision::ObjectToObject(GameObject* GameObject1, GameObject* GameObject2)
{
	if(    (  GameObject1->GetX() >= GameObject2->GetX()  )                             && (  GameObject1->GetX() <= (GameObject2->GetX()+GameObject2->GetWidth()-1)  )                             &&  (   GameObject1->GetY() >= GameObject2->GetY()  )                             && (  GameObject1->GetY() <= (GameObject2->GetY()+GameObject2->GetHeight()-1)  )
        || (  GameObject1->GetX() >= GameObject2->GetX()  )                             && (  GameObject1->GetX() <= (GameObject2->GetX()+GameObject2->GetWidth()-1)  )                             &&  (  (GameObject1->GetY()+GameObject1->GetHeight()-1) >= GameObject2->GetY()  ) && (  (GameObject1->GetY()+GameObject1->GetHeight()-1) <= (GameObject2->GetY()+GameObject2->GetHeight()-1)  )
        || (  (GameObject1->GetX()+GameObject1->GetWidth()-1) >= GameObject2->GetX()  )	&& (  (GameObject1->GetX()+GameObject1->GetWidth()-1) <= (GameObject2->GetX()+GameObject2->GetWidth()-1)  ) &&  (   GameObject1->GetY() >= GameObject2->GetY()  )                             && (  GameObject1->GetY() <= (GameObject2->GetY()+GameObject2->GetHeight()-1)  )
        || (  (GameObject1->GetX()+GameObject1->GetWidth()-1) >= GameObject2->GetX()  )	&& (  (GameObject1->GetX()+GameObject1->GetWidth()-1) <= (GameObject2->GetX()+GameObject2->GetWidth()-1)  ) &&  (  (GameObject1->GetY()+GameObject1->GetHeight()-1) >= GameObject2->GetY()  ) && (  (GameObject1->GetY()+GameObject1->GetHeight()-1) <= (GameObject2->GetY()+GameObject2->GetHeight()-1)  )  ) 
    {
        return true;
        //PixelPerfectCollision(OtherCharacter);
    }
    else if( ( GameObject2->GetX() >= GameObject1->GetX() )                             && ( GameObject2->GetX() <= GameObject1->GetX() + GameObject1->GetWidth()-1 )								&& ( GameObject2->GetY() >= GameObject1->GetY() )                                 && ( GameObject2->GetY() <= GameObject1->GetY() + GameObject1->GetHeight()-1 )
    ||       ( GameObject2->GetX() >= GameObject1->GetX() )                             && ( GameObject2->GetX() <= GameObject1->GetX() + GameObject1->GetWidth()-1 )								&& ( GameObject2->GetY() + GameObject2->GetHeight()-1 >= GameObject1->GetY() )    && ( GameObject2->GetY() + GameObject2->GetHeight()-1 <= GameObject1->GetY() + GameObject1->GetHeight()-1 )
    ||       ( GameObject2->GetX() + GameObject2->GetWidth()-1 >= GameObject1->GetX() ) && ( GameObject2->GetX()  + GameObject2->GetWidth()-1 <= GameObject1->GetX() + GameObject1->GetWidth()-1 )  && ( GameObject2->GetY() >= GameObject1->GetY() )                                 && ( GameObject2->GetY() <= GameObject1->GetY() + GameObject1->GetHeight()-1 )
    ||       ( GameObject2->GetX() + GameObject2->GetWidth()-1 >= GameObject1->GetX() ) && ( GameObject2->GetX()  + GameObject2->GetWidth()-1 <= GameObject1->GetX() + GameObject1->GetWidth()-1 )  && ( GameObject2->GetY() + GameObject2->GetHeight()-1 >= GameObject1->GetY() )    && ( GameObject2->GetY() + GameObject2->GetHeight()-1 <= GameObject1->GetY() + GameObject1->GetHeight()-1 ) )
    {
        return true;
    }
 
    return false;
}

bool Collision::PointToObject(int xPos, int yPos, GameObject* GameObject1)
{
	if (((xPos >= GameObject1->GetX()) && (xPos <= (GameObject1->GetX() + GameObject1->GetWidth()))) && ((yPos >= GameObject1->GetY()) && (yPos <= (GameObject1->GetY() + GameObject1->GetHeight()))))
		return true;
	else
		return false;
}
