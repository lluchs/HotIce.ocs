/**
	HeliBullet
	

	@author 
*/

local Name = "$Name$";
local Description = "$Description$";

public func Launch(int angle, int speed, int pa, int ps)
{
	SetAction("Travel");
	SetVelocity(angle, speed, pa, ps);
	AddEffect("HitCheck", this, 1,1, nil,nil, this);

	CreateObjectAbove(BulletTrail,0,0)->Set(1, 100, this);
}

func HitObject(obj)
{
	WeaponDamage(obj, 15);
	
	if(obj->GetID() == Boompack)
	{
		obj->Fuse();
	}
	
	Sound("Hits::ProjectileHitLiving?");
	RemoveObject();
}

func Hit()
{
		BlastFree(GetX(), GetY(), 10);
		
		Sound("Objects::Weapons::Musket::BulletHitGround?");
		
		CreateParticle("StarSpark", 0, 0, PV_Random(-20, 20), PV_Random(-20, 20), PV_Random(10, 20), Particles_Glimmer(), 3);
		
		RemoveObject();
}

public func TrailColor(int time)
{
	return RGBa(255,255,100,255);
}

local ActMap = {

	Travel = {
		Prototype = Action,
		Name = "Travel",
		Procedure = DFA_FLOAT,
		NextAction = "Travel",
		Length = 1,
		Delay = 1,
		FacetBase = 1,
		Speed = 100000,
	},
};