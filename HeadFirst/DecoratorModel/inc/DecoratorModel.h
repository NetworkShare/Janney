#ifndef __DECORATOR_MODEL_H__
#define __DECORATOR_MODEL_H__
#include<string>
#include <iostream>

class CBeverage //饮料基类
{
  public:
        CBeverage( ) ;
        virtual ~CBeverage( ) ; 
  public:
        virtual std::string GetDescription( ) = 0;
        virtual double GetCost() = 0 ;
  public:
        std::string m_sDescription ;

};


class CCondimentDecorator:public CBeverage //饮料调料装饰基类
{
      public:
            CCondimentDecorator(CBeverage *lpBeverage) ;
            virtual ~CCondimentDecorator( ) ;
      protected:
	CBeverage *m_lpBeverage;
};


class CDarkToast:public CBeverage  //深焙咖啡,饮料主体具体类
{
      public:
        CDarkToast( ) ;
        ~CDarkToast( ) ;   

        public:
        double GetCost( );
        std::string GetDescription( ) ;
};


class CHouseBlend:public CBeverage  //首选咖啡,饮料主体具体类
{
      public:
        CHouseBlend( ) ;
        ~CHouseBlend( ) ;   

        public:
        double GetCost( ) ;
        std::string GetDescription( ) ;
};


class CMocha:public CCondimentDecorator //摩卡 饮料调料具体类
{
      public:
            CMocha(CBeverage *lpBeverage) ;
            ~CMocha( ) ;  
      public:   
           double GetCost( ) ;   
           std::string GetDescription( ) ;

}  ;


class CSoy:public CCondimentDecorator //豆浆 饮料调料具体类
{
      public:
            CSoy(CBeverage *lpBeverage) ;
            ~CSoy( ) ;  
      public:   
           double GetCost( ) ;   
           std::string GetDescription( ) ;
}  ;


class CMilk:public CCondimentDecorator //牛奶 饮料调料具体类
{
      public:
            CMilk(CBeverage *lpBeverage) ;
            ~CMilk( ) ;  
      public:   
           double GetCost( ) ;   
           std::string GetDescription( ) ;
}  ;


#endif