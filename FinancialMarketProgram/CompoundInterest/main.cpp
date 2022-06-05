/*
 * Calculate the compound interest accumulated by a given principal value after the
    passage of N time periods.
     * 
     * V = P(1+R)^N, where V: future value
     *                     P: present value
     *                     R: interest rate
     *                     N: number of period
     * 
     * 

 * Continous compounding :
 * 
 * V = P*e^(RN), the payment are made continuously over time.
 * */
 
 #include <iostream>
 #include <cmath> //to use pow and exp
 
 
class CompoundIntRate {
private:
    double m_rate; //R
    
public:
    CompoundIntRate(double rate);
    CompoundIntRate(const CompoundIntRate &v);
    CompoundIntRate &operator=(const CompoundIntRate &v);
    ~CompoundIntRate();

    double MonthlyMultiplePeriod(double value, int numPeriod, int numMonth); //monthly
    
    
 };
 
CompoundIntRate::CompoundIntRate(double rate) : m_rate(rate){
    
}
CompoundIntRate::~CompoundIntRate(){
    
}
CompoundIntRate::CompoundIntRate(const CompoundIntRate &v) :m_rate(v.m_rate) {
    
}
CompoundIntRate &CompoundIntRate::operator =(const CompoundIntRate &v){
    if(this != &v){
        this->m_rate = v.m_rate;
    }
    return *this;
}


double CompoundIntRate::MonthlyMultiplePeriod(double value, int numPeriod, int numMonth){
    
    int num = 12/numMonth;
    double f = value*pow((1+(m_rate/num)), num*numPeriod);
    return f;
}


///////////////////////////////////////////////////////////////////////////////

int main(){
    
    double rate{};
    double value{};
    int period{};
    int numMonth{};
    
    std::cout<<"Month-Annual conversion"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Semiannual: every 6 months  : 2 times a year "<<std::endl;
    std::cout<<"Quarterly : every 3 months  : 4 times a year"<<std::endl;
    std::cout<<"Monthly   : every 12 months : 1 times a year"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"Enter your Rate in %: ";
    std::cin>>rate;
    std::cout<<"Enter your Investment Amount: ";
    std::cin>>value;
    std::cout<<"How many years you want to invest? : ";
    std::cin>>period;
    std::cout<<"Enter number of Monthly Payment : ";
    std::cin>>numMonth;
    
    CompoundIntRate compIntrate{rate/100};
    double multiperiod = compIntrate.MonthlyMultiplePeriod(value,period,numMonth);
    
    
    std::cout<<std::endl;
    std::cout<<"================================="<<std::endl;

    std::cout<<"Rate             : "<<rate<<"%"<<std::endl;
    std::cout<<"Investment Amount: $"<<value<<std::endl;
    std::cout<<"Investment Period: "<<period<<" Years"<<std::endl;
    std::cout<<"Periodic payment: every "<<numMonth<<" Months"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"MULTIPERIOD METHOD:"<<std::endl;
    std::cout<<"Your Periodic payment will be: $"<<multiperiod<<" every "<<numMonth<<" months"<< " to "<<period<<" years"<<std::endl;
    std::cout<<std::endl;
    
        
    return 0;
}