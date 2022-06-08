/**
 * SIMPLE INTEREST RATE
 * 
 * V = P(1+R), where V: future value
 *                   P: Principal
 *                   R: Interest rate
 */

#include <iostream>


class InterestRate {
private:
    double m_rate; //as R
    
public:

    InterestRate(double r);
    InterestRate(InterestRate &r); //&: take by reference so that a new InterestRate should not be created when i call the constractor
                                      // it is a "Copy constractor"
    void setRate(double rate); //mutator
    double getRate();           //accesor
    double SimplePeriod(double value, int numDays); 
    
    ~InterestRate();
};

////////////////////////////////////////////////////////////////////////
inline double InterestRate::SimplePeriod(double value, int numDays){
    double future_value;
    future_value = value*(1+(m_rate*numDays/365));
    return future_value;
}

InterestRate::InterestRate(double r) :m_rate(r){
}

InterestRate::InterestRate(InterestRate &r) : m_rate(r.m_rate){
    
}

InterestRate::~InterestRate(){
}

void InterestRate::setRate(double rate){ 
    m_rate = rate;
}

double InterestRate::getRate(){
    return m_rate;
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
    
    InterestRate *IntRate=new InterestRate(rate/100);
    //IntRate->setRate(rate/100);
    
    double rest = IntRate->SimplePeriod(value, num_days);
    
    std::cout<<"================================="<<std::endl;
    std::cout<<"Your Future Value will be: $"<<rest<<" after "<<num_days<<" Days"<<std::endl;
    
    return 0;
}