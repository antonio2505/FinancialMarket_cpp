/**
 * SIMPLE INTEREST RATE
 * 
 * V = P(1+R), where V: future value
 *                   P: Principal
 *                   R: Interest rate
 */

#include <iostream>
#include <cmath>


class InterestRate {
private:
    double m_rate; //as R
public:
    InterestRate(double rate);
    InterestRate(const InterestRate &v); //copy constructor
    InterestRate &operator =(const InterestRate &v); //copy assegnment
    ~InterestRate();
    
    inline double SimplePeriod(double value, int numDays); 
    inline double ReturnOnInvestment(double value, double finalvalue);
};

////////////////////////////////////////////////////////////////////////
double InterestRate::SimplePeriod(double value, int numDays){
    
    double future_value;
    future_value = value*(1+(m_rate*numDays/365));
    return future_value;
}

double InterestRate::ReturnOnInvestment(double value, double finalvalue){
    
    double returns = (finalvalue-value)/value;
    return returns*100;
}

InterestRate::InterestRate(double rate) : m_rate(rate){
    
}
InterestRate::~InterestRate(){
    
}
InterestRate::InterestRate(const InterestRate &v) :m_rate(v.m_rate){
    
}
InterestRate &InterestRate::operator =(const InterestRate &v){
    if(&v != this){
        this->m_rate = v.m_rate;
    }
    return *this;
}




///////////////////////////////////////////////////////////////////////////////

int main(){
    
    double rate{};
    double value{};
    int num_days{};
    
    std::cout<<"365 days in 1 Year."<<std::endl;
    std::cout<<"30 or 31 days in 1 Month."<<std::endl;
    std::cout<<std::endl;
    
    
    std::cout<<"Enter number of Days of Investment: ";
    std::cin>>num_days;
    
    std::cout<<"Enter your Rate in %: ";
    std::cin>>rate;
    
    std::cout<<"Enter your Investment Amount: ";
    std::cin>>value;
    std::cout<<std::endl;
    
    InterestRate IntRate(rate/100);
    
    double rest = IntRate.SimplePeriod(value, num_days);
    double pl = IntRate.ReturnOnInvestment(value, rest);
    
    std::cout<<"================================="<<std::endl;
    std::cout<<"Your Future Value will be   : $"<<rest<<" after "<<num_days<<" Days"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Your Returns On Investment is: "<<pl<<"% after "<<num_days<<" Days"<<std::endl;
    
    return 0;
}