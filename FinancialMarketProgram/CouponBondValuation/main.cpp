#include <iostream>
#include <vector>
#include <cmath>

class CouponBond{
private:
    double coupon;
    int m_timePeriod;// store the date when the payment occur
    double m_rate;

public:
    CouponBond(double r, double c);//r: rate
    CouponBond(const CouponBond &r);//copy constrator
    CouponBond &operator =(const CouponBond &r);//copy assegnment
    ~CouponBond();
    double PresentValue(double futureValue, int timePeriod);

};

CouponBond::CouponBond(double c, double r) : coupon(c), m_rate(r){
    
}

CouponBond::~CouponBond(){
    
}

CouponBond::CouponBond(const CouponBond &r) : coupon(r.coupon), m_rate(r.m_rate){
    
}

CouponBond &CouponBond::operator =(const CouponBond &r){
    if(this!=&r){
        this->coupon=r.coupon;
        this->m_rate = r.m_rate;
        this->m_timePeriod=r.m_timePeriod;
    }
    return *this;
}

double CouponBond::PresentValue(double f, int t){
    
    double c = coupon*f;
    double pv1{0};
    double pv2{0};
    for (int i{1}; i<=t-1; ++i){
    
    pv1 += c/pow(1+m_rate, i);
    std::cout<<"PV Year "<<i<<" is: $"<<pv1<<std::endl;
    }
    pv2 = (f+c)/pow(1+m_rate, t);
    std::cout<<"PV Year "<<t<<" is: $"<<pv2<<std::endl;
    std::cout<<std::endl;
    return pv1+pv2;
}




int main(){

    double rate{0};
    double couponRate{0};
    double princapl{0};
    int period{0};
    
    
    std::cout<<std::endl;
    std::cout<<"Enter Interest Rate in %: ";
    std::cin>>rate;
    std::cout<<"Enter Coupon Rate in %  : ";
    std::cin>>couponRate;
    std::cout<<"Enter Principal         : ";
    std::cin>>princapl;
    std::cout<<"Enter Period in Year    : ";
    std::cin>>period;
    std::cout<<std::endl;
    
    CouponBond coupRat(couponRate/100, rate/100);

    std::cout<<std::endl;
    std::cout<<"=============================="<<std::endl;
    
    double result = coupRat.PresentValue(princapl, period);
    std::cout<<std::endl;
    std::cout<<"=============================="<<std::endl;
    
    std::cout<<"Interest Rate r= "<<rate<<"%"<<std::endl;
    std::cout<<"Face value     : $"<<princapl<<std::endl;
    std::cout<<"Coupon         : $"<<couponRate/100*princapl<<std::endl;
    std::cout<<"Period         : "<<period<<" years"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"=============================="<<std::endl;
    std::cout<<"The Present Value is: $"<<round(result)<<std::endl;
    std::cout<<"=============================="<<std::endl;
    std::cout<<std::endl;
    
    return 0;
}