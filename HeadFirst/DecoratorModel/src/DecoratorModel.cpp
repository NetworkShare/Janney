// DecoratorModel.cpp : Defines the entry point for the console application.

#include "DecoratorModel.h"

CBeverage::CBeverage( )
{
	m_sDescription = "Unknown Beverage" ;
}


CBeverage::~CBeverage( )
{

}


CCondimentDecorator::CCondimentDecorator(CBeverage *lpBeverage) 
{
	m_lpBeverage = lpBeverage ;
}


CCondimentDecorator::~CCondimentDecorator( )
{

}


CDarkToast::CDarkToast( )
{
	m_sDescription = "Dark Toast Coffee" ;
}


CDarkToast::~CDarkToast( )
{

}


double CDarkToast::GetCost( ) 
{
	return 1.99 ;
}


std::string CDarkToast::GetDescription( )
{
	return m_sDescription ;
}




CHouseBlend::CHouseBlend( )
{
	m_sDescription = "HouseBlend Coffee" ;
}


CHouseBlend::~CHouseBlend( )
{

}


double CHouseBlend::GetCost( ) 
{
	return 0.99 ;
}


std::string CHouseBlend::GetDescription( )
{
	return m_sDescription ;
}





CMocha::CMocha(CBeverage *lpBeverage):CCondimentDecorator(lpBeverage)
{

}


CMocha::~CMocha( )
{

}


std::string  CMocha::GetDescription() 
{
	return m_lpBeverage->GetDescription( ) + " Mocha" ;
}


double CMocha::GetCost( ) 
{
	return m_lpBeverage->GetCost( ) + 0.2 ;
}




CSoy::CSoy(CBeverage *lpBeverage):CCondimentDecorator(lpBeverage)
{

}


CSoy::~CSoy( )
{

}


std::string  CSoy::GetDescription() 
{
	return m_lpBeverage->GetDescription( ) + " Soy" ;
}


double CSoy::GetCost( ) 
{
	return m_lpBeverage->GetCost( ) + 0.3 ;
}





CMilk::CMilk(CBeverage *lpBeverage):CCondimentDecorator(lpBeverage)
{

}


CMilk::~CMilk( )
{

}


std::string  CMilk::GetDescription() 
{
	return m_lpBeverage->GetDescription( ) + " Milk" ;
}


double CMilk::GetCost( ) 
{
	return m_lpBeverage->GetCost( ) + 0.1 ;
}





int main(int argc, char* argv[])
{

	CDarkToast cDarkToast ;
	std::cout<< cDarkToast.GetDescription()<<"; "<<"Cost:"<<cDarkToast.GetCost() <<std::endl ;

	{
		CHouseBlend cHouseBlend ;
		std::cout<< cHouseBlend.GetDescription()<<"; "<<"Cost:"<<cHouseBlend.GetCost() <<std::endl ;
		CMocha  cMocha1(&cHouseBlend) ;
		std::cout<< cMocha1.GetDescription()<<"; "<<"Cost:"<<cMocha1.GetCost() <<std::endl ;
		CMocha  cMocha2(&cMocha1) ;
		std::cout<< cMocha2.GetDescription()<<"; "<<"Cost:"<<cMocha2.GetCost() <<std::endl ;
		CSoy    cSoy(&cMocha2) ;
		std::cout<< cSoy.GetDescription()<<"; "<<"Cost:"<<cSoy.GetCost() <<std::endl ;	
	}


	{
		CHouseBlend cHouseBlend ;
		std::cout<< cHouseBlend.GetDescription()<<"; "<<"Cost:"<<cHouseBlend.GetCost() <<std::endl ;
		CMocha  cMocha1(&cHouseBlend) ;
		std::cout<< cMocha1.GetDescription()<<"; "<<"Cost:"<<cMocha1.GetCost() <<std::endl ;
		CMilk  cMilk(&cMocha1) ;
		std::cout<< cMilk.GetDescription()<<"; "<<"Cost:"<<cMilk.GetCost() <<std::endl ;
		CSoy    cSoy(&cMilk) ;
		std::cout<< cSoy.GetDescription()<<"; "<<"Cost:"<<cSoy.GetCost() <<std::endl ;	
	}

	return 0;
}

