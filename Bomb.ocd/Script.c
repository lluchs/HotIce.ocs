/**
	Bomb
	

	@author 
*/

local Name = "$Name$";
local Description = "$Description$";


local RotateFx = new Effect {

	Timer = func()
	{
		var angle = Angle(0, 0, Target->GetXDir(), Target->GetYDir());
		var a = Target->GetR() + 90;
		
		if (a < angle)
			Target->SetR(Target->GetR()+1);
		else
			Target->SetR(Target->GetR()-1);
	
	}

};

func Initialize()
{
	CreateEffect(RotateFx, 1, 1);
}

func Hit()
{
	CastObjects(Flame, 5, 10);
	Explode(40);
}
