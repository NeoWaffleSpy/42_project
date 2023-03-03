#include "Warlock.hpp"
#include "TargetGenerator.hpp"

int main(void)
{
	Warlock richard("richard", "Le connard");
	Fireball* fb = new Fireball();
	Polymorph* pm = new Polymorph();

	TargetGenerator gen;
	Dummy dum;
	BrickWall bw;

	gen.learnTargetType(&bw);
	gen.learnTargetType(&dum);

	richard.learnSpell(fb);
	richard.learnSpell(pm);

	ATarget* brick = gen.createTarget("Inconspicuous Red-brick Wall");

	richard.launchSpell("Fireball", *brick);
	richard.launchSpell("Polymorph", *brick);

	delete fb;
	delete pm;

	Fwoosh* fw = new Fwoosh();
	richard.launchSpell("Fwoosh", *brick);
	richard.learnSpell(fw);
	richard.launchSpell("Fwoosh", *brick);
	delete fw;
	richard.launchSpell("Fwoosh", *brick);
	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", *brick);
}