#include "Strategy.h"

CFlyBehavior::CFlyBehavior()
{

}


CFlyBehavior::~CFlyBehavior()
{

}


CFlyWithWings::CFlyWithWings()
{

}

CFlyWithWings::~CFlyWithWings()
{

}

void CFlyWithWings::Fly()
{
	printf("Fly with wings!\r\n");
}


CFlyNoWay::CFlyNoWay()
{

}


CFlyNoWay::~CFlyNoWay()
{

}


void CFlyNoWay::Fly()
{
	printf("I can not fly!\r\n");
}


CFlyWithRocket::CFlyWithRocket()
{

}


CFlyWithRocket::~CFlyWithRocket()
{

}


void CFlyWithRocket::Fly()
{
	printf("Fly with rocket!\r\n");
}


CQuackBehavior::CQuackBehavior()
{

}


CQuackBehavior::~CQuackBehavior()
{

}


CQuack::CQuack()
{

}


CQuack::~CQuack()
{

}


void CQuack::Quack()
{
	printf("I can quack!\r\n");
}


CMuteQuack::CMuteQuack()
{

}


CMuteQuack::~CMuteQuack()
{

}


void CMuteQuack::Quack()
{
	printf("Slient\r\n");
}


CSqueak::CSqueak()
{

}


CSqueak::~CSqueak()
{

}


void CSqueak::Quack()
{
	printf("I can squeak!\r\n");
}


CDuck::CDuck()
{

}


CDuck::~CDuck()
{

}


void CDuck::PerformFly( )
{
	m_cFlyBehavior->Fly() ;
} 


void CDuck::PerformQuack( )
{
	m_cQuackBehavior->Quack();
} 


void CDuck::Swim( )
{
	printf("All ducks can swim!\r\n");
}


void CDuck::SetFlyBehavior(CFlyBehavior* cFlyBehavior)
{
	m_cFlyBehavior = cFlyBehavior ;
} 


void CDuck::SetQuackBehavior(CQuackBehavior* cQuackBehavior)
{
	m_cQuackBehavior = cQuackBehavior ;
} 


CMallardDuck::CMallardDuck()
{
	m_lpFlyBehavior = new CFlyWithWings ;
	m_lpQuackBehavior = new CQuack ;
	SetFlyBehavior(m_lpFlyBehavior) ;
	SetQuackBehavior(m_lpQuackBehavior) ;
}


CMallardDuck::~CMallardDuck()
{
	delete m_lpQuackBehavior ;
	delete m_lpFlyBehavior ;

}


void CMallardDuck::Display()
{
	printf("I am a real Mallard duck!\r\n") ;
}


CModelDuck::CModelDuck()
{
	m_lpFlyBehavior = new CFlyNoWay ;
	m_lpQuackBehavior = new CMuteQuack ;
	SetFlyBehavior(m_lpFlyBehavior) ;
	SetQuackBehavior(m_lpQuackBehavior) ;
}


CModelDuck::~CModelDuck()
{
	delete m_lpQuackBehavior ;
	delete m_lpFlyBehavior ;
}


void CModelDuck::Display()
{
	printf("I am a Model duck!\r\n") ;
} 


int main(int arg, char** argv)
{
	CMallardDuck cMallardDuck ;
	CFlyWithRocket cFlyRocket ;
	CSqueak		 cSqueak ;
	CQuack		 cQuack ;
	cMallardDuck.Display();
	cMallardDuck.PerformFly() ;
	cMallardDuck.PerformQuack() ;
	cMallardDuck.Swim();

	getchar() ;
	printf("Now change Mallard duck behavior\r\n") ;
	cMallardDuck.SetFlyBehavior(&cFlyRocket) ;
	cMallardDuck.SetQuackBehavior(&cSqueak) ;
	cMallardDuck.Display();
	cMallardDuck.PerformFly() ;
	cMallardDuck.PerformQuack() ;
	cMallardDuck.Swim();
	
	getchar() ;
	CModelDuck cModelDuck ;
	CFlyWithWings cFlyWithWings ;
	cModelDuck.Display();
	cModelDuck.PerformFly() ;
	cModelDuck.PerformQuack() ;
	cModelDuck.Swim();

	getchar() ;
	printf("Now change Model duck behavior\r\n") ;
	cModelDuck.SetFlyBehavior(&cFlyWithWings) ;
	cModelDuck.SetQuackBehavior(&cQuack) ;
	cModelDuck.Display();
	cModelDuck.PerformFly() ;
	cModelDuck.PerformQuack() ;
	cModelDuck.Swim();
	getchar() ;

	return 0 ;
}


